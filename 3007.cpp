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

int n, start;
vector<vector<int>> adj, und;
vector<int> path, in, out;
vector<bool> vis;
vector<vector<int>> res;

void dfs(int u, int pos) {
    if (pos == n) {
        for (int fin : adj[u])  {
            if (fin == start) {
                path.push_back(start);
                res.push_back(path);
                path.pop_back();
                break;
            }
        }
        return;
    }

    for (int v : adj[u]) {
        if (v == start) {
            continue;
        }
        if (!vis[v]) {
            vis[v] = true;
            path[pos] = v;
            dfs(v, pos + 1);
            vis[v] = false;
        }
    }
}

int main() {
    fastio;
    freopen("CT.INP", "r", stdin); freopen("CT.OUT", "w", stdout);
    cin >> n >> start;
    adj.resize(n + 1);
    und.resize(n + 1);
    in.resize(n + 1);
    out.resize(n + 1);
    path.clear(), path.assign(n, 0);
    vis.assign(n + 1, false);
    res.clear();

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            if (x) {
                adj[i].push_back(j);
                und[i].push_back(j);
                und[j].push_back(i);
                ++in[j];
                ++out[i];
            }
        }
    }

    //1
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0 || out[i] == 0) {
            cout << 0;
            return 0;
        }
    }

    //2
    vector<bool> vvis(n + 1, false);
    queue<int> q;
    q.push(start);
    vvis[start] = true;
    int cnt = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int des : und[v]) {
            if (!vvis[des])  {
                vvis[des]  = true;
                q.push(des);
                ++cnt;
            }
        }
    }
    if (cnt < n) {
        cout << 0;
        return 0;
    }

    path[0] = start;
    vis[start] = true;
    dfs(start, 1);

    if (res.empty()) {
        cout << 0;
    } else {
        sort(res.begin(), res.end());
        for (auto& c : res) {
            for (int i = 0; i < c.size(); ++i) {
                cout << c[i] << " ";
            }
            cout << NL;
        }
        cout << res.size();
    }

    return 0;
}