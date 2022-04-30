#include<iostream>
#include <cstring>
using namespace std;
//����װ������
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
        cout<<"����4400cc����������װ���"<<endl;
    }
};
class cc_4500:public Engine
{
private:
    /* data */
public:
    virtual void installengine(){
        cout<<"����4500cc����������װ���"<<endl;
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
        engine_m->installengine();//����car��ʵ�ֶ����ڷ�������(Ҫ��ϵĶ���)ʵ��
    };
};
class WBM6:public Car
{
public:
    WBM6(Engine *engine):Car(engine)
    {
        
    }
    virtual void installengine(){
        cout<<"����WBM6"<<endl;
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