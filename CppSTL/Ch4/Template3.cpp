//
// Created by 조민국 on 2019-02-08.
//

#include <iostream>

using namespace std;

template<typename T>
class Queue
{
public:
    Queue()
    {
        q = new T();
        start = 0;
        end = 0;
    }

    void Push(T arg)
    {
        q[end++] = arg;
    }

    int Pop()
    {
        return q[start++];
    }

    bool Empty()
    {
        if(start == end)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    T* q;
    int start;
    int end;
};

int main()
{
    Queue<int> q;
    q.Push(10);
    q.Push(20);
    q.Push(30);

    if(!q.Empty())
    {
        cout << q.Pop() << endl;
    }
    if(!q.Empty())
    {
        cout << q.Pop() << endl;
    }
    if(!q.Empty())
    {
        cout << q.Pop() << endl;
    }

    return 0;
}