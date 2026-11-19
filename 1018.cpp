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

int main() {
    fastio;
    freopen("DT.INP", "r", stdin); freopen("DT.OUT", "w", stdout);
    int t;
    int n;
    cin >> t >> n;
    vector<int> adj[n + 1];
    vector<int> in(n + 1, 0), out(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            adj[i].push_back(x);
            ++in[x], ++out[i];
        }
    }
    if (t == 1) {
        for (int i = 1; i <= n; ++i)     {
            cout << in[i] << " " << out[i] << NL;
        }
    } else {
        cout << n << NL;
        vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int x : adj[i]) {
                a[i][x] = 1;
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