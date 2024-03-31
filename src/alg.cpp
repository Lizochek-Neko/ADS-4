// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = len - 1; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int cbinsearch(int* arr, int size, int value) {
    int i = 0, j = size - 1;
    while (i <= j) {
        if (i == j) {
            if (arr[i] != value) {
                return 0;
            }
        }
        int mid = i + (j - i) / 2;
        if (arr[mid] == value) {
            int count = 0;
            while (mid >= 0 && arr[mid] == value) {
                mid--;
            }
            mid++;
            while (mid < size && arr[mid] == value) {
                count++;
                mid++;
            }
            return count;
        } else if (arr[mid] > value) {
            j = mid;
        } else {
            i = mid + 1;
        }
    }
    return 0;
}
int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int c = cbinsearch(arr + i + 1, len - i - 1, value - arr[i]);
        count += c;
    }
    return count;
}
