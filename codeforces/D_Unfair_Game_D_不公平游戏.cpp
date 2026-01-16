#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll C[40][40];
void init()
{
    for (int i = 0; i <= 31; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}
void solve()
{
    int n, k;
    cin>>n>>k;
    int tep = n;
    int p = 0;
    while (tep)
    {
        tep >>= 1;
        p++;
    }
    p-=1;
    int ans = 0;
    if (p +1 > k)
    {
        ans += 1;
    }
    for (int i = p - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i + j + 1 > k)
            {
                ans += C[i][j];
            }
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    init();
    
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}