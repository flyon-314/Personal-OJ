#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> v;
    string inp;
    cin>>inp;
    for(int i=0;i<inp.length();i++){
        v.push_back(inp.substr(i,inp.length()));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<inp.length();i++){
        cout<<v[i]<<"\n";
    }
    
}