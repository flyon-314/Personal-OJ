#include <iostream>
#include <vector>
using namespace std;
const long long MOD = 1000000000;
int main() {
    int dp[101][11]={0,};
    for(int i=1;i<10;i++){
        dp[1][i]=1;
    }
    
    for(int i=2;i<101;i++){
        dp[i][0] = dp[i - 1][1] % MOD;
        for(int j=1;j<9;j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%MOD;
        }
        dp[i][9] = dp[i - 1][8] % MOD;
    }
    int n;
    int sum=0;
    cin>>n;
    for(int i=0;i<10;i++){
        sum=(sum+dp[n][i])%MOD;
    }
    cout<<sum;
    return 0;
}