#include <bits/stdc++.h>

using namespace std;

int arr[3][100001];
int dp[3][100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    
    int count=1;
    while(true){
        int n;
        cin>>n;if(n==0) return 0;
        for(int i=0;i<n;i++) cin>>arr[0][i]>>arr[1][i]>>arr[2][i];
        
        dp[0][0] = 9999999; 
        dp[1][0] = arr[1][0]; 
        dp[2][0] = arr[1][0] + arr[2][0];
        for(int i=1;i<n;i++){
            dp[0][i]=arr[0][i]+min(dp[0][i-1],dp[1][i-1]);
            dp[1][i]=arr[1][i]+min(min(dp[0][i],dp[0][i-1]),min(dp[1][i-1],dp[2][i-1]));
            dp[2][i]=arr[2][i]+min(min(dp[1][i],dp[1][i-1]),dp[2][i-1]);
        }
        cout<<count<<". "<<dp[1][n-1]<<"\n";
        count++;
    }
}