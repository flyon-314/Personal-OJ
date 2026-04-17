#include <bits/stdc++.h>

using namespace std;
vector <int> pos;
vector <int> neg;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int sol=0;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(num>0) pos.push_back(num);
        else neg.push_back(num);
    }
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    
    int i=pos.size()-1;
    while(i>=0){
        if (i==0){
            sol+=pos[i];
            i--;
        }
        else if(pos[i]*pos[i-1]==pos[i]){
            sol+=pos[i];
            i--;
        }
        else{
            sol+=pos[i]*pos[i-1];
            i-=2;
        }
    }
    i=0;
    while(i<neg.size()){
        if(i==neg.size()-1){
            sol+=neg[i];
            i++;
        }
        else {
            sol+=neg[i]*neg[i+1];
            i+=2;
        }
    }
    cout<<sol;
}