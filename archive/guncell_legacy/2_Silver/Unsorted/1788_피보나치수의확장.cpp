#include <bits/stdc++.h>

using namespace std;
int pos[1000001];
int neg[1000001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    pos[0]=0;pos[1]=1;pos[2]=1;
    neg[0]=0;neg[1]=1;neg[2]=-1;
    if(n>0){
        cout<<"1\n";
        for(int i=3;i<=n;i++) pos[i]=(pos[i-1]+pos[i-2])%1000000000;
        cout<<pos[n];
    }
    else if(n<0){
        
        n*=-1;
        for(int i=3;i<=n;i++) neg[i]=(neg[i-2]-neg[i-1])%1000000000;
        if(neg[n]<0){
            cout<<"-1\n";
            cout<<neg[n]*-1;
        }
        else{
            cout<<"1\n";
            cout<<neg[n];
        }
        
    }
    else cout<<"0\n0";
}