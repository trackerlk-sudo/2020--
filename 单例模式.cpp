#include<iostream>
#include<mutex>

using namespace std;

//单例模式 懒汉模式
class Single {
private:
	Single(){}
	static Single* instance;//静态成员指针
	static mutex mut;

public:
	static Single* getinstance();
};

Single* Single::instance = NULL;
mutex Single::mut;


Single* Single::getinstance() 
{
	if (instance == NULL)
	{
		mut.lock();
		if (instance == NULL)
		{
			instance = new Single();
		}
		mut.unlock();
	}
	return instance;
}

//单例模式 饿汉模式
//class SingleObj {
//private:
//	SingleObj(){}
//
//public:
//	static SingleObj* instance;
//	static SingleObj* getinstance()
//	{
//		return instance;
//	}
//
//};
//SingleObj* SingleObj::instance = new SingleObj();//类的成员变量的定义，可以调用私有函数



int main()
{
	Single* instance1=Single::getinstance();
	Single* instance2 = Single::getinstance();
	Single* instance3 = Single::getinstance();

	cout << instance1 << endl;
	cout << instance2 << endl;
	cout << instance3 << endl;
	system("pause");
	return 0;
}