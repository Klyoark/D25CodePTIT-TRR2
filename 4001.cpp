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

vector<vector<int>> a;
vector<bool> vis;
vector<pii> ans;
int t, n, s;

void dfs(int u)   {
    vis[u] = true;
    for (int v = 1; v <= n; ++v) {
        if (!vis[v] && a[u][v]) {
            ans.emplace_back(u, v);
            dfs(v);
        }
    }
}

void bfs(int u)   {
    queue<int> q;
    vis[u] = true;
    q.push(u);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int w = 1; w <= n; ++w) {
            if (!vis[w] && a[v][w]) {
                ans.emplace_back(v, w);
                q.push(w);
                vis[w] = true;
            }
        }
    }
}

bool check() {
    vis.assign(n + 1, false);
    queue<int> q;
    vis[s] = true;
    q.push(s);
    int cnt = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n; ++v) {
            if (a[u][v] && !vis[v]) {
                q.push(v);
                vis[v] = true;
                ++cnt;
            }
        }
    }
    if (cnt < n) {
        return false;
    }
    return true;
}

int main() {
    fastio;
    freopen("CK.INP", "r", stdin); freopen("CK.OUT", "w", stdout);
    
    cin >> t >> n >> s;
    a.resize(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    
    if (!check()) {
        cout << 0;
        return 0;
    }

    vis.assign(n + 1, false);
    if (t == 1) {
        dfs(s);
    } else if (t == 2) {
        bfs(s);
    }

    if (ans.size() != n - 1) {
        cout << 0;
    } else {
        cout << ans.size() << NL;
        for (const pii& e : ans) {
            cout << min(e.first, e.second) << " " << max(e.first, e.second) << NL;
        }
    }

    return 0;
}