#include <bits/stdc++.h>

using namespace std;

int monkey[201][201];
int vistied[201][201][31];
int dx[12]={1,0,-1,0,2,1,-1,-2,-2,-1,1,2};
int dy[12]={0,-1,0,1,-1,-2,-2,-1,1,2,2,1};
int main() {
    int w,h,k;
    cin>>k>>w>>h;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)cin>>monkey[i][j];
    }
    queue <pair<int,pair<int,int>>> q;
    q.push({0,{0,0}});
    int count=0;
    while(!q.empty()){
        if(q.front().second.second==w-1 && q.front().second.first==h-1) {
            cout<<count;
            return 0;
        }
        int s=q.size();
        count++;
        while(s--){
            pair<int,pair<int,int>> temp=q.front(); q.pop();
            temp.first++;
            for(int dir=0;dir<12;dir++){
                if(dir>=4&& temp.first>k) break;
                int nx=temp.second.second+dx[dir];
                int ny=temp.second.first+dy[dir];
                if(nx==w-1 && ny==h-1) {
                    cout<<count;
                    return 0;
                }
                if(nx<0||nx>=w||ny<0||ny>=h)continue;
                if(dir<4){
                    if(vistied[ny][nx][temp.first-1]!=0||monkey[ny][nx]!=0) continue;
                    vistied[ny][nx][temp.first-1]=1;
                    q.push({temp.first-1,{ny,nx}});
                }
                if(dir>=4){
                    if(vistied[ny][nx][temp.first]!=0||monkey[ny][nx]!=0) continue;
                    vistied[ny][nx][temp.first]=1;
                    q.push({temp.first,{ny,nx}});
                }
                
            }
        }
    }
    cout<<-1;
    
    return 0;
}