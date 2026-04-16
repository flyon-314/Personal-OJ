#include <iostream>

using namespace std;

int main() {
    int n;
    int sequence[1001];
    int dp[2][1001]={0,};
    int answer=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>sequence[i];
    }
    for(int i=1;i<=n;i++){
        dp[0][i]=1;
        for(int j=1;j<=i;j++){
            
            if(sequence[i]>sequence[j]){
                dp[0][i]=max(dp[0][i],dp[0][j]+1);
            }
                
        }
        
        
    }
    for(int i = n; i >= 1; i--){
        dp[1][i]=1;
        for(int j=n;j>=1;j--){
            if(sequence[i]>sequence[j]){
                dp[1][i]=max(dp[1][i],dp[1][j]+1);
            }
                
        }
        
        
    }
    answer=dp[0][1]+dp[1][1];
    for(int i=2;i<=n;i++){
        answer=max(dp[0][i]+dp[1][i],answer);
    }
    
    cout<<answer-1;
}