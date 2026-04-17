#include <iostream>
#include<string>
const int MAX=1000000;

using namespace std;

int main() {
    int arr[5001];
    int dp[5001]={0,};
    string inp;
    cin>>inp;
    for(int i=1;i<=inp.length();i++){
        arr[i]=inp[i-1]-'0';
    }
    if(arr[1]>0 && arr[1]<=9){
        dp[0]=dp[1]=1;
    }
    else if(arr[1]==0){
        cout<<0<<endl;
        return 0;
    }
    
    for(int i=2;i<=inp.length();i++){
        if(arr[i]>0 && arr[i]<=9){
            dp[i]=dp[i-1]%MAX;
        }
        int temp=arr[i-1]*10+arr[i];
        if(temp>=10 && temp<=26){
            dp[i]=(dp[i-2]+dp[i])%MAX;
        }
    }
    cout<<dp[inp.length()];
    
    return 0;
}