#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int space =  i-1;
        int star = 2*(n-i)+1;

        cout<<string (space,' ');
        cout<<string (star,'*')<<endl;
    }
}