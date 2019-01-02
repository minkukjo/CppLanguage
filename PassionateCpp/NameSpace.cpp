//
// Created by 조민국 on 02/01/2019.
//

#include <iostream>

namespace BestComImpl
{
    void SimpleFunc(void);
}
namespace BestComImpl
{
    void PrettyFunc(void);
}
namespace ProgComImpl
{
    void SimpleFunc(void);
}

void BestComImpl::SimpleFunc(void)
{
    std::cout<<"BestCom이 정의한 함수입니다."<<std::endl;
    PrettyFunc();
    ProgComImpl::SimpleFunc();
}

void BestComImpl::PrettyFunc()
{
    std::cout<<"카와이~!"<<std::endl;
}
void ProgComImpl::SimpleFunc() {
    std::cout<<"ProgCom이 정이한 함수"<<std::endl;
}

int main()
{
    BestComImpl::SimpleFunc();
    return 0;
}