#include <bits/stdc++.h>
using namespace std;

int n,M,num;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    deque <int> dq;
    cin>>n>>M;
    for(int i=1;i<=n;i++) dq.push_back(i);
    int count=0,idx;
    while(M--){
        cin>>num;
        for(int i = 0; i < dq.size(); i++) {
            if(dq[i] == num ){
                idx = i;
                break;
            }
        }
        
        if(idx <= dq.size() / 2) {
            while(1) {
                if(dq.front() == num) {
                    dq.pop_front();
                    break;
                }
                ++count;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } 
        else { 
            while(1) {
                if(dq.front() == num) {
                    dq.pop_front();
                    break;
                }
                ++count;
                dq.push_front(dq.back());
                dq.pop_back();
            }
            
        }
    }
    cout<<count<<"\n";
}