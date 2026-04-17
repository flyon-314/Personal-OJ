#include <bits/stdc++.h>

using namespace std;

int dp[1500001];
int dist[2][1500001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,sol=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>dist[0][i]>>dist[1][i];
    for(int i=1;i<=n;i++){
        dp[i]=max(dp[i],dp[i-1]);
        if(dist[0][i]+i>n+1) continue;
        dp[i+dist[0][i]]=max(dp[i+dist[0][i]],dp[i]+dist[1][i]);
        sol=max(sol,dp[i+dist[0][i]]);
    }
    cout<<sol;
}