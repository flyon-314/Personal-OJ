#include <bits/stdc++.h>

using namespace std;

char building[31][31][31];
int visited[31][31][31];
int dx[6]={1,0,-1,0,0,0};
int dy[6]={0,-1,0,1,0,0};
int dz[6]={0,0,0,0,1,-1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        int l,r,c;
        cin>>l>>r>>c;
        if(l==0 &&r==0&& c==0) return 0;
        queue <pair<int,pair<int,int>>> q;
        for(int k=0;k<l;k++){
            for(int j=0;j<r;j++){
                string s;
                cin>>s;
                for(int i=0;i<c;i++){
                    building[k][j][i]=s[i];
                    if(s[i]=='S') {
                        visited[k][j][i]=1;
                        q.push({k,{j,i}});
                    }
                }
            }
        }
        int count=0;
        bool check=false;
        while(!q.empty()){
            int s=q.size();
            for(int j=0;j<s;j++){
                pair<int,pair<int,int>> temp=q.front(); q.pop();
                for(int i=0;i<6;i++){
                    int nz=temp.first+dz[i];
                    int nx=temp.second.second+dx[i];
                    int ny=temp.second.first+dy[i];
                    if(building[nz][ny][nx]=='E'){
                        count++;
                        cout<<"Escaped in "<<count<<" minute(s).\n";
                        check=true;
                        break;
                    }
                    if(nz<0 ||nz>=l ||nx<0||nx>=c||ny<0||ny>=r) continue;
                    if(building[nz][ny][nx]=='#'||visited[nz][ny][nx]==1) continue;
                    visited[nz][ny][nx]=1;
                    q.push({nz,{ny,nx}});
                }
                if(check) break;
            }
            count++;
            if(check) break;
        }
        if(!check) cout<<"Trapped!\n";
        for(int k=0;k<l;k++){
            for(int j=0;j<r;j++){
                fill(building[k][j],building[k][j]+c,'0');
                fill(visited[k][j],visited[k][j]+c,0);
            }
        }
    }
}