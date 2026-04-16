#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int graph[51][51];
int visited[51][51]={0,};
int dx[8]={0, -1, 1, 0, -1, 1, -1, 1};
int dy[8]={1, 0, 0, -1, 1, 1, -1, -1};
int W=1,H=1,cou=0;
string str;

void reasearch(int cur_y,int cur_x){
    visited[cur_y][cur_x]=1;
    for(int i=0;i<8;i++){
        int next_x=cur_x+dx[i];
        int next_y=cur_y+dy[i];
        if(visited[next_y][next_x]==0 && next_x<=W && next_y<=H && graph[next_y][next_x]==1){
            reasearch(next_y,next_x);
            cou++;
        }
            
    }
}

int main() {
    while(W!=0 && H!=0){
        int i_count=0;
        cin>>W>>H;
    
        visited[0][0]=1;
        for(int i=1;i<=H;i++){
            visited[i][0]=1;
        }
        for(int i=1;i<=W;i++){
            visited[0][i]=1;
        }
        
        for(int i=1;i<=H;i++){
            for(int j=1;j<=W;j++){
                 cin>>graph[i][j];
            }
        }
    
        for(int i=1;i<=H;i++){
          for(int j=1;j<=W;j++){
            if(visited[i][j]==0 &&graph[i][j]==1){
                reasearch(i,j);
                i_count++;
            }
          }
                   
        }
        if(W!=0 &&H!=0){
            cout<<i_count<<"\n";
            memset(visited,0,sizeof(visited));
            memset(graph,0,sizeof(graph));
        }
        
        
    }
}