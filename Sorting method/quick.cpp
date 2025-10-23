// QUICK SORT 

#include <iostream>
#include <vector>
using namespace std; 
/**
 * This algo partitions the array around a pivot element.
 * * This function takes the first element (arr[low]) as the pivot.
 * It rearranges the array segment [low...high] such that all elements
 * less than or equal to the pivot are on its left, and all elements
 * greater than the pivot are on its right.
 * arr-> The vector to be partitioned (passed by reference).
 *low-> The starting index of the segment.
 *high-> The ending index of the segment.
 * return The final index of the pivot element after partitioning.
 */
int partition(vector<int>& arr, int low, int high) {
    // Choose the first element as the pivot
    int pivot = arr[low]; 
    
    // Initialize two pointers, 'i' starting just after the pivot and 'j' at the end
    int i = low;
    int j = high;

    // Continue as long as the two pointers have not crossed
    while (i < j) {
        
        // Find an element on the left side (starting from low) that is > pivot
        // We also check i <= high - 1 to prevent out-of-bounds access
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        // Find an element on the right side (starting from high) that is <= pivot
        // We also check j >= low + 1 to prevent out-of-bounds access
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }

        // If the pointers haven't crossed, swap the elements at i and j
        // This puts the element > pivot on the right and <= pivot on the left
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    
    // When the loop finishes (i >= j), 'j' points to the correct position for the pivot.
    // Swap the original pivot (arr[low]) with the element at index 'j'.
    swap(arr[low], arr[j]);
    
    // Return the pivot's new index
    return j;
}

/**
 The main recursive function for QuickSort.
*/
void qs(vector<int>& arr, int low, int high) {
    // Base case: If the segment has more than one element (low < high)
    if (low < high) {
        // Find the partition index (pivot's final position)
        int pIndex = partition(arr, low, high);

        // Recursively sort the subarray to the left of the pivot
        qs(arr, low, pIndex - 1);
        
        // Recursively sort the subarray to the right of the pivot
        qs(arr, pIndex + 1, high);
    }
    // If low >= high, the segment has 0 or 1 elements, which is already sorted (base case)
}

vector<int> final(vector<int>& arr) {
    int n = arr.size();
    // Call the recursive quicksort function on the entire array
    qs(arr, 0, n - 1);
    return arr;
}

// The main function where the program execution begins
int main() {
    // Initialize a sample vector
    vector<int> arr = {4, 5, 2, 1, 3};
    int n = arr.size(); // Get the size of the vector

    // Print the original (unsorted) array
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; // New line

    // Call the quicksort function to sort the array in place
    qs(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; // New line

    return 0; // Indicate successful execution
}
