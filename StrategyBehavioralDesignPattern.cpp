/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>


void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printArray(std::vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++) 
        std::cout << arr[i] << " "; 
    std::cout << std::endl; 

}
// Step 1: Define the Strategy Interface
class SortingStrategy
{
public:
    virtual void sort(std::vector<int>& arr) = 0;
};

// Step 2: Implement Concrete Strategies
class BubbleSort : public SortingStrategy
{
public:
    void sort(std::vector<int>& arr) override
    {
        int n = arr.size();
        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<n-i-1; j++)
            {
                if(arr[j] > arr[j+1])
                    swap(arr[j], arr[j+1]);
            }
        }
    }
};

class QuickSort : public SortingStrategy
{
public:
    void sort(std::vector<int>& arr) override
    {
        quickSort(arr,0,arr.size()-1);
    }
    
    int partition(std::vector<int>& arr, int start, int end)
    {
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
    }
    
    void quickSort(std::vector<int>& arr, int start, int end)
    {
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
    }
};

// Step 3: Create the Context
class SortContext
{
private:
    SortingStrategy* m_Strategy;
    
public:
    void setStrategy(SortingStrategy* strategy)
    {
        m_Strategy = strategy;
    }
    void executeStrategy(std::vector<int>& arr)
    {
        m_Strategy->sort(arr);
    }
};

// Step 4: Utilize the Strategy Pattern
int main()
{
    std::vector<int> data = {5, 2, 7, 1, 9};
    
    SortContext context;
    BubbleSort bubbleSort;
    QuickSort quickSort;
    
    context.setStrategy(&bubbleSort);
    context.executeStrategy(data); // Execute Bubble Sort
    
    printArray(data);
    
    std::vector<int> data1 = {6, 4, 9, 8, 3};
    
    context.setStrategy(&quickSort);
    context.executeStrategy(data1); // Execute Quick Sort
    
    printArray(data1);

    return 0;
}
