#include <bits/stdc++.h>

using namespace std;

int rope[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>rope[i];
    
    sort(rope,rope+n);
    int sol=0;
    
    for(int i=0;i<n;i++) sol=max(sol,rope[i]*(n-i));
    
    cout<<sol;
}