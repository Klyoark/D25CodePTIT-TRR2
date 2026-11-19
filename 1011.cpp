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

int main() {
    fastio;
    freopen("DT.INP", "r", stdin); freopen("DT.OUT", "w", stdout);
    int t, n, m;
    cin >> t >> n >> m;
    vector<Edge> edges;
    vector<int> d(n, 0);
    for (int i = 0; i < m; ++i) {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        edges.push_back(e);
        ++d[e.u - 1], ++d[e.v - 1];
    }
    if (t == 1) {
        for (int x : d) {
            cout << x << " ";
        }
    } else {
        cout << n << NL;
        vector<vector<int>> a(n + 1, vector<int>(n + 1, LIM));
        for (Edge& e : edges) {
            a[e.u][e.v] = e.w;
            a[e.v][e.u] = e.w;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j) cout << 0 << " ";
                else cout << a[i][j] << " ";
            }
            cout << NL;
        }
    }
    
    return 0;
}