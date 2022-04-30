#include<iostream>
#include <cstring>
#include<list>
using namespace std;
class Worker;
class State
{
public:
    virtual void doSomeThing(Worker* w) = 0;
};
class Worker
{
public:
    Worker();
    int getHour(){
        return m_hour;
    }
    void setHour(int hour){
        m_hour = hour;
    }
    State *getState(){
        return m_currstate;
    }
    void setState(State *state){
        m_currstate = state;
    }
    void doSomeThing(){
        m_currstate->doSomeThing(this);
    }
private:
    int m_hour;
    State *m_currstate;//对象当前状态
};
class State2:public State
{
public:
    virtual void doSomeThing(Worker* w);
};
class State1:public State
{
public:
    virtual void doSomeThing(Worker* w){
        if(w->getHour()==7||w->getHour()==8){
            cout<<"吃早餐"<<endl;
        }
        else{
            delete w->getState();//状态1不满足，要转到状态2
            w->setState(new State2);
            w->getState()->doSomeThing(w);
        }
    }
};
Worker::Worker(){
    m_currstate = new State1;
}
class State3:public State
{
public:
    virtual void doSomeThing(Worker* w);
};
void State2::doSomeThing(Worker* w){
    if(w->getHour()==9||w->getHour()==10){
        cout<<"工作"<<endl;
    }
    else{
        delete w->getState();//状态2不满足，要转到状态3
        w->setState(new State3);
        w->getState()->doSomeThing(w);
    }
}
void State3::doSomeThing(Worker* w){
    if(w->getHour()==11||w->getHour()==12){
        cout<<"午睡"<<endl;
    }
    else{
        delete w->getState();//状态3不满足，要转到状态1
        w->setState(new State1);
        w->getState()->doSomeThing(w);
    }
}

int main(){
    Worker *w1 = new Worker;
    w1->setHour(8);
    w1->doSomeThing();
    w1->setHour(10);
    w1->doSomeThing();
    w1->setHour(12);
    w1->doSomeThing();
    delete w1;
    cout<<"hello"<<endl;
    return 0;
}