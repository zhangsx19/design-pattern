#include<iostream>
#include <cstring>
#include<list>
using namespace std;
class MakeCar
{
public:
    virtual void MakeHead() = 0;
    virtual void MakeBody() = 0;
    virtual void MakeTail() = 0;
    virtual void Make(){//模板函数
        MakeHead();
        MakeBody();
        MakeTail();
    };
};
class Jeep:public MakeCar
{
public:
    virtual void MakeHead(){
        cout<<"jeep head"<<endl;
    };
    virtual void MakeBody(){
        cout<<"jeep body"<<endl;
    };
    virtual void MakeTail(){
        cout<<"jeep tail"<<endl;
    };
};
class Bus:public MakeCar
{
public:
    virtual void MakeHead(){
        cout<<"Bus head"<<endl;
    };
    virtual void MakeBody(){
        cout<<"Bus body"<<endl;
    };
    virtual void MakeTail(){
        cout<<"Bus tail"<<endl;
    };
};
int main(){
    //面向抽象类编程
    MakeCar *car = new Bus;
    car->Make();
    delete car;
    cout<<"hello"<<endl;
    return 0;
}