#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll s, k, m;
    cin >> s >> k >> m;
    if (s <= k) {
        ll r = m % k;
        cout << max(0LL, s - r) << endl;
    } else {
        ll p = 2 * k;
        ll r = m % p;
        if (r < k) {
            cout << s - r << endl;
        } else {
            cout << 2 * k - r << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}