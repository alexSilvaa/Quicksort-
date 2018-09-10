#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int swapcount = 0;
int comparisons = 0;

/*
int occurences(int arr[], int num, int x) {
    int temp = 0;
    for(int i = 0; i < num; i++){
        if(x == arr[i]) {
            temp++;
        }
    }
    return temp;
}

int search(int arr[], int a, int b, int c) {
    if(b >= a) {
        int middle = 1 + (b-1)/2;
        if(arr[middle] == c) {
            return middle;
        }
        if(arr[middle] > c) {
            return search(arr, a, middle - 1, c);
        }
        return search(arr, middle + 1, b, c);
    }
    return -1;
}
*/


void quicksort(int arr[], int first, int last) {
    int pivot, temp, index1, index2;
    if(first < last) {
        pivot = first;
        index1 = first;
        index2 = last;
        

        while(index1 < index2) {
            comparisons++;
            while(arr[index1] <= arr[pivot] && index1 < last) {
                index1++;
            }
            while(arr[index2] > arr[pivot]) {
                index2--;
            }
            if(index1 < index2) {
                temp = arr[index1];
                arr[index1] = arr[index2];
                arr[index2] = temp;
                swapcount++;
            }
        }
        
        
        temp = arr[pivot];
        arr[pivot] = arr[index2];
        arr[index2] = temp;
        

        quicksort(arr, first, index2-1);
        quicksort(arr, index2+1, last);
    }
}

int main(void) {

    int counter, key, bincount, max;
    char type[20];
    printf("Enter type of number set \n");
    scanf("%19s", type);
    printf("Enter number of values in array \n");
    scanf("%d", &max);


    int array[max];
    if(max > 10) {
        max = 10000;
        
        srand(0);
        for(int i = 0; i < max; i++) {
            array[i] = rand() % 10;
            }
    }

   else {
        printf("Enter the integers and press enter after each \n");
        for(counter = 0; counter < max; counter++) {
            scanf("%d", &array[counter]);
        }
   
   }

   printf("Press [Enter] to sort values \n");
   while(getchar() != '\n');
   getchar();

   quicksort(array, 0, max);
   
   for(counter = 0; counter < max; counter++) {
       printf("\n Array[%d] = %d", counter, array[counter]);
       }
   
   puts("\n press enter to continue ");
   getc(stdin);
   
/*
    printf("\n Enter value to search for \n");
    scanf("%d", &key);

   int point = search(array, 0, max -1, key);

   
   
   if(point != -1) {
       bincount = occurences(array, max, key);
       printf("%d occurs %d time(s) \n", key, bincount);
       printf("%d first occurence at array[%d] \n", key, point);
       }

   else {
       printf("%d not found \n", key);
   }*/
    printf("Type: %s \n", type);
    printf("Swaps made: %d \n", swapcount);
    printf("Comparisons made: %d \n", comparisons);

    return 0;
}