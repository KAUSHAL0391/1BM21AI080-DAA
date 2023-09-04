#include <iostream>
#include <vector>

using namespace std;

vector<int> subset;
vector<vector<int>> subsets;

void findSubsetsWithSum(int arr[], int n, int sum, int currSum, int index) {
    if (currSum == sum) {
        subsets.push_back(subset);
        return;
    }

    if (index == n || currSum > sum) {
        return;
    }
    subset.push_back(arr[index]);
    findSubsetsWithSum(arr, n, sum, currSum + arr[index], index + 1);
    subset.pop_back();
    findSubsetsWithSum(arr, n, sum, currSum, index + 1);
}

int main() {
    int n, sum;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> sum;

    findSubsetsWithSum(arr, n, sum, 0, 0);

    if (subsets.empty()) {
        cout << "No solution found." << endl;
    } else {
        cout << "Subsets with the sum " << sum << " are:" << endl;
        for (const vector<int>& s : subsets) {
            cout << "{";
            for (int num : s) {
                cout << num << " ";
            }
            cout << "}" << endl;
        }
    }

    return 0;
}