#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        do {
            i++;
        } while (i <= high && arr[i] <= pivot);

        do {
            j--;
        } while (j >= low && arr[j] > pivot);

        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int j = partition(arr, low, high);
        QuickSort(arr, low, j);
        QuickSort(arr, j + 1, high);
    }
}

int main() {
    int arr[] = {6, 5, 8, 9, 3, 10, 15, 12, 16};
    cout << "Performing QuickSort" << endl;
    int n = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, 0, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
