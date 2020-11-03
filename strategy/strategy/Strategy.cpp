/*����ģʽ����*/
#include <iostream>
#include <map> //���Դ���ʹ�õĹ���ģʽ��״̬����
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
		std::cout << "�㷨A" << std::endl;
	}
};

class ConcreteStrategyB :public Strategy
{
public:
	void algorithmInterface()
	{
		std::cout << "�㷨B" << std::endl;
	}
};

class ConcreteStrategyC :public Strategy
{
public:
	void algorithmInterface()
	{
		std::cout << "�㷨C" << std::endl;
	}
};

/*����ģʽ�Ĵ���*/
/*
* 1.һ����˵����ģʽ��Ҫʹ��type�������־�����㷨��Ϊ�˷�װ���Դ������߼����δ�����ϸ�ڣ���type�������Ե��߼�������������빤�����С�
* 2.�������Ƿ������Ա�������Է�Ϊ��״̬����״̬	
*
*
*
*
*/

//��״̬�Ĳ��Թ���
class StrategyFactory
{
public:
	static  std::map<std::string, Strategy*> init();
	static Strategy* getStrategy(std::string type);			//�����಻����Ϊ�����ķ���ֵ������ʹ�ó������ָ������á�
	static void RegistStrategy(std::string type,Strategy* s);
private:
	static std::map<std::string, Strategy*> _strategies;			//����Ӧ���õ�ע�����
};

std::map<std::string, Strategy*> StrategyFactory::_strategies = StrategyFactory::init();

//��ʱ��������
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

//ʹ�ò���ģʽ����
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
		std::cout << "���㷨������" << std::endl;
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
	std::cout << "����APP" << std::endl;
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







