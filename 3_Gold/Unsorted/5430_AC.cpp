#include <bits/stdc++.h>
using namespace std;

int n,t;
string str,arr;
void parse(string& tmp,deque<int>& d){
    int cur=0;
    for(int i=1 ; i+1 < tmp.length() ; i++){
        if(tmp[i]==','){
            d.push_back(cur);
            cur=0;
        }
        else{
            cur=10*cur+(tmp[i]-'0');
        }
    }
    if(cur!=0)
        d.push_back(cur);
}
void arr_print(deque<int>& d,int rev){
    if(d.empty()) {
        cout<<"[]\n";
        return;
    }
    if(rev==0){
        cout<<"["<<d.front();
        d.pop_front();
        while(!d.empty()){
            cout<<","<<d.front();
            d.pop_front();
        }
        cout<<"]\n";
    }
    else{
        cout<<"["<<d.back();
        d.pop_back();
        while(!d.empty()){
            cout<<","<<d.back();
            d.pop_back();
        }
        cout<<"]\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>t;
    while(t--){
        bool iswrong=true;
        deque<int> d;
        int rev=0;
        cin>>str;
        cin>>n;
        cin>>arr;
        parse(arr,d);
        for(char c: str){
            if(c=='R')
                rev = 1 - rev;
            else{
                if(d.empty()){
                    iswrong=false;
                    break;
                }
                else if(rev==0) d.pop_front();
                else if(rev==1) d.pop_back();
            }
        }
        if(iswrong) arr_print(d,rev);
        else cout<<"error\n";
    }
    
}