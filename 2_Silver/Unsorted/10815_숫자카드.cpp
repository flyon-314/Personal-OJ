#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,M;
vector <int> s_v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int temp;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>temp;
        s_v.push_back(temp);
    }
    sort(s_v.begin(),s_v.end());
    cin>>M;
    while(M--){
        cin>>temp;
        int left=0;
        int right=N-1;
        int mid,sol=1;
        while(left<=right){
            mid=(left+right)/2;
            
            if(s_v[mid]==temp){
                cout<<"1"<<" ";
                sol=0;
                break;
            }
                
            else if(s_v[mid]<temp)
                left=mid+1;
            else
                right=mid-1;
        }
        if(sol)
            cout<<"0"<<" ";
        
    }
    
    
}