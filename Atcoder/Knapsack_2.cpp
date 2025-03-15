//URL: https://atcoder.jp/contests/dp/tasks/dp_e
//Solution  by: Subrata Biswas

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define Wrong                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

vector<ll> w(110), val(110);
vector<vector<ll>> dp(110, vector<ll>(1e5 + 100, -1));
ll calc(ll i, ll limt)
{
    if (limt == 0)
        return 0;

    if (i < 0)
        return 1e9 + 10;

    if (dp[i][limt] != -1)
        return dp[i][limt];

    ll ans = calc(i - 1, limt);
    if (limt - val[i] >= 0)
        ans = min(ans, (calc(i - 1, limt - val[i]) + w[i]));
    return dp[i][limt] = ans;
}
int main()
{
    Wrong;
    ll n, limt;
    cin >> n >> limt;

    for (ll i = 0; i < n; i++)
    {
        cin >> w[i];
        cin >> val[i];
    }
    for (ll j = 1e5 + 10; j >= 0; j--)
    {
        if (calc(n - 1, j) <= limt)
        {
            cout << j << '\n';
            break;
        }
    }
    return 0;
}
