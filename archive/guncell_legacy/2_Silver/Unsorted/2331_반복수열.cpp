#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int A,P;
int visited[1000000];

int calc(int a){
    int sum=0;
    while(a>0){
        sum=sum+(int)(pow(a%10,P));
        a/=10;
    }
    
    return sum;
}

void DFS(int s){
    visited[s]++;
    if(visited[s] > 2) return;
    DFS(calc(s));
}

int main() {
    int count=0;
    int sum=0;
    
    cin>>A>>P;
    DFS(A);
    
    for(int i=1;i<1000000;i++){
        if(visited[i]==1)
            count++;
    }
    cout<<count;
    
    
    
}