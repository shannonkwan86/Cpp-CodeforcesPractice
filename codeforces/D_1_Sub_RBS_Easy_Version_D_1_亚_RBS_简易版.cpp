#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> suf(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        suf[i] = suf[i + 1];
        if (s[i] == '(')
            suf[i]++;
    }
    int py = -1;
    vector<int> nxy(n + 1, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        nxy[i] = py;
        if (s[i] == '(')
            py = i;
    }
    int mxl = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')')
        {
            int j = nxy[i];
            if (j != -1)
            {
                int k = j - i;
                if (suf[j + 1] >= k)
                {
                    mxl = max(mxl, n - 2 * k);
                }
            }
        }
    }
    cout << mxl << endl;
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