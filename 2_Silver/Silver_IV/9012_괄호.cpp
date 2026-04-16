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

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        bool flag = true;
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') st.push(s[i]);
            else if (s[i] == ')') {
                if (st.empty()) {
                    flag = false;
                    break;
                }
                else st.pop();
            }
        }

        if (st.empty() && flag) cout << "YES\n"; 
        else cout << "NO\n";
    }
    
}   