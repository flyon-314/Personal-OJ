#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main() {
    
    string inp;
    
    
    int n;
    int count=0;
    string sol="YES";
    vector<char> v;
    cin>>inp;
    for(int i=0;i<inp.length();i++){
        if(inp[i]=='(')
            v.push_back(inp[i]);
        else if(inp[i]==')' && inp[i-1]==')'){
            v.pop_back();
            count++;
        }
        else if(inp[i]==')' && !v.empty()){
            v.pop_back();
            count+=v.size();
        }
    }
    cout<<count<<"\n";
              
}