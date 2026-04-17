#include <bits/stdc++.h>

using namespace std;
int arr[50];
int num[10];
int n;

void func(int k){
    if(k==6){
        for(int i=0;i<6;i++)cout<<arr[num[i]]<<" ";
        cout<<"\n";
        return;
    }
    int st=0;
    if(k!=0) st=num[k-1]+1;
    for(int i=st;i<n;i++){
        if(arr[num[k-1]]>arr[i]) continue;
        num[k]=i;
        func(k+1);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        cin>>n;
        if(n==0) return 0;
        for(int i=0;i<n;i++)cin>>arr[i];
        func(0);
        cout<<"\n";
    }
    return 0;
}