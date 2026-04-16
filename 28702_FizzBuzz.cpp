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

    string s;
    int num;
    for (int i = 0 ; i < 3 ; i++) {
        cin >> s;
        if (s != "Fizz" && s != "Buzz" && s != "FizzBuzz") num = stoi(s) + 3 - i;
    }
    if (num % 3 == 0 && num % 5 == 0) cout << "FizzBuzz";
    else if (num % 3 == 0) cout << "Fizz";
    else if (num % 5 == 0) cout << "Buzz";
    else cout << num;
    return 0;
}