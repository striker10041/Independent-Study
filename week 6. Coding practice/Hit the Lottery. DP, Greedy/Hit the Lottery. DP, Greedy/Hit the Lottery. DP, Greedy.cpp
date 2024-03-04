//https://codeforces.com/problemset/problem/996/A?locale=en

#include<iostream>
using namespace std;
int main() {
	int a;
	cin >> a;
	cout << a / 100 + a % 100 / 20 + a % 20 / 10 + a % 10 / 5 + a % 5 / 1;
}