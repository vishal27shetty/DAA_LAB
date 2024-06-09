#include <iostream>
using namespace std;
int BinarySearch(int arr[],int low,int high,int key)
{
    if(low<=high) {
    int mid = (high+low)/2;
         if(arr[mid]==key)
            return mid;
         else if(arr[mid]<key)
            return BinarySearch(arr,mid+1,high,key);
         else 
            return BinarySearch(arr,low,mid-1,key);
    }
    else 
        return -1;
}

int main() {
    int arr[] = {2,3,4,5,20,40};
    int key;
    cout << "Enter the key: " << endl;
    cin >> key;
    int N = sizeof(arr)/sizeof(arr[0]);
    int result = BinarySearch(arr,0,N-1,key);
    if(result==-1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at index " << result << endl;
}
