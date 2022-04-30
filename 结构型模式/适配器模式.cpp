#include<iostream>
#include <cstring>
using namespace std;
class Current18v//希望用的接口 
{
private:
    /* data */
public:
    virtual void useCurrent18v() = 0;
};
class Current220v//已有的接口 
{
private:
    /* data */
public:
    virtual void useCurrent220v(){
        cout<<"我是220v"<<endl;
    }
};
class Adapter:public Current18v//接口18v,内部220v接口
{
private:
    Current220v *current_m;
public:
    Adapter(Current220v *current){
        current_m = current;
    }
    virtual void useCurrent18v(){
        cout<<"适配器 适配220v"<<endl;
        current_m->useCurrent220v();
    };
};




int main(){
    Current220v *current = new Current220v();
    Adapter *adapter = new Adapter(current);
    adapter->useCurrent18v();
    cout<<"hello"<<endl;
    return 0;
}