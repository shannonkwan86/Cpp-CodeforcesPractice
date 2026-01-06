#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k % 2 != 0)
    {
        while (k--)
        {
            cout << n << " ";
        }
        cout << endl;
    }
    else
    {
        vector<int> num(k + 1);
        vector<int> lim(k + 1);
        for (int i = 0; i <= k; i++)
            lim[i] = 1;
        int cnt = 0;
        for (int i = 30; i >= 0; i--)
        {
            int bitn = (n >> i) & 1;
            if (bitn == 1)
            {
                bool fg = false;
                if (cnt == k)
                {
                    for (int j = 2; j <= k; j++)
                    {
                        num[j] += (1 << i);
                    }
                }
                else
                {
                    for (int j = 1; j <= k; j++)
                    {
                        if (lim[j] && !fg)
                        {
                            lim[j] = 0;
                            fg = true;
                            cnt++;
                            continue;
                        }
                        num[j] += (1 << i);
                    }
                }
            }
            else
            {
                if (cnt % 2 == 0)
                {
                    for (int j = 1; j <= k; j++)
                    {

                        if (lim[j] == 0)
                        {
                            num[j] += (1 << i);
                        }
                    }
                }
                else
                {
                    bool fg = false;
                    for (int j = 1; j <= k; j++)
                    {
                        if (lim[j] == 0 && fg == false)
                        {
                            fg = true;
                            continue;
                        }
                        if (lim[j] == 0)
                        {
                            num[j] += (1 << i);
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= k; i++)
        {
            cout << num[i] << " ";
        }
        cout << endl;
    }
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