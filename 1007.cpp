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
    cin >> t >> n;
    vector<int> adj[n + 1];
    vector<int> d(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int k; cin >> k;
        for (int j = 0; j < k; ++j) {
            int v;
            cin >> v;
            adj[i].push_back(v);
            ++d[i];
        }
    }
    if (t == 1) {
        for (int i = 1; i <= n; ++i) {
            cout << d[i] << " ";
        }
    } else {
        cout << n << NL;
        vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int x : adj[i]) {
                a[i][x] = 1;
                a[x][i] = 1;
            }
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