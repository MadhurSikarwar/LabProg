#include <iostream>

using namespace std;

int w[100]; 
int subset[100]; 
int target_sum;
int n;

void sumOfSubsets(int current_sum, int index, int remaining_weight) {
    subset[index] = 1;
    
    if (current_sum + w[index] == target_sum) {
        cout << "{ ";
        for (int i = 0; i <= index; i++) {
            if (subset[i] == 1) cout << w[i] << " ";
        }
        cout << "}" << endl;
    } 
    else if (index + 1 < n && current_sum + w[index] + w[index + 1] <= target_sum) {
        sumOfSubsets(current_sum + w[index], index + 1, remaining_weight - w[index]);
    }

    subset[index] = 0;
    
    if (index + 1 < n && current_sum + remaining_weight - w[index] >= target_sum && current_sum + w[index + 1] <= target_sum) {
        sumOfSubsets(current_sum, index + 1, remaining_weight - w[index]);
    }
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;

    int total_weight = 0;
    cout << "Enter " << n << " elements in increasing order:\n";
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        total_weight += w[i];
    }

    cout << "Enter target sum: ";
    cin >> target_sum;

    cout << "\nFinding subsets that sum to " << target_sum << " using Backtracking:" << endl;
    
    if (total_weight < target_sum || w[0] > target_sum) {
        cout << "No subset possible." << endl;
    } else {
        sumOfSubsets(0, 0, total_weight);
    }

    return 0;
}
