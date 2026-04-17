#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(); 

    for (int i = 1; i <= N; i++) {
        string line;
        getline(cin, line);
        cout << i << ". " << line << endl; 
    }

    return 0;
}