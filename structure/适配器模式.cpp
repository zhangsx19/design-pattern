#include<iostream>
#include <cstring>
using namespace std;
class Current18v//ϣ���õĽӿ� 
{
private:
    /* data */
public:
    virtual void useCurrent18v(char input) = 0;
};
class Current220v//���еĽӿ� 
{
private:
    /* data */
public:
    virtual void useCurrent220v(int input){
        cout<<"����220v"<<endl;
    }
};
class Adapter:public Current18v//�ӿ�18v,�ڲ�220v�ӿ�
{
private:
    Current220v *current_m;
public:
    Adapter(Current220v *current){
        current_m = current;
    }
    virtual void useCurrent18v(char input){
        cout<<"������ ����220v"<<endl;
        current_m->useCurrent220v((int)input);
    };
};




int main(){
    Current220v *current = new Current220v();
    Adapter *adapter = new Adapter(current);
    char input = 'a';
    adapter->useCurrent18v(input);
    cout<<"hello"<<endl;
    return 0;
}