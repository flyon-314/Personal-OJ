#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> num(100);
    for(int i=1;i<=n;i++) num[i-1]=i;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        swap(num[a-1],num[b-1]);
    }
    for(int i=0;i<n;i++) cout<<num[i]<<" ";
}