#include<iostream>
#include <cstring>
#include<list>
using namespace std;
//完成一个任务需要把任务传递下去
class CarHandle
{
public:
    virtual void HandleCar() = 0;
    CarHandle *setNextHandle(CarHandle *Handle){
        m_handle = Handle;
        return m_handle;
    }
protected:
    CarHandle *m_handle;//下一个处理单元
};

class HeadCarHandle:public CarHandle
{
public:
    virtual void HandleCar(){
        cout<<"造车头"<<endl;
        //造完车头，执行下一个任务
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
        cout<<"造车身"<<endl;
        //造完车身，执行下一个任务
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
        cout<<"造车尾"<<endl;
        //造完车尾，执行下一个任务
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
    //业务逻辑(没写死)
    headhandle->setNextHandle(bodyhandle);
    bodyhandle->setNextHandle(tailhandle);
    tailhandle->setNextHandle(NULL);//结束任务
    headhandle->HandleCar();
    cout<<"hello"<<endl;
    return 0;
}