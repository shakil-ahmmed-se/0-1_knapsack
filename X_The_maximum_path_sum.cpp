#include<bits/stdc++.h>
using namespace std;
int maxSumPath(vector<vector<int>>& A, int i, int j, vector<vector<int>>& memo) {
    int N = A.size();
    int M = A[0].size();

    // Base case: reached the bottom-right cell
    if (i == N - 1 && j == M - 1) {
        return A[i][j];
    }

    // Check if the maximum sum for this cell is already calculated
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    // Calculate the maximum sum by moving down or right
    int downSum = (i < N - 1) ? maxSumPath(A, i + 1, j, memo) : 0;
    int rightSum = (j < M - 1) ? maxSumPath(A, i, j + 1, memo) : 0;

    // Store the maximum sum for this cell
    memo[i][j] = A[i][j] + max(downSum, rightSum);

    return memo[i][j];
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(M));
    vector<vector<int>> memo(N, vector<int>(M, -1));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    int maxSum = maxSumPath(A, 0, 0, memo);
    cout << maxSum << endl;

    return 0;
}