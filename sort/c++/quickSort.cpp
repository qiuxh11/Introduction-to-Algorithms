//
// Created by qiuxh on 2018/11/10.
//


#include <iostream>

int partition(int a[], int low, int high){
    int key = a[low];

    while(low < high){
        while(low < high && a[high] >= key){
            high--;
        }

        a[low] = a[high];

        while(low < high && a[low] <= key){
            low++;
        }

        a[high] = a[low];
    }

    a[low] = key;

    return low;
}

void quick_sort(int a[], int low, int high){
    if (low < high){
        int partion_index = partition(a, low ,high);
        quick_sort(a, low, partion_index-1);
        quick_sort(a, partion_index+1, high);
    }
}

int main() {
    int a[] = {2,9,1,7,6,5, 12, 19, 20, 2, 3, 0};
    //int a[] = {3,2};
    int length = sizeof(a) / sizeof(a[0]);

    quick_sort(a, 0, length - 1);
    for(int i = 0; i < length; i ++){
        std::cout << a[i] << std::endl;
    }

    return 0;

}