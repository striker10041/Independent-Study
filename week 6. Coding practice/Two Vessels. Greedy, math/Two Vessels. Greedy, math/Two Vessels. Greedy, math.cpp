//https://codeforces.com/problemset/problem/1872/A?locale=en

#include <iostream>

using namespace std;

int main()
{
    int t, a, b, cap;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b >> cap;
        if (a < b) {
            int max = a;
            a = b;
            b = max;
        }
        if (a == b)
            cout << 0 << " ";
        int cnt = 0;
        while (a != b) {
            a = a - cap;
            b = b + cap;
            cnt++;
            if (b > a || b == a) {
                a = b;
                cout << cnt << " ";
            }
        }
    }

    return 0;
}
