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

vector<vector<int>> a;
vector<bool> vis;
vector<pii> ans;
int t, n, s;
vector<int> d, par;

void prim() {
    d.assign(n + 1, LIM);
    par.assign(n + 1, -1);
    vis.assign(n + 1, false);

    d[s] = 0;
    par[s] = 0;
    int total = 0;
    
    for (int i = 1; i <= n; ++i) {
        int u = -1;

        for (int v = 1; v <= n; ++v) {
            if (!vis[v] && (u == -1 || d[v] < d[u] || (d[v] == d[u] && par[v] < par[u]))) {
                u = v;
            }
        }

        if (u == -1 || d[u] == LIM) {
            cout << 0;
            return;
        }

        vis[u] = true;
        total += d[u];
        if (u != s) {
            ans.emplace_back(min(par[u], u), max(par[u], u));
        }

        for (int v = 1; v <= n; ++v) {
            if (!vis[v] && a[u][v] != 0 && a[u][v] != LIM && (a[u][v] < d[v] || (a[u][v] == d[v] && u < par[v]))){
                d[v] = a[u][v];
                par[v] = u;
            }
        }
    }

    cout << total << NL;
    for (const pii& e : ans) {
        cout << e.first << " " << e.second << " " << a[e.first][e.second] << NL;
    }
}

int main() {
    fastio;
    freopen("CK.INP", "r", stdin); freopen("CK.OUT", "w", stdout);
    
    cin >> n >> s;
    a.resize(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    prim();

    return 0;
}