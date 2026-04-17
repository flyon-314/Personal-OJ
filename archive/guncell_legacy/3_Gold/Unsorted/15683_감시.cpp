#include <bits/stdc++.h>

using namespace std;
int arr[10][10];
int board[10][10];
int n,m,wall;
int anl=999999999;
vector <pair<int,pair<int,int>>> cctv;
void ser(int k,int num,int x,int y){
    switch(k)
    {
        case 0:
        {
            for(int i=x;i<m;i++){
                if(arr[y][i]==6)break;
                else if(board[y][i]!=0) continue;
                board[y][i]=num;
            }
            break;
        }
        case 1:
        {
            for(int i=y;i>=0;i--) {
                if(arr[i][x]==6)break;
                else if(board[i][x]!=0) continue;
                board[i][x]=num;
            }
            break;
        }
        case 2:
        {
            
            for(int i=x;i>=0;i--) {
                if(arr[y][i]==6)break;
                else if(board[y][i]!=0) continue;
                board[y][i]=num;
            }
            break;
        }
        case 3:
        {
            for(int i=y;i<n;i++){
                if(arr[i][x]==6)break;
                else if(board[i][x]!=0) continue;
                board[i][x]=num;
            }
            break;
        }
    }
    return ;
}
void del(int num){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==num) board[i][j]=0;
        }
    }
    return;
}
void func(int k){
    if(k==cctv.size()){
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==0) cnt++;
            }
        }
        cnt-=wall;
        anl=min(anl,cnt);
        return ;
    }
    switch(cctv[k].first)
    {
        case 1:
        {
            for(int i=0;i<4;i++){
                ser(i,k+1,cctv[k].second.second,cctv[k].second.first);
                func(k+1);
                del(k+1);
            }
            break;
        }
        case 2:
        {
            for(int i=0;i<2;i++){
                ser(i,k+1,cctv[k].second.second,cctv[k].second.first);
                ser(i+2,k+1,cctv[k].second.second,cctv[k].second.first);
                func(k+1);
                del(k+1);
                
            }
            break;
        }
        case 3:
        {
            for(int i=0;i<4;i++){
                ser(i%4,k+1,cctv[k].second.second,cctv[k].second.first);
                ser((i+1)%4,k+1,cctv[k].second.second,cctv[k].second.first);
                func(k+1);
                del(k+1);
            }
            break;
        }
        case 4:
        {
            for(int i=0;i<4;i++){
                ser(i,k+1,cctv[k].second.second,cctv[k].second.first);
                ser((i+1)%4,k+1,cctv[k].second.second,cctv[k].second.first);
                ser((i+2)%4,k+1,cctv[k].second.second,cctv[k].second.first);
                func(k+1);
                del(k+1);
            }
            break;
        }
        case 5:
        {
            ser(0,k+1,cctv[k].second.second,cctv[k].second.first);
            ser(1,k+1,cctv[k].second.second,cctv[k].second.first);
            ser(2,k+1,cctv[k].second.second,cctv[k].second.first);
            ser(3,k+1,cctv[k].second.second,cctv[k].second.first);
            func(k+1);
            del(k+1);
            break;
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]>=1 &&arr[i][j]<=5){
                cctv.push_back({arr[i][j],{i,j}});
            }
            else if(arr[i][j]==6) {
                wall++;
            }
        }
    }
    func(0);
    cout<<anl;
}