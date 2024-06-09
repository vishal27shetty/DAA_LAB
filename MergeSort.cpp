
#include <iostream>
#include <vector>

using namespace std;

void Merge(int arr[], int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    
    // Merge the two halves into the temp vector
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    
    // Copy remaining elements of the left half, if any
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    
    // Copy remaining elements of the right half, if any
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    
    // Copy the sorted elements back into the original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void MergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {6, 5, 8, 9, 3, 10, 15, 12, 16};
    cout << "Performing MergeSort" << endl;
    int n = sizeof(arr) / sizeof(arr[0]);
    MergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}


