#include<iostream>
#include <cstring>
using namespace std;
//����¼
class MememTo
{
public:
    MememTo(string name,int age){
        m_name = name;
        m_age = age;
    }
    string getName(){
        return m_name;
    }
    int getAge(){
        return m_age;
    }
    void setName(string name){
        m_name = name;
    }
    void setAge(int age){
        m_age = age;
    }
private:
    string m_name;
    int m_age;
};

class Person
{
public:
    Person(string name,int age){
        m_name = name;
        m_age = age;
    }
    string getName(){
        return m_name;
    }
    int getAge(){
        return m_age;
    }
    void setName(string name){
        m_name = name;
    }
    void setAge(int age){
        m_age = age;
    }
    MememTo *createMememTo(){//�浵
        return new MememTo(m_name,m_age);
    }
    void setMememTo(MememTo *mememto){//����
        m_name = mememto->getName();
        m_age = mememto->getAge();
    }
    void printT(){
        cout<<"name:"<<m_name<<"age:"<<m_age<<endl;
    }
private:
    string m_name;
    int m_age;
};
void main1(){
    Person *p = new Person("zhangsan",25);
    p->printT();
    MememTo *m = NULL;
    //�浵
    m = p->createMememTo();
    p->setName("lisi");
    p->printT();
    //����
    p->setMememTo(m);
    p->printT();
    delete m;
    delete p;
}
class Manager//������
{
public:
    Manager(MememTo *m){
        this->m = m;
    }
    MememTo *getMememTo(){
        return m;
    }
    void setMememTo(MememTo *m){
        this->m = m;
    }
private:
    MememTo *m;//����list
};
void main2(){
    Person *p = new Person("zhangsan",25);
    p->printT();
    MememTo *m = NULL;
    Manager *manager = NULL;
    //�浵
    manager = new Manager(p->createMememTo());
    p->setName("lisi");
    p->printT();
    //����
    p->setMememTo(manager->getMememTo());
    p->printT();
    delete m;
    delete p;
}
int main(){
    //main1();
    main2();
    cout<<"hello"<<endl;
    return 0;
}