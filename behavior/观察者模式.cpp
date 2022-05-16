#include<iostream>
#include <cstring>
#include <list>
using namespace std;
class Secretary;
class Employee{
public:
    Employee(string name,Secretary *s);
    void receive(string inform);
private:
    string m_name;
    Secretary *m_s;
};

class Secretary
{
public:
    Secretary(){
        employee.clear();
    }
    void addObserver(Employee *p){
        employee.push_back(p);
    }
    void setaction(string inform){
        for (list<Employee *>::iterator it = employee.begin(); it != employee.end(); it++)
        {
            (*it)->receive(inform);
        }
    }
private:
    list<Employee *> employee;
};

Employee::Employee(string name,Secretary *s){
    m_name = name;
    m_s = s;
}

void Employee::receive(string inform){
    cout<<inform<<endl;
}

int main(){
    //���۲���(֪ͨ��)
    Secretary *s1 = new Secretary;
    //�۲���(��֪ͨ��)
    Employee *p1 = new Employee("С��",s1);
    Employee *p2 = new Employee("С��",s1);
    s1->addObserver(p1);
    s1->addObserver(p2);
    s1->setaction("�ϰ�����");
    s1->setaction("�ϰ�����");
    cout<<"hello"<<endl;
    return 0;
}