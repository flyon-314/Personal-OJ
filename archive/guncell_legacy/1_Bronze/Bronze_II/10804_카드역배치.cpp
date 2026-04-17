#include <bits/stdc++.h>

using namespace std;
int main(){
    int num[20];
    for(int i=1;i<=20;i++) num[i-1]=i;

    for(int i=0;i<10;i++){
        int a,b;
        cin>>a>>b;

        reverse(num+a-1,num+b);
    }

    for(int a : num){
        cout<<a<<" ";
    }
}