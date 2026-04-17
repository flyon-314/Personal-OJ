#include <bits/stdc++.h>

using namespace std;

int score[101];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,sol=0;
    cin>>n;
    for(int i=0;i<n;i++) cin>>score[i];
    for(int i=n-2;i>=0;i--){
        if(score[i]>=score[i+1]){
            sol+=score[i]-(score[i+1]-1);
            score[i]=score[i+1]-1;
        }
    }
    cout<<sol;
}