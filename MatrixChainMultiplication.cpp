#include <bits/stdc++.h>

int matrixMultiplication(vector<int> &A, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0;
            }
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = A[i - 1] * A[k] * A[j] + dp[i][k] + dp[k + 1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][n - 1];
}
