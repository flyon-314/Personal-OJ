#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> s_v;
int N, M, temp;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		s_v.push_back(temp);
	}
	sort(s_v.begin(), s_v.end()); 
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		cout << upper_bound(s_v.begin(), s_v.end() , temp) - lower_bound(s_v.begin(), s_v.end(), temp)<<" ";
	}
}