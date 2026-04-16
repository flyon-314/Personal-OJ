#include <bits/stdc++.h>

using namespace std;
int stock[1000001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long n,sol=0,vlaue=0;
        cin>>n;
        
        for(int i=0;i<n;i++) cin>> stock[i];
        
        for(int i=n-1;i>=0;i--){
            if(stock[i]>vlaue) vlaue=stock[i];
            else sol+=vlaue-stock[i];
        }
        cout<<sol<<"\n";
        fill(stock,stock+n,0);
    }
}