#include <iostream>
#include<cmath>
using namespace std;

int main() {
	long long a, b ;
	cin >> a >> b;
	long long sol=1;
	long long sml=min(a,b);
	long long big=max(a,b);
	while(big%sml!=0){
	    long long tmp=big;
	    big=sml;
	    sml=tmp%sml;
	    
	}
	for(int i=0;i<sml;i++){
	    cout<<1;
	}
	

}