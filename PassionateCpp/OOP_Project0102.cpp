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
    user(int account_number, string user_name, int user_balance)
    {
        this->account_number = account_number;
        this->user_name = user_name;
        this->user_balance = user_balance;
    }
    int get_account_number()
    {
        return account_number;
    }
    void set_account_number(int account_number)
    {
        this->account_number = account_number;
    }

    string get_user_name()
    {
        return user_name;
    }
    void set_user_name(string user_name)
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
    string user_name;
    int user_balance;
};

int main()
{
    vector<user> userlist;
    int menu_num;
    int in_accnum;
    string in_usrname;
    int in_balance;

    while(true)
    {
        cout << "-----Menu------\n";
        cout << "1. 계좌개설\n";
        cout << "2. 입금\n";
        cout << "3. 출금\n";
        cout << "4. 계좌정보 전체 출력\n";
        cout << "5. 프로그램 종료\n";
        cout << "선택:";
        cin >> menu_num;

        switch(menu_num)
        {
            case 1:
                cout <<"[계좌개설]\n";
                cout <<"계좌ID:";
                cin >> in_accnum;
                cout <<"이름:";
                cin >> in_usrname;
                cout <<"입금액:";
                cin >> in_balance;
                userlist.push_back(user(in_accnum,in_usrname,in_balance));
                break;
            case 2:
                cout<<"[입금]\n";
                cout<<"계좌ID:";
                cin >> in_accnum;
                cout <<"입금액:";
                cin >> in_balance;

                for(vector<user>::iterator iter=userlist.begin(); iter!= userlist.end(); ++iter)
                {
                    if(iter->get_account_number() == in_accnum)
                    {
                        iter->set_user_balance(in_balance);
                        break;
                    }

                    if(iter+1 == userlist.end())
                    {
                        cout<<"해당 계좌는 존재하지 않습니다."<<endl;
                    }

                }
                break;
            case 3:
                cout<<"[출금]\n";
                cout<<"계좌ID:";
                cin >> in_accnum;
                cout <<"출금액:";
                cin >> in_balance;

                for(vector<user>::iterator iter=userlist.begin(); iter!= userlist.end(); ++iter)
                {
                    if(iter->get_account_number() == in_accnum)
                    {
                        iter->set_user_balance(-in_balance);
                        break;
                    }

                    if(iter+1 == userlist.end())
                    {
                        cout<<"해당 계좌는 존재하지 않습니다."<<endl;
                    }

                }
                break;
            case 4:
                for(vector<user>::iterator iter=userlist.begin(); iter!= userlist.end(); ++iter)
                {
                    cout << "계좌ID :" << iter->get_account_number()<<"\n";
                    cout << "이름 :"<< iter->get_user_name()<< "\n";
                    cout << "잔액 :" << iter->get_user_balance() << endl;
                }
                break;
            case 5:
                return 0;
        }

    }
}