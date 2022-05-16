#include<iostream>
#include <cstring>
#include<list>
using namespace std;
class Doctor{
public:
    void treat_eye(){
        cout<<"�����ۿƲ�"<<endl;
    }
    void treat_nose(){
        cout<<"���ƱǿƲ�"<<endl;
    }
};
void main1(){
    //ҽ��ֱ�ӿ���
    Doctor *doctor = new Doctor;
    doctor->treat_eye();
    delete doctor;
}
class Command
{
public:
    virtual void treat() = 0;
};
class CommandTreatEye:public Command
{
public:
    CommandTreatEye(Doctor *doctor){
        m_doctor = doctor;
    }
    void treat(){
        m_doctor->treat_eye();
    }
private:
    Doctor *m_doctor;
};
class CommandTreatNose:public Command
{
public:
    CommandTreatNose(Doctor *doctor){
        m_doctor = doctor;
    }
    void treat(){
        m_doctor->treat_nose();
    }
private:
    Doctor *m_doctor;
};
void main2(){
    //ͨ��һ������
    Doctor *doctor = new Doctor;
    CommandTreatEye *commandtreateye = new CommandTreatEye(doctor);
    commandtreateye->treat();
    delete commandtreateye;
    delete doctor;    
}
class Nurse
{
public:
    Nurse(Command *command){
        this->command = command;
    }
    void setCommand(Command *command){
        this->command = command;
    }
    void SubmitCase(){//�ύ���� �´�����
        command->treat();
    }
private:
    Command *command;
};
void main3(){
    //��ʿ�ύ������ҽ������
    Doctor *doctor = new Doctor;
    Command *command = new CommandTreatEye(doctor);
    Nurse *nurse = new Nurse(command);
    nurse->SubmitCase();
    delete nurse;
    delete command;
    delete doctor;    
}
class HeadNurse//��ʿ��
{
public:
    HeadNurse(){
        m_list.clear();
    }
    void setCommand(Command *command){
        m_list.push_back(command);
    }
    void SubmitCase(){//�����ύ���� �´�����
        for (list<Command *>::iterator it = m_list.begin(); it != m_list.end(); it++)
        {
            (*it)->treat();
        }
    }
private:
    list<Command *>m_list;
};
void main4(){
    //��ʿ�������ύ������ҽ������
    Doctor *doctor = new Doctor;
    Command *command1 = new CommandTreatEye(doctor);
    Command *command2 = new CommandTreatNose(doctor);
    Command *command3 = new CommandTreatNose(doctor);
    HeadNurse *headnurse = new HeadNurse();
    headnurse->setCommand(command1);
    headnurse->setCommand(command2);
    headnurse->setCommand(command3);
    headnurse->SubmitCase();
    delete headnurse;
    delete command3;
    delete command2;
    delete command1;
    delete doctor;    
}
int main(){
    //main1();
    //main2();
    //main3();
    main4();
    cout<<"hello"<<endl;
    return 0;
}