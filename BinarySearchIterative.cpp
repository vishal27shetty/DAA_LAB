#include <iostream>
using namespace std;
int BinarySearch(int arr[],int N,int key)
{
     int high = N-1;
     int low = 0;
     while(low<=high)
     {
         int mid = (high+low)/2;
         if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            low=mid+1;
        else
            high=mid-1;
     }
     return -1;
}

int main() {
    int arr[] = {2,3,4,5,20,40};
    int key;
    cout << "Enter the key: " << endl;
    cin >> key;
    int N = sizeof(arr)/sizeof(arr[0]);
    int result = BinarySearch(arr,N,key);
    if(result==-1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at index " << result << endl;
}
