#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int graph[101][101];
int visited[101][101]={0,};
int dx[4]={0, -1, 1, 0};
int dy[4]={1, 0, 0, -1};
int N;

struct miro {
    int y, x;
};
int BFS(int label){
    queue<miro> q;
    int sol = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(graph[i][j]==label){
                visited[i][j] = 1;
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        int Q=q.size();
        for(int i=0;i<Q;i++){
            int cur_x=q.front().x;
            int cur_y=q.front().y;
            q.pop();
            
            for(int j=0;j<4;j++){
                int next_x=cur_x+dx[j];
                int next_y=cur_y+dy[j];
                if(next_x>=0 &&next_y>=0 && next_x<N&&next_y<N){
                    if (graph[next_y][next_x]!=label && graph[next_y][next_x]!=0)
                        return sol;
                    else if(visited[next_y][next_x]==0 && graph[next_y][next_x]==0){
                        q.push({next_y,next_x});
                        visited[next_y][next_x]=1;
                    }
                }
            }
        }
        sol++;
    }
}

void land(int y,int x,int label){
    queue <miro> l;
    l.push({y,x});
    while(!l.empty()){
        miro temp=l.front();
        visited[temp.y][temp.x]=1;
        graph[temp.y][temp.x]=label;
        l.pop();
        for(int i=0;i<4;i++){
            int next_y=temp.y+dy[i];
            int next_x=temp.x+dx[i];
            if(visited[next_y][next_x]==0&&graph[next_y][next_x]==-1 && next_x>=0 &&next_y>=0 && next_x<N&&next_y<N){
                l.push({next_y,next_x});
                graph[next_y][next_x]=label;
            }
        }
    }
    
}
int main() {
    string str;
    cin>>N;
    int sol=99999;
    int l_num=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            
            cin>>graph[i][j];
            if(graph[i][j]==1)
                graph[i][j]=-1;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(graph[i][j]==-1&&visited[i][j]==0){
                land(i,j,l_num);
                l_num++;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(graph[i][j]==-1&&visited[i][j]==0){
                land(i,j,l_num);
                l_num++;
            }
        }
    }
    memset(visited,0,sizeof(visited));
    for(int i=1;i<=l_num-1;i++){
        sol=min(sol,BFS(i));
        memset(visited,0,sizeof(visited));
        
    }
    cout<<sol;
    
}