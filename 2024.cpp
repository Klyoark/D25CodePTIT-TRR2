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
vector<bool> vis;
int n;
void bfs(int r, int exc) {  
    queue<int> q;
    vis[r] = true;
    q.push(r);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!vis[v] && v != exc) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

int count(int exc) {
    vis.assign(n + 1, false);
    int cnt = 0;
    for (int v = 1; v <= n; ++v) {
        if (!vis[v] && v != exc) {
            ++cnt;
            bfs(v, exc);
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

    int base = count(0);
    vector<int> res;
    for (int v = 1; v <= n; ++v) {
        if (count(v) > base) res.push_back(v);
    }
    
    cout << res.size() << NL;
    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}