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

int main() {
    fastio;
    freopen("DT.INP", "r", stdin); freopen("DT.OUT", "w", stdout);
    int t, n, m;
    cin >> t >> n >> m;
    vector<pii> edges;
    vector<int> d(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        ++d[u], ++d[v];
        edges.push_back(make_pair(u, v));
    }
    if (t == 1) {
        for (int i = 1; i <= n; ++i) {
            cout << d[i] << " ";
        }
    } else {
        cout << n << NL;
        vector<int> a[n + 1];
        for (const pii& e : edges) {
            a[e.first].push_back(e.second);
            a[e.second].push_back(e.first);
        }
        for (int i = 1; i <= n; ++i) {
            if (!a[i].empty()) {
                cout << a[i].size() << " ";
                for (int& x : a[i]) {
                    cout << x << " ";
                } 
                cout << NL;
            } else {
                cout << 0 << NL;
            }
        }
    }
    return 0;
}