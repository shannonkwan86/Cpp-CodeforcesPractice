#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
long long quick_pow(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a;
        b >>= 1;
        a *= a;
    }
    return ans;
}

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    int k1 = 1, k2 = 1;
    int ans = 1;
    while (k1)
    {
        long long p = quick_pow(4LL, k1);
        long long s = (p - 1LL) / 3LL;
        // cout << 2 * s << " " << b << endl;
        if (s <= a && 2LL * s <= b)
        {
            ans = max(ans, 2 * k1);
            k1++;
        }
        else
            break;
    }
    while (k2)
    {
        long long p = quick_pow(4LL, k2);
        long long s = (p - 1LL) / 3LL;
        long long p2 = quick_pow(4LL, k2 - 1LL);
        long long s2 = (p2 - 1LL) / 3LL;
        if (s <= b && 2LL * s2 <= a)
        {
            ans = max(ans, 2 * k2 - 1);
            k2++;
        }
        else
            break;
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}