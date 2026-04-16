#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int slen; string s; cin >> slen >> s;
	int l = 0, r = slen - 1;
	int ans = 0;
	while (l < r) {
		if (s[l++] != s[r--]) ans++;
	}

	cout << ans;
}