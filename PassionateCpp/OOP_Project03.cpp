//
// Created by 조민국 on 04/01/2019.
//

//
// Created by 조민국 on 02/01/2019.
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
    int get_account_number()
    {
        return account_number;
    }
    void set_account_number(int account_number)
    {
        this->account_number = account_number;
    }

    char* get_user_name()
    {
        return user_name;
    }
    void set_user_name(char* user_name)
    {
        this->user_name = user_name;
    }

    int get_user_balance()
    {
        return user_balance;
    }
    void set_user_balance(int user_balance)
    {
        this->user_balance += user_balance;
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