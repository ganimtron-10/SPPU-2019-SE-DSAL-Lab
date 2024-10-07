/*
Aledutron
SPPU 2019 SE DSAL Lab
SPPU Computer Engineering Second Year (SE) Data Structures &amp; Algorithms (DSA) Lab Assignments (2019 Pattern)
Youtube DSAL Playlist Link: https://www.youtube.com/playlist?list=PLlShVH4JA0ov8DstIyTidJhSmW4WIGa7V

Problem Statement:
Group-E/Q22.cpp
Read the marks obtained by students of second year in an online examination of particular subject. Find out maximum and minimum marks obtained in that subject. Use heap data structure. Analyze the algorithm.

Explaination Video Link: https://www.youtube.com/watch?v=OI0cUNtHLLU&list=PLlShVH4JA0ov8DstIyTidJhSmW4WIGa7V&index=3&pp=iAQB
*/

#include <iostream>
using namespace std;

// min heap
void minInsert(int arr[], int i)
{
	int parent = (i - 1) / 2;
	int cur = i;
	while (parent >= 0 && arr[parent] > arr[cur])
	{
		swap(arr[parent], arr[cur]);
		cur = parent;
		parent = (cur - 1) / 2;
	}
}

// max heap
void maxInsert(int arr[], int i)
{
	int parent = (i - 1) / 2;
	int cur = i;
	while (parent >= 0 && arr[parent] < arr[cur])
	{
		swap(arr[parent], arr[cur]);
		cur = parent;
		parent = (cur - 1) / 2;
	}
}

int main()
{
	int arr[] = {20, 30, 15, 2, 5, 10};

	for (int i = 1; i < 6; i++)
	{
		minInsert(arr, i);
	}

	// cout << "After inserting all: ";
	// for(int i = 0; i < 6; i++){
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;

	cout << "Minimum value is " << arr[0] << endl;

	for (int i = 1; i < 6; i++)
	{
		maxInsert(arr, i);
	}

	cout << "Maximum value is " << arr[0] << endl;
}