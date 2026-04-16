#include <bits/stdc++.h>

using namespace std;

int arr[2200][2200];
int k;
void func(int x, int y,int n){
    if((x/n)%3==1 &&(y/n)%3==1)cout<<" ";
    else{
        if(n/3==0) cout<<"*";
        else func(x,y,n/3);
    }
    
    
    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>k;
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            func(i,j,k);
        }
        cout<<"\n";
    }
    
    return 0;
}