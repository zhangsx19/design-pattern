#include<iostream>
#include <cstring>
using namespace std;
class Singelton//����ʽ
{
private:
    Singelton(){
        m_singer = NULL;
        m_count = 0;
        cout<<"����ʽ���캯��do"<<endl;
    }
    static Singelton *m_singer;
    static int m_count;
public:
    static Singelton *getInstance(){
        if(m_singer == NULL){//����ʽ��1.ÿ�λ�ȡʵ����Ҫ�ж�2.���̻߳�������(���������double check)
            m_singer = new Singelton;
        }
        return m_singer;
    }
    static void printT(){
        cout<<"count:"<<m_count<<endl;
    }
};
Singelton *Singelton::m_singer = NULL;//����ʽ ��û�д�����������
int Singelton::m_count = 0;

void main1(){
    //����ʽ
    Singelton *p1 = Singelton::getInstance();//ֻ����ʹ��ʱ��ȥ��������
    Singelton *p2 = Singelton::getInstance();
    if(p1!=p2){
        cout<<"����ͬһ������"<<endl;
    }else cout<<"��ͬһ������"<<endl;
    p1->printT();
    p2->printT();
    
}
class Singelton2{//����ʽ
private:
    Singelton2(){
        m_singer = NULL;
        m_count = 0;
        cout<<"����ʽ���캯��do"<<endl;
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
Singelton2 *Singelton2::m_singer = new Singelton2;//����ʽ���������Ƿ񴴽�ʵ��������ʵ��new����
int Singelton2::m_count = 0;
void main2(){
    //����ʽ
    Singelton2 *p1 = Singelton2::getInstance();
    Singelton2 *p2 = Singelton2::getInstance();
    if(p1!=p2){
        cout<<"����ͬһ������"<<endl;
    }else cout<<"��ͬһ������"<<endl;
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