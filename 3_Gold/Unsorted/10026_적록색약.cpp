#include <bits/stdc++.h>

using namespace std;

string str[101];
int visited[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n;

int BFS(){
    int r_count=0,b_count=0,g_count=0;
    queue <pair<int,int>> q;
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==0){
                if(str[i][j]=='R'){
                    r_count++;
                    visited[i][j]=1;
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        pair<int,int> temp=q.front();
                        q.pop();
                        for(int i=0;i<4;i++){
                            int ny=temp.first+dy[i];
                            int nx=temp.second+dx[i];
                            if(ny<0||ny>=n||nx<0||nx>=n) continue;
                            if(str[ny][nx]!='R'||visited[ny][nx]==1)continue;
                            visited[ny][nx]=1;
                            q.push(make_pair(ny,nx));
                        }
                    }
                }
                else if(str[i][j]=='B'){
                    b_count++;
                    visited[i][j]=1;
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        pair<int,int> temp=q.front();
                        q.pop();
                        for(int i=0;i<4;i++){
                            int ny=temp.first+dy[i];
                            int nx=temp.second+dx[i];
                            if(ny<0||ny>=n||nx<0||nx>=n) continue;
                            if(str[ny][nx]!='B'||visited[ny][nx]==1)continue;
                            visited[ny][nx]=1;
                            q.push(make_pair(ny,nx));
                        }
                    }
                }
                else{
                    g_count++;
                    visited[i][j]=1;
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        pair<int,int> temp=q.front();
                        q.pop();
                        for(int i=0;i<4;i++){
                            int ny=temp.first+dy[i];
                            int nx=temp.second+dx[i];
                            if(ny<0||ny>=n||nx<0||nx>=n) continue;
                            if(str[ny][nx]!='G'||visited[ny][nx]==1)continue;
                            visited[ny][nx]=1;
                            q.push(make_pair(ny,nx));
                        }
                    }
                }
                
            }
        }
    }
    return r_count+b_count+g_count;
}
int RG_BFS(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r_count=0,b_count=0;
    queue <pair<int,int>> q;
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==0){
                if(str[i][j]=='R'||str[i][j]=='G'){
                    r_count++;
                    visited[i][j]=1;
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        pair<int,int> temp=q.front();
                        q.pop();
                        for(int i=0;i<4;i++){
                            int ny=temp.first+dy[i];
                            int nx=temp.second+dx[i];
                            if(ny<0||ny>=n||nx<0||nx>=n) continue;
                            if(!(str[ny][nx]=='R'||str[ny][nx]=='G')||visited[ny][nx]==1)continue;
                            visited[ny][nx]=1;
                            q.push(make_pair(ny,nx));
                        }
                    }
                }
                
                else if(str[i][j]=='B'){
                    b_count++;
                    visited[i][j]=1;
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        pair<int,int> temp=q.front();
                        q.pop();
                        for(int i=0;i<4;i++){
                            int ny=temp.first+dy[i];
                            int nx=temp.second+dx[i];
                            if(ny<0||ny>=n||nx<0||nx>=n) continue;
                            if(str[ny][nx]!='B'||visited[ny][nx]==1)continue;
                            visited[ny][nx]=1;
                            q.push(make_pair(ny,nx));
                        }
                    }
                }
                
            }
        }
    }
    return r_count+b_count;
}
int main() {
    
    cin>>n;
    for(int i=0;i<n;i++) cin>>str[i];
    cout<<BFS()<<" ";
    for(int i=0;i<101;i++) fill(visited[i],visited[i]+100,0);
    cout<<RG_BFS();
}