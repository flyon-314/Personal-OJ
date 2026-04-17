#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long N,high,sum=0;
    stack <long long> tower;
    cin>>N;
    while(N--){
        cin>>high;
        while(!tower.empty()){
            if(tower.top()>high) {
                sum+=tower.size();
                break;
            }
            tower.pop();
        }
        tower.push(high);
    }
    cout<<sum;
}