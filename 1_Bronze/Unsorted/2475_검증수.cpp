#include <iostream>

using namespace std;

int main() {
    int n[5];
    for(int i=0;i<5;i++){
        cin>>n[i];
    }
    cout<<(n[0]*n[0]+n[1]*n[1]+n[2]*n[2]+n[3]*n[3]+n[4]*n[4])%10<<endl;
}