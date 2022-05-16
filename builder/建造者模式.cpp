#include<iostream>
#include <cstring>
using namespace std;
class House
{
private:
    string wall;
    string door;
    string window;
public:
    void setWall(string s){
        wall = s;
    }
    void setDoor(string s){
        door = s;
    }
    void setWindow(string s){
        window = s;
    }
    string getWall(){
        return wall;
    }
    string getDoor(){
        return door;
    }
    string getWindow(){
        return window;
    }
};
//抽象工程队接口：负责干具体的活
class Builder
{
private:
    /* data */ 
public:
    virtual void buildWall() = 0;
    virtual void buildDoor() = 0;
    virtual void buildWindow() = 0;
    virtual House *getHouse() = 0;    
};
//公寓工程队
class FlatBuilder:public Builder
{
private:
    House *house_m;
public:
    FlatBuilder(){
        house_m = new House;
    };
    virtual void buildWall(){
        house_m->setWall("flat wall");
    };
    virtual void buildDoor(){
        house_m->setDoor("flat door");
    };
    virtual void buildWindow(){
        house_m->setWindow("flat window");
    };
    virtual House *getHouse(){
        return house_m;
    };
};
//别墅工程队
class VillaBuilder:public Builder
{
private:
    House *house_m;
public:
    VillaBuilder(){
        house_m = new House;
    };
    virtual void buildWall(){
        house_m->setWall("Villa wall");
    };
    virtual void buildDoor(){
        house_m->setDoor("Villa door");
    };
    virtual void buildWindow(){
        house_m->setWindow("Villa window");
    };
    virtual House *getHouse(){
        return house_m;
    };
};
//设计师:负责建造逻辑
class Director
{
private:
    Builder *builder_m;
public:
    Director(Builder *builder){
        builder_m=builder;
    }
    void construct(){
        builder_m->buildDoor();
        builder_m->buildWall();
        builder_m->buildWindow();
    }
};

int main(){
    House *house = NULL;
    Builder *builder = NULL;
    Director *director = NULL;
    //请工程队建造别墅
    builder = new VillaBuilder;
    //设计师指挥工程队干活
    director = new Director(builder);
    director->construct();
    //拿到房子
    house = builder->getHouse();
    //检查房子类型
    cout<<house->getDoor()<<endl;
    delete house;
    delete director;
    delete builder;
    //建造公寓
    builder = new FlatBuilder;
    director = new Director(builder);
    director->construct();
    house = builder->getHouse();
    cout<<house->getDoor()<<endl;
    delete house;
    delete director;
    delete builder;
    cout<<"hello"<<endl;
    return 0;
}