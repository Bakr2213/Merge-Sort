#include <iostream>
using namespace std;
void merge(int arr[], int l, int m, int r) // m = l + (r - l) / 2;      "0 , 6"
{
    int i, j, k;
    int n1 = m - l + 1; // first subarray                            "4"
    int n2 = r - m;     // second subarray                           "3"
    int* L = new int[n1], * R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[i + l];
    for (j=0;j<n2;j++)
        R[j] = arr[m + 1 + j];
    i = j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])  // >=
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    // Deallocate memory
    delete[] L;
    delete[] R;
}
void mergesort(int arr[], int l, int r) // 0 , 6
{
    if (l < r)
    {
        int m = l + (r - l) / 2;  //3

        // Sort first and second halves
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        
        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
int main()
{
    int arr[] = { 60,10,20,5,80,70 };
    int size = sizeof(arr) / sizeof(arr[0]); // 24 / 4 = 6

    mergesort(arr, 0, size - 1);
    print(arr,size);
}
