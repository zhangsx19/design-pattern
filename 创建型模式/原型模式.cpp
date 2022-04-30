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
    char *resume;//有指针涉及浅拷贝
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
    //浅拷贝(在改变新的数组（对象）的时候，会改变原数组（对象）)
    //注意c1调用的是person类的析构函数
    Person *c2 = c1->clone();
    c2->printT();
    delete c1;
    delete c2;
    cout<<"hello"<<endl;
    return 0;
}