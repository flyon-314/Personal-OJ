#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
 
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    
    cin >> n;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        v.push_back(make_pair(start,end ));
    }
    sort(v.begin(), v.end()); 
 
    pq.push(v[0].second);
    for (int i = 1; i < v.size(); i++) {
        if (v[i].first >= pq.top()) {
            pq.pop();
            pq.push(v[i].second);
        }
        else {
            pq.push(v[i].second);
        }
    }
    cout << pq.size();
}
