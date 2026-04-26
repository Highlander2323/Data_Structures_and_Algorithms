#include <iostream>
#include <random>

using namespace std;

// ------------------------ Binary Search ------------------------
int binarySearch(int *arr, int left, int right, int key){
    if(left >= right){
        return -1;
    }
    
    int mid = (left + right) / 2;
    
    if(arr[mid] == key){
        return mid;
    }
    else if(arr[mid] < key){
        return binarySearch(arr, mid + 1, right, key);
    }
    else{
        return binarySearch(arr, left, mid, key);
    }
}

// ------------------------ Merge Sort ------------------------
void merge(int *arr, int left, int mid, int right){
    int nL = (mid - left) + 1, nR = right - mid;
    int L[nL], R[nR];
    
    for (int i = 0; i < nL; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < nR; j++)
        R[j] = arr[mid + 1 + j];
        
    int i = 0, j = 0, curr = left;
    while(i < nL && j < nR){
        if(L[i] < R[j]){
            arr[curr++] = L[i++];
        }
        else{
            arr[curr++] = R[j++];
        }
    }
    
    while(i < nL){
        arr[curr++] = L[i++];
    }
    
    while(j < nR){
        arr[curr++] = R[j++];
    }
}

void mergeSort(int *arr, int left, int right){
    if(left >= right){
        return;
    }
    
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void printArr(int *arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}

// ------------------------ Find maximum ------------------------
int findMax(int *arr, int left, int right){
    if(left >= right){
        return arr[left];
    }

    int mid = (left + right) / 2;
    int maxLeft = findMax(arr, left, mid);
    int maxRight = findMax(arr, mid + 1, right);
    return maxLeft > maxRight ? maxLeft : maxRight;
}

// ------------------------ Find minimum ------------------------
int findMin(int *arr, int left, int right){
    if(left >= right){
        return arr[left];
    }

    int mid = (left + right) / 2;
    int minLeft = findMin(arr, left, mid);
    int minRight = findMin(arr, mid + 1, right);
    return minLeft < minRight ? minLeft : minRight;
}

// ------------------------ Main function ------------------------
int main() {

    int arr[30];
    for(int i = 0; i < 30; ++i){
        arr[i] = rand() % 100;
    }

    // FIND MIN & MAX:
    cout << "Max: " << findMax(arr, 0, 29) << endl;
    cout << "Min: " << findMin(arr, 0, 29) << endl;
    
    // MERGE SORT
    printArr(arr, 30);
    mergeSort(arr, 0, 29);
    printArr(arr, 30);

    //BINARY SEARCH
    int varToFind = rand() % 100;
    cout << "Searching for " << varToFind << ": ";
    binarySearch(arr, 0, 29, varToFind) == -1 ? cout << "Not Found" : cout << "Found";
    cout << endl;
    system("pause");

    return 0;
}