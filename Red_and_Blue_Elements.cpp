#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        vector<long long> pre(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] + a[i];
        }

        long long sum = pre[n];
        long long ans = 0;

        for (int k = 0; k <= n; k++)
        {
            long long sum_red;

            if (n - 2 * k >= 0)
            {
                sum_red = sum - pre[n - k];
            }
            else
            {
                sum_red = pre[k];
            }

            long long count_red = k;
            long long count_blue = n - k;
            long long sum_blue = sum - sum_red;

            long long current = sum_red * count_blue + sum_blue * count_red;

            ans = max(ans, current);
        }

        cout << ans << endl;
    }

    return 0;
}