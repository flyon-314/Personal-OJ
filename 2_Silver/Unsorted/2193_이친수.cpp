#include <iostream>
#include <vector>
using namespace std;
int main() {
    long long int dp[91];
    int n;
    cin>>n;
    dp[0]=0;dp[1]=1;dp[2]=1;dp[3]=2;
    for(int i=4;i<91;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
}