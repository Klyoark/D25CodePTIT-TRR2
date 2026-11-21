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

vector<vector<int>> adj;
vector<int> comp;
vector<vector<int>> res;
int n;

void bfs(int r, int id) {
    queue<int> q;
    comp[r] = id;
    q.push(r);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (comp[v] == 0) {
                comp[v] = id;
                q.push(v);
            }
        }
    }
}

int count() {
    int cnt = 0;
    for (int u = 1; u <= n; ++u) {
        if (comp[u] == 0) {
            ++cnt;
            bfs(u, cnt);
        }
    }
    return cnt;
}

int main() {
    fastio;
    freopen("TK.INP", "r", stdin); freopen("TK.OUT", "w", stdout);
    
    cin >> n;
    adj.resize(n + 1);
    comp.assign(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            if (x) adj[i].push_back(j);
        }
    }

    int cnt = count();
    res.resize(cnt + 1);

    for (int v = 1; v <= n; ++v) {
        res[comp[v]].push_back(v);
    }

    cout << cnt << NL;
    for (int i = 1; i <= cnt; ++i) {
        for (int x : res[i]) cout << x << " ";
        cout << NL;
    }
    return 0;
}