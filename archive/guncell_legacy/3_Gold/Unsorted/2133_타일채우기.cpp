#include <iostream>
using namespace std;

int main() {
    int n;
    int dp[31]={0,};
    cin>>n;
    
    dp[0]=1;dp[2]=3;dp[4]=11; dp[6]=41;
    for(int i=8;i<=30;i+=2){
        dp[i]+=dp[i-2]*dp[2];
        for(int j=i-4;j>=0;j-=2){
            dp[i]+=dp[j]*2;
        }
    }
    cout<<dp[n];
}