#include <bits/stdc++.h>

using namespace std;
int ice[301][301];
int visited[301][301];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    queue <pair<int,int>> q;
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            cin>>ice[i][j];
            if(ice[i][j]==0) q.push({i,j});
        }
    }
    int count=0;
    while(!q.empty()){
        count++;
        queue <pair<int,int>> ice_q;
        int s=q.size();
        int check=0;
        while(s--){
            pair <int,int> temp=q.front(); q.pop();
            for(int dir=0;dir<4;dir++){
                int nx=temp.second+dx[dir];
                int ny=temp.first+dy[dir];
                if(nx<0||nx>=m||ny<0||ny>=n||ice[ny][nx]==0)continue;
                if(ice[ny][nx]!=0){
                    ice[ny][nx]--;
                    if(ice[ny][nx]==0) q.push({ny,nx});
                }
            }
            q.push({temp.first,temp.second});
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ice[i][j]!=0 &&visited[i][j]==0){
                    if(check==1){
                        cout<<count;
                        return 0;
                    }
                    visited[i][j]=1;
                    ice_q.push({i,j});
                    while(!ice_q.empty()){
                        pair<int,int> temp=ice_q.front(); ice_q.pop();
                        for(int dir=0;dir<4;dir++){
                            int nx=temp.second+dx[dir];
                            int ny=temp.first+dy[dir];
                            if(nx<0||nx>=m||ny<0||ny>=n)continue;
                            if(visited[ny][nx]==1||ice[ny][nx]==0)continue;
                            visited[ny][nx]=1;
                            ice_q.push({ny,nx});
                        }
                    }
                    check++;
                }
            }
        }
        if(check==0){
            cout<<0;
            return 0;
        }
        for(int i=0;i<n;i++) fill(visited[i],visited[i]+m,0);
    }
}