#include<iostream>
#include <cstring>
using namespace std;
class Fruit
{
private:
    /* data */
public:
    virtual void getFruit()=0;
};
class Banana:public Fruit
{
private:
    /* data */
public:
    virtual void getFruit(){
        cout<<"我是香蕉"<<endl;
    }
};
class Apple:public Fruit
{
private:
    /* data */
public:
    virtual void getFruit(){
        cout<<"我是苹果"<<endl;
    }
};
class Factory//关键类，如果想添加西红柿，就要修改Factory，不符合设计原则
{
private:
    /* data */
public:
    Fruit *CreateFruit(char *p){
        if(!strcmp("banana",p)) return new Banana;
        else if(!strcmp("apple",p)) return new Apple;
        else {
            cout<<"输入错误"<<endl;
            return NULL;
        }
    }
};


int main(){
    Factory *f = new Factory;
    Fruit *fruit = f->CreateFruit("banana");
    fruit->getFruit();
    delete fruit;
    delete f;
    cout<<"hello"<<endl;
    return 0;
}