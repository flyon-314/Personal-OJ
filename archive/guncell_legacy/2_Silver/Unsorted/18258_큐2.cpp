#include <bits/stdc++.h>
using namespace std;

long long h[100001];
int n,num;
string inp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    queue <int> q;
    while(n--){
        cin>>inp;
        if(inp=="push"){
            cin>>num;
            q.push(num);
        }
        else if(inp=="pop"){
            if(q.empty()) cout<<"-1\n";
            else {
                cout<<q.front()<<"\n";
                q.pop();
            }
        }
        else if(inp=="size") cout<<q.size()<<"\n";
        else if(inp=="empty"){
            if(q.empty()) cout<<"1\n";
            else cout<<"0\n";
        }
        else if(inp=="front"){
            if(q.empty()) cout<<"-1\n";
            else cout<<q.front()<<"\n";
        }
        else{
            if(q.empty()) cout<<"-1\n";
            else cout<<q.back()<<"\n";
        }
    }
}