/*����ģʽ����*/
#include <iostream>
#include <map> //���Դ���ʹ�õĹ���ģʽ��״̬����
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
		std::cout << "�㷨A" << std::endl;
	}
};

class ConcreteStrategyB :public Strategy
{
protected:
	virtual void algorithmInterface()
	{
		std::cout << "�㷨B" << std::endl;
	}
};

/*����ģʽ�Ĵ���*/
/*
* 1.һ����˵����ģʽ��Ҫʹ��type�������־�����㷨��Ϊ�˷�װ���Դ������߼����δ�����ϸ�ڣ���type�������Ե��߼�������������빤�����С�
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
	static Strategy* getStrategy(std::string type);			//�����಻����Ϊ�����ķ���ֵ������ʹ�ó������ָ������á�
private:
	std::map<std::string, Strategy*> strategies;
};





