#include <bits/stdc++.h>

using namespace std;
int arr[42];
int dp[42];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    int sol=1;
    cin>>n>>m;
    dp[0]=1;dp[1]=1;dp[2]=2;dp[3]=3;
    arr[0]=1;
    for(int i=4;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    while(m--){
        int temp;
        cin>>temp;
        arr[temp]=1;
    }
    int count=0;
    for(int i=1;i<=n;i++){
        if(arr[i]==1){
            sol*=dp[count];
            count=0;
            continue;
        }
        else if(i==n){
            count++;
            sol*=dp[count];
        }
        else{
            count++;
        }
    }
    cout<<sol;
}