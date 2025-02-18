
using namespace std;

void selectionSort(int arr[], int n){
    for (int i=0; i<n-2; i++){
        // to find min
        int min_index = i;
        for (int j = i; j < n; j++){
            if (arr[j] < arr[min_index]) min_index = j;
        }
        // swap element
        swap(arr[i],arr[min_index]);
    }
}

/*
nums = [50,30,10,20,40] ----> [10,20,30,40,50]
Algorithm: 
step1: select min element
step2: swap it withe 1st element
step3: reduce the range / move range to right
Time Complexity = n + (n-1) + (n-2) + ...... + 2
                = n + (n-1) + (n-2) + ...... + 2 + 1  ----> Adding 1 for approximation (which doesn't affect the time complexity)
                = n(n + 1)/2
                = ((n^2)/2) + (n/2) ----> Ignoring constants and lower powers
                = O(n^2)
T.c = O(n^2);

*/
 

void bubbleSort(int arr[], int n){
    bool is_sorted;
    for (int i=n-1; i>0; i--){
        is_sorted = true; // is_sorted variable is used to optimize the 
        //sorting process by detecting whether the array has already been sorted 
        //in a previous iteration of the outer loop. 
        for (int j=0; j < i; j++){
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                is_sorted = false;
            }
        }
        if (is_sorted) break;
    }
}

/*
bubble
Time Complexity = 1 + 2 + 3 + ... + (n-1)
                = ((n-1) * (n-1+1))/2
                = (n * (n-1)) / 2
                = (n^2)/2 - n/2
                = O((n^2)/2 - n/2)
                = O(n^2)
worest and averge case = O(n^2)
best case = O(n) // by use is_sorted boolean variable; 

*/

void insertionSort(int arr[], int n){
    int j;
    for (int i = 1; i < n; i++){
        j = i;
        while((arr[j-1] > arr[j]) && j>0){
            swap(arr[j-1], arr[j]);
            j -= 1;
        }
    }
}

/*
insertion sort
Time Complexity = 1 + 2 + 3 + ... + (n-1)
                = ((n-1) * (n-1+1))/2
                = (n * (n-1)) / 2
                = (n^2)/2 - n/2
                = O((n^2)/2 - n/2)
                = O(n^2)
best and avereage case T.C = O(n^2)
best case  = O(n) - beacuse the while loop never executes in each iteration where its already sorted;
 */
 
void applyMerge(int arr[], int left, int mid, int right){
     int i = left, k = 0; // i and j are starts and limits are set by left and mid+1
     int j = mid + 1;
     int n = right - left + 1; // new array length should be merge of two arrays
     int newArr[n];
     
     while (i <= mid && j <= right){
         if (arr[i] < arr[j]){
             newArr[k] = arr[i];
             i++, k++;
         }else{
             newArr[k] = arr[j];
             j++,k++;
         }
     }
     // for remaining elements in left array
     while (i <= mid){
         newArr[k] = arr[i];
         k++,i++;
     }
     // for remaining elemets in right array 
     while (j <= right){
         newArr[k] = arr[j];
         k++,j++;
     }
     // and resulttant array are again stored in original array
     for(int c = 0; c < n; c++) arr[left + c] = newArr[c];
 }
 
 void mergeSortRecursive(int arr[],int left,int right){
     if (left == right){
         return;
     }
     int mid = (left + right) / 2;
     mergeSortRecursive(arr,left, mid);
     mergeSortRecursive(arr,mid+1,right);
     applyMerge(arr,left,mid,right);
     
 }

 void mergeSort(int arr[], int n){
     mergeSortRecursive(arr,0,n-1);
 }

/*
alogorithm:
step1: divide array into two equal lists (divide)
step2: sort left and sort right (conquer)
step3: merge the two sorted lists (merge)

apporach: 
1. If the list has only one element or is empty, it is already sorted.
2. Divide the list into two halves.
3. Recursively apply MergeSort to both halves.
4. Merge the two sorted halves to produce a single sorted list.
*/



int main() {
    int arr[] = {20, 50, 40, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int k: arr) cout << k << " ";
    cout << endl;
    
    // Uncomment one of the sorting functions to test

    // selectionSort(arr, n);
    // bubbleSort(arr, n);
    // insertionSort(arr, n);
    mergeSort(arr, n);

    cout << "Sorted array: ";
    for (int k: arr) cout << k << " ";
    cout << endl;

    return 0;
}

/*
nums = [50,30,10,20,40] ----> [10,20,30,40,50]
Algorithm: 
step1: select min element
step2: swap it withe 1st element
step3: reduce the range / move range to right
Time Complexity = n + (n-1) + (n-2) + ...... + 2
                = n + (n-1) + (n-2) + ...... + 2 + 1  ----> Adding 1 for approximation (which doesn't affect the time complexity)
                = n(n + 1)/2
                = ((n^2)/2) + (n/2) ----> Ignoring constants and lower powers
                = O(n^2)
T.c = O(n^2);

ex:
find min
[50,30,10,20,40]
 |      |
 min = 10
 swap 50 and 10 
 fin min
[10,30,50,20,40]
     |     |
min = 20
swap 30 and 20
[10,20,50,30,40]
        |  |
min = 30
swap 50 and 30
find min
[10,20,30,50,40]
           |  |
min = 40
swap 50 and 40
[10,20,30,40,50]
             ||
if we iterated till n-2 is enough
sorting is done
*/