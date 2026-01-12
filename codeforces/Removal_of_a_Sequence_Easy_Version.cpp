#include <iostream>
using namespace std;
typedef long long ll;
const ll mx = 1e12;
void solve()
{
    ll x, y, k;
    cin >> x >> y >> k;
    if (y == 1)
    {
        cout << -1 << "\n";
        return;
    }
    for (int i = 1; i <= x; i++)
    {
        k = k + (k - 1LL) / (y - 1LL);
        if (k > mx)
            break;
    }
    if (k > mx)
        cout << -1 << "\n";
    else
        cout << k << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}