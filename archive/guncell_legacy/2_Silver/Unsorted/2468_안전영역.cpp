#include <bits/stdc++.h>

using namespace std;

int arr[101][101];
int visited[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,high=0,sol=0;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
            high=max(high,arr[i][j]);
        }
    }
    for(int h=0;h<high;h++){
        
        queue <pair<int,int>> q;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]>h &&!visited[i][j]){
                    count++;
                    visited[i][j]=1;
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        pair <int,int> temp=q.front(); q.pop();
                        for(int dir=0;dir<4;dir++){
                            int nx=temp.second+dx[dir];
                            int ny=temp.first+dy[dir];
                            if(nx<0||nx>=n||ny<0||ny>=n)continue;
                            if(visited[ny][nx]==1||arr[ny][nx]<=h) continue;
                            visited[ny][nx]=1;
                            q.push(make_pair(ny,nx));
                        }
                    }
                }
                
            }
        }
        sol=max(sol,count);
        for(int i=0;i<n;i++) fill(visited[i],visited[i]+n,0);
    }
    cout<<sol;
}