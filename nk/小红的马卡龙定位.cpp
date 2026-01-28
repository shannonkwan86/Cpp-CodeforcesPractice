#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int xa, ya;
    int xb, yb;
    int xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    if (xa * 2 == xb + xc && ya * 2 == yb + yc)
    {
        cout << 1 << endl;
    }
    if (xb * 2 == xa + xc && yb * 2 == ya + yc)
    {
        cout << 2 << endl;
    }
    if (xc * 2 == xb + xa && yc * 2 == yb + ya)
    {
        cout << 3 << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}