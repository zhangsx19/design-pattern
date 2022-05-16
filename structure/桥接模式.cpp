#include<iostream>
#include <cstring>
using namespace std;
//车安装发动机
class Engine
{
private:
    /* data */
public:
    virtual void installengine() = 0;
};
class cc_4400:public Engine
{
private:
    /* data */
public:
    virtual void installengine(){
        cout<<"我是4400cc发动机，安装完毕"<<endl;
    }
};
class cc_4500:public Engine
{
private:
    /* data */
public:
    virtual void installengine(){
        cout<<"我是4500cc发动机，安装完毕"<<endl;
    }
};
class Car
{
protected:
    Engine *engine_m;
public:
    Car(Engine *engine){
        engine_m = engine;
    }
    virtual void installengine() = 0;
};
class WBM5:public Car
{
public:
    WBM5(Engine *engine):Car(engine)
    {
        
    }
    virtual void installengine(){
        engine_m->installengine();//不在car类实现而是在发动机类(要组合的对象)实现
    };
};
class WBM6:public Car
{
public:
    WBM6(Engine *engine):Car(engine)
    {
        
    }
    virtual void installengine(){
        cout<<"我是WBM6"<<endl;
        engine_m->installengine();
    };
};


int main(){
    Engine *engine = new cc_4400;
    Car *car = new WBM6(engine);
    car->installengine();
    delete car;
    delete engine;
    cout<<"hello"<<endl;
    return 0;
}