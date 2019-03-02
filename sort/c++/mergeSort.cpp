//
// Created by qiuxh on 2018/11/10.
//


#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>

void merge(int a[], int low, int mid, int high){
    int left_length = mid - low + 1;
    int right_length = high - mid;

    int *left = new int [left_length + 1];
    int *right = new int [right_length + 1];

    for(int i = low; i <= mid; i++){
        left[i - low] = a[i];
    }

    for(int i = mid + 1; i <= high; i++){
        right[i - mid - 1] = a[i];
    }

    left[left_length] = INT_MAX;
    right[right_length] = INT_MAX;

    int left_index = 0;
    int right_index = 0;

    for(int i = low; i <= high; i++){
        if(left[left_index] <= right[right_index]){
            a[i] = left[left_index];
            left_index++;
        }
        else{
            a[i] = right[right_index];
            right_index++;
        }
    }

    delete [] left;
    delete [] right;
}

void merge_sort(int a[], int low, int high){
    if(low < high){
        int mid = (low + high)/2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    //int a[] = {2,9,1,7,6,5, 12, 19, 20, 2, 3, 0};
    int a[] = {3,2,1,0,0,0};
    int length = sizeof(a) / sizeof(a[0]);

    merge_sort(a, 0, length - 1);
    for(int i = 0; i < length; i ++){
        std::cout << a[i] << std::endl;
    }

    return 0;

}

