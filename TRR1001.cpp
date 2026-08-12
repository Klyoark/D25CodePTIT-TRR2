#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int main() {
    fastio;

    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    if (t == 1) {
        for (int i = 0; i < n; ++i){
            int d = 0;
            for (int j = 0; j < n; ++j) {
                d += a[i][j];
            }
            cout << d << " ";
        }
    } else {
        vector<pair<int, int>> e;
        e.reserve(1e5);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[i][j] == 1) {
                    e.push_back({i + 1, j + 1});
                }
            }
        }
        cout << n << " " << e.size() << NL;
        for (pair<int, int> ed : e) {
            cout << ed.first << " " << ed.second << NL;
        }
    }

    return 0;
}