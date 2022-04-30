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
        cout<<"�����㽶"<<endl;
    }
};
class Apple:public Fruit
{
private:
    /* data */
public:
    virtual void getFruit(){
        cout<<"����ƻ��"<<endl;
    }
};
class Factory//�ؼ��࣬������������������Ҫ�޸�Factory�����������ԭ��
{
private:
    /* data */
public:
    Fruit *CreateFruit(char *p){
        if(!strcmp("banana",p)) return new Banana;
        else if(!strcmp("apple",p)) return new Apple;
        else {
            cout<<"�������"<<endl;
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