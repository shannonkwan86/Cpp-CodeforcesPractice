#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
typedef long long ll;
#define int long long
// const int MOD = 998244353;
const int MX = 1000005;
ll fac[MX], inv[MX];
ll ksm(ll a, ll b)
{
    ll res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}
void init()
{
    fac[0] = 1;
    for (int i = 1; i < MX; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv[MX - 1] = ksm(fac[MX - 1], MOD - 2);
    for (int i = MX - 2; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
}
ll Com(ll n, ll m)
{
    if (m < 0 || m > n)
        return 0;
    return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int cnt = 0;
    int l, r;
    int ans = 1;
    bool fg = false;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            cnt++;
            if (!fg)
            {
                fg = true;
                if (i == 1)
                    l = 1000;
                else
                    l = a[i - 1];
            }
        }
        else
        {
            if (fg == true)
            {
                fg = false;
                r = a[i];
                ans = (ans * Com(l - r + cnt, cnt)) % MOD;
                cnt = 0;
            }
        }
    }
    if (fg)
    {
        fg = false;
        r = 1;
        ans = (ans * Com(l - r + cnt, cnt)) % MOD;
        cnt = 0;
    }
    cout << ans << endl;
}

signed main()
{
    init();
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}