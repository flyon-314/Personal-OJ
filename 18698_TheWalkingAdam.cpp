#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--){
        string str;
        cin >> str;

        int count = 0;

        for(char c : str){
            if(c == 'D') break;
            count++;
        }

        cout << count << endl;
    }
}