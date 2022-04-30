#include<iostream>
#include <cstring>
#include<list>
using namespace std;
class ParkElement;
class Visitor
{
public:
    virtual void visit(ParkElement *parkelement) = 0;//���ʹ�԰
};
class ParkElement
{
public:
    virtual void accept(Visitor *visitor) = 0;//��԰���ܷ���,�÷�����������
};
class ParkA:public ParkElement
{
public:
    virtual void accept(Visitor *v){
        v->visit(this);
    }
};

class ParkB:public ParkElement
{
public:
    virtual void accept(Visitor *v){
        v->visit(this);
    }
};
//������԰
class Park:public ParkElement
{
public:
    Park(){
        m_list.clear();
    }
    void setParkElement(ParkElement *parkelement){
        m_list.push_back(parkelement);
    }
    virtual void accept(Visitor *v){
        for (list<ParkElement*>::iterator it = m_list.begin(); it != m_list.end(); it++)
        {
            (*it)->accept(v);
        }
        
    }
private:
    list<ParkElement*> m_list;
};
class VisitorA:public Visitor
{
public:
    virtual void visit(ParkElement *parkelement){
        cout<<"��๤A ��ɹ�԰A��ɨ"<<endl;//parkelement->getName()
    }
};

class VisitorB:public Visitor
{
public:
    virtual void visit(ParkElement *parkelement){
        cout<<"��๤B ��ɹ�԰B��ɨ"<<endl;
    }
};
//������
class ManagerVisitor:public Visitor
{
    virtual void visit(ParkElement *parkelement){
        cout<<"������ ���ʹ�԰��������"<<endl;
    }
};
void main1(){
    Visitor *vA = new VisitorA;
    Visitor *vB = new VisitorB;
    ParkElement *pA = new ParkA;
    ParkElement *pB = new ParkB;
    pA->accept(vA);
    pB->accept(vB);
    delete pB;
    delete pA;
    delete vB;
    delete vA;
}
void main2(){
    Visitor *mV = new ManagerVisitor;
    Park *p = new Park;
    ParkElement *pA = new ParkA;
    ParkElement *pB = new ParkB;
    p->setParkElement(pA);
    p->setParkElement(pB);
    //������԰���ܹ����߷���
    p->accept(mV);
    delete pA;
    delete pB;
    delete p;
    delete mV;
}
int main(){
    //main1();
    main2();
    //main3();
    cout<<"hello"<<endl;
    return 0;
}