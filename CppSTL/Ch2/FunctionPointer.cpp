//
// Created by 조민국 on 2019-02-08.
//

// 멤버 함수 호출

#include <iostream>

using namespace std;

void Print()
{
    cout << "정적 함수 Print()" << endl;
}

class Point
{
public:
    void Print()
    {
        cout <<"멤버 함수 Print()" << endl;
    }
};

int main()
{
    Point pt;
    Point *p = &pt;

    Print();
    pt.Print();
    p->Print();
    return 0;
}