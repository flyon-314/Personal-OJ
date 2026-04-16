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
        for(int j=i-1;j>=1;j--){
            if(sequence[i]<sequence[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
                
        }
        answer=max(dp[i],answer);
        
    }
    cout<<answer+1;
}