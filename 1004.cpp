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
    int t;
    cin >> t;
    int n, m;
    cin >> n >> m;
    vector<pii> edges;
    vector<int> d(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        ++d[u]; ++d[v];
        edges.push_back(make_pair(u, v));
    }
    if (t == 1) {
        for (int i = 1; i <= n; ++i) {
            cout << d[i] << " ";
        }
    } else if (t == 2) {
        cout << n << NL;
        vector<vector<int>> a(n + 1, vector<int>(n + 1));
        for (pii& e : edges) {
            a[e.first][e.second] = 1;
            a[e.second][e.first] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << a[i][j] << " ";
            }
            cout << NL;

        }
    }

    return 0;
}