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
int n;
vector<Edge> wedges;
vector<pii> edges;
vector<vector<int>> a;
vector<vector<int>> adj, radj, und;
vector<bool> vis;
vector<int> par;

vector<int> comp;

void dfs(int u, int id) {
    comp[u] = id;
    for (int v : adj[u]) {
        if (!comp[v]) dfs(v, id);
    }
}

int countComp() {
    int cnt = 0;
    for (int u = 1; u <= n; ++u) {
        if (comp[u] == 0) {
            ++cnt;
            dfs(u, cnt);
        }
    }
    return cnt;
}

int main() {
    fastio;
    freopen("TK.INP", "r", stdin); freopen("TK.OUT", "w", stdout);
    
    cin >> n;
    adj.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            if (x) { 
                adj[i].push_back(j);
            }
        }
    }

    comp.assign(n + 1, 0);
    int cnt = countComp();
    vector<vector<int>> res(cnt + 1);
    for (int u = 1; u <= n; ++u)  {
        res[comp[u]].push_back(u);
    }
    
    cout << cnt << NL;
    for (int i = 1; i <= cnt; ++i) {
        for (int v : res[i]) cout << v << " ";
        cout << NL;
    }
    return 0;
}