#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    for (int i = n; i > 0; i--)
    {
        for (int j = i - 1; j > 0; j--)
        {
            if (a[i] < a[j])
            {
                cnt++;
                break;
            }
        }
    }
    cout<<cnt<<endl;
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