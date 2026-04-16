#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T,N;
int graph[1001];
int visited[1001];

void DFS(int s){
    int node=graph[s];
    if(visited[node]==0){
        visited[node]=1;
        DFS(node);
    }       
}

int main() {
    cin>>T;
    
    while(T--){
        
        int count=0;
        cin>>N;
        for(int i = 1; i <= N ;i ++){
            cin>>graph[i];
        }
        
        for(int i = 1;i <= N ;i++){
            int node=graph[i];
            if(visited[node]==0){
                visited[node]=1;
                DFS(node);
                count++;
            }
        }
        
        memset(visited, 0, sizeof(visited));
        
        cout<<count<<"\n";
    }
    
    
}