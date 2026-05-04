#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <climits>
#include <stack>
#include <unordered_set>

using namespace std;

int city[51][51];

vector <pair <int, int>> house;
vector <pair<int,int>> chicken;
vector<bool> chick_visited;
vector <int> chick_select;
int chick_len[101][14];
int chick_back(int chick_cur, int chick_cnt)
{
    if (chick_select.size() == chick_cnt) {
        int sum = 0;
        for (int i = 0 ; i < house.size() ; i++) {
            int temp = INT_MAX;
            for (int j = 0 ; j < chick_select.size() ; j++) {
                temp = min(temp,chick_len[i][chick_select[j]]);
            }
            sum += temp;
        }
        return sum;
    }
    int sol = INT_MAX;    
    for (int i = chick_cur; i < chicken.size(); i++) {
        if (chick_visited[i]) continue;
        chick_visited[i] = true;
        chick_select.push_back(i);
        sol = min(sol, chick_back(i + 1, chick_cnt));
        chick_select.pop_back();
        chick_visited[i] = false;
    }
    return sol;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
            if (city[i][j] == 1) house.push_back(make_pair(i, j));
            else if (city[i][j] == 2) chicken.push_back(make_pair(i, j));
        }
    }
    for (int i = 0; i < house.size(); i++) {
        for (int j = 0; j < chicken.size(); j++) {
            chick_len[i][j] = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
        }
    }
    int anw = INT_MAX;
    for (int i = 1 ; i <= m ; i++) {
        chick_visited = vector <bool> (chicken.size(), false);
        anw = min (anw, chick_back(0, i));   
    }

    cout << anw;
}   