//https://codeforces.com/problemset/problem/141/A?locale=en

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;
    str1 = str1 + str2;
    int cnt = 0;
    if (str1.length() != str3.length()) {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < str3.length(); i++) {
        for (int j = 0; j < str1.length(); j++) {
            if (str3[i] == str1[j] && str3[i] != '1') {
                cnt++;
                str3[i] = '1';
                str1[j] = '1';
            }
        }

    }

    if ((cnt * 2) == (str3.length() * 2))
        cout << "YES";
    else
        cout << "NO";

}