#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    stack <int> s;
    int sol=0,temp=1;
    bool check=false;
    
    getline(cin,str);
    
    for(auto i :str ){
        if(i=='(' ) {
            s.push(i);
            if(check) check=false;
            temp*=2;
        }
        else if(i=='['){
            s.push(i);
            if(check) check=false;
            temp*=3;
        }
        else if(!s.empty()){
            if(i==')' &&s.top()=='('){
                s.pop();
                if(!check) sol+=temp;
                check=true;
                temp/=2;
            }
            else if(i==']'&&s.top()=='['){
                s.pop();
                if(!check) sol+=temp;
                check=true;
                temp/=3;
            }
            else{
                sol=0;
                break;
            }
        }
        else{
            sol=0;
            break;
        }
    }
    if(s.empty()) cout<<sol;
    else cout<<"0";
}