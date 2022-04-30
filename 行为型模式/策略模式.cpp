#include<iostream>
#include <cstring>
using namespace std;
class Strategy{
public:
    virtual void crypt() = 0;
};
//对称加密
class AES:public Strategy
{
public:
    virtual void crypt(){
        cout<<"AES"<<endl;
    };
};
//非对称加密
class DES:public Strategy
{
public:
    virtual void crypt(){
        cout<<"DES"<<endl;
    };
};
class Context
{
public:
    void setStrategy(Strategy *strategy){
        this->strategy = strategy;
    }
    void myoperation(){
        strategy->crypt();
    }
private:
    Strategy *strategy;
};
int main(){
    Strategy *strategy = new DES;
    Context *context = new Context;
    context->setStrategy(strategy);
    context->myoperation();
    cout<<"hello"<<endl;
    return 0;
}