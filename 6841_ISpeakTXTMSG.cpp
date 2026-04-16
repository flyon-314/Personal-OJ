#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<string, string> translation = {
        {"CU", "see you"},
        {":-)", "I’m happy"},
        {":-(", "I’m unhappy"},
        {";-)", "wink"},
        {":-P", "stick out my tongue"},
        {"(~.~)", "sleepy"},
        {"TA", "totally awesome"},
        {"CCC", "Canadian Computing Competition"},
        {"CUZ", "because"},
        {"TY", "thank-you"},
        {"YW", "you’re welcome"},
        {"TTYL", "talk to you later"}
    };

    string input;

    while (true) {
        getline(cin, input);

        if (translation.find(input) != translation.end()) {
            cout << translation[input] << endl;
        } else {
            cout << input << endl;
        }

        if (input == "TTYL") {
            break;
        }
    }

    return 0;
}
