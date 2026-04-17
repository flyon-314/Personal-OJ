#include <bits/stdc++.h>

using namespace std;

int dist[1000001];
int visited[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int f,s,g,u,d;
    queue <int> q;
    cin>>f>>s>>g>>u>>d;
    q.push(s);
    visited[s]=1;
    dist[s]=0;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            int temp=q.front();
            q.pop();
            int up=temp+u;
            int down=temp-d;
            if(up<=f&&visited[up]==0){
                visited[up]=1;
                dist[up]=dist[temp]+1;
                q.push(up);
            }
            if(down<=f &&down>=1 && visited[down]==0){
                visited[down]=1;
                 dist[down]=dist[temp]+1;
                q.push(down);
            }
        }
    }
    if(!visited[g]) cout<<"use the stairs";
    else cout<<dist[g];
}