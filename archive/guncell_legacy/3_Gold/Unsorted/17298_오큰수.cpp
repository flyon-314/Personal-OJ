#include <bits/stdc++.h>

using namespace std;

int main() {
    int N,sol[1000001];
    cin>>N;
    int num;
    stack <pair<int,int>> NGE;
    for(int i=0;i<N;i++){
        cin>>num;
        while(!NGE.empty() && NGE.top().second<num){
            sol[NGE.top().first]=num;
            NGE.pop();
            if(NGE.empty())
                break;
        }
        NGE.push(make_pair(i,num));
    }
    while(!NGE.empty()){
        sol[NGE.top().first]=-1;
        NGE.pop();
    }
    for(int i=0;i<N;i++) cout<<sol[i]<<" ";
}