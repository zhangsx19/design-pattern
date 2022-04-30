#include<iostream>
#include <cstring>
using namespace std;
class Car
{
private:
    /* data */
public:
    virtual void show() = 0;
};
class RunCar:public Car//�����ܵĳ�(��װ��)
{
private:
public:
    virtual void show(){
        cout<<"�ܳ�"<<endl;
    }
};

class SwimDecorate:public Car//����swim
{
private:
    Car *car_m;
public:
    SwimDecorate(Car *car){
        car_m = car;
    }
    virtual void show(){
        car_m->show();
        swim();
    }
    void swim(){
        cout<<"�γ�"<<endl;
    }
};
class FlyDecorate:public Car//����swim
{
private:
    Car *car_m;
public:
    FlyDecorate(Car *car){
        car_m = car;
    }
    virtual void show(){
        car_m->show();//�ɵ���װ�ι���show
        fly();
    }
    void fly(){
        cout<<"�ɳ�"<<endl;
    }
};

int main(){
    Car *runcar = new RunCar;
    runcar->show();
    FlyDecorate *flycar = new FlyDecorate(runcar);
    flycar->show();
    SwimDecorate *swimandflycar = new SwimDecorate(flycar);
    swimandflycar->show();
    cout<<"hello"<<endl;
    return 0;
}