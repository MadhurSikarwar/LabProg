#include <iostream>

using namespace std;

int max_val(int a, int b) {
    if (a > b) return a;
    return b;
}

int knapsackDP(int W, int wt[], int val[], int n) {
    int dp[100][100]; 

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                dp[i][w] = max_val(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    int val[100];
    int wt[100];

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "Enter values of the " << n << " items:\n";
    for(int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << "Enter weights of the " << n << " items:\n";
    for(int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    int result = knapsackDP(W, wt, val, n);

    cout << "\nMaximum value in Knapsack = " << result << endl;

    return 0;
}
