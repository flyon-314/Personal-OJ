#include <bits/stdc++.h>

using namespace std;
int func(int y, int x, int n){
    if(n==0) return 0;
    int mid=1<<(n-1);
    if(y<mid &&x<mid)return func(y,x,n-1);
    else if(y<mid &&x>=mid) return mid*mid+func(y,x-mid,n-1);
    else if(y>=mid &&x<mid) return 2*mid*mid+func(y-mid,x,n-1);
    return 3*mid*mid+func(y-mid,x-mid,n-1);
    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x,y;
    cin>>n;
    cin>>y>>x;
    cout<<func(y,x,n);
    return 0;
}