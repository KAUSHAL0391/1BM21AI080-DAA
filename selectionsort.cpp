#include <iostream>
using namespace std;
int main(){
    int n , arr[50];
    cout<<"Enter number of elements in an array : ";
    cin >> n;
    cout << "Enter " << n << " Elements : ";
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    for(int i=0 ; i<n-1 ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(arr[j]<arr[i]){
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    cout << "Sorted array is : ";
    for(int i=0 ; i<n ; i++){
        cout << arr[i] << "";
    }
    cout << endl;
}