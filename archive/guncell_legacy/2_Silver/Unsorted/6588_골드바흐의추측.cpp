#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int nArr[1000001];
    for(int i=2;i<=1000000;i++){
            nArr[i]=i;
    }
    for(int i=2;i<=sqrt(1000000);i++){
        if(nArr[i]==0)
            continue;
        for(int j=i*i;j<=1000000;j+=i){
            nArr[j]=0;
        }
    }
    while(n!=0){
        
        for(int i=2;i<=n;i++){
            if((nArr[i]+nArr[n-i])==n){
                cout<<n<<" = "<<nArr[i]<<" + "<<nArr[n-i]<<"\n";
                break;
            }
        }
        cin>>n;
    }
}