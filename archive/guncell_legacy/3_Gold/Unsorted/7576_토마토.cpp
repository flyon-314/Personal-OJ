#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int graph[1001][1001];
int visited[51][51]={0,};
int dx[4]={0, -1, 1, 0};
int dy[4]={1, 0, 0, -1};
int M,N,cou=0;

struct tomato {
    int y, x;
};
queue<tomato> q;
void BFS(){
    while(!q.empty()){
        tomato cur=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int next_y=cur.y+dy[i];
            int next_x=cur.x+dx[i];
            if(graph[next_y][next_x]==0 && next_x>=0 &&next_y>=0 && next_x<M&&next_y<N){
                q.push({next_y,next_x});
                graph[next_y][next_x]=graph[cur.y][cur.x]+1;
            }
        }
    }
    
}

int main() {
    int sol=0;
    cin>>M>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>graph[i][j];
            if(graph[i][j]==1)
                q.push({i,j});
        }
    }
    BFS();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(graph[i][j]==0){
                cout<<"-1";
                return 0;
            }
            sol=max(sol,graph[i][j]);
        }
    }
    cout<<sol-1;
}