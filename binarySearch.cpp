#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target)
{
    int left = 0, right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2; // Защита от переполнения
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1; // Не найдено
}


// Пример
int main()
{
    std::vector<int> arr{1, 3, 5, 7, 9, 11};
    std::cout << binarySearch(arr, 7) << "\n";

    return 0;
}
