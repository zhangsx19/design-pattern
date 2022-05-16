#include<iostream>
#include <cstring>
#include<list>
using namespace std;
class Mediator;//预定义

class Person
{
public:
    Person(string name,int condi,Mediator *mediator){
        m_name = name;
        m_condi = condi;
        m_sex = "";
        m_mediator = mediator;
    }
    string getSex(){
        return m_sex;
    }
    int getCondi(){
        return m_condi;
    }
    virtual void getPair(Person *p) = 0;
protected:
    string m_name;
    string m_sex;
    int m_condi;//适配等级
    Mediator *m_mediator;
};

class Mediator//婚姻中介者
{
public:
    virtual void getPair(){
        if(pwoman->getSex()==pman->getSex()){
            cout<<"同性"<<endl;
        }
        else{
            if(pwoman->getCondi()==pman->getCondi())cout<<"绝配"<<endl;
            else cout<<"不配"<<endl;
        }
    };
    void setMan(Person *man){
        pman = man;
    }
    void setWoman(Person *woman){
        pwoman = woman;
    }
protected:
    Person *pman;
    Person *pwoman;//也可做成一对多的list
};

class Woman:public Person
{
public:
    Woman(string name,int condi,Mediator *mediator):Person(name,condi,mediator)
    {
        m_sex = "woman";
    }
    virtual void getPair(Person *p){
        m_mediator->setWoman(this);
        m_mediator->setMan(p);
        m_mediator->getPair();
    }
};
class Man:public Person
{
public:
    Man(string name,int condi,Mediator *mediator):Person(name,condi,mediator)
    {
        m_sex = "man";
    }
    virtual void getPair(Person *p){
        m_mediator->setMan(this);
        m_mediator->setWoman(p);
        m_mediator->getPair();
    }
};
int main(){
    Mediator *m = new Mediator;
    Person *xiaofang = new Woman("小芳",5,m);
    Person *zhangsan = new Man("张三",4,m);
    Person *lisi = new Man("李四",5,m);
    xiaofang->getPair(zhangsan);
    xiaofang->getPair(lisi);
    zhangsan->getPair(lisi);
    cout<<"hello"<<endl;
    return 0;
}