#include<iostream>
#include <cstring>
#include<map>
using namespace std;
class Person{
public:
    Person(string name,int age){
        name_m = name;
        age_m = age;
    }
    virtual void printT() = 0;
protected:
    string name_m;
    int age_m;
};
class Teacher:public Person
{
public:
    Teacher(string name,int age,string id):Person(name,age)
    {
        id_m = id;
    }
    virtual void printT(){
        cout<<"name:"<<name_m<<"age:"<<age_m<<"id:"<<id_m<<endl;
    }
private:
    string id_m;
};

//完成老师结点的存储,map插入有四种方法，前三种若key已存在，则报错；第四种若key已存在，则修改

class FlyWeightTeacherFactory//享元工厂
{
public:
    FlyWeightTeacherFactory(){
        map1.clear();
    }
    ~FlyWeightTeacherFactory(){//记得释放内存
        while (!map1.empty())
        {
            Person *tmp = NULL;
            map<string,Person*>::iterator it = map1.begin();
            tmp = it->second;
            map1.erase(it);//把第一个结点从容器中删除
            delete tmp;
        }
        
    }
    Person *GetTeacher(string id){
        map<string,Person*>::iterator it = map1.find(id);
        Person *tmp = NULL;
        if(it == map1.end()){//没找到
            cout<<"请输入老师名字、年龄"<<endl;
            string name;
            int age;
            cin>>name>>age;
            tmp = new Teacher(name,age,id);
            map1.insert(pair<string,Person*>(id,tmp));
        }else{
            tmp = it->second;
        }
        return tmp;
    }//返回父类指针
private:
    map<string,Person*> map1;
};

int main(){
    Person *p1 = NULL;
    Person *p2 = NULL;
    FlyWeightTeacherFactory *fwtf = new FlyWeightTeacherFactory;
    p1 = fwtf->GetTeacher("001");
    p1->printT();
    p2 = fwtf->GetTeacher("001");
    p2->printT();//p2和p1结果应相等
    delete fwtf;
    cout<<"hello"<<endl;
    return 0;
}