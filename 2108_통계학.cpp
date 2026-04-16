#include <algorithm>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
    
int main(   )
{
    int n;
    int num[8001] = {0};
    double sum = 0;
    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        
        num[temp + 4000]++;
        sum += temp;
    }

    int  a = round(sum / n);
    cout << a<< "\n";

    int center = 0;
    for (int i = 0; i < 8001; i++)
    {
        if (num[i] != 0) center += num[i];
        if (center >= n/2 + 1)
        {
            cout << i - 4000 << "\n";
            break;
        }
    }

    int many = 0;
    for (int i = 0; i < 8001; i++)
    {
        many = max(many, num[i]);
    }
    vector <int> v;
    for (int i = 0; i < 8001; i++)
    {
        if (num[i] == many)
        {
            v.push_back(i-4000);
        }
    }
    sort(v.begin(), v.end());

    if (v.size() > 1)
        cout << v[1] << "\n";
    else
        cout << v[0] << "\n";
    
    int range = 0;

    for (int i = 8000; i >= 0; i--)
    {
        if (num[i] != 0)
        {
            range = i - 4000;
            break;
        }
    }

    for (int i = 0; i < 8001; i++)
    {
        if (num[i] != 0)
        {
            range -= i-4000;
            break;
        }
    }

    cout << range << "\n";
    

    return 0;
}
