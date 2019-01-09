//
// Created by 조민국 on 08/01/2019.
// 클래스 갖고놀기


#include <iostream>

using namespace std;

class Person
{
public:
    void Sleep() {
        cout << "sleep~" << endl;
    }
};

class Student : public Person
{
public:
    void study()
    {
        cout<<"stduying~"<<endl;
    }

};

class PartTimeStudent : public Student
{
public:
    void Work()
    {
        cout<<"Work"<<endl;
    }
};

int main()
{
    Person* ptr1 = new Student();
    ptr1->Sleep();
    Student* ptr2 = new PartTimeStudent();
    ptr2->study();
}