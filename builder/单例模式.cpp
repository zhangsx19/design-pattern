#include<iostream>
#include <cstring>
using namespace std;
class Singelton//懒汉式
{
private:
    Singelton(){
        m_singer = NULL;
        m_count = 0;
        cout<<"懒汉式构造函数do"<<endl;
    }
    static Singelton *m_singer;
    static int m_count;
public:
    static Singelton *getInstance(){
        if(m_singer == NULL){//懒汉式：1.每次获取实例都要判断2.多线程会有问题(解决方法：double check)
            m_singer = new Singelton;
        }
        return m_singer;
    }
    static void printT(){
        cout<<"count:"<<m_count<<endl;
    }
};
Singelton *Singelton::m_singer = NULL;//懒汉式 并没有创建单例对象
int Singelton::m_count = 0;

void main1(){
    //懒汉式
    Singelton *p1 = Singelton::getInstance();//只有在使用时才去创建对象
    Singelton *p2 = Singelton::getInstance();
    if(p1!=p2){
        cout<<"不是同一个对象"<<endl;
    }else cout<<"是同一个对象"<<endl;
    p1->printT();
    p2->printT();
    
}
class Singelton2{//饿汉式
private:
    Singelton2(){
        m_singer = NULL;
        m_count = 0;
        cout<<"饿汉式构造函数do"<<endl;
    }
    static Singelton2 *m_singer;
    static int m_count;
public:
    static Singelton2 *getInstance(){
        if(m_singer==NULL){
            m_singer = new Singelton2;
        }
        return m_singer;
    }
    static void FreeInstance(){
        if(m_singer!=NULL){
            delete m_singer;
            m_singer = NULL;
            m_count = 0;
        }
    }
    static void printT(){
        cout<<"count:"<<m_count<<endl;
    }

};
Singelton2 *Singelton2::m_singer = new Singelton2;//饿汉式：不管你是否创建实例，均把实例new出来
int Singelton2::m_count = 0;
void main2(){
    //饿汉式
    Singelton2 *p1 = Singelton2::getInstance();
    Singelton2 *p2 = Singelton2::getInstance();
    if(p1!=p2){
        cout<<"不是同一个对象"<<endl;
    }else cout<<"是同一个对象"<<endl;
    p1->printT();
    p2->printT();
    Singelton2::FreeInstance();
    Singelton2::FreeInstance();
}
int main(){
    //main1();
    main2();
    cout<<"hello"<<endl;
    return 0;
}