#include <iostream>
const int MIN=-1001;
using namespace std;

int main() {
    int n;
    int sequence[100001];
    int sol=MIN;
    int sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>sequence[i];
    }
    for(int i=1;i<=n;i++){
        sum=max(sum+sequence[i],sequence[i]);
        sol=max(sum,sol);
        
    }
    cout<<sol;
    
}