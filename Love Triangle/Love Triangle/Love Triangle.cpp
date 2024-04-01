//  https://codeforces.com/problemset/problem/939/A?locale=en

#include <iostream>
using namespace std;

const int N = 1e9;
int main() {
	int n, m;
	cin >> n;
	int a[n + 9];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[a[a[i]]] == i) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
