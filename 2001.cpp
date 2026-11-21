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

struct Edge{
    int u, v, w;
};

vector<Edge> wedges;
vector<pii> edges;
vector<vector<int>> a;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> path;

bool dfs(int u, int e) {
    if (u == e) {
        return true;
    }
    for (int v : adj[u]) {
        if (!vis[v]) {
            vis[v] = true;
            path.push_back(v);
            if (dfs(v, e)) return true;
            path.pop_back();
        }
    }
    return false;
}

int main() {
    fastio;
    freopen("TK.INP", "r", stdin); freopen("TK.OUT", "w", stdout);
    int t, n, b, e;
    cin >> t >> n >> b >> e;
    a.assign(n + 1, vector<int>(n + 1, 0));
    adj.resize(n + 1);
    vis.assign(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            if (a[i][j] != 0) adj[i].push_back(j);
        }
    }
    if (t == 1) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += a[b][i] * a[i][e];
        }   
        cout << ans;
    } else {
        vis[b] = true;
        path.push_back(b);
        if (dfs(b, e)) {
            for (int i : path) cout << i << " ";
        } else {
            cout << 0;
        }
    }
    return 0;
}