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
class RunCar:public Car//可以跑的车(无装饰)
{
private:
public:
    virtual void show(){
        cout<<"跑车"<<endl;
    }
};

class SwimDecorate:public Car//可以swim
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
        cout<<"游车"<<endl;
    }
};
class FlyDecorate:public Car//可以swim
{
private:
    Car *car_m;
public:
    FlyDecorate(Car *car){
        car_m = car;
    }
    virtual void show(){
        car_m->show();//可调用装饰过的show
        fly();
    }
    void fly(){
        cout<<"飞车"<<endl;
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