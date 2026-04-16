#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string getGrade(int rank) {
    if (rank >= 1 && rank <= 5) return "A+";
    else if (rank >= 6 && rank <= 15) return "A0";
    else if (rank >= 16 && rank <= 30) return "B+";
    else if (rank >= 31 && rank <= 35) return "B0";
    else if (rank >= 36 && rank <= 45) return "C+";
    else if (rank >= 46 && rank <= 48) return "C0";
    else if (rank >= 49 && rank <= 50) return "F";
    return "Invalid";
}

int main() {
    vector<int> scores(50);
    int hongikScore;

    // Input scores
    for (int i = 0; i < 50; ++i) {
        cin >> scores[i];
    }

    // Input Hongik's score
    cin >> hongikScore;

    // Find Hongik's rank
    auto it = find(scores.begin(), scores.end(), hongikScore);
    int rank = distance(scores.begin(), it) + 1;

    // Output grade
    cout << getGrade(rank) << endl;

    return 0;
}