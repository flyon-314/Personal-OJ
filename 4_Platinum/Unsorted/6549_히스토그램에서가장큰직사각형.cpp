#include <bits/stdc++.h>
using namespace std;

long long h[100001];
int n;

int main() {
    while(true){
        cin>>n;
        if(n==0) break;
        
        for(int i=0;i<n;i++) cin>>h[i];
        stack <pair<int,int>> s;
        long long sol=0;
        for(int i=0;i<n;i++){
            int idx=i;
            while(!s.empty() &&s.top().first >=h[i]){
                sol=max(sol,1ll*(i-s.top().second)*s.top().first);
                idx=s.top().second;
                s.pop();
            }
            s.push(make_pair(h[i],idx));
        }
        while(!s.empty()){
            sol=max(sol,1ll*(n-s.top().second)*s.top().first);
            s.pop();
        }
        cout<<sol<<"\n";
    }    
}