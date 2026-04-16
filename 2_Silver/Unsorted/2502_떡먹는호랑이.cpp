#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[31][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int d, k;
    cin >> d >> k;

    arr[1][0] = 1; arr[1][1] = 0;
    arr[2][0] = 0; arr[2][1] = 1;
    
    for (int i = 3; i <= d; i++) {
        arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
        arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
    }
    
    for (int i = 1; i < k; i++) {
        int numerator = k - i * arr[d][0];

        if (numerator > 0 && numerator % arr[d][1] == 0) {
            int j = numerator / arr[d][1];
            
            if (i <= j) {
                cout << i << "\n" << j;
                return 0;
            }
        }
    }
    
    return 0;
}