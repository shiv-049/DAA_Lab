#include <iostream>
using namespace std;

// Quick Sort function
void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = a[low];
        int i = low;
        int j = high;
        int temp;

        // Partition the array
        while (i < j)
        {
            // Find an element greater than pivot
            while (a[i] <= pivot && i < high)
            {
                i++;
            }

            // Find an element smaller than or equal to pivot
            while (a[j] > pivot)
            {
                j--;
            }

            // Swap the elements
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        // Put pivot in its correct position
        temp = a[low];
        a[low] = a[j];
        a[j] = temp;

        // Sort left part
        quickSort(a, low, j - 1);

        // Sort right part
        quickSort(a, j + 1, high);
    }
}

int main()
{
    int a[100], n;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter unsorted array:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Call Quick Sort
    quickSort(a, 0, n - 1);

    cout << "Sorted array:\n";

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
