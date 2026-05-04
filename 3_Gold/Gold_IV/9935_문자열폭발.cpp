#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, bomb;
    cin >> s >> bomb;

    stack<char> st;

    for (int i = 0 ; i < s.length()  ; i++) {
        st.push(s[i]);
        if (st.top() == bomb[bomb.length() - 1]&& st.size() >= bomb.length()) {
            string temp = "";
            bool flag = false;
            
            for (int j = bomb.length() - 1 ; j >= 0; j--) {
                if (st.top() != bomb[j]) {
                    flag = true;
                    break;
                }
                temp += st.top();
                st.pop();
            }
            
            if (flag) {
                for (int j = temp.length() - 1; j >= 0 ; j--) st.push(temp[j]);
            }
        }
    }
    if (st.empty()) cout << "FRULA";
    else {
        string sol = "";
        while (!st.empty()) {
            sol += st.top();
            st.pop();
        }
        for (int i = sol.length() - 1 ; i >= 0 ; i--) cout << sol[i]; 
    }
    return 0;
}