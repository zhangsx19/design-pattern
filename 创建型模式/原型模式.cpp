#include<iostream>
#include <cstring>
using namespace std;
class Person
{
private:
    /* data */
public:
    virtual Person *clone()=0;
    virtual void printT()=0;
};
class CProgrammer:public Person
{
private:
    string name;
    int age;
    char *resume;//��ָ���漰ǳ����
public:
    CProgrammer(){
        name="";
        age = 0;
        resume = NULL;
    }
    CProgrammer(string n,int a){
        name = n;
        age = a;
        resume = NULL;
    }
    void setResume(char *p){
        if(resume!=NULL){
            delete resume;    
        }
        resume = new char[strlen(p)+1];//\n
        strcpy(resume,p);
    }
    virtual void printT(){
        cout<<"name:"<<name<<"age:"<<age<<"resume:"<<&resume<<endl;
    }
    virtual Person *clone(){
        CProgrammer *tmp = new CProgrammer;
        tmp->age = this->age;
        tmp->name =this->name;
        tmp->resume=this->resume;
        return tmp;
    }
};

int main(){
    Person *c1 = new CProgrammer("ZHANG SAN",32);
    c1->printT();
    //ǳ����(�ڸı��µ����飨���󣩵�ʱ�򣬻�ı�ԭ���飨����)
    //ע��c1���õ���person�����������
    Person *c2 = c1->clone();
    c2->printT();
    delete c1;
    delete c2;
    cout<<"hello"<<endl;
    return 0;
}