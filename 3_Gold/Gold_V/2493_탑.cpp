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

        int n;
        cin >> n;
        
        stack<pair<int,int>> s;
        vector<int> v;

        for (int i = 1 ; i <= n ; i++)
        {
            int high;
            cin >> high;

            while (!s.empty() && s.top().first < high) s.pop();

            if (s.empty())
            {
                v.push_back(0);
                s.push(make_pair(high, i));
            }
            else
            {
                v.push_back(s.top().second);
                s.push(make_pair(high, i));
            }
            
        }

        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }

        return 0;
    }
