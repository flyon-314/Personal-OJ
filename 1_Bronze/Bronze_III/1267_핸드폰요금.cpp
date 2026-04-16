#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    int Y=0,M=0;
    cin>>n;
    int call[10001];
    for(int i=0;i<n;i++)cin>>call[i];
    for(int i=0;i<n;i++){
        if(call[i]%30<30) Y+=(call[i]/30)*10+10;
        else  Y+=(call[i]/30)*10;
    }
    for(int i=0;i<n;i++){
        if(call[i]%60<60) M+=(call[i]/60)*15+15;
        else  M+=(call[i]/60)*15;
    }
    if(Y<M) cout<<"Y "<<Y;
    else if(M<Y) cout<<"M "<<M;
    else cout<<"Y M "<<Y;
}