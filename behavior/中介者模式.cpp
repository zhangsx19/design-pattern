#include<iostream>
#include <cstring>
#include<list>
using namespace std;
class Mediator;//Ԥ����

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
    int m_condi;//����ȼ�
    Mediator *m_mediator;
};

class Mediator//�����н���
{
public:
    virtual void getPair(){
        if(pwoman->getSex()==pman->getSex()){
            cout<<"ͬ��"<<endl;
        }
        else{
            if(pwoman->getCondi()==pman->getCondi())cout<<"����"<<endl;
            else cout<<"����"<<endl;
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
    Person *pwoman;//Ҳ������һ�Զ��list
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
    Person *xiaofang = new Woman("С��",5,m);
    Person *zhangsan = new Man("����",4,m);
    Person *lisi = new Man("����",5,m);
    xiaofang->getPair(zhangsan);
    xiaofang->getPair(lisi);
    zhangsan->getPair(lisi);
    cout<<"hello"<<endl;
    return 0;
}