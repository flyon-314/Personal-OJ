#include <bits/stdc++.h>

using namespace std;
string str[1001];
int dp[1001][1001];
int n,m;
int anl;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>str[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)dp[i][j]=(str[i-1][j-1]-'0')+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
    }
    bool flag=false;
    for(int s=1;s<=min(n,m);s++){
        flag=false;
        for(int i=s;i<=n;i++){
            for(int j=s;j<=m;j++){
                if((dp[i][j]+dp[i-s][j-s]-dp[i-s][j]-dp[i][j-s])==s*s){
                    flag=true;
                    anl=s*s;
                    break;
                }    
            }
            if(flag)break;
        }
    }
    cout<<anl;
}