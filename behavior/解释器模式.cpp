#include<iostream>
#include <cstring>
#include<list>
using namespace std;
class Context
{
public:
    Context(int num){
        m_num = num;
    }
    void setNum(int num){
        m_num = num;
    }
    void setRes(int res){
        m_res = res;
    }
    int getNum(){
        return m_num;
    }
    int getRes(){
        return m_res;
    }
private:
    int m_num;//ÊäÈë
    int m_res;//Êä³ö
};
class Expression
{
public:
    virtual void interpreter(Context *context) = 0;
protected:
  
};
class AddExpreesion:public Expression
{
public:
    
    virtual void interpreter(Context *context){
        int num = context->getNum();
        num++;
        context->setNum(num);
        context->setRes(num);
    };
};

class SubExpreesion:public Expression
{
public:
    
    virtual void interpreter(Context *context){
        int num = context->getNum();
        num--;
        context->setNum(num);
        context->setRes(num);
    };
};
int main(){
    
    Context *context = new Context(10);
    Expression *e1 = new AddExpreesion;
    e1->interpreter(context);
    cout<<context->getRes()<<endl;
    Expression *e2 = new SubExpreesion;
    e2->interpreter(context);
    cout<<context->getRes()<<endl;
    delete e2;
    delete e1;
    delete context;
    cout<<"hello"<<endl;
    return 0;
}