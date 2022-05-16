#include<iostream>
#include <cstring>
#include<list>
using namespace std;
class IFile
{
public:
    virtual void display() = 0;//显示目录名字
    virtual int add(IFile *ifile) = 0;
    virtual int remove(IFile *ifile) = 0;
    virtual list<IFile*> *getchild() = 0;
};
class File:public IFile
{
public:
    File(string name){
        name_m = name;
    }
    virtual void display(){
        cout<<"my name is "<<name_m<<endl;
    };
    virtual int add(IFile *ifile){
        return -1;
    }
    virtual int remove(IFile *ifile){
        return -1;
    }
    virtual list<IFile*> *getchild(){
        return NULL;
    }
private:
    string name_m;
};
//目录节点
class Dir:public IFile
{
public:
    Dir(string name){
        name_m = name;
        child_m = new list<IFile*>;
    }
    virtual void display(){
        cout<<"my name is "<<name_m<<endl;
    };
    virtual int add(IFile *ifile){
        child_m->push_back(ifile);
        return 0;
    }
    virtual int remove(IFile *ifile){
        child_m->remove(ifile);
        return 0;
    }
    virtual list<IFile*> *getchild(){
        return child_m;
    }
private:
    string name_m;
    list<IFile*> *child_m;
};

int main(){
    Dir *root = new Dir("C:");
    root->display();
    Dir *dir1 = new Dir("111dir");
    File *file1 = new File("a.txt");
    root->add(dir1);
    root->add(file1);
    list<IFile*> *child = root->getchild();
    for(list<IFile*> ::iterator it = child->begin();it!=child->end();it++){
        (*it)->display();
    }
    cout<<"hello"<<endl;
    return 0;
}