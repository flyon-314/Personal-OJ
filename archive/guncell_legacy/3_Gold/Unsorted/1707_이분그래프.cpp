#include <iostream>
#include <vector>
#include <cstring>

#define RED 2
#define BLUE 3

using namespace std;

int K,V,E;
int visited[20001];
vector<int> graph[20001];

void DFS(int s){
    if (visited[s] == 0)
        visited[s] = RED;
    for(int i = 0 ; i < graph[s].size() ; i++){
        
        if(visited[graph[s][i]]==0){
            if(visited[s]==RED)
                visited[graph[s][i]]=BLUE;
                
            else if(visited[s]==BLUE)
                visited[graph[s][i]]=RED;
                
            DFS(graph[s][i]);
        }
    
        
    }

    
}
bool check(){
    for(int i = 1 ; i <= V ; i++ ){
        
        for(int j = 0 ; j < graph[i].size() ;j++){
            if(visited[i]==visited[graph[i][j]])
                return false;
            
        }
        
    }
    return true;
    
}
int main() {
    cin>>K;
    
    while (K--){
        cin>>V>>E;
        
        for(int i = 0 ; i < E; i++){
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for(int i = 1 ; i <= V ; i++ ){
            if(visited[i]==0){
                visited[i]=RED;
                DFS(i);
            }
            
        }
        
        if(check())
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";
            
        memset(visited, 0, sizeof(visited));
        memset(graph, 0, sizeof(graph));
    }
    
}