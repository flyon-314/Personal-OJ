#include <iostream>

using namespace std;

int main() {
    int student[7][2]={};
    int N,K;
    int S,Y,count=0;
    cin>>N>>K;
    for(int i=0;i<N;i++) {
        cin>>S>>Y;
        student[Y][S]++;
    }
    for(int i=0;i<2;i++){
        for(int j=1;j<7;j++){
            while(student[j][i]>0){
                count++;
                student[j][i]-=K;
            }
        }
    }
    cout<<count;
}