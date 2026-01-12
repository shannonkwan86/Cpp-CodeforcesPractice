#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    ll n, m, k;
    cin>>n>>m>>k;

    ll lim_l = k - 1;  
    ll lim_r = n - k;  
    ll ans = 1;

    for (ll l = 0; l <= lim_l; ++l) {
        
        ll cur = -1;

        if (m + 1 - 2 * l >= 0) {
            ll r1 = min({l, lim_r, m + 1 - 2 * l});
            cur = max(cur, r1);
        }

        ll rma = (m + 1 - l) / 2;
        if (rma > l) {
            ll r2 = min(lim_r, rma);
            if (r2 > l) cur = max(cur, r2);
        }

        if (cur != -1) {
            ans = max(ans, 1 + l + cur);
        }
    }

    cout << min(n, ans) << endl;
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