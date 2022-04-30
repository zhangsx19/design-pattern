#include<iostream>
#include <cstring>
#include<list>
using namespace std;
//���һ��������Ҫ�����񴫵���ȥ
class CarHandle
{
public:
    virtual void HandleCar() = 0;
    CarHandle *setNextHandle(CarHandle *Handle){
        m_handle = Handle;
        return m_handle;
    }
protected:
    CarHandle *m_handle;//��һ������Ԫ
};

class HeadCarHandle:public CarHandle
{
public:
    virtual void HandleCar(){
        cout<<"�쳵ͷ"<<endl;
        //���공ͷ��ִ����һ������
        if (m_handle!=NULL)
        {
            m_handle->HandleCar();
        }
        
    };
};

class BodyCarHandle:public CarHandle
{
public:
    virtual void HandleCar(){
        cout<<"�쳵��"<<endl;
        //���공��ִ����һ������
        if (m_handle!=NULL)
        {
            m_handle->HandleCar();
        }
    };
};

class TailCarHandle:public CarHandle
{
public:
    virtual void HandleCar(){
        cout<<"�쳵β"<<endl;
        //���공β��ִ����һ������
        if (m_handle!=NULL)
        {
            m_handle->HandleCar();
        }
    };
};
int main(){
    CarHandle *headhandle = new HeadCarHandle;
    CarHandle *bodyhandle = new BodyCarHandle;
    CarHandle *tailhandle = new TailCarHandle;
    //ҵ���߼�(ûд��)
    headhandle->setNextHandle(bodyhandle);
    bodyhandle->setNextHandle(tailhandle);
    tailhandle->setNextHandle(NULL);//��������
    headhandle->HandleCar();
    cout<<"hello"<<endl;
    return 0;
}