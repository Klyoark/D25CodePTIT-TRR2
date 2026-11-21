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
vector<int> in, out;
int n, t, start;

void dfs(int u) {
    vis[u] = true;
    for (int v = 1; v <= n; ++v) {
        if (!vis[v] && (a[u][v] || a[v][u])) {
            dfs(v);
        }
    }
}
bool weak() {
    int cnt = 0;
    vis.assign(n + 1, false);
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
    int pos = 0, neg = 0, diff;
    for (int u = 1; u <= n; ++u) {
        diff = in[u] - out[u];
        if (diff == 0) continue;
        else if (diff == -1) ++neg;
        else if (diff == 1) ++pos;
        else return 0;
    }

    if (pos == 0 && neg == 0) return 1;
    if (pos == 1 && neg == 1) return 2;
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
            st.push(v);
        } else {
            res.push_back(u);
            st.pop();
        }
    }
    reverse(res.begin(), res.end());
    for (int x : res) cout << x << " ";
}

int main() {
    fastio;
    freopen("CT.INP", "r", stdin); freopen("CT.OUT", "w", stdout);
    
    cin >> t;
    if (t == 1) {
        cin >> n;
        a.resize(n + 1, vector<int>(n + 1));
        in.assign(n + 1, 0);
        out.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> a[i][j];
                if (a[i][j]) {
                    ++out[i];
                    ++in[j];
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