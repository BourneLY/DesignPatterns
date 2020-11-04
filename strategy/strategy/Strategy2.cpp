#include <iostream>
#include <map>
#include <string>

class Strategy
{
public:
	Strategy() {}
	virtual ~Strategy() {}
	virtual void Alogrithm() = 0;
private:

};

//�ο�
class ConcreteStrategyA : public Strategy
{
public:
	ConcreteStrategyA(int num, std::string name) :_number(num), _name(name) {}
	~ConcreteStrategyA() {}
	void Alogrithm();
private:
	int _number;
	std::string _name;
};

void ConcreteStrategyA::Alogrithm()
{
	std::cout <<"***************************"<< std::endl;
	std::cout << "�ο�: " << std::endl;
	std::cout << "_number:" << this->_number << std::endl;
	std::cout << "_name" << this->_name << std::endl;
	std::cout << "**************************" << std::endl;
}

//ע�����
class ConcreteStrategyB :public Strategy
{
public:
	ConcreteStrategyB(int num, std::string name,std::string address, int tele) :_number(num), _name(name),_address(address), _telephone(tele) {}
	~ConcreteStrategyB(){}
	void Alogrithm();
private:
	int _number;
	std::string _name;
	std::string _address;
	int _telephone;
};

void ConcreteStrategyB::Alogrithm()
{
	std::cout << "***************************" << std::endl;
	std::cout << "ע�����: " << std::endl;
	std::cout << "_number:" << this->_number << std::endl;
	std::cout << "_name" << this->_name << std::endl;
	std::cout << "_address:" << this->_address << std::endl;
	std::cout << "_telephone:" << this->_telephone << std::endl;
	std::cout << "**************************" << std::endl;
}

//vip���
class ConcreteStrategyC :public Strategy
{
public:
	ConcreteStrategyC(int num, std::string name, std::string address, int tele,int g) :_number(num), _name(name), _address(address), _telephone(tele),_gold(g) {}
	~ConcreteStrategyC() {}
	void Alogrithm();
private:
	int _number;
	std::string _name;
	std::string _address;
	int _telephone;
	int _gold;
};

void ConcreteStrategyC::Alogrithm()
{
	std::cout << "***************************" << std::endl;
	std::cout << "vip���: " << std::endl;
	std::cout << "_number:" << this->_number << std::endl;
	std::cout << "_name" << this->_name << std::endl;
	std::cout << "_address:" << this->_address << std::endl;
	std::cout << "_telephone:" << this->_telephone << std::endl;
	std::cout << "_gold:" << this->_gold << std::endl;
	std::cout << "**************************" << std::endl;
}