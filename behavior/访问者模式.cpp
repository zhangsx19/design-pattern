#include<iostream>
#include <cstring>
#include<list>
using namespace std;
class ParkElement;
class Visitor
{
public:
    virtual void visit(ParkElement *parkelement) = 0;//���ʹ�԰
    virtual string gettype() = 0;
};
class ParkElement
{
public:
    virtual void accept(Visitor *visitor) = 0;//��԰���ܷ���,�÷�����������
};
class ParkA:public ParkElement
{
public:
    ParkA(){
        m_type = "��԰A����";
    }
    virtual void accept(Visitor *v){
        if(v->gettype()=="A��๤"||v->gettype()=="������"){
            v->visit(this);
            cout<<m_type<<endl;
        }else{
            cout<<"��Ȩ����"<<endl;
        }
    }
    string gettype(){
        return m_type;
    }
private:
    string m_type;
};

class ParkB:public ParkElement
{
public:
    ParkB(){
        m_type = "��԰B����";
    }
    virtual void accept(Visitor *v){
        if(v->gettype()=="B��๤"||v->gettype()=="������"){
            v->visit(this);
            cout<<m_type<<endl;
        }else{
            cout<<"��Ȩ����"<<endl;
        }
    }
    string gettype(){
        return m_type;
    }
private:
    string m_type;
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
    VisitorA(){
        m_type = "A��๤";
    }
    virtual void visit(ParkElement *parkelement){
        cout<<"��๤A ��ɨ��";//parkelement->getName()
    }
    virtual string gettype(){
        return m_type;
    }
private:
    string m_type;
};

class VisitorB:public Visitor
{
public:
    VisitorB(){
        m_type = "B��๤";
    }
    virtual void visit(ParkElement *parkelement){
        cout<<"��๤B ��ɨ��";
    }
    virtual string gettype(){
        return m_type;
    }
private:
    string m_type;
};
//������
class ManagerVisitor:public Visitor
{
public:    
    ManagerVisitor(){
        m_type = "������";
    }
    virtual void visit(ParkElement *parkelement){
        cout<<"������ ������";
    }
    virtual string gettype(){
        return m_type;
    }
private:
    string m_type;
};
void main1(){
    Visitor *vA = new VisitorA;
    Visitor *vB = new VisitorB;
    ParkElement *pA = new ParkA;
    ParkElement *pB = new ParkB;
    typeid(pA);
    pA->accept(vA);
    pA->accept(vB);
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
    main1();
    //main2();
    cout<<"hello"<<endl;
    return 0;
}