#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right)
{
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    
    while (j <= right)
        temp[k++] = arr[j++];
    
    for (int p = 0; p < k; p++)
        arr[left + p] = temp[p];
}

void mergeSort(std::vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Пример
int main()
{
    std::vector<int> arr{32, 3, 65, 71, 98, 11};
    mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);

    for (int x : arr)
        std::cout << x << " ";
    std::cout << "\n";

    return 0;
}