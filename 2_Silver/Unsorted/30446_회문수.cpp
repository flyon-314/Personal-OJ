#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;

    long long count = 0;

    for (long long i = 1; ; ++i) {
        bool flag = true;
        string s = to_string(i);
        string rs = s;
        reverse(rs.begin(), rs.end());
        
        string str = s + rs;
        
        if (stoll(str) <= n)
        {
            count++;
            flag = false;
        }
        if (s.length() == 1)
        {
            if (stoll(s) <= n)
            {
                count++;
                flag = false;
            }
        }
        else
        {
            string str1 = s.substr(0, s.length() - 1);
            
            reverse(str1.begin(), str1.end());
            
            string str2 = s + str1;
            if (stoll(str2) <= n) {
                count++;
                flag = false;
            }
        }
        
        if (flag) break;
    }

    cout << count << "\n";

    return 0;
}
