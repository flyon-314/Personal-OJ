#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(); // 개행 문자 제거

    while (T--) {
        string line;
        getline(cin, line);

        int freq[26] = {0};
        // 각 문자의 빈도수 계산 (공백은 무시)
        for (char c : line) {
            if (c != ' ') {
                freq[c - 'a']++;
            }
        }
        
        int maxFreq = 0;
        // 최대 빈도수 구하기
        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
            }
        }
        
        int countMax = 0;
        int maxIndex = -1;
        // 최대 빈도수를 가진 문자가 여러 개인지 확인
        for (int i = 0; i < 26; i++) {
            if (freq[i] == maxFreq) {
                countMax++;
                maxIndex = i;
            }
        }
        
        // 최대 빈도수가 단 하나면 해당 문자, 아니면 '?' 출력
        if (countMax == 1)
            cout << char('a' + maxIndex) << "\n";
        else
            cout << "?" << "\n";
    }
    
    return 0;
}
