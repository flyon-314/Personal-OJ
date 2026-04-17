#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int bridge[31][31] = {0};
    int t;
    cin >> t;

    for (int i = 1; i < 31; i++) bridge[1][i] =  bridge[1][i - 1] + 1;
    for (int i = 2; i < 31; i++)
    {
        for (int j = 2; j < 31; j++)
        {
            bridge[i][j] = bridge[i - 1][j - 1] + bridge[i][j - 1];
            
        }
    }
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cout << bridge[n][m] << "\n";
    }
}