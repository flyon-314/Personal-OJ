#include <bits/stdc++.h>

using namespace std;

int dp[1000001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<int>> v;
    int n,sol=0;
    cin>>n;
    dp[1]=0;dp[2]=1;dp[3]=1;
    v.push_back({0});
    v.push_back({1});
    v.push_back({1,2});
    v.push_back({1,3});
    for(int i=4;i<=n;i++){
        dp[i]=dp[i-1]+1;
        v.push_back(v[i-1]);
        if(i%2==0) {
            if(dp[i]>dp[i/2]+1){
                dp[i]=dp[i/2]+1;
                v[i]=v[i/2];
            }
        }
        if(i%3==0) {
            if(dp[i]>dp[i/3]+1){
                dp[i]=dp[i/3 ]+1;
                v[i]=v[i/3];
            }
        }
        v[i].push_back(i);
    }
    cout<<dp[n]<<"\n";
    for(int i=v[n].size()-1;i>=0;i--){
        cout<<v[n][i]<<" ";
    }
}