#include <iostream>
const int MAX=1000000000;
using namespace std;

int main() {
    int n,k;
    int dp[201][201]={0,};
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        dp[0][i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MAX;
        }
    }
    cout<<dp[n][k];
    return 0;
}