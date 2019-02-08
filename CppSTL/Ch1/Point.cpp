//
// Created by 조민국 on 2019-02-08.
//

#include <iostream>

using namespace std;

class Point
{
public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y){}
    void Print() const
    {
        cout << x << ',' << y << endl;
    }
private:
    int x;
    int y;
};

class PointPtr
{
public:
    PointPtr(Point *p) : ptr(p) { }
    ~PointPtr()
    {
        delete ptr;
    }
    // ->를 오버로딩하여 사용했음. 이렇게 안하면 Point 클래스의 print함수를 사용할 수 없음.
    Point* operator->()
    {
        return ptr;
    }
private:
    Point* ptr;
};

int main()
{
    PointPtr p1 = new Point(2,3);
    PointPtr p2 = new Point(3,5);

    p1->Print(); // p1.operator->()->Print() 호출
    p2->Print(); // p2.operator->()->Print() 호출

    return 0;
}