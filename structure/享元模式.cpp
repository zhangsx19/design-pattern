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
//完成老师结点的存储,map插入有四种方法，前三种若key已存在，则报错；第四种若key已存在，则修改

class FlyWeightMusicFactory//享元工厂
{
public:
    FlyWeightMusicFactory(){
        FreeMusicMap.clear();
    }
    ~FlyWeightMusicFactory(){//记得释放内存
        while (!FreeMusicMap.empty())
        {
            Music *tmp = NULL;
            map<string,Music*>::iterator it = FreeMusicMap.begin();
            tmp = it->second;
            FreeMusicMap.erase(it);//把第一个结点从容器中删除
            delete tmp;
        }
        
    }
    Music *GetMusic(string name,bool &isvip){//isvip表示音乐是否是vip音乐
        map<string,Music*>::iterator itFree = FreeMusicMap.find(name);
        Music *tmp = NULL;
        if(itFree == FreeMusicMap.end()){//免费库没找到
            map<string,Music*>::iterator itVip = VipMusicMap.find(name);
            if(itVip == VipMusicMap.end()){//vip库也没找到
                cout<<"请输入音乐的作者、流行度"<<endl;
                string author;
                int popular;
                cin>>author>>popular;
                tmp = AddMusic(name,author,popular,isvip);
            }
            else{//vip库找到了
                tmp = itVip->second;
                isvip = true;
            }
        }else{//免费库找到了
            tmp = itFree->second;
            isvip = false;
        }
        return tmp;
    }//返回父类指针

    Music *AddMusic(string name,string author,int popular,bool &isvip){//若是vip音乐，返回真
        Music *tmp = NULL;
        if(popular<5){//免费音乐
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
            cout<<"你不是vip用户，请升级"<<endl;
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
    //vip音乐 m2和m1结果不相等
    m1 = p1->GetMusic("qingchun",fwtf);
    m2 = p2->GetMusic("qingchun",fwtf);
    if(m1==m2){
        cout<<"m2和m1结果相等"<<endl;
    }else{
        cout<<"m2和m1结果不相等"<<endl;
    }
    //免费音乐
    m1 = p1->GetMusic("yangfan",fwtf);
    m2 = p2->GetMusic("yangfan",fwtf);
    if(m1==m2){
        cout<<"m2和m1结果相等"<<endl;
    }else{
        cout<<"m2和m1结果不相等"<<endl;
    }
    delete fwtf;
    delete p2;
    delete p1;
    delete m2;
    delete m1;
    cout<<"hello"<<endl;
    return 0;
}