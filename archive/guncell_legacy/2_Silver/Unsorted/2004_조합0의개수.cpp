#include <iostream>

using namespace std;

long long func(int n, int x)
{
	int num = 0;

	for (long long i = x; n / i >= 1; i *= x) {
		num += n / i;
	}

	return num;
}
int main() {
    int n,m;
    cin>>n>>m;
    long long a,b;
    a = func(n,5)-func(n-m,5)-func(m,5);
	b = func(n,2)-func(n-m,2)-func(m,2);
	cout<<min(a,b);
    return 0;
}
