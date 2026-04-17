#include <iostream>
#include <vector>
int main() {
    int basket[100];
    int n,m;
    std::cin>>n>>m;
    for(int i=0;i<n;i++){
        basket[i]=i+1;
    }
    for(int y=0;y<m;y++){
        
        int i,j;
        int temp;
        std::cin>>i>>j;
        for(int x=0;i+x-1<j-x-1;++x){
            temp=basket[i+x-1];
            basket[i+x-1]=basket[j-x-1];
            basket[j-x-1]=temp;
        }
    }
    for(int i=0;i<n;i++){
        std::cout<<basket[i]<<" ";
    }
    
    return 0;
}