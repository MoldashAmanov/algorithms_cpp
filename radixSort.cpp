#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void countingSortByDigit(std::vector<int>& arr, int exp)
{
    int n = arr.size();
    std::vector<int> output(n), count(10, 0);
    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    arr = output;
}

void radixSort(std::vector<int>& arr)
{
    if (arr.empty()) return;
    int max_val = *std::max_element(arr.begin(), arr.end());
    for (int exp = 1; max_val / exp > 0; exp *= 10)
        countingSortByDigit(arr, exp);
}

void printVector(const std::vector<int>& arr, const std::string& label)
{
    std::cout << label << ": [";
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i];
        if (i + 1 < arr.size())
            std::cout << ", ";
    }
    std::cout << "]\n";
}

int main()
{
    std::vector<int> arr = {170, 45, 54, 223, 654, 86, 23, 96};
    printVector(arr, "Исходный массив");

    // Промежуточные шаги(разряды: единицы, десятки, сотни)
    for (int exp = 1; *std::max_element(arr.begin(), arr.end()) / exp > 0; exp *= 10)
    {
        countingSortByDigit(arr, exp);
        printVector(arr, "После сортировки по разряду " + std::to_string(exp));
    }
    std::cout << "\nИтоговый отсортированный массив:\n";
    printVector(arr, "Результат");

    return 0;
}