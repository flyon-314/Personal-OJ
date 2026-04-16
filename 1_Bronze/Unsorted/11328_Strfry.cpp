#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--){
        string str1,str2;
        cin >> str1 >> str2 ;
        
        if(str1.length() != str2.length()) {
            cout << "Impossible" << endl;
            continue;
        }

        int count1[26]={ }, count2[26] = { };

        for(char c : str1) count1[c - 'a']++;
        for(char c : str2) count2[c - 'a']++;

        bool ispossible=true;
        for(int i = 0; i < 26; i++){
            if(count1[i] != count2[i]){
                ispossible = false;
                break;
            }
        }

        if(ispossible) cout << "Possible" << endl;
        else cout << "Impossible" << endl;
    }
    
}