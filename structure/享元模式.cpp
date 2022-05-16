#include<iostream>
#include <cstring>
#include<map>
using namespace std;
class Music{
public:
    Music(string author,int popular){
        author_m = author;
        popular_m = popular;
    }
    virtual void printT() = 0;
protected:
    string author_m;
    int popular_m;
};
class FreeMusic:public Music
{
public:
    FreeMusic(string author,int popular,string name):Music(author,popular)
    {
        name_m = name;
    }
    virtual void printT(){
        cout<<"author:"<<author_m<<"popular:"<<popular_m<<"name:"<<name_m<<endl;
    }
private:
    string name_m;
};

class VipMusic:public Music
{
public:
    VipMusic(string author,int popular,string name):Music(author,popular)
    {
        name_m = name;
    }
    virtual void printT(){
        cout<<"author:"<<author_m<<"popular:"<<popular_m<<"name:"<<name_m<<endl;
    }
private:
    string name_m;
};
//�����ʦ���Ĵ洢,map���������ַ�����ǰ������key�Ѵ��ڣ��򱨴���������key�Ѵ��ڣ����޸�

class FlyWeightMusicFactory//��Ԫ����
{
public:
    FlyWeightMusicFactory(){
        FreeMusicMap.clear();
    }
    ~FlyWeightMusicFactory(){//�ǵ��ͷ��ڴ�
        while (!FreeMusicMap.empty())
        {
            Music *tmp = NULL;
            map<string,Music*>::iterator it = FreeMusicMap.begin();
            tmp = it->second;
            FreeMusicMap.erase(it);//�ѵ�һ������������ɾ��
            delete tmp;
        }
        
    }
    Music *GetMusic(string name,bool &isvip){//isvip��ʾ�����Ƿ���vip����
        map<string,Music*>::iterator itFree = FreeMusicMap.find(name);
        Music *tmp = NULL;
        if(itFree == FreeMusicMap.end()){//��ѿ�û�ҵ�
            map<string,Music*>::iterator itVip = VipMusicMap.find(name);
            if(itVip == VipMusicMap.end()){//vip��Ҳû�ҵ�
                cout<<"���������ֵ����ߡ����ж�"<<endl;
                string author;
                int popular;
                cin>>author>>popular;
                tmp = AddMusic(name,author,popular,isvip);
            }
            else{//vip���ҵ���
                tmp = itVip->second;
                isvip = true;
            }
        }else{//��ѿ��ҵ���
            tmp = itFree->second;
            isvip = false;
        }
        return tmp;
    }//���ظ���ָ��

    Music *AddMusic(string name,string author,int popular,bool &isvip){//����vip���֣�������
        Music *tmp = NULL;
        if(popular<5){//�������
            tmp = new FreeMusic(author,popular,name);
            FreeMusicMap.insert(pair<string,Music*>(name,tmp));
            isvip = false;
        }
        else{
            tmp = new VipMusic(author,popular,name);
            VipMusicMap.insert(pair<string,Music*>(name,tmp));
            isvip = true;
        }
        return tmp;
    }
private:
    map<string,Music*> FreeMusicMap;
    map<string,Music*> VipMusicMap;
};

class Person
{
public:
    virtual Music *GetMusic(string name,FlyWeightMusicFactory *m_fwtf) = 0;
};
class FreePerson:public Person
{
public:
    virtual Music *GetMusic(string name,FlyWeightMusicFactory *m_fwtf){
        bool isvip;
        Music *tmp = m_fwtf->GetMusic(name,isvip);
        if(isvip){
            cout<<"�㲻��vip�û���������"<<endl;
            return NULL;
        }else{
            return tmp;
        }
    }
};
class VipPerson:public Person
{
public:
    virtual Music *GetMusic(string name,FlyWeightMusicFactory *m_fwtf){
        bool isvip;
        return m_fwtf->GetMusic(name,isvip);
    }
};

int main(){
    Music *m1 = NULL;
    Music *m2 = NULL;
    Person *p1 = new FreePerson;
    Person *p2 = new VipPerson;
    FlyWeightMusicFactory *fwtf = new FlyWeightMusicFactory;
    //vip���� m2��m1��������
    m1 = p1->GetMusic("qingchun",fwtf);
    m2 = p2->GetMusic("qingchun",fwtf);
    if(m1==m2){
        cout<<"m2��m1������"<<endl;
    }else{
        cout<<"m2��m1��������"<<endl;
    }
    //�������
    m1 = p1->GetMusic("yangfan",fwtf);
    m2 = p2->GetMusic("yangfan",fwtf);
    if(m1==m2){
        cout<<"m2��m1������"<<endl;
    }else{
        cout<<"m2��m1��������"<<endl;
    }
    delete fwtf;
    delete p2;
    delete p1;
    delete m2;
    delete m1;
    cout<<"hello"<<endl;
    return 0;
}