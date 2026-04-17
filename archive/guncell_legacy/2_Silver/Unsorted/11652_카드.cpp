#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector <long long> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        long long tmp;
		cin >> tmp;
		v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    long long card = v[0];
	int cnt = 0, max = 0;
	for (int i = 1; i < n; i++){
		if (v[i] == v[i - 1]) 
		    cnt++;
		else cnt = 0;

		if (cnt > max){
			max = cnt;
			card = v[i];
		}
	}
	cout << card << endl;
}