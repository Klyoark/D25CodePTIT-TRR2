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
    cin >> t;
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<int> in(n + 1, 0), out(n + 1, 0);
    vector<pii> edges;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            if (a[i][j]) {
                ++in[j], ++out[i];
                edges.push_back(make_pair(i, j));
            }
        }
    }
    if (t == 1) {
        for (int i = 1; i <= n; ++i) {
            cout << in[i] << " " << out[i] << NL;
        }
    } else {
        cout << n << " " << edges.size() << NL;
        for (const pii& e : edges) {
            cout << e.first << " " << e.second << NL;
        }
    }

    return 0;
}