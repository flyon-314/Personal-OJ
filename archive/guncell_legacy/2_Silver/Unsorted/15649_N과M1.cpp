#include <bits/stdc++.h>

using namespace std;
int arr[10];
int infuese[10];
int n,m;
void func(int k){
    if(k==m){
        for(int i=0;i<k;i++) cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(!infuese[i]){
            arr[k]=i;
            infuese[i]=1;
            func(k+1);
            infuese[i]=0;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    func(0);
    return 0;
}