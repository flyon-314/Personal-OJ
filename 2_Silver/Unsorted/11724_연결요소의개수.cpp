#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int graph[1001][1001];
int visited[1001];
int N,M;
queue <int> q;

int DFS(int s){
    
    for(int i = 1 ; i <= N ; i++){
        if(graph[s][i] &&visited[i]==0){
            visited[i]=1;
            DFS(i);
        }
    }
    return 1;
}
int main() {
    
    int a,b;
    int count=0;
    cin>>N>>M;
    
    for(int i = 0 ; i < M ; i++){
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    
    for(int i = 1 ; i <=N ; i++){
        
        if(visited[i]==0)
            count+=DFS(i);
        visited[i]=1;
    }
    cout<<count;
    
    
}