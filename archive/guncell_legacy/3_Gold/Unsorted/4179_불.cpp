#include <bits/stdc++.h>

using namespace std;

queue <pair<int,int>> fq;
queue <pair<int,int>> jq;
string str[1001];
int jihoon[1001][1001];
int fire[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;

void f_bfs(){
    while(!fq.empty()){
        pair<int,int> temp=fq.front();
        fq.pop();
        for(int i=0;i<4;i++){
            int nx=temp.first+dx[i];
            int ny=temp.second+dy[i];
            if(nx<0 ||nx>=n||ny<0||ny>=m) continue;
            if(str[nx][ny]=='#' || fire[nx][ny]>=0) continue;
            fire[nx][ny]=fire[temp.first][temp.second]+1;
            fq.push(make_pair(nx,ny));
        }
    }
}
void j_bfs(){
    while(!jq.empty()){
        pair<int,int> temp=jq.front();
        jq.pop();
        for(int i=0;i<4;i++){
            int nx=temp.first+dx[i];
            int ny=temp.second+dy[i];
            if(nx<0|| nx>=n||ny<0||ny>=m){
                cout<<jihoon[temp.first][temp.second]+1;
                return;
            }
            if(str[nx][ny]=='#' || jihoon[nx][ny]>=0) continue;
            if(fire[nx][ny]!=-1 &&fire[nx][ny]<=jihoon[temp.first][temp.second]+1) continue;
            jihoon[nx][ny]=jihoon[temp.first][temp.second]+1;
            jq.push(make_pair(nx,ny));
        }
    }
    cout<<"IMPOSSIBLE";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>> n >> m;
    for(int i=0;i<n;i++){
        fill(jihoon[i],jihoon[i]+m,-1);
        fill(fire[i],fire[i]+m,-1);
    }
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(str[i][j]=='F'){
                fq.push(make_pair(i,j));
                fire[i][j]=0;
            }
            if(str[i][j]=='J'){
                jq.push(make_pair(i,j));
                jihoon[i][j]=0;
            }
        }
    }
    
    f_bfs();
    j_bfs();
    return 0;
}