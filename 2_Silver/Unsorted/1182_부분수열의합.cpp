#include <bits/stdc++.h>

using namespace std;
int n,s,cnt=0;
int arr[21];

void func(int cur,int total){
    if(cur==n){
        if(total==s)cnt++;
        return;
    }
    func(cur+1,total);
    func(cur+1,total+arr[cur]);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0;i<n;i++)cin>>arr[i];
    func(0,0);
    if(s==0)cnt--;
    cout<<cnt;
    return 0;
}