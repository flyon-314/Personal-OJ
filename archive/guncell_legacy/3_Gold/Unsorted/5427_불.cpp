#include <bits/stdc++.h>

using namespace std;

string str[1001];
int f_visited[1001][1001];
int j_visited[1001][1001];
int f_dist[1001][1001];
int j_dist[1001][1001];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int w,h;
queue <pair<int,int>> fq;
queue <pair<int,int>> jq;
void j_bfs(){
    while(!jq.empty()){
        pair <int,int> temp=jq.front(); jq.pop();
        for(int dir=0;dir<4;dir++){
            int ny=temp.first+dy[dir];
            int nx=temp.second+dx[dir];
            if(ny<0||ny>=h||nx<0||nx>=w){
                cout<<j_dist[temp.first][temp.second]+1<<"\n";
                return;
            }
            if(j_visited[ny][nx]!=0 ||j_dist[ny][nx]!=-1||str[ny][nx]=='#') continue;
            if(f_dist[ny][nx]!=-1 &&f_dist[ny][nx]<=j_dist[temp.first][temp.second]+1) continue;
            j_dist[ny][nx]=j_dist[temp.first][temp.second]+1;
            j_visited[ny][nx]=1;
            jq.push(make_pair(ny,nx));
        }
    }
    cout<<"IMPOSSIBLE"<<"\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin>>t;
    
    
    while(t--){
        cin>>w>>h;
        fq=queue<pair<int, int>>();
        jq=queue<pair<int, int>>();
        for(int i=0;i<1001;i++){
            fill(f_visited[i],f_visited[i]+1000,0);
            fill(j_visited[i],j_visited[i]+1000,0);
            fill(f_dist[i],f_dist[i]+1000,-1);
            fill(j_dist[i],j_dist[i]+1000,-1);
        }
        
        for(int i=0;i<h;i++){
            cin>>str[i];
        }
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(str[i][j]=='*') {
                    f_dist[i][j]=0;
                    f_visited[i][j]=1;
                    fq.push(make_pair(i,j));
                }
                else if (str[i][j]=='@') {
                    j_dist[i][j]=0;
                    j_visited[i][j]=1;
                    jq.push(make_pair(i,j));
                }
            }
        }
        
        while(!fq.empty()){
            pair <int,int> temp=fq.front(); fq.pop();
            for(int dir=0;dir<4;dir++){
                int ny=temp.first+dy[dir];
                int nx=temp.second+dx[dir];
                if(ny<0||ny>=h||nx<0||nx>=w)continue;
                if(f_visited[ny][nx]!=0 ||f_dist[ny][nx]!=-1||str[ny][nx]=='#') continue;
                f_dist[ny][nx]=f_dist[temp.first][temp.second]+1;
                f_visited[ny][nx]=1;
                fq.push(make_pair(ny,nx));
            }
        }
        
        j_bfs();
        
    }
}