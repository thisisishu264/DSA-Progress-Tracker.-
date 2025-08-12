#include <stdio.h> 
#include <stdlib.h> 

void binarySearch(int low[] , int size , int target) {
    int *high = low + size - 1; 
    while (low <= high) {
        int *mid = low + (high - low) / 2 ; 
        if (target == *mid) {
            printf("Found\n") ; 
            return ; 
        } else if (target > *mid) {
            printf("right ") ; 
            low = mid + 1 ; 
        } else {
            printf("left ") ;
            high = mid -1 ; 
        }        
    }
    printf("Not Found\n") ; 
}

void arrayPrinter(int arr[] , int size) {
    for (int i = 0 ; i < size ; i++) {
        printf("%d " , arr[i]) ; 
    }
    printf("\n") ; 
}

void bubbleSorter(int arr[] , int size , int target) {
    int temp ; 
    for (int i = 0 ; i < size ; i++) {
        for (int j = i+1 ; j < size ; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[j] ; 
                arr[j] = arr[i] ; 
                arr[i] = temp ; 
            }
        }
    }
    
    arrayPrinter(arr , size) ;  
    binarySearch(arr , size , target) ; 
}

void selectionSorter(int arr[] , int size , int target) { 
    int temp ; 
    for (int i = 0 ; i < size ; i++) {
        int minimum_index = i ; 
        for (int j = i + 1 ; j < size ; j++) { 
            if (arr[j] < arr[minimum_index]) {
                minimum_index = j ; 
            }
        }
        temp = arr[i] ; 
        arr[i] = arr[minimum_index] ; 
        arr[minimum_index] = temp ; 
    }
    arrayPrinter(arr , size) ; 
    binarySearch(arr , size , target) ; 
}

void insertionSorter(int arr[] , int size , int target) { 
    for (int i = 1 ; i < size ; i++) {
        int key = arr[i]; 
        int j = i - 1 ; 
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j] ;
            j-- ; 
        }
        arr[j+1] = key ; 
    }
    arrayPrinter(arr,size) ; 
    binarySearch(arr , size , target) ; 
}

int main() {
    printf("Enter the number of elements: ") ; 
    int size = 0 ; 
    scanf("%d" , &size) ; 
    int *arr = malloc(size * sizeof(int)) ; 
    printf("Enter the elements below:\n") ; 
    for (int i = 0 ; i < size ; i++ ) { 
        scanf("%d" , &arr[i]) ; 
    }
    printf("Enter the target: ") ; 
    int target = 0 ; 
    scanf("%d" , &target) ; 
    printf("1 to bubble , 2 to selection , 3 to insertion.\n") ; 
    int choice; 
    scanf("%d" , &choice) ; 
    if (choice == 1) {
        bubbleSorter(arr , size , target) ;
    } else if (choice == 2) {
        selectionSorter(arr, size, target) ; 
    } else if (choice == 3) {
        insertionSorter(arr , size , target) ; 
    } else {
        printf("Bruh") ;
    }
    free(arr) ; 
    arr = NULL ; 
    return 0 ; 
}