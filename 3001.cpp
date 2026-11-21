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

vector<vector<int>> a, und;
vector<int> in, out, d;
vector<bool> vis;
int t, n, start;


void dfs(int u) {
    vis[u] = true;
    for (int v = 1; v <= n; ++v) {
        if ((a[u][v] || a[v][u]) && !vis[v]) dfs(v);
    }
}
bool weak() {
    vis.assign(n + 1, false);
    int cnt = 0;
    for (int v = 1; v <= n; ++v) {
        if (!vis[v]) {
            ++cnt;
            dfs(v);
        }
    }
    return (cnt == 1);
}

int solve1() {
    if (!weak()) {
        return 0;
    }
    int odd = 0;
    for (int i = 1; i <= n; ++i) {
        if (d[i] % 2 == 1) ++odd;
    } 
    if (odd == 0) return 1; //eu
    if (odd == 2) return 2; //half eu
    return 0;
}

void solve2(int start) {
    vector<vector<int>> b = a;
    vector<int> res;

    stack<int> st;
    st.push(start);
    
    while (!st.empty()) {
        int u = st.top();
        
        int v;
        for (v = 1; v <= n; ++v) {
            if (b[u][v]) break;
        }
        
        if (v <= n) {
            b[u][v] = 0;
            b[v][u] = 0;
            st.push(v);
        } else {
            res.push_back(u);
            st.pop();
        }
    }

    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
}

int main() {
    fastio;
    freopen("CT.INP", "r", stdin); freopen("CT.OUT", "w", stdout);
    cin >> t;
    if (t == 1) {
        cin >> n;
        a.resize(n + 1, vector<int>(n + 1));
        d.assign(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> a[i][j];
                if (a[i][j]) {
                    ++d[i];
                }
            }
        }
        cout << solve1();
        
    } else if (t == 2) {
        cin >> n >> start;
        a.resize(n + 1, vector<int>(n + 1));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> a[i][j];
            }
        }
        solve2(start);
    }

    return 0;
}