//
// Created by 조민국 on 02/01/2019.
//

#include <iostream>


int main()
{
    const int v = 12;
    const int *num = &v;
    const int *(&ref) = num;

    std::cout << &num << std::endl;
    std::cout << ref << std::endl;
    return 0;
}