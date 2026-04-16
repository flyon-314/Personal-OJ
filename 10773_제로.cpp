#include <iosfwd>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int stack[100005];
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
        int command;
        cin >> command;

        if (command == 0)
        {
            pop();
        }
        else
        {
            push(command);
        }
    }
    int sol = 0;
    for (int i = 0; !empty() ; i++)
    {
        sol += pop();
    }
    cout << sol << "\n";
}
