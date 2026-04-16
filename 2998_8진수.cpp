#include <iostream>
#include <string>
using namespace std;

int main() {
    string binary;
    cin >> binary;

    while (binary.length() % 3 != 0) {
        binary = "0" + binary;
    }

    string octal = "";

    for (size_t i = 0; i < binary.length(); i += 3) {
        string group = binary.substr(i, 3);

        if (group == "000") octal += "0";
        else if (group == "001") octal += "1";
        else if (group == "010") octal += "2";
        else if (group == "011") octal += "3";
        else if (group == "100") octal += "4";
        else if (group == "101") octal += "5";
        else if (group == "110") octal += "6";
        else if (group == "111") octal += "7";
    }

    cout << octal << endl;

    return 0;
}
