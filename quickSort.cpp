#include <iostream>
#include <vector>
#include <algorithm>

int partition(std::vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Пример
int main()
{
    std::vector<int> arr{32, 3, 65, 71, 98, 11};
    quickSort(arr, 0, static_cast<int>(arr.size()) - 1);

    for (int x : arr)
        std::cout << x << " ";
    std::cout << "\n";

    return 0;
}