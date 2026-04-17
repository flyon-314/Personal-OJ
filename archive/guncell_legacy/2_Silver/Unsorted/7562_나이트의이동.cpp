#include <bits/stdc++.h>

using namespace std;

int visited[301][301];
int l,cur_x,cur_y,tar_x,tar_y;
int dx[8]={2,1,-1,-2,-2,-1,1,2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin>>t;
    
    while(t--){
        int sol=0;
        queue <pair<int,int>> q;
        for(int i=0;i<301;i++) fill(visited[i],visited[i]+300,0);
        
        cin>>l;
        cin>>cur_y>>cur_x;
        cin>>tar_y>>tar_x;
        if(cur_y==tar_y&&cur_x==tar_x){
            cout<<"0\n";
            continue;
        }
        
        q.push(make_pair(cur_y,cur_x));
        visited[cur_y][cur_x]=1;
        
        while(visited[tar_y][tar_x]==0){
            int size=q.size();
            for(int j=0;j<size;j++){
                pair<int,int> temp=q.front(); q.pop();
                for(int i=0;i<8;i++){
                    int ny=temp.first+dy[i];
                    int nx=temp.second+dx[i];
                    if(ny<0 || ny>=l || nx<0 || nx>=l)continue;
                    if(visited[ny][nx]!=0)continue;
                    visited[ny][nx]=1;
                    q.push(make_pair(ny,nx));
                }
            }
            sol++;
        }
        cout<<sol<<"\n";
        
    }
}