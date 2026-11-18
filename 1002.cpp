#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m;

int main() {
    fastio;
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t = 1;
    cin >> t >> n;
    vector<vector<int>> a(n, vector<int>(n));                                             
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    if (t == 1) {
        for (int i = 0; i < n; ++i) {
            int d = 0;
            for (int j = 0; j < n; ++j) {
                d += a[i][j];
            }
            cout << d << " ";
        }
        cout << NL;
    } else if (t == 2) {
        vector<vector<int>> k(n);
        cout << n << NL;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j]) {
                    k[i].push_back(j);
                }
            }
        }

        for (vector<int>& r : k) {
            cout << r.size() << " ";
            for (int& x : r) {
                cout << x + 1 << " ";
            }
            cout << NL;
        }
        cout << NL;
    }
    
    return 0;
}