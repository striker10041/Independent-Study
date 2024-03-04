//https://codeforces.com/problemset/problem/189/A?locale=en

#include<iostream>
using namespace std;

int main() {
	int n, a, b, c, ans = 0, i, j, k;
	cin >> n >> a >> b >> c;

	for (i = 0; i <= n; i++) {
		for (j = 0; j <= n; j++) {
			k = n - i * a - j * b;
			if ((k >= 0 && k % c == 0) && (ans < i + j + k / c))
				ans = i + j + k / c;
		}
	}

	cout << ans;
}