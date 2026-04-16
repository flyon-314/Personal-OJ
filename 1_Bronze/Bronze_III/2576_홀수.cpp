#include <bits/stdc++.h>

using namespace std;
int main(){
    int low=101,sum=0;

    for(int i=0;i<7;i++){
        int temp;
        cin>>temp;
        if(temp%2==1){
            sum+=temp;
            low=min(temp,low);
        }
    }
    if (low==101) cout<<-1;
    else{
        cout<<sum<<endl<<low<<endl;
    }
}