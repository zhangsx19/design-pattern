#include<iostream>
#include <cstring>
using namespace std;
class Subject//书店,协议类
{
private:
    /* data */
public:
    virtual void sellbook() = 0;
};
class RealSubject:public Subject//实体书店
{
private:
public:
    virtual void sellbook(){
        cout<<"卖书"<<endl;
    }
};
class dangdangProxy:public Subject
{
private:
    Subject *subject;//含有被代理类的实例
public:
    virtual void sellbook(){
        subject = new RealSubject;
        discount();
        subject->sellbook();
    }//与抽象类有相同接口
    void discount(){
        cout<<"双十一打折"<<endl;
    }
};

int main(){
    Subject *dangdang = new dangdangProxy;
    dangdang->sellbook();
    delete dangdang;
    cout<<"hello"<<endl;
    return 0;
}