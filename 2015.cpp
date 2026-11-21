//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define pii pair<int, int>
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;
constexpr int LIM = 10000;

vector<vector<int>> adj, radj, und;
vector<int> vis;
int n;

void dfs(int u, const vector<vector<int>>& g) {
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, g);
        }
    }
}


bool check() {
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) return false;
    }
    return true;
}
int solve() {
    vis.assign(n + 1, 0);
    dfs(1, und);
    if (!check()) {
        return 0;
    }
    
    vis.assign(n + 1, 0);
    dfs(1, adj);
    if (!check()) {
        return 2;
    }

    vis.assign(n + 1, 0);
    dfs(1, radj);
    if (!check()) {
        return 2;
    }
    return 1;
}

int main() {
    fastio;
    freopen("TK.INP", "r", stdin); freopen("TK.OUT", "w", stdout);
    cin >> n;
    adj.resize(n + 1);
    radj.resize(n + 1);
    und.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            if (x) {
                adj[i].push_back(j);
                und[i].push_back(j);
                und[j].push_back(i);
                radj[j].push_back(i);
            }
        }
    }

    cout << solve();
    return 0;
}