#include <bits/stdc++.h>

using namespace std;
int arr[100001];
int visited[100001];
int dx[2]={-1,1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int sol=0,z_count=0,o_count=0;
    for(int i=0;i<s.length();i++){
        if(s[i]!=s[i+1]){
            if(s[i]=='0')z_count++;
            else o_count++;
        }
    }
    cout<<min(z_count,o_count);
}