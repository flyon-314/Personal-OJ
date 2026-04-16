#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
bool star[4000][8000];
int N;
void triange(int r, int c, int size)
{
    if (size == 3) {
        star[r][c] = !star[r][c];
        star[r + 1][c - 1] = !star[r + 1][c - 1];
        star[r + 1][c + 1] = !star[r + 1][c + 1];
        for (int i = 0 ; i < 5; i++) star[r + 2][c - 2 + i] = !star[r + 2][c - 2 + i];
        return;
    }
    
    int next = size / 2;
    triange(r, c, next);
    triange(r + next, c + next, next);
    triange(r + next, c - next ,  next); 
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    triange(1,N, N);

    for (int i = 1 ; i <= N ; i++) {
        for (int j = 1 ; j <= N * 2 ; j++) {
            if (star[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << "\n";
    }
}