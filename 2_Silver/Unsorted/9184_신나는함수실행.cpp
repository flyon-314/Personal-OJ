#include <iostream>

using namespace std;
int a,b,c;
int cnt[21][21][21];

int solve(int x, int y, int z) {
	if(x <= 0 || y <= 0 || z <= 0) return 1;
	if(x > 20 || y > 20 || z > 20) return solve(20,20,20);
	if(cnt[x][y][z] != 0) return cnt[x][y][z];
	if(x < y && y < z) return cnt[x][y][z] = solve(x,y,z-1) + solve(x,y-1,z-1) - solve(x,y-1,z);
	return cnt[x][y][z] = solve(x-1,y,z) + solve(x-1,y-1, z) + solve(x-1,y,z-1) - solve(x-1,y-1,z-1);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	while(true) {
		cin >> a >> b >> c;
		if(a == -1 && b == -1 && c == -1) break;
		solve(a,b,c);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a,b,c) << '\n';
	}
	return 0;
}