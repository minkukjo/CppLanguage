//
// Created by 조민국 on 04/01/2019.
//

#include <iostream>
using namespace std;

class man{
public:
    man(int age)
    {
        this->age = age;
        cout << this->age << endl;
        cout << "객체가 생성되었습니다" << endl;
    }
    ~man()
    {
        cout << "객체가 주겄습니다" << endl;
    }
private:
    int age;
};

void p_1()
{
    man c1(26);
}

void p_2()
{
    man* c2 = new man(25);
    delete c2;
}

int main()
{
    p_1();
    p_2();



    return 0;
}