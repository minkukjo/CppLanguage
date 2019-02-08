//
// Created by 조민국 on 2019-02-08.
//

#include <iostream>

using namespace std;

class MyType{};

template<typename T>
void Copy(T a[], T b[], int c)
{
    for(int i=0;i <c; i++)
    {
        a[i] = b[i];
    }
}

int main()
{
    int arr1[5] = {10,20,30,40,50};
    int arr2[5];

    Copy(arr2,arr1,5);
    MyType myArr1[4];
    MyType myArr2[4];
    Copy(myArr2,myArr1,4);
    return 0;
}