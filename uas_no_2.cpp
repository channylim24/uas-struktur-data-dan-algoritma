#include <iostream>

void bubbleSort(int arr[], int idx[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                temp = idx[j];
                idx[j] = idx[j+1];
                idx[j+1] = temp;
            }
        }
    }
}

void binarySearch(int arr[], int idx[], int n, int x) {
    int left = 0, right = n - 1, count = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            count++;
            int temp = mid;
            while (temp+1 < n && arr[temp+1] == x) {
                count++;
                temp++;
            }
            temp = mid;
            while (temp-1 >= 0 && arr[temp-1] == x) {
                count++;
                temp--;
            }
            std::cout << "Angka " << x << " ada di indeks ke ";
            for (int i = temp; i < temp + count; i++) {
                std::cout << idx[i]+1;
                if (i < temp + count - 2)
                    std::cout << ", ";
                else if (i == temp + count - 2)
                    std::cout << " dan ";
            }
            std::cout << std::endl;
            return;
        }
        if (arr[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    std::cout << "Angka " << x << " tidak ada dalam array" << std::endl;
}

int main() {
    int arr[] = {19, 40, 10, 90, 2, 50, 60, 50, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int idx[n];
    for (int i = 0; i < n; i++)
        idx[i] = i;
    bubbleSort(arr, idx, n);

    int x;
    std::cout << "Masukkan angka yang ingin dicari: ";
    std::cin >> x;

    binarySearch(arr, idx, n, x);

    return 0;
}
