#include <bits/stdc++.h>

using namespace std;

pair <int,int> a[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].second>>a[i].first;
    }
    sort(a,a+n);
    int sol=0,t=0;
    
    for(int i=0;i<n;i++){
        if(a[i].second>=t){
            sol++;
            t=a[i].first;
        }
    }
    cout<<sol;
    return 0;
}