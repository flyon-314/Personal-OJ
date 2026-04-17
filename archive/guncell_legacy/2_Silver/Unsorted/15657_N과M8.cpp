#include <bits/stdc++.h>

using namespace std;
int n,m;
int num[10];
int arr[10];
void func(int k){
    if(k==m){
        for(int i=0;i<m;i++) cout<<arr[num[i]]<<" ";
        cout<<"\n";
        return;
    }
    int st=0;
    if(k!=0)st=num[k-1];
    for(int i=st;i<n;i++){
       num[k]=i;
       func(k+1);
    
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    func(0);
    return 0;
}