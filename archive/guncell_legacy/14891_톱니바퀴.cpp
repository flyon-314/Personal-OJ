#include <algorithm>
#include <iosfwd>
#include <iostream>
#include <list>
#include <queue>
#include <stdio.h>
#include <vector>
#include<cmath>

using namespace std;

vector<vector<bool>> wheel;
bool visited[4];
void roll(int num, int t )
{
    if (t == 1)
    {
        vector <bool> v;
        v.push_back(wheel[num][7]);
        for (int i = 0 ;i <7 ; i++) v.push_back(wheel[num][i]);
        for (int i = 0 ; i < 8 ; i++) wheel[num][i] = v[i];
    }
    else
    {
        vector <bool> v;
        for (int i = 1 ;i <8 ; i++) v.push_back(wheel[num][i]);
        v.push_back(wheel[num][0]);
        for (int i = 0 ; i < 8 ; i++) wheel[num][i] = v[i];
    }
}
void roll_wheel(int num, int t)
{
    if (visited[num] ) return;
    visited[num] = true;
    if (num - 1 >= 0 && wheel[num][6] != wheel[num - 1][2]) roll_wheel(num - 1, t * (- 1));
    if (num + 1 < 4 && wheel[num][2] != wheel[num + 1][6]) roll_wheel(num + 1, t * (- 1));
    roll(num, t);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0 ; i < 4 ; i++)
    {
        string str;
        cin >> str;
        vector<bool> l;
        for (int j = 0 ; j < str.length() ; j++)
        {
            l.push_back(str[j]  - '0');
        }
        wheel.push_back(l);
    }
    
    int n;
    cin >> n;
    
    while (n--)
    {
        fill(visited, visited + 4, false);
        int number, t;
        cin >> number >> t;
        roll_wheel(number - 1, t);
        
    }
    int sol = 0;
    for (int i = 0 ; i < 4 ; i++)
    {
        if (wheel[i][0]) sol += pow(2,i);
    }

    cout << sol << endl;
}
    