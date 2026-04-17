#include <bits/stdc++.h>
using namespace std;

int n,l;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    
    deque<pair<int,int>> DQ;
    cin>>n>>l;
    
    for(int i=0;i<n;i++){
        cin>>num;
        while(!DQ.empty()&&DQ.back().first>num)
            DQ.pop_back();
        DQ.push_back(make_pair(num,i));
        if(i-DQ.front().second>=l)
            DQ.pop_front();
        cout<<DQ.front().first<<" ";
    }
    
}