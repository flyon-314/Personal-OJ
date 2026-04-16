#include <bits/stdc++.h>

using namespace std;

int egg[10][2];
int n,cnt,sol;
void func(int k){
    if(k==n){
        sol=max(sol,cnt);
        return;
    }
    if(egg[k][0]<=0||cnt==n-1){
        func(k+1);
        return;
    }
    for(int i=0;i<n;i++){
        if(i==k||egg[i][0]<=0) continue;
        egg[i][0]-=egg[k][1];
        egg[k][0]-=egg[i][1];
        if(egg[i][0]<=0)cnt++;
        if(egg[k][0]<=0)cnt++;
        
        func(k+1);
        
        if(egg[i][0]<=0)cnt--;
        if(egg[k][0]<=0)cnt--;
        egg[i][0]+=egg[k][1];
        egg[k][0]+=egg[i][1];
        
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++) cin>>egg[i][0]>>egg[i][1];
    
    func(0);
    cout<<sol;
    
}