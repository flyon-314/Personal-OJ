#include <bits/stdc++.h>

using namespace std;

int dist[1001];
int dp[1001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,sol=1;
    int k=0;
    cin>>n;
    vector <vector<int>> v;
    for(int i=0;i<n;i++)cin>>dist[i];
    dp[0]=1;
    v.push_back({dist[0]});
    for(int i=1;i<n;i++){
        v.push_back({});
        dp[i]=1;
        for(int j=i-1;j>=0;j--){
            if(dist[i]>dist[j] &&dp[i]<dp[j]+1) {
                v[i]=v[j];
                dp[i]=dp[j]+1;
                if(sol<dp[i]){
                    sol=dp[i];
                    k=i;
                }
            }
        }
        v[i].push_back(dist[i]);
    }
    cout<<sol<<"\n";
    for(int i=0;i<v[k].size();i++){
        cout<<v[k][i]<<" ";
    }
}