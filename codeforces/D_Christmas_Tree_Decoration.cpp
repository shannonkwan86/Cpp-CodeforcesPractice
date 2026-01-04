#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int MOD = 998244353;
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

int a[55];
void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int cst = 0;
    int R = sum / n;
    int rem = sum % n;
    int cnt1 = 0;
    for (int i = 1; i <= n; i++)
    {
        cst += max(0 * 1LL, R-a[i]);
        if (a[i] > R)
            cnt1++;
    }
    if (a[0] < cst)
    {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    for (int k = 0; k <= 50; k++)
    {
        if (k <= a[0] - cst && k <= n - cnt1 && k <= rem && rem - k <= cnt1)
        {
            ans = (ans + ((Com(cnt1, rem - k) * Com(n - cnt1, k)) % MOD * fac[rem]) % MOD * fac[n - rem]) % MOD;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    init();
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}