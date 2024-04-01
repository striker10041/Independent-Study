// https://codeforces.com/problemset/problem/115/A?locale=en

#include <iostream>
#include <vector>

typedef long long ll;
typedef long double ld;

using namespace std;

vector<int> adj[2005];
vector<bool> vis;
int mx = -1;

void dfs(int u, int level) {
    vis[u] = true;
    mx = max(mx, level);

    for (auto neig : adj[u]) {
        if (!vis[neig])
            dfs(neig, level + 1);
    }
}

void solve() {
    int n;
    cin >> n;

    vis.resize(n);

    int u;
    vector<int> roots;
    for (int i = 0; i < n; i++) {
        cin >> u;
        if (u != -1)
            adj[--u].push_back(i);
        else
            roots.push_back(i);
    }

    for (auto i : roots) {
        dfs(i, 1);
    }

    cout << mx << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();

    return 0;
}