#include <bits/stdc++.h>

using namespace std;

int arr[2200][2200];
int zero,one;
void func(int x, int y,int n){
    bool flag=false;
    int temp=arr[y][x];
    int t=n/2;
    for(int i=y;i<y+n;i++){
        for(int j=x;j<x+n;j++){
            if(arr[i][j]!=temp){
                cout<<"(";
                func(x,y,t);
                func(x+t,y,t);
                func(x,y+t,t);
                func(x+t,y+t,t);
                cout<<")";
                flag=true;
                break;
            }
        }
        if(flag) return;
    }
    if(temp==0) cout<<0;
    if(temp==1) cout<<1;
    if(n==1) return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        for(int j=0;j<str.length();j++) arr[i][j]=str[j] - '0';
    }
    func(0,0,n);
    return 0;
}