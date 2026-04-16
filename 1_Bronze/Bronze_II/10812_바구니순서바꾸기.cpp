#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> baskets(N);
    
    for (int i = 0; i < N; i++) {
        baskets[i] = i + 1;
    }
    
    for (int i = 0; i < M; i++) {
        int start, end, mid;
        cin >> start >> end >> mid;
        
        start--; end--; mid--;
        
        vector<int> temp;
        
        for (int j = mid; j <= end; j++) {
            temp.push_back(baskets[j]);
        }
        
        for (int j = start; j < mid; j++) {
            temp.push_back(baskets[j]);
        }
        
        for (int j = start; j <= end; j++) {
            baskets[j] = temp[j - start];
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << baskets[i] << " ";
    }
    cout << endl;
    
    return 0;
}
