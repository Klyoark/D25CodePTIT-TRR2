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

void dijkstra() {
    d.assign(n + 1, LIM);
    par.assign(n + 1, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    d[s] = 0;
    pq.emplace(0, s);

    while (!pq.empty()) {
        int du = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (du > d[u]) continue;  // skip, this dist is outdated

        int v, w;
        for (const pii& ew : adj[u]) {
            v = ew.first;
            w = ew.second;
            if (du + w < d[v]) {
                d[v] = du + w;
                par[v] = u;
                pq.emplace(d[v], v);
            }
        }
    }
}

int main() {
    fastio;
    freopen("DN.INP", "r", stdin); freopen("DN.OUT", "w", stdout);

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

    dijkstra();

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