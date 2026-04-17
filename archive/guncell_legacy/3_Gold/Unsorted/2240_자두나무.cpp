#include <bits/stdc++.h>

using namespace std;

int dp[2][31][1001];
int dist[1001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,w;
    
    cin>>n>>w;
    
    for(int i=1;i<=n;i++) cin>>dist[i];
    
    for(int i=1;i<=n;i++){
        dp[0][0][i]=dp[0][0][i-1]+(dist[i]==1);
    }
    
    for(int i=1;i<=w;i++){
        for(int j=1;j<=n;j++){
            dp[0][i][j]=max(dp[0][i][j-1]+(dist[j]==1),dp[1][i-1][j-1]+(dist[j]==1));
            dp[1][i][j]=max(dp[1][i][j-1]+(dist[j]==2),dp[0][i-1][j-1]+(dist[j]==2));
        } 
    }
    int sol=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<=w;j++){
            sol=max(sol,dp[i][j][n]);
        }
    }
    cout<<sol;
}