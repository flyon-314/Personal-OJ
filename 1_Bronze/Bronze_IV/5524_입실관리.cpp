#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--){
        string temp;
        cin >> temp;

        for(int i = 0; i < temp.length(); i++){
            if(temp[i] < 'a') temp[i] += 'a' - 'A';
        }

        cout << temp << "\n";
    }
}