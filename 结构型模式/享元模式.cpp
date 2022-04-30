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

//�����ʦ���Ĵ洢,map���������ַ�����ǰ������key�Ѵ��ڣ��򱨴���������key�Ѵ��ڣ����޸�

class FlyWeightTeacherFactory//��Ԫ����
{
public:
    FlyWeightTeacherFactory(){
        map1.clear();
    }
    ~FlyWeightTeacherFactory(){//�ǵ��ͷ��ڴ�
        while (!map1.empty())
        {
            Person *tmp = NULL;
            map<string,Person*>::iterator it = map1.begin();
            tmp = it->second;
            map1.erase(it);//�ѵ�һ������������ɾ��
            delete tmp;
        }
        
    }
    Person *GetTeacher(string id){
        map<string,Person*>::iterator it = map1.find(id);
        Person *tmp = NULL;
        if(it == map1.end()){//û�ҵ�
            cout<<"��������ʦ���֡�����"<<endl;
            string name;
            int age;
            cin>>name>>age;
            tmp = new Teacher(name,age,id);
            map1.insert(pair<string,Person*>(id,tmp));
        }else{
            tmp = it->second;
        }
        return tmp;
    }//���ظ���ָ��
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
    p2->printT();//p2��p1���Ӧ���
    delete fwtf;
    cout<<"hello"<<endl;
    return 0;
}