#include<iostream>
#include <cstring>
using namespace std;
class Subject//���,Э����
{
private:
    /* data */
public:
    virtual void sellbook() = 0;
};
class RealSubject:public Subject//ʵ�����
{
private:
public:
    virtual void sellbook(){
        cout<<"����"<<endl;
    }
};
class dangdangProxy:public Subject
{
private:
    Subject *subject;//���б��������ʵ��
public:
    virtual void sellbook(){
        subject = new RealSubject;
        discount();
        subject->sellbook();
    }//�����������ͬ�ӿ�
    void discount(){
        cout<<"˫ʮһ����"<<endl;
    }
};

int main(){
    Subject *dangdang = new dangdangProxy;
    dangdang->sellbook();
    delete dangdang;
    cout<<"hello"<<endl;
    return 0;
}