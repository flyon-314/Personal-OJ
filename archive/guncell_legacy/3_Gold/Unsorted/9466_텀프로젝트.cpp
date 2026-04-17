#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX=100001;

int graph[MAX]={0,};
int visited[MAX]={0,};
int done[MAX]={0,};
int T,N,sol=0;
void DFS(int cur){
    int next=graph[cur];
    
    visited[cur]=1;
    
    if(visited[next]==0)
        DFS(next);
    else if(done[next]==0){
        for(int i=next;i!=cur;i=graph[i]){
            sol++;
        }
        sol++;
    }
    done[cur]=1;
}

int main() {
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=1;i<=N;i++){
            cin>>graph[i];
        }
        for(int i=1;i<=N;i++){
            if(visited[i]==0)
                DFS(i);
        }
        cout<<N-sol<<"\n";
        sol=0;
        memset(visited,0,sizeof(visited));
        memset(graph,0,sizeof(graph));
        memset(done,0,sizeof(done));
        
    }
}