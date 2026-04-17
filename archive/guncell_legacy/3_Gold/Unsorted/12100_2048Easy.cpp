#include <bits/stdc++.h>

using namespace std;

int board[21][21];
int n;
void func(vector <vector<int>> &temp,int dir){
    switch(dir){
        case 0:{
            for(int i=0;i<n;i++){
                vector<int> arr(n,0);
                int idx=0;
                for(int j=0;j<n;j++){
                    if(temp[i][j]==0)continue;
                    else{
                        if(arr[idx]==0) arr[idx]=temp[i][j];
                        else if(arr[idx]==temp[i][j])arr[idx++]=2*temp[i][j];
                        else arr[++idx]=temp[i][j];
                    }
                }
                for(int j=0;j<n;j++)temp[i][j]=arr[j];
            }
            break;
        }
        case 1:{
            for(int i=0;i<n;i++){
                vector<int> arr(n,0);
                int idx=n-1;
                for(int j=n-1;j>=0;j--){
                    if(temp[i][j]==0)continue;
                    else{
                        if(arr[idx]==0) arr[idx]=temp[i][j];
                        else if(arr[idx]==temp[i][j])arr[idx--]=2*temp[i][j];
                        else arr[--idx]=temp[i][j];
                    }
                }
                for(int j=0;j<n;j++)temp[i][j]=arr[j];
            }
            break;
            
        }
        case 2:{
            for(int i=0;i<n;i++){
                vector<int> arr(n,0);
                int idx=0;
                for(int j=0;j<n;j++){
                    if(temp[j][i]==0)continue;
                    else{
                        if(arr[idx]==0) arr[idx]=temp[j][i];
                        else if(arr[idx]==temp[j][i])arr[idx++]=2*temp[j][i];
                        else arr[++idx]=temp[j][i];
                    }
                }
                for(int j=0;j<n;j++)temp[j][i]=arr[j];
            }
            break;
            
        }
        case 3:{
            for(int i=0;i<n;i++){
                vector<int> arr(n,0);
                int idx=n-1;
                for(int j=n-1;j>=0;j--){
                    if(temp[j][i]==0)continue;
                    else{
                        if(arr[idx]==0) arr[idx]=temp[j][i];
                        else if(arr[idx]==temp[j][i])arr[idx--]=2*temp[j][i];
                        else arr[--idx]=temp[j][i];
                    }
                }
                for(int j=0;j<n;j++)temp[j][i]=arr[j];
            }
            break;
            
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int sol=0;
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>board[i][j];
    
    for(int tmp=0;tmp<(1<<(2*5));tmp++){
        vector <vector<int>> temp(n,vector <int>(n));
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) temp[i][j]=board[i][j];
        
        int brute=tmp;
        for(int i=0;i<5;i++){
            int dir=brute%4;
            brute/=4;
            func(temp,dir);
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) sol=max(sol,temp[i][j]);
    }
    
    cout<<sol;
    return 0;
}