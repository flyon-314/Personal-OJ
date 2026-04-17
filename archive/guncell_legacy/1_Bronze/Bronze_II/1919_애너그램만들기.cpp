#include <bits/stdc++.h>

using namespace std;

int main() {

    string str1,str2;
    cin >> str1 >> str2 ;

    int count1[26]={ }, count2[26] = { };

    for(char c : str1) count1[c - 'a']++;
    for(char c : str2) count2[c - 'a']++;

    int count = 0;
    for(int i = 0; i < 26; i++){
        if(count1[i] != count2[i]) count += max(count1[i],count2[i]) - min(count1[i],count2[i]);
    }

    cout << count;
}