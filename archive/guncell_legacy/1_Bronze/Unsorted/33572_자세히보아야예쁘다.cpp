#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int N;
    long long M;

    cin >> N >> M;

    long long sol =0;
    for (int i = 0 ; i < N ; i++){
        int temp;
        cin >> temp;
        sol += temp;
    }
    sol -= N;
    cout << (M <= sol ? "DIMI" : "OUT"); 

}