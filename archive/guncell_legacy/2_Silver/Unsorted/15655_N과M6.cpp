#include <bits/stdc++.h>

using namespace std;
int arr[10];
int num[10];
int isued[10];
int n,m;
void func(int k){
    if(k==m){
        for(int i=0;i<m;i++) cout<<num[arr[i]]<<" ";
        cout<<"\n";
        return ;
    }
    int st=0;
    if(k!=0) st=arr[k-1]+1;
    for(int i=st;i<n;i++){
        if(isued[i]) continue;
        arr[k]=i;
        isued[i]=1;
        func(k+1);
        isued[i]=0;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>num[i];
    sort(num,num+n);
    func(0);
    return 0;
}