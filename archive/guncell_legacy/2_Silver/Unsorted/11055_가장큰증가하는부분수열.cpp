#include <iostream>

using namespace std;

int main() {
    int n;
    int sequence[1001];
    int dp[1001]={0,};
    int answer=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>sequence[i];
    }
    for(int i=1;i<=n;i++){
        dp[i]=sequence[i];
        for(int j=1;j<i;j++){
            if(sequence[i]>sequence[j]){
                dp[i]=max(dp[i],dp[j]+sequence[i]);
            }
                
        }
        answer=max(dp[i],answer);
        
    }
    cout<<answer;
}