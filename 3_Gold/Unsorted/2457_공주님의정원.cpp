#include <bits/stdc++.h>

using namespace std;
vector <pair<int,int>> v;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,s1,s2,e1,e2,count=0;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>s1>>s2>>e1>>e2;
        v.push_back(make_pair(s1*100+s2,e1*100+e2));
    }
    sort(v.begin(),v.end());
    
    int  cur=301,end=301;
    for(int i=0;i<n;i++){
        if(v[i].first<=cur ){
            if(v[i].second>1130) {
                cout<<++count;
                return 0;
            }
            else if(v[i].second>end) end=v[i].second;
        }
        else {
            cur=end;
            count++;
            if(v[i].first<=cur ){
                if(v[i].second>1130) {
                    cout<<++count;
                    return 0;
                }
                else if(v[i].second>end) end=v[i].second;
            }
        }
    }
    cout<<0;
    return 0;
}