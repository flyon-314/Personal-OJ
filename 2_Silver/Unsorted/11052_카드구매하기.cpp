#include <iostream>

using namespace std;

int main() {
    int card[1001];
    int dp[1001]={0,};
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>card[i];
    }
    for(int i=1;i<=n;i++){
        dp[i]=card[i];
        for(int j=1;j<i;j++){
            dp[i]=max(dp[i],dp[j]+dp[i-j]);
        }
    }
    cout<<dp[n];
}