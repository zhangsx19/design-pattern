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
    State *m_currstate;//����ǰ״̬
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
            cout<<"�����"<<endl;
        }
        else{
            delete w->getState();//״̬1�����㣬Ҫת��״̬2
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
        cout<<"����"<<endl;
    }
    else{
        delete w->getState();//״̬2�����㣬Ҫת��״̬3
        w->setState(new State3);
        w->getState()->doSomeThing(w);
    }
}
void State3::doSomeThing(Worker* w){
    if(w->getHour()==11||w->getHour()==12){
        cout<<"��˯"<<endl;
    }
    else{
        delete w->getState();//״̬3�����㣬Ҫת��״̬1
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