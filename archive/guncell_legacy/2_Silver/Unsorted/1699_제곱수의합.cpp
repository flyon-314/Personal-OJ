#include <iostream>
using namespace std;
const int MAX=99999;
int main() {
    int n;
    int dp[100001]={0,};
    cin>>n;
    
    dp[1]=1;dp[2]=2;dp[3]=3; dp[4]=1;
    for(int i=5;i<=n;i++){
        dp[i]=MAX;
        for(int j=1;i>=j*j;j++){
            dp[i]=min(dp[i],dp[i-j*j]+1);
        }
    }
    cout<<dp[n];
}