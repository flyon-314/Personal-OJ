#include <iostream>

using namespace std;

int main() {
    int n;
    int arr[2][16]={0,};
    int dp[16]={0,};
    int maxe=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[0][i]>>arr[1][i];
    }
    for(int i=0;i<=n;i++){
        dp[i]=max(maxe,dp[i]);
        if(arr[0][i]+i<=n){
            dp[arr[0][i]+i]=max(dp[arr[0][i]+i],arr[1][i]+dp[i]);
        }
        maxe=max(maxe,dp[i]);
    }
    cout<<maxe;
    
}