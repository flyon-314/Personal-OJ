#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long N,C;
    long long tmp,sol=0;
    vector <long long> v;
    cin>>N>>C;
    for(int i=0;i<N;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    long long left=0,right=v[N-1],mid;
    
    while(left<=right){
        mid=(left+right)/2;
        long long count=1;
        long long x1=v[0];
        for(long i=1;i<N;i++){
            if(v[i]-x1>=mid){
                count++;
                x1=v[i];
            }
        }
        if(count>=C){
            left=mid+1;
            sol=max(sol,mid);
        }
        else
            right=mid-1;
    }
    cout<<sol;
}