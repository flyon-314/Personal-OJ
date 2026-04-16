#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B, C;
    cin >> A >> B >> C;

    int numA = stoi(A);
    int numB = stoi(B);
    int numC = stoi(C);
    
    cout << numA + numB - numC << "\n";
    
    string com = A + B;
    long long anw = stoll(com) - stoll(C);
    cout << anw << "\n";
    return 0;
}