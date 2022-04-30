#include<iostream>
#include <cstring>
#include<list>
using namespace std;
class ParkElement;
class Visitor
{
public:
    virtual void visit(ParkElement *parkelement) = 0;//访问公园
};
class ParkElement
{
public:
    virtual void accept(Visitor *visitor) = 0;//公园接受访问,让访问者做操作
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
//整个公园
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
        cout<<"清洁工A 完成公园A打扫"<<endl;//parkelement->getName()
    }
};

class VisitorB:public Visitor
{
public:
    virtual void visit(ParkElement *parkelement){
        cout<<"清洁工B 完成公园B打扫"<<endl;
    }
};
//管理者
class ManagerVisitor:public Visitor
{
    virtual void visit(ParkElement *parkelement){
        cout<<"管理者 访问公园各个部分"<<endl;
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
    //整个公园接受管理者访问
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