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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int,int> umap;
    int n, m;
    string str;
    cin >> n >> m >> str;

    int st = 0, ed = 0;

    int len = 0;
    int anw = 0;
    while (ed < m ) {
        if (str[ed] != 'I' && str[st] != 'I') {
            ed++;
            st++;
        }

        if (str[ed] == 'I' && str[st] == 'I') {
            if (ed + 2 >= m) break;
            if (str[ed + 1] == 'O' && str[ed + 2] == 'I') {
                ed += 2;
                len++;
                if (len >= n) anw++;
            }
            else {
                st = ++ed;
                len = 0;
            }
        } 
    }

    cout << anw;
}   