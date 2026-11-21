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

vector<vector<int>> adj;
vector<bool> vis;
int n;

void dfs(int u, int a, int b) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (vis[v]) continue;
        if ((v == a && u == b) || (v == b && u == a)) {
            continue;
        }
        dfs(v, a, b);
    }
}

int count(int a, int b) {
    vis.assign(n + 1, 0);
    int cnt = 0;
    for (int u = 1; u <= n; ++u) {
        if (!vis[u]) {
            ++cnt;
            dfs(u, a, b);
        }
    }
    return cnt;
}

int main() {
    fastio;
    freopen("TK.INP", "r", stdin); freopen("TK.OUT", "w", stdout);
    cin >> n;
    adj.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            if (x) {
                adj[i].push_back(j);
            }
        }
    }

    int base = count(0, 0);
    vector<pii> res;

    for (int u = 1; u <= n; ++u) {
        for (int v = u + 1; v <= n; ++v) {
            if (count(u, v) > base) {
                res.push_back(make_pair(u, v));
            }
        }
    }
    
    cout << res.size() << NL;
    for (const pii& e : res) {
        cout << e.first << " " << e.second << NL;
    }

    return 0;
}