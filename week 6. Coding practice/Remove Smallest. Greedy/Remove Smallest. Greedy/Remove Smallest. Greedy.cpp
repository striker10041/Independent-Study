// https://codeforces.com/problemset/problem/1399/A?locale=en

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        int a[t], cnt = 0;
        for (int j = 0; j < t; j++) {
            cin >> a[j];
        }
        sort(a, a + t);
        for (int k = 1; k < t; k++) {
            if ((a[k] - a[k - 1]) > 1) {
                cout << "NO" << endl;
                cnt++;
                break;
            }
        }
        if (cnt == 0)
            cout << "YES" << endl;
    }
}