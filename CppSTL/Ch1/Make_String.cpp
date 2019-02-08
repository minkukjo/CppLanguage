//
// Created by 조민국 on 2019-02-08.
//

#include <iostream>

using namespace std;

class String
{
public:
    String(char* arg)
    {
        cout << arg << endl;
        str = arg;
    }

    operator char*()
    {
        return str;
    }

private:
    char* str;
};

int main()
{
    String s("Hello!");
    const char* sz = s;

    cout << sz << endl;

    return 0;
}