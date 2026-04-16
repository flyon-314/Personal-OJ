#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    string s=to_string(a*b*c);
    int num[10]={0};
    for(char count:s){
        num[count-'0']++;
    }
    for(int n:num) cout<<n<<endl;
}