#include <iosfwd>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int stack[10000];
int top = 0;
void push(int item)
{
    stack[top++] = item;
}
int pop()
{
    if (top == 0) return -1;
    else return stack[--top];
}
int size()
{
    return top;
}
int empty()
{
    return top == 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (str == "push")
        {
            int num;
            cin >> num;
            push(num);
        }
        else if (str == "pop")
        {
            cout << pop() << "\n";
        }
        else if (str == "size")
        {
            cout << size() << "\n";
        }
        else if (str == "empty")
        {
            cout << empty() << "\n";
        }
        else
        {
            if (top == 0) cout << -1 << "\n";
            else cout << stack[top - 1] << "\n"; 
        }
    }
    
}