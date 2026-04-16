#include <bits/stdc++.h>

using namespace std;

int dist[101][101];
int vistied[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int m,n,k;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x1,y1,x2,y2;
    int count=0;
    int area;
    vector<int> square;
    queue <pair<int,int>> q;
    cin>>n>>m>>k;
    while(k--){
        cin>>x1>>y1>>x2>>y2;
        for(int i=y1;i<y2;i++){
            for(int j=x1;j<x2;j++){
                dist[i][j]=1;
                vistied[i][j]=1;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist[i][j]==0 &&vistied[i][j]==0){
                vistied[i][j]=1;
                q.push(make_pair(i,j));
                count++;
                area=0;
                while(!q.empty()){
                    area++;
                    pair <int,int> temp=q.front(); 
                    q.pop();
                    for(int dir=0;dir<4;dir++){
                        int ny=temp.first+dy[dir];
                        int nx=temp.second+dx[dir];
                        if(nx<0||nx>=m||ny<0||ny>=n) continue;
                        if(vistied[ny][nx]==1||dist[ny][nx]==1)continue;
                        vistied[ny][nx]=1;
                        q.push(make_pair(ny,nx));
                    }
                }
                square.push_back(area);
            }
        }
    }
    sort(square.begin(),square.end());
    cout<<count<<"\n";
    for(int i=0;i<square.size();i++) cout<<square[i]<<" ";
}
