#include <bits/stdc++.h>

using namespace std;
char arr[50];
char ar[5]={'a','e','i','o','u'};
int num[10];
int n,m;

void func(int k){
    if(k==m){
        int a_count=0,b_count=0;
        bool check=false;
        for(int i=0;i<m;i++){
            check=false;
            for(int j=0;j<5;j++){
                if(arr[num[i]]==ar[j]){
                    a_count++;
                    check=true;
                    break;
                }
            }
            if(!check)b_count++;
        }
        if(a_count<1||b_count<2)return;
        for(int i=0;i<m;i++)cout<<arr[num[i]];
        cout<<"\n";
        return;
    }
    int st=0;
    if(k!=0) st=num[k-1]+1;
    for(int i=st;i<n;i++){
        if(arr[num[k-1]]>arr[i]) continue;
        num[k]=i;
        func(k+1);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>m>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    func(0);
    return 0;
}