#include <bits/stdc++.h>

using namespace std;

int board[501][501];
int visited[501][501];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m;

int bfs(int y,int x){
    if(visited[y][x]==0) visited[y][x]=1;
    int width=0;
    queue <pair<int,int>> q;
    q.push(make_pair(y,x));
    width++;
    while(!q.empty()){
        pair<int,int> temp=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int next_y=temp.first+dy[i];
            int next_x=temp.second+dx[i];
            if(next_y<0||next_y>=n ||next_x<0||next_x>m) continue;
            if(visited[next_y][next_x]==1 || board[next_y][next_x]!=1) continue;
            visited[next_y][next_x]=1;
            q.push(make_pair(next_y,next_x));
            width++;
        }
    }
    return width;
    
    
}
int main() {
    int count=0;
    int width=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>board[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            if(visited[i][j]==0 && board[i][j]==1){
                count++;
                visited[i][j]=1;
                width=max(width,bfs(i,j)) ;
            }
        }
    }
    cout<<count<<"\n"<<width;
    
}