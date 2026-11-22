// #pragma GCC optimize("O3,unroll-loops")
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

vector<vector<pii>> adj;
vector<int> d;
vector<int> par;
int n, s, t;
bool neg = false;

void bellmanford() {
    d.assign(n + 1, LIM);
    par.assign(n + 1, -1);
    d[s] = 0;

    for (int i = 1; i < n; ++i) {
        for (int u = 1; u <= n; ++u) {
            if (d[u] == LIM) continue;
            for (const pii& e : adj[u]) {
                int v = e.first;
                int w = e.second;
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    par[v]= u;
                }
            }
        }
    }
    for (int u = 1; u <= n; ++u) {
        if (d[u] == LIM) continue;
        for (const pii& e : adj[u]) {
            int v = e.first;
            int w = e.second;
            if (d[u] + w < d[v]) {
                neg = true;
                return;
            }
        }
    }
}

int main() {
    fastio;
    freopen("BN.INP", "r", stdin); freopen("BN.OUT", "w", stdout);

    cin >> n >> s >> t;
    adj.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            if (x != LIM && i != j) {
                adj[i].emplace_back(j, x);
            }
        }
    }

    neg = false;
    bellmanford();

    if (neg) {
        cout << -1;
        return 0;
    }

    vector<int> path;
    for (int v = t; v != -1; v = par[v]) {
        path.emplace_back(v);
    }
    reverse(path.begin(), path.end());
    if (d[t] == LIM) {
        cout << 0;
    } else {
        cout << d[t] << NL;
        for (int x : path) {
            cout << x << " ";
        }
    }

    return 0;
}