#include <iosfwd>
#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num = 0 ;
    stack<int> s;
    vector <char> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int inp;
        cin >> inp;

        while (num < inp)
        {
            num++;
            s.push(num);
            v.push_back('+');
        }

        if (s.top() == inp)
        {
            s.pop();
            v.push_back('-');
        }
        else
        {
            while (s.top() != inp)
            {
                s.pop();
                if (s.empty())
                {
                    cout << "NO\n";
                    return 0;
                }
                v.push_back('-');
            }    
        }
        
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] <<"\n";
    }
}
