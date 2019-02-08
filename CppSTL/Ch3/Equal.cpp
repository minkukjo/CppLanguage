//
// Created by 조민국 on 2019-02-08.
//

#include <iostream>

using namespace std;

class Equal
{
public:
    bool operator()(int a, int b)
    {
        return a == b ? true : false;
    }
};
int main()
{
    Equal cmp;
    if(cmp(10,20))
    {
        cout << "같다!" << endl;
    }
    else
    {
        cout << "다르다!" << endl;
    }

    if(cmp(20,20))
    {
        cout << "같다!" << endl;
    }
    else
    {
        cout << "다르다!" << endl;
    }
    return 0;
}