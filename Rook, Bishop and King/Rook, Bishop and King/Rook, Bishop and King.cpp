// https://codeforces.com/problemset/problem/370/A?locale=en

#include <iostream>
#include <string>

static int rook(int r1, int c1, int r2, int c2) {
    int res = 0;
    if (r1 == r2 || c1 == c2) {
        res = 1;
    }
    else {
        res = 2;
    }
    return res;
}

static int bishop(int r1, int c1, int r2, int c2) {
    int res = 0;
    if ((r1 + c1) % 2 == (r2 + c2) % 2) {
        if (abs(r1 - r2) == abs(c1 - c2)) {
            res = 1;
        }
        else {
            res = 2;
        }
    }
    return res;
}

static int king(int r1, int c1, int r2, int c2) {
    int res = 0;
    if (r1 == r2 || c1 == c2) {
        res = abs(r1 - r2) + abs(c1 - c2);
    }
    else if (abs(r1 - r2) == abs(c1 - c2)) {
        res = abs(c1 - c2);
    }
    else {
        if (abs(r1 - r2) > abs(c1 - c2)) {
            res = abs(r1 - r2);
        }
        else {
            res = abs(c1 - c2);
        }
    }
    return res;
}

int main() {
    int r1, c1, r2, c2;
    std::cin >> r1 >> c1 >> r2 >> c2;
    std::cout << rook(r1, c1, r2, c2) << " ";
    std::cout << bishop(r1, c1, r2, c2) << " ";
    std::cout << king(r1, c1, r2, c2);
    return 0;
}