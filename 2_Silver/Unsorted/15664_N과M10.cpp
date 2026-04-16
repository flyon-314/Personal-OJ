#include <bits/stdc++.h>

using namespace std;
int arr[10];
int num[10];
bool isued[10];
int n,m;

void func(int k){
    if(k==m){
        for(int i=0;i<m;i++)cout<<arr[num[i]]<<" ";
        cout<<"\n";
        return;
    }
    int st=0;
    if(k!=0) st=num[k-1];
    for(int i=st;i<n;i++){
        if(isued[i]) continue;
        if(num[k]!=-1&&arr[i]==arr[num[k]]) continue;
        isued[i]=1;
        num[k]=i;
        func(k+1);
        isued[i]=0;
    }
    num[k]=-1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    fill(num,num+n,-1);
    func(0);
    return 0;
}