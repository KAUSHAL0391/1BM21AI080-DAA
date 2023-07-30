#include <iostream>
using namespace std;

void swap(int arr[] , int pos1, int pos2){
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}
int partition(int arr[] , int l , int r){
    int pivot = arr[r];
    int i = l-1;
    for (int j=l ; j<r ; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr , i , j);
        }
    }
    swap(arr , i+1 , r);
    return i+1;
}
void quickSort(int arr[], int l, int r){
	if( l < r ){
	int pi = partition(arr, l , r);
	quickSort(arr, l, pi-1);
	quickSort(arr, pi+1, r);
	}
}
int main(){
    int n;
    cout << "Enter number of elements in array : ";
    cin >> n;
    int arr[n];
    cout << "Enter" << n << "Elements :";
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    quickSort(arr , 0 , n-1);
    cout << "Sorted array is : ";
    for(int i=0 ; i<n ; i++){
        cout << arr[i] << "\t";
    }
}