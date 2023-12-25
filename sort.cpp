#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <random>
#include <conio.h>

int main(void) {
	while (1) {
		int n =INT_MAX;
		int q;
		srand(time(NULL));
		printf("Sort type:\n1 - ascending\n2 - descending\n");
		scanf_s("%d", &q);
		system("cls");
		if (q == 1) {
			for (int i = 10000; i < n; i += 10000) {
				int* a = (int*)malloc(i * sizeof(int));
				int* b = (int*)malloc(i * sizeof(int));
				char c = _kbhit();
				if (!c) {
					fill(a, i);
					printf("Bubble:\t     Select:\t     Insert:\t     Count:\t     Merge:\t     Quick:");
					printf("\nNumber: %d", i);
					printf("\n");
					//Time(a, b, i, aC, bubbleSort); printf("\t");
					//Time(a, b, i, aC, selectSort); printf("\t");
					//Time(a, b, i, aC, insertSort); printf("\t");
					Time(a, b, i, aC2, CountingSort); printf("\t");
					//logTime(a, b, i, aC, MergeSort); printf("\t");
					//logTime(a, b, i, aC, quicksort); printf("\t");
					printf("\n");
					free(a);
					free(b);
				}
				else {
					system("cls");
					break; }
			}
		}
		else if (q == 2) {
			for (int i = 10000; i < n; i += 10000) {
				int* a = (int*)malloc(i * sizeof(int));
				int* b = (int*)malloc(i * sizeof(int));
				char c = _kbhit();
				if (!c) {
					fill(a, i);
					printf("Bubble:\t     Select:\t     Insert:\t     Count:\t     Merge:\t     Quick:");
					printf("\nNumber: %d", i);
					printf("\n");
					Time(a, b, i, dC, bubbleSort); printf("\t");
					Time(a, b, i, dC, selectSort); printf("\t");
					Time(a, b, i, dC, insertSort); printf("\t");
					Time(a, b, i, dC, CountingSort); printf("\t");
					logTime(a, b, i, dC, MergeSort); printf("\t");
					logTime(a, b, i, dC, quicksort); printf("\t");
					printf("\n");
					free(a);
					free(b);
				}
				else {
					system("cls");
					break; }
			}
		}
	}
}