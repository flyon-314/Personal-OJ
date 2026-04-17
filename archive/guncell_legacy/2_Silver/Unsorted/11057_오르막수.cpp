#include <iostream>
#include <vector>
using namespace std;
const long long MOD = 10007;
int main() {
    int dp[1001][10]={0,};
    for(int i=0;i<10;i++){
        dp[1][i]=1;
    }
    for(int i=2;i<1001;i++){
        for(int j=0;j<10;j++){
            int sum=0;
            for(int k=j;k<10;k++){
                sum=(sum+dp[i-1][k])%MOD;
            }
            dp[i][j]=sum;
        }
    }
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<10;i++){
        sum=(sum+dp[n][i])%MOD;
    }
    cout<<sum;
}