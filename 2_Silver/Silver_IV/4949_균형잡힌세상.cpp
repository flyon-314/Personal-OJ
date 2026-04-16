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

    string s;
    while (true) {
        getline(cin, s);
        
        if (s == ".") {
            return 0;
        }
        
        bool flag = false;
        stack<char> st;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[' || s[i] == '(') st.push(s[i]);
            else if (s[i] == ']' || s[i] == ')') {
                if (st.empty()) {
                    flag = true;
                    break;
                }
                if (s[i] == ']' && st.top() == '[') st.pop();
                else if (s[i] == ')' && st.top() == '(') st.pop();
                else {
                    flag = true;
                    break;
                }
            }
        }
        
        if (flag) cout << "no\n";
        else {
            if (s[s.length() - 1] == '.' && st.empty()) cout << "yes\n";
            else cout << "no\n";
        }
        
    }
    return 0;
    
}   