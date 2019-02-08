//
// Created by 조민국 on 2019-02-08.
//

#include <iostream>

using namespace std;

template<typename T>
class Stack
{
public:
    Stack()
    {
        st = new T();
        size = 0;
    }

    void Push(T arg)
    {
        st[size++] = arg;
    }

    int Pop()
    {
        return st[--size];
    }

    bool Empty()
    {
        if(size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
private:
    T* st;
    int size;
};

int main()
{
    Stack<int> st;

    st.Push(10);
    st.Push(20);
    st.Push(30);

    if(!st.Empty())
    {
        cout << st.Pop() << endl;
    }
    if(!st.Empty())
    {
        cout << st.Pop() << endl;
    }
    if(!st.Empty())
    {
        cout << st.Pop() << endl;
    }

    return 0;
}