#include <bits/stdc++.h>

using namespace std;
int dp[100001][2];
bool visited[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    vector <int> sol;
    cin>>n>>k;
    if(n==k){
        cout<<"0\n"<<n;
        return 0;
    }
    queue <int> q;
    
    visited[n]=true;
    q.push(n);
    while(!q.empty()){
        if(q.front()==k) break;
        int temp=q.front(); q.pop();
        if(!visited[temp*2]&&temp*2<=k+1){
            visited[temp*2]=true;
            dp[temp*2][0]=dp[temp][0]+1;
            dp[temp*2][1]=temp;
            q.push(temp*2);
        }
        if(!visited[temp-1]&&temp-1>=0){
            visited[temp-1]=true;
            dp[temp-1][0]=dp[temp][0]+1;
            dp[temp-1][1]=temp;
            q.push(temp-1);
            
        }
        
        
        if(!visited[temp+1]&&temp<=k+1){
            visited[temp+1]=true;
            dp[temp+1][0]=dp[temp][0]+1;
            dp[temp+1][1]=temp;
            q.push(temp+1);
        }
    }
    cout<<dp[k][0]<<"\n";
    sol.push_back(k);
    for(int i=k;dp[i][1]!=n;i=dp[i][1]){
        sol.push_back(dp[i][1]);
    }
    sol.push_back(n);
    for(int i=sol.size()-1;i>=0;i--)cout<<sol[i]<<" ";
}