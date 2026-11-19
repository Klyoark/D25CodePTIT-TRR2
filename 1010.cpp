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
int LIM = 1e4;

int main() {
    fastio;
    freopen("DT.INP", "r", stdin); freopen("DT.OUT", "w", stdout);
    int t, n, m = 0;
    cin >> t >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<int> d(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;   
            if (i == j) {
                a[i][j] = 0;
            } else {
                a[i][j] = x;
                if (x != 0 && x != LIM) {
                    ++d[i]  ;
                    if (i < j) ++m;
                }
            }
        }
    }
    if (t == 1) {
        for (int i = 1; i <= n; ++i) {
            cout << d[i] << " ";
        }
    } else {
        cout << n << " " << m << NL;
        for (int i = 1; i<=n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (i < j && a[i][j] != LIM && a[i][j] != 0) {
                    cout << i << " " << j << " " << a[i][j] << NL;
                }
            }
        }
    }
    return 0;
}