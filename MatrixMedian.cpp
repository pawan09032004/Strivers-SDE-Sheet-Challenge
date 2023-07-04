#include <bits/stdc++.h>

int getMedian(vector<vector<int>> &matrix) {
    int start = INT_MAX;
    int end = INT_MIN;
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        start = std::min(start, matrix[i][0]);
        end = std::max(end, matrix[i][m - 1]);
    }

    int midpos = (n * m + 1) / 2;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        int count = 0;

        for (int i = 0; i < n; i++) {
            int index = std::upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            count += index;
        }

        if (count < midpos) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return start;
}
