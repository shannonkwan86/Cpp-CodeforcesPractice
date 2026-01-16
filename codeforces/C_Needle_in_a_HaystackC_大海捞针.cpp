#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s;
    cin >> s;
    string t;
    cin >> t;
    map<int, int> mps;
    map<int, int> mpt;
    for (int i = 0; i < s.size(); i++)
    {
        mps[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size(); i++)
    {
        mpt[t[i] - 'a']++;
    }
    for (int i = 0; i <= 25; i++)
    {
        if (mps[i] > mpt[i])
        {
            cout << "Impossible" << endl;
            return;
        }
    }
    string srt = "";
    for (int i = 0; i <= 25; i++)
    {
        int cnt = mpt[i] - mps[i];
        while (cnt--)
        {
            srt.push_back('a' + i);
        }
    }
    // cout<<srt<<endl;
    int i = 0;
    int j = 0;
    while (i < s.size() && j < srt.size())
    {
        if (s[i] <= srt[j])
        {
            cout << s[i];
            i++;
        }
        else
        {
            cout << srt[j];
            j++;
        }
    }
    while (i < s.size())
    {
        cout << s[i];
        i++;
    }
    while (j < srt.size())
    {
        cout << srt[j];
        j++;
    }
    cout << endl;
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