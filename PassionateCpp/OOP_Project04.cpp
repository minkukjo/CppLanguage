//
// Created by 조민국 on 07/01/2019.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class user
{
public:
    user(int account_number, char* user_name, int user_balance)
    {
        this->account_number = account_number;
        this->user_name = new char[strlen(user_name)+1];
        strcpy(this->user_name,user_name);
        this->user_balance = user_balance;
    }

    ~user()
    {
        delete []user_name;
        cout << "유저 이름 삭제" << endl;
    }
    int get_account_number() const
    {
        return account_number;
    }
    void set_account_number(int account_number)
    {
        this->account_number = account_number;
    }

    char* get_user_name() const
    {
        return user_name;
    }
    void set_user_name(char* user_name)
    {
        this->user_name = user_name;
    }

    int get_user_balance() const
    {
        return user_balance;
    }
    void set_user_balance(int user_balance)
    {
        this->user_balance += user_balance;
    }

    void ShowAccInfo() const
    {
        cout<< "계좌ID: "<<account_number<<endl;
        cout<<"이 름: "<<user_name<<endl;
        cout<<"잔 액: "<<user_balance<<endl;
    }


private:

    int account_number;
    char* user_name;
    int user_balance;
};

void call_user()
{
    user a(100,"minkuk",1000);
    user b = a;
}

int main()
{
    call_user();

}