//
//  Sort.h
//  CppTest
//
//  Created by meng zhang on 28/03/2015.
//  Copyright (c) 2015 meng zhang. All rights reserved.
//

#ifndef CppTest_Sort_h
#define CppTest_Sort_h

#include "global.h"

class Node {
public:
	int mIndex;
	Node* next;
	Node(int a):mIndex(a)
	{
		next = NULL;
	}
};

Node* reverselist(Node* head)
{
	Node *tail = head;
	Node* tmp = head->next;
	head->next = NULL;
	while (tmp->next) {
		head = tmp->next;
		tmp->next = tail;
		tail = tmp;
		tmp = head;
	}
	head->next = tail;
	return head;
}

void swap(int arr[], int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void selectionsort(int array[], int len)
{
	int arr[len];
	memcpy(arr, array, len*sizeof(int));
	int min, mindex;
	for (int i = 0; i < len; i++) {
		min = arr[i];
		mindex = i;
		for (int j = i+1; j < len; j++) {
			if (arr[j] < min) {
				min = arr[j];
				mindex = j;
			}
		}
		swap(arr, i, mindex);
	}
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
}

void bubblesort(int array[], int len)
{
	int arr[len];
	memcpy(arr, array, len*sizeof(int));
	bool finish = true;
	for (int i = len-1; i > 0; i --) {
		finish = true;
		for (int j = 0; j < i; j ++) {
			if (arr[j] > arr[j+1]) {
				swap(arr, j, j+1);
				finish = false;
			}
		}
		if (finish) {
			break;
		}
	}
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
}

void quicksort(int arr[], int len)
{
	if (len < 2) {
		return;
	}
	int mid = arr[len/2];
	int i, j;
	printf("mid: %d\n", mid);
	for (i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	for (i = 0, j = len-1; i < j;) {
		if (arr[i] >= mid) {
			while (arr[j] > mid && i < j)
				j--;
			if (i < j) {
				swap(arr, i, j);
			}
		}
		i++;
	}
	quicksort(arr, i);
	quicksort(&arr[j], len-j);
}

int binarySearch(vector<int> &array, int target) {
	int size = (int)array.size();
	if (size < 1)
		return -1;
	if (array.size())
	if (target < array[0] || target > array[array.size() - 1])
		return -1;
	if (target == array[0])
		return 0;
	
	vector<int> top(array.begin(), array.begin() + size/2);
	vector<int> bottom(array.begin() + size/2, array.end());
	
	int ret = binarySearch(top, target);
	if (ret != -1)
		return ret;
	ret = binarySearch(bottom, target);
	if (ret != -1)
		return ret + size/2;
	
	return -1;
}

void test_binarySearch()
{
	vector<int> array = {0};
	int target = 3;
	
	for (int i = 0; i < array.size(); i ++)
		printf("%d, ", array[i]);
	cout << endl;
	printf("target: %d\n", target);
	
	int index = binarySearch(array, target);
	printf("index:%d\n", index);
}

#endif
