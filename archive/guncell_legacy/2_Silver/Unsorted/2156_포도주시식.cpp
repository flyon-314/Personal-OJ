#include <iostream>

using namespace std;

int main() {
    int n;
    int podo[10001];
    int dp[10001]={0,};
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>podo[i];
    }
    dp[1]=podo[1];
    dp[2]=dp[1]+podo[2];
    for(int i=3;i<=n;i++){
        dp[i]=max(dp[i-2]+podo[i],dp[i-3]+podo[i-1]+podo[i]);
        dp[i]=max(dp[i],dp[i-1]);
    }
    cout<<dp[n]<<endl;
    return 0;
}