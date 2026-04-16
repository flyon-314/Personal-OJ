#include <bits/stdc++.h>

using namespace std;
int main(){
    for(int i=0;i<3;i++){
        int count=0;
        for(int j=0;j<4;j++){
            int temp;
            cin>>temp;
            if(temp==0) count++;
        }
        if(count==4)cout<<"D"<<endl;
        else if(count==3)cout<<"C"<<endl;
        else if(count==2)cout<<"B"<<endl;
        else if(count==1)cout<<"A"<<endl;
        else cout<<"E"<<endl;
    }
}