#include <iostream>
using namespace std;
int LinearSearch(int arr[],int N,int key)
{
      for(int i=0;i<N;i++)
    {
        if(key==arr[i])
            return i;
    }
    return -1;
}
int main() {
    int arr[] = {2,3,4,5,20,40};
    int key;
    cout << "Enter the key: " << endl;
    cin >> key;
    int N = sizeof(arr)/sizeof(arr[0]);
    int result = LinearSearch(arr,N,key);
    if(result==-1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at index " << result << endl;
}
