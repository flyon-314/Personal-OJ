#include <bits/stdc++.h>

using namespace std;

int laptop[41][41];
int n,m,k,r,c;

vector<vector<int>> rotated(vector<vector<int>> matrix){
    int m = matrix.size();         
    int n = matrix[0].size();
    
    vector<vector<int>> rotate(n,vector<int>(m));
   for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            rotate[j][m-1-i] = matrix[i][j];
        }
    }
    return rotate;
}
void del(int k){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(laptop[i][j]==k) laptop[i][j]=0;
        }
    }
}
bool sticker(vector<vector<int>> stick,int y,int x, int k){
    if(y+stick.size()-1>=n ||x+stick[0].size()-1>=m) return false;
    for(int i=0;i<stick.size();i++){
        for(int j=0;j<stick[0].size();j++){
            if(laptop[y+i][x+j]==0){
                if(stick[i][j]==1) laptop[y+i][x+j]=k;
            }
            else if(laptop[y+i][x+j]!=0&&stick[i][j]==1) {
                del(k);
                return false;
            }
        }
    }
       
    return true;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m>>k;
    
    for(int t=1;t<=k;t++){
        vector<vector<int>> matrix;
        cin>>r>>c;
        for(int i=0;i<r;i++){
            vector<int> temp;
            for(int j=0;j<c;j++){
                int p;
                cin>>p; temp.push_back(p);
            }
            matrix.push_back(temp);
        }
        bool flag=false;
        for(int d=0;d<4;d++){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(sticker(matrix,i,j,t)){
                        flag=true;
                        break;
                    }
                    else del(t);
                }
                if(flag)break;
            }
            if(flag)break;
            else matrix=rotated(matrix);
        }
        
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) if(laptop[i][j]!=0)count++;
    }
    cout<<count;
    
}