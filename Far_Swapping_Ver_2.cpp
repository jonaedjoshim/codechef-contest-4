#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

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

        vector<int> p(n + 1);
        vector<int> position(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
            position[p[i]] = i;
        }

        vector<long long> current_dp(1, 1);

        for (int value = 1; value < n; value++)
        {
            vector<long long> next_dp(value + 1, 0);

            if (position[value] < position[value + 1])
            {
                long long prefix_sum = 0;

                for (int j = 0; j <= value; j++)
                {
                    if (j > 0)
                    {
                        prefix_sum = (prefix_sum + current_dp[j - 1]) % mod;
                    }

                    next_dp[j] = prefix_sum;
                }
            }
            else
            {
                long long suffix_sum = 0;

                for (int j = value; j >= 0; j--)
                {
                    if (j < value)
                    {
                        suffix_sum = (suffix_sum + current_dp[j]) % mod;
                    }

                    next_dp[j] = suffix_sum;
                }
            }

            current_dp = next_dp;
        }

        long long answer = 0;

        for (int i = 0; i < n; i++)
        {
            answer = (answer + current_dp[i]) % mod;
        }

        cout << answer << endl;
    }

    return 0;
}