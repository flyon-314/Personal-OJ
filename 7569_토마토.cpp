#include <bits/stdc++.h>

using namespace std;

int dist[101][101][101];
int visited[101][101][101];
int sol=0;
int n,m,h;
int dx[6]={1,0,-1,0,0,0};
int dy[6]={0,-1,0,1,0,0};
int dz[6]={0,0,0,0,-1,1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    queue <pair<pair<int,int>,int>> q;
    cin>>m>>n>>h;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin>>dist[i][j][k];
                if(dist[i][j][k]==1){
                    q.push(make_pair(make_pair(i,j),k));
                    visited[i][j][k]=1;
                }
            }
        }
    }
    while(!q.empty()){
        sol++;
        int size=q.size();
        for(int i=0;i<size;i++){
            pair<pair<int,int>,int> temp=q.front();
            q.pop();
            for(int dir=0;dir<6;dir++){
                int nz=temp.first.first+dz[dir];
                int ny=temp.first.second+dy[dir];
                int nx=temp.second+dx[dir];
                if(ny<0||ny>=n||nx<0||nx>=m||nz<0||nz>=h) continue;
                if(visited[nz][ny][nx] ==1 ||dist[nz][ny][nx]!=0)continue;
                visited[nz][ny][nx]=1;
                dist[nz][ny][nx]=1;
                q.push(make_pair(make_pair(nz,ny),nx));
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(dist[i][j][k]==0){
                    cout<<-1;
                    return 0;
                }
            }
        }
    }
    cout<<sol-1;
}