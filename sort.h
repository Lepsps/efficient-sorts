#pragma once
#include <time.h>

inline void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

inline void fill(int* a, int n) {
	for (int i = 0; i < n; i++) {
		//a[i] = rand();
		a[i] = n - i;
	}
}
inline void vivod(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf_s("%d ", a[i]);
	}
}

///////comparators//////////////
int aC(int a, int b) {
	return a - b;
}

int dC(int a, int b) {
	return b - a;
}

int aC2(int a, int b) {
	return a;
}
/////////////////////////////////

inline void bubbleSort(int* arr, int n, int (*comparator)(int, int)) {
	for (int i = n - 1; i >= 0; i--) {
		bool unordered = true;
		for (int j = 0; j < i; j++) {
			if (comparator(arr[j], arr[j + 1]) > 0) {
				swap(&arr[j], &arr[j + 1]);
				unordered = false;
			}
		}
		if (unordered)
			break;
	}
}
inline void insertSort(int* arr, int n, int (*comparator)(int, int)) {
	for (int i = 0; i < n - 1; i++) {
		int key = arr[i + 1];
		for (int j = i; j >= 0; j--) {
			if (comparator(key, arr[j]) < 0) {
				swap(&arr[j], &arr[j + 1]);
			}
			else
				break;
		}
	}
}

inline void selectSort(int* a, int n, int (*comparator)(int, int)) {
	for (int i = 0; i < n; i++) {
		int minIndex = i;
		for (int j = i; j < n; j++) {
			if (comparator(a[j], a[minIndex]) <= 0)
				minIndex = j;
		}
		swap(&a[i], &a[minIndex]);
	}
}

inline int partition(int* arr, int left, int right, int(*comparator)(int, int)) {
	int pivot = arr[right];
	int i = (left - 1);
	for (int j = left; j <= right - 1; j++) {
		if (comparator(arr[j], pivot) < 0) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[right]);
	return (i + 1);
}
inline void quicksort(int* arr, int left, int right, int (*comparator)(int, int)) {
	if (left < right) {
		int pi = partition(arr, left, right, comparator);
		quicksort(arr, left, pi - 1, comparator);
		quicksort(arr, pi + 1, right, comparator);
	}
}
inline void CountingSort(int* a, int n, int (*comparator)(int, int)) {
	int* output = (int*)malloc(n * sizeof(int));
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max)
			max = a[i];
	}
	int* count = (int*)malloc((max + 1) * sizeof(int));
	for (int i = 0; i <= max; ++i)	count[i] = 0;
	for (int i = 0; i < n; i++)	count[a[i]]++;
	for (int i = 1; i <= max; i++)	count[i] += count[i - 1];
	for (int i = n - 1; i >= 0; i--) {
		output[comparator(count[a[i]] - 1, n - 1)] = a[i];
		count[a[i]]--;
	}
	for (int i = 0; i < n; i++)	a[i] = output[i];
}

inline void Merge(int* a, int left, int mid, int right, int(*comparator)(int, int)) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* L = (int*)malloc((mid - left + 1) * sizeof(int));
	int* R = (int*)malloc((right - mid) * sizeof(int));
	for (int i = 0; i < n1; i++)
		L[i] = a[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = a[mid + 1 + j];
	int j, i;
	j = i = 0;
	int k = left;
	while (i < n1 && j < n2) {
		if (comparator(L[i], R[j]) <= 0) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		a[k] = R[j];
		j++;
		k++;
	}
}

void MergeSort(int* a, int left, int right, int (*comparator)(int, int)) {
	if (left >= right) return;
	int mid = (left + right - 1) / 2;
	MergeSort(a, left, mid, comparator);
	MergeSort(a, mid + 1, right, comparator);
	Merge(a, left, mid, right, comparator);
}



//////////////////////////////////////////////////////////
inline void copy(int* arr, int* b, int n) {
	for (int i = 0; i < n; i++)
		b[i] = arr[i];
}

inline void Time(int* arr, int* b, int n, int (*comparator)(int, int), void(func)(int*, int, int(*)(int, int))) {
	copy(arr, b, n);
	clock_t start = clock();
	func(b, n, comparator);
	clock_t end = clock();
	double time = double(end - start) / CLOCKS_PER_SEC;
	printf_s("%lf", time);
}
inline void logTime(int* arr, int* b, int n, int (*comparator)(int, int), void(func)(int*, int, int, int(*)(int, int))) {
	copy(arr, b, n);
	clock_t start = clock();
	func(b, 0, n - 1, comparator);
	clock_t end = clock();
	double time = double(end - start) / CLOCKS_PER_SEC;
	printf_s("%lf", time);
}
