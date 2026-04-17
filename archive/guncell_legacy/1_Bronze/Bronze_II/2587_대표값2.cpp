#include <bits/stdc++.h>

using namespace std;
int main(){
    int num[5];
    int avg=0;
    for(int i=0;i<5;i++) {
        cin>>num[i];
        avg+=num[i];
    }
    avg/=5;
    sort(num,num+5);
    cout<<avg<<endl<<num[2];
}