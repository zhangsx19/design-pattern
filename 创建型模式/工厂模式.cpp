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
class AbFactory
{
private:
    /* data */
public:
    virtual Fruit *CreateFruit() = 0;
};

class BananaFactory:public AbFactory
{
private:
    /* data */
public:
    virtual Fruit *CreateFruit(){
        return new Banana;
    }
};
class AppleFactory:public AbFactory
{
private:
    /* data */
public:
    virtual Fruit *CreateFruit(){
        return new Apple;
    }
};

int main(){
    
    AbFactory *f = NULL;
    Fruit *fruit = NULL;
    //生产香蕉
    f = new BananaFactory;
    fruit = f->CreateFruit();
    fruit->getFruit();
    delete fruit;
    delete f;
    //想吃新水果->梨子
    //先增加梨子类，再增加梨子工厂类，并没有修改原来的类而是增加，符合开闭原则
    cout<<"hello"<<endl;
    return 0;
}