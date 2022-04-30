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
    //�����㽶
    f = new BananaFactory;
    fruit = f->CreateFruit();
    fruit->getFruit();
    delete fruit;
    delete f;
    //�����ˮ��->����
    //�����������࣬���������ӹ����࣬��û���޸�ԭ������������ӣ����Ͽ���ԭ��
    cout<<"hello"<<endl;
    return 0;
}