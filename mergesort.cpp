#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        b[i] = arr[mid + i + 1]; // Fixed the array name here
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) { // Fixed the condition here
        if (a[i] < b[j]) {
            arr[k] = a[i];
            k++;
            i++;
        } else {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n1) {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2) { // Changed to 'j' here
        arr[k] = b[j]; // Changed to 'b[j]' here
        k++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r); // Changed to 'merge' here
    }
}

void display(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Removed the newline after each element
    }
    cout << endl; // Added a newline after printing the array
}

int main() {
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " Elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Array before Sorting: ";
    display(arr, n);
    mergeSort(arr, 0, n - 1);
    cout << "Array after Sorting: ";
    display(arr, n);
}
