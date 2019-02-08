//
// Created by 조민국 on 2019-02-08.
//

#include <iostream>

using namespace std;

class String
{
public:
    String(const char* arg)
    {
        str = new char[strlen(arg)+1];
    }

    String()
    {
        delete[] str;
    }

    const String& operator=(const String& arg)
    {
        delete[] str;
        str = new char[strlen(arg.str)+1];
        strcpy(str,arg.str);

        return *this;
    }


private:
    char* str;
};

int main()
{
    const char* sz = "Hello!";
    String s("Hi~!");
    s = sz;
    return 0;
}