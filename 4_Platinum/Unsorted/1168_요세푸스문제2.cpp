#include <iostream>

using namespace std;

int segment[300001];
int init(int s,int e,int node){
    if(s==e)
        return segment[node]=1;
    int mid=(s+e)/2;
    return segment[node]=init(s,mid,node*2)+init(mid+1,e,node*2+1);
}
int get_num(int s,int e,int node,int idx){
    segment[node]--;
    if(s==e)
        return s;
    int mid=(s+e)/2;
    if(idx<segment[2*node]) return get_num(s,mid,node*2,idx);
    else return get_num(mid+1,e,node*2+1,idx-segment[2*node]);
}
int main() {
    int n,k;
    
    cin>>n>>k;
    int idx=k-1;
    init(1,n,1);
    cout<<"<";
    for(int i=1;i<=n;i++){
        int num=get_num(1,n,1,idx);
        if(i!=n) cout<<num<<", ";
        else cout<<num;
        if (segment[1] == 0)
			break;
        idx += k - 1;
		idx %= segment[1];
    }
    cout<<">";
}