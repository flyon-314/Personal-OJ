#include <bits/stdc++.h>

using namespace std;

void func(int s, int e, int n){
    if(n==1){
        cout<<s<<" "<<e<<"\n";
        return;
    }
    func(s,6-s-e,n-1);
    cout<<s<<" "<<e<<"\n";
    func(6-s-e,e,n-1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin>>k;
    cout<<(1<<k)-1<<"\n";
    func(1,3,k);
    return 0;
}