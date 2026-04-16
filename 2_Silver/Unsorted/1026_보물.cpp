#include <bits/stdc++.h>

using namespace std;

int a[51];
int b[51];
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    sort(a,a+n); sort(b,b+n);
    int sol=0;
    for(int i=0;i<n;i++) sol+=a[i]*b[n-i-1];
    cout<<sol;
  
}