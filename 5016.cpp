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

int n;
vector<vector<pii>> a;
vector<vector<int>> d, nxt;

int main() {
    fastio;
    freopen("DN.INP", "r", stdin); freopen("DN.OUT", "w", stdout);
    
    cin >> n;
    a.resize(n + 1, vector<pii>(n + 1));
    d.resize(n + 1, vector<int>(n + 1));
    nxt.resize(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            if (i == j) {
                d[i][j] = min(0, x);
                nxt[i][j] = 0;
            } else if (x == LIM) {
                d[i][j] = LIM;
                nxt[i][j] = 0;
            } else {
                d[i][j] = x;
                nxt[i][j] = j;
            }
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (d[i][k] == LIM) continue;
            for (int j = 1; j <= n; ++j) {
                if (d[k][j] == LIM) continue; 
                int nd = d[i][k] + d[k][j];
                if (nd < d[i][j]) {
                    d[i][j] = nd;
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    bool neg = false;

    for (int i = 1; i <= n; ++i) {
        if (d[i][i] < 0) {
            neg = true;
            break;
        }
    }
    if (neg) {
        cout << 0;
        return 0;
    }

    int best = -1;
    int u = 0, v = 0;
    bool found = false;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            if (d[i][j] == LIM) continue;
            if (!found || d[i][j] > best) {
                found = true;
                best = d[i][j];
                u = i, v = j;
            }
        }
    }
    
    if (!found) {
        cout << 0;
        return 0;
    }

    vector<int> path = {u};
    for (int x = u; x != v && path.size() <= n; ) {
        x = nxt[x][v];
        path.push_back(x);
    }

    cout << u << " " << v << " " << best << NL;
    for (int x : path) {
        cout << x << " ";
    }

    return 0;
}