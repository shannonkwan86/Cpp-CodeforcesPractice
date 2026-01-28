#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> p;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
            p.push_back(i);
    }
    int cnt1 = p.size();
    int cnt0 = n - p.size();
    if (cnt1 == 0 || cnt0 == 0)
    {
        cout << "Bob" << endl;
        return;
    }
    bool fg = true;
    for (int i = 1; i < n; i++)
    {
        if (s[i] > s[i + 1])
            fg = false;
    }
    if (fg)
    {
        cout << "Bob" << endl;
        return;
    }
    else
    {
        vector<int> pre1(n + 1);
        vector<int> sub0(n + 1);
        for (int i = 1; i <= n; i++)
        {
            pre1[i] = pre1[i - 1];
            if (s[i] == '1')
                pre1[i]++;
        }
        if (s[n] == '0')
            sub0[n] = 1;
        else
            sub0[n] = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            sub0[i] = sub0[i + 1];
            if (s[i] == '0')
            {
                sub0[i]++;
            }
        }
        int pos;
        for (int i = 0; i < n; i++)
        {
            if (pre1[i] == sub0[i + 1])
            {
                pos = i;
                break;
            }
        }
        vector<int> ans;
        for (int i = 1; i <= pos; i++)
        {
            if (s[i] == '1')
                ans.push_back(i);
        }
        for (int i = pos + 1; i <= n; i++)
        {
            if (s[i] == '0')
            {
                ans.push_back(i);
            }
        }
        cout << "Alice" << endl;
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }cout<<endl;
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