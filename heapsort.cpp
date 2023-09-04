#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to heapify a subtree rooted at 'root'
void heapify(int arr[], int n, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0);   // call max heapify on the reduced heap
    }
}

int main() {
    int N;
    cout << "Enter the number of elements (N): ";
    cin >> N;

    int arr[N];
    cout << "Choose input method:\n1. Manual Entry\n2. Random Numbers\nEnter your choice: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Enter " << N << " integers:\n";
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
    } else if (choice == 2) {
        // Generate N random integers
        srand(time(NULL)); // Seed the random number generator
        for (int i = 0; i < N; i++) {
            arr[i] = rand() % 1000; // Random integers between 0 and 999
        }
    } else {
        cout << "Invalid choice. Exiting.\n";
        return 1;
    }

    clock_t start = clock();
    heapSort(arr, N);
    clock_t end = clock();

    double timeTaken = double(end - start) / CLOCKS_PER_SEC;

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Time taken: " << timeTaken << " seconds\n";

    return 0;
}
