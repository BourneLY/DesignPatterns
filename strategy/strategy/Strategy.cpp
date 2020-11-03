/*策略模式定义*/
#include <iostream>
#include <map> //策略创建使用的工厂模式中状态变量
#include <string>

class Strategy
{
public:
	virtual void algorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy
{
protected:
	virtual void algorithmInterface()
	{
		std::cout << "算法A" << std::endl;
	}
};

class ConcreteStrategyB :public Strategy
{
protected:
	virtual void algorithmInterface()
	{
		std::cout << "算法B" << std::endl;
	}
};

/*策略模式的创建*/
/*
* 1.一般来说策略模式需要使用type进行区分具体的算法，为了封装策略创建的逻辑屏蔽创建的细节，将type创建策略的逻辑抽离出来，放入工厂类中。
*	
*
*
*
*
*/

class StrategyFactory
{
public:
	static void init();
	static Strategy* getStrategy(std::string type);			//抽象类不能作为函数的返回值，可以使用抽象类的指针或引用。
private:
	std::map<std::string, Strategy*> strategies;
};





