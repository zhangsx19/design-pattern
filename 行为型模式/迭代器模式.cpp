#include<iostream>
#include <cstring>
#include<list>
using namespace std;
typedef int Object;
#define SIZE 5
class MyIterator
{
public:
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() = 0;
    virtual Object CurrentItem() = 0;
};
class Aggregate//��������
{
public:
    virtual MyIterator *CreateIter() = 0;
    virtual Object getItem(int index) = 0;
    virtual int getSize() = 0;//��ȡ��С���ж�ʲôʱ��ĩβ
};
class ConcreIterator:public MyIterator
{
public:
    ConcreIterator(Aggregate *ag){
        curr_index = 0;
        m_ag = ag;
    }
    virtual void First(){
        curr_index = 0;//���α�ص�λ��0
    };
    virtual void Next(){
        if(!this->IsDone())curr_index++;
    };
    virtual bool IsDone(){
        return curr_index==m_ag->getSize();
    };
    virtual Object CurrentItem(){
        return m_ag->getItem(curr_index);
    };
private:
    int curr_index;//��������ǰ��ָ���λ��
    Aggregate *m_ag;
};
class ConcreAggregate:public Aggregate//���弯��
{
public:
    ConcreAggregate(){
        for (int i = 0; i < SIZE; i++)
        {
            m_o[i] = i+100;
        }
    }
    virtual MyIterator *CreateIter(){
        return new ConcreIterator(this);//�õ����������������
    };
    virtual Object getItem(int index){
        return m_o[index];
    };
    virtual int getSize(){
        return SIZE;
    }
private:
    Object m_o[SIZE];//�����ʼ��
};
int main(){
    Aggregate *ag = new ConcreAggregate;
    MyIterator *it = ag->CreateIter();
    while(!it->IsDone()){
        cout<<it->CurrentItem()<<endl;
        it->Next();
    }
    cout<<"hello"<<endl;
    return 0;
}