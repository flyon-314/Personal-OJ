#include <iosfwd>
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    int count[26] = {0};
    cin>>s;
    
    for (char c : s) count[c - 'a']++;
    for (int i : count) cout << i << " ";
    
    cout << "\n";

    return 0;
}