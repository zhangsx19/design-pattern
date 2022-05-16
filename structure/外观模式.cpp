#include<iostream>
#include <cstring>
#include<list>
using namespace std;
class SubSystemA
{
public:
    void dothing(){
        cout<<"SubSystemA run"<<endl;
    }
};
class SubSystemB
{
public:
    void dothing(){
        cout<<"SubSystemB run"<<endl;
    }
};
class SubSystemC
{
public:
    void dothing(){
        cout<<"SubSystemC run"<<endl;
    }
};
class Facade
{
public:
    Facade(){
        sysA = new SubSystemA;
        sysB = new SubSystemB;
        sysC = new SubSystemC;
    }
    ~Facade(){
        delete sysA;
        delete sysB;
        delete sysC;
    }
    void dothing(){
        sysA->dothing();
        sysB->dothing();
        sysC->dothing();
    }
private:
    SubSystemA *sysA = new SubSystemA;
    SubSystemB *sysB = new SubSystemB;
    SubSystemC *sysC = new SubSystemC;
};
void main1(){
    //�ͻ�ԭ�����÷�
    SubSystemA *sysA = new SubSystemA;
    SubSystemB *sysB = new SubSystemB;
    SubSystemC *sysC = new SubSystemC;
    sysA->dothing();
    sysB->dothing();
    sysC->dothing();
    delete sysA;
    delete sysB;
    delete sysC;
    //��ϵͳ�����仯����Ҫ�޸�,�ҷ���
    
}
void main2(){
    //���ģʽ
    Facade *f = new Facade;
    f->dothing();
    delete f;
}
int main(){
    //main1();
    main2();
    cout<<"hello"<<endl;
    return 0;
}