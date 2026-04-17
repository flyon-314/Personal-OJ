#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector <int> A;
    vector <int> B;
    int N,M,temp,A_num=0,B_num=0;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>temp;
        A.push_back(temp);
    }
    for(int i=0;i<M;i++){
        cin>>temp;
        B.push_back(temp);
    }
    while(A_num<N && B_num<M){
        if(A[A_num]<B[B_num])
            cout<<A[A_num++]<<" ";
        else
            cout<<B[B_num++]<<" ";
    }
    while(A_num<N){
        cout<<A[A_num++]<<" ";
    }
    while(B_num<M){
        cout<<B[B_num++]<<" ";
    }
}