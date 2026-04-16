#include <bits/stdc++.h>
using namespace std;

int n,l;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,count=0;;
    cin>>n;
    while(n--){
        string str;
        stack <char> s;
        
        cin>>str;
        for(auto i : str){
            if(s.empty()) s.push(i);
            else if (!s.empty()&&s.top()==i) s.pop();
            else s.push(i);
            
        }
        if(s.empty()) {
            count++;
        }
    }
    cout<<count;
    
}