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
int n, m;
vector<bool> vis;

struct Edge {
    int u, v, w, id;
};
vector<Edge> edges;
vector<int> par;


int Find(int u) {
    if (u == par[u]) return u;
    return par[u] = Find(par[u]);
}
bool Uni(int u, int v) {
    u = Find(u);
    v = Find(v);

    if (u == v) return false;
    if (u < v) swap(u, v);
    par[v] = u;
    return true;
}

void prep() {
    par.resize(n + 1);
    vis.assign(n + 1, false);
    iota(par.begin(), par.end(), 0); //init DSU

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){
        if (a.w != b.w) {
            return a.w < b.w;
        }
        return a.id < b.id;
    });
}

void DSU() {
    vector<Edge> ans;
    int total = 0;

    for (const Edge& e : edges) {
        if (Uni(e.u, e.v)) {
            ans.push_back({min(e.u, e.v), max(e.u, e.v), e.w, e.id});
            total += e.w;
        }
        if (ans.size() == n - 1) break;
    }

    if (ans.size() != n - 1) {
        cout << 0;
        return;
    }

    cout << total << NL;
    for (const Edge& e : ans) {
        cout << e.u << " " << e.v << " " << e.w << NL;
    }
}

int main() {
    fastio;
    freopen("CK.INP", "r", stdin); freopen("CK.OUT", "w", stdout);
    cin >> n >> m;    
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w, i});
    }

    prep();
    DSU();

    return 0;
}