/*策略模式定义*/
#include <iostream>
#include <map> //策略创建使用的工厂模式中状态变量
#include <string>
#include <utility>

class Strategy
{
public:
	Strategy() {}
	virtual ~Strategy() {}
	virtual void algorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy
{
public:
	ConcreteStrategyA() {}
	~ConcreteStrategyA() {}
	void algorithmInterface()
	{
		std::cout << "算法A" << std::endl;
	}
};

class ConcreteStrategyB :public Strategy
{
public:
	void algorithmInterface()
	{
		std::cout << "算法B" << std::endl;
	}
};

class ConcreteStrategyC :public Strategy
{
public:
	void algorithmInterface()
	{
		std::cout << "算法C" << std::endl;
	}
};

/*策略模式的创建*/
/*
* 1.一般来说策略模式需要使用type进行区分具体的算法，为了封装策略创建的逻辑屏蔽创建的细节，将type创建策略的逻辑抽离出来，放入工厂类中。
* 2.策略类是否包含成员变量可以分为有状态和无状态	
*
*
*
*
*/

//无状态的策略工厂
class StrategyFactory
{
public:
	static  std::map<std::string, Strategy*> init();
	static Strategy* getStrategy(std::string type);			//抽象类不能作为函数的返回值，可以使用抽象类的指针或引用。
	static void RegistStrategy(std::string type,Strategy* s);
private:
	static std::map<std::string, Strategy*> _strategies;			//这里应该用到注册最好
};

std::map<std::string, Strategy*> StrategyFactory::_strategies = StrategyFactory::init();

//暂时先用这种
std::map<std::string, Strategy*> StrategyFactory::init()
{
	std::map<std::string, Strategy*> strategies;
	Strategy *A = new ConcreteStrategyA();
	strategies.insert(std::make_pair("strategyA", A));
	strategies.insert(std::make_pair("strategyB", new ConcreteStrategyB()));
	return strategies;
}
Strategy* StrategyFactory::getStrategy(std::string type)
{
	if (type == "" || type.empty())
	{
		return NULL;
	}
	std::map<std::string, Strategy*>::iterator it = _strategies.find(type);
	if (it == _strategies.end())
		return NULL;
	return it->second;
}

void StrategyFactory::RegistStrategy(std::string type, Strategy *s)
{
	_strategies.insert(std::make_pair(type, s));
}

//使用策略模式的类
class UserCache
{
public:
	UserCache(std::string type) :_type(type) {}
	~ UserCache() {}
	void DoSomethings();
private:
	//Strategy *_strategy;
	std::string _type;
};

void UserCache::DoSomethings()
{
	Strategy* strategy = StrategyFactory::getStrategy(this->_type);
	if (strategy == NULL)
	{
		std::cout << "此算法不存在" << std::endl;
		return;
	}
	strategy->algorithmInterface();
}

class Application
{
public:
	friend class Strategy;
public:
	Application(UserCache* uc) :_userCache(uc){}
	~Application();
	void AppDoSomethings();
	void AppRegistStrategy(std::string type,Strategy* s);
private:
	UserCache *_userCache;
};

Application::~Application()
{
	delete _userCache;
	_userCache = NULL;
	std::cout << "析构APP" << std::endl;
}

void Application::AppDoSomethings()
{
	_userCache->DoSomethings();
}

void Application::AppRegistStrategy(std::string type, Strategy* s)
{
	StrategyFactory::RegistStrategy(type, s);
}

int main()
{
	UserCache *useCache = new UserCache("strategyC");
	Application *app = new Application(useCache);
	std::string type = "strategyC";
	Strategy *strategy = new ConcreteStrategyC();
	app->AppRegistStrategy(type, strategy);
	app->AppDoSomethings();
	delete app;
	app = NULL;
	return 0;
}







