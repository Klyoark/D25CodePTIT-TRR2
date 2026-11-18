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
    int t, n;
    cin >> t >> n;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> adj[i][j];
        }
    }
    if (t== 1) {
        for (int i = 1; i <= n; ++i) {
            int d = 0;
            for (int j = 1; j <= n; ++j) {
                if (adj[i][j]) ++d;
            }
            cout << d << " ";
        }
    } else if (t == 2) {
        vector<pii> edges;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (adj[i][j]) edges.push_back(make_pair(i, j));
            }
        }
        int m = edges.size();
        vector<vector<int>> lt(n + 1, vector<int>(m, 0));
        for (int i = 0; i < m; ++i) {
            int u = edges[i].first;
            int v = edges[i].second;
            lt[u][i] = 1;
            lt[v][i] = 1;
        }
        cout << n << " " << m << NL;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << lt[i][j] << " ";
            }
            cout << NL;
        }
    }
    return 0;
}