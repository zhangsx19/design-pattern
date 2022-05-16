#include<iostream>
#include <cstring>
using namespace std;
class Cola
{
private:
    /* data */
public:
    virtual void Sayname()=0;
};
class CocaCola:public Cola
{
private:
    /* data */
public:
    virtual void Sayname(){
        cout<<"我是Coca Cola"<<endl;
    }
};
class PesiCola:public Cola
{
private:
    /* data */
public:
    virtual void Sayname(){
        cout<<"我是Pesi Cola"<<endl;
    }
};
class Bottle
{
private:
    /* data */
public:
    virtual void Sayname()=0;
};
class CocaBottle:public Bottle
{
private:
    /* data */
public:
    virtual void Sayname(){
        cout<<"我是Coca Bottle"<<endl;
    }
};
class PesiBottle:public Bottle
{
private:
    /* data */
public:
    virtual void Sayname(){
        cout<<"我是Pesi Bottle"<<endl;
    }
};
class AbFactory//缺点:产品线写死了
{
private:
    /* data */
public:
    virtual Cola *CreateCola() = 0;
    virtual Bottle *CreateBottle() = 0;
};

class CocaFactory:public AbFactory
{
private:
    /* data */
public:
    virtual Cola *CreateCola(){
        return new CocaCola;
    };
    virtual Bottle *CreateBottle(){
        return new CocaBottle;
    };
};

class PesiFactory:public AbFactory
{
private:
    /* data */
public:
    virtual Cola *CreateCola(){
        return new PesiCola;
    };
    virtual Bottle *CreateBottle(){
        return new PesiBottle;
    };
};

int main(){
    AbFactory *f =  NULL;
    //生产百事可乐
    f = new PesiFactory;
    Cola *cola = f->CreateCola();
    Bottle *bottle = f->CreateBottle();
    cola->Sayname();
    bottle->Sayname();
    cout<<"hello"<<endl;
    return 0;
}