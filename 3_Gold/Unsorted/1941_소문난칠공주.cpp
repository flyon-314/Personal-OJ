#include<bits/stdc++.h>

using namespace std;
bool mask[25];
int ans;
string name[5];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0;i<5;i++)cin>>name[i];
    fill(mask+7,mask+25,true);
    do{
        queue <pair<int,int>> q;
        bool vis[5][5]={},pri[5][5]={};
        int cnt=0,som=0;
        for(int i=0;i<25;i++){
            if(!mask[i]){
                int y=i/5 , x=i%5;
                pri[y][x]=true;
                if(q.empty()){
                    q.push({y,x});
                    vis[y][x]=true;
                }
            }
        }
        while(!q.empty()){
            pair<int,int> temp=q.front(); q.pop();
            if(name[temp.first][temp.second]=='S')som++;
            cnt++;
            for(int dir=0;dir<4;dir++){
                int nx=temp.second+dx[dir];
                int ny=temp.first+dy[dir];
                if(ny<0||ny>=5||nx<0||nx>=5)continue;
                if(vis[ny][nx]||!pri[ny][nx])continue;
                vis[ny][nx]=true;
                q.push({ny,nx});
            }
        }
        ans+=(cnt>=7&&som>=4);
    }while(next_permutation(mask,mask+25));
    cout<<ans;
}