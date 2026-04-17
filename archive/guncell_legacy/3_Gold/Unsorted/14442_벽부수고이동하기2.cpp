#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int wall[1001][1001];
bool visited[11][1001][1001];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        for(int j=0;j<m;j++) {
            wall[i][j]=str[j]-'0';    
        }
    }
    queue <pair<int,pair<int,int>>> q;
    int count=1;
    visited[0][0][0]=true;
    q.push({0,{0,0}});
    while(!q.empty()){
        int s=q.size();
        for(int i=0;i<s;i++){
            pair<int,pair<int,int>> temp=q.front(); q.pop();
            if(temp.second.first==n-1&&temp.second.second==m-1){
                cout<<count;
                return 0;
            }
            
            for(int dir=0;dir<4;dir++){
                int nx=temp.second.second+dx[dir];
                int ny=temp.second.first+dy[dir];
                if(nx<0||ny<0||ny>=n||nx>=m)continue;
                if(wall[ny][nx]==1){
                    if(temp.first>=k) continue;
                    if(visited[temp.first+1][ny][nx]==true)continue;
                    visited[temp.first+1][ny][nx]=true;
                    q.push({temp.first+1,{ny,nx}});
                }
                else{
                    if(visited[temp.first][ny][nx])continue;
                    visited[temp.first][ny][nx]=true;
                    q.push({temp.first,{ny,nx}});
                }
            }
        }
        count++;
    }
    cout<<-1;
}