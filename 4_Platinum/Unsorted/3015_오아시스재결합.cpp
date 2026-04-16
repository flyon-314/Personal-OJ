#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long N,sol[500001],sum=0;
    cin>>N;
    long long num;
    stack <pair<long long,long long>> human;
    for(int i=0;i<N;i++){
        long long cnt=1;
        cin>>num;
        while(!human.empty()&&human.top().second<=num){
            if(human.top().second==num) cnt+=human.top().first;
            sum+=human.top().first;
            human.pop();
        }
        if(!human.empty()&&human.top().second>num) {
            sum++;
        }
        human.push(make_pair(cnt,num));
    }
    cout<<sum;
}