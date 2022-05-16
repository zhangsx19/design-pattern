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
    //被观察者(通知者)
    Secretary *s1 = new Secretary;
    //观察者(被通知者)
    Employee *p1 = new Employee("小张",s1);
    Employee *p2 = new Employee("小李",s1);
    s1->addObserver(p1);
    s1->addObserver(p2);
    s1->setaction("老板来了");
    s1->setaction("老板走了");
    cout<<"hello"<<endl;
    return 0;
}