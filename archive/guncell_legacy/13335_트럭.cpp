#include <algorithm>
#include <iosfwd>
#include <iostream>
#include <list>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n, w, l;
    cin >> n >> w >> l;

    int sol = 0;    

    queue <int> truck;

    for (int i = 0; i < n; i++)
    {
        int weight;
        cin >> weight;
        truck.push(weight);
    }

    queue<pair<int,int>> bridge;

    do
    {
        if (!bridge.empty() && bridge.front().second == 0)
        {
            n++;
            l += bridge.front().first;
            bridge.pop();
        }
        if (!bridge.empty())
        {
            for (int i = 0; i < bridge.size() ; i++)
            {
                bridge.front().second--;
                bridge.push(bridge.front());
                bridge.pop();
            }
        }
        if (!truck.empty() &&n > 0 && l - truck.front() >= 0)
        {
            n--;
            l -= truck.front();
            
            bridge.push(make_pair(truck.front(), w - 1));
            truck.pop();
        } 
        sol++;
    }while (!truck.empty() || !bridge.empty());
    cout << sol;
}
    