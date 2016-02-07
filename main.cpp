/**
*	@file : main.cpp
*	@author : Ethan Ward
*	@date : 2015.04.02
*	@brief: Creates random int arrays of variable sizes, and allows the user to create and sort arrays for as long as they want.
*/
#ifndef MAIN_CPP
#define MAIN_CPP

#include "Sorts.h"
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <cassert>

int* createRandomIntArray(int size, int min, int max) {

	int* nums = new int[size];
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(min,max);
	
	for(int i = 0; i < size; i++) {
		nums[i] = distribution(generator);
	}

	return(nums);
}

void printMenu() {

	std::cout 	<< "\n\nSelect a sort:\n"
			<< "1) Bubble Sort\n"
			<< "2) Insertion Sort\n"
			<< "3) Selection Sort\n"
			<< "4) Bogo Sort (use only with very small arrays!)\n"
			<< "Enter choice: ";
}

int main() {

Sorts<int> sort = Sorts<int>();
int* nums;
int size = 0;
int minValue = 0;
int maxValue = 0;
char stop = ' ';
int choice = 0;
std::chrono::system_clock::time_point start;
std::chrono::system_clock::time_point end;
std::chrono::duration<double> elapsed;


while(stop != 'y') {

	printMenu();
	std::cin >> choice;

	std::cout << "\nInput a size for the random array: ";
	std::cin >> size;

	std::cout <<"\nInput a lower bound on the range of random numbers: ";
	std::cin >> minValue;

	std::cout << "\nInput an upper bound on the range of random numbers: ";
	std::cin >> maxValue;

	nums = createRandomIntArray(size, minValue, maxValue);

	std::cout << "\nDo you want to print the unsorted array? (y/n): ";
	std::cin >> stop;

	if(stop == 'y') {
		std::cout << "\nHere is the unsorted array:\n";		
		for(int i = 0; i < size; i++) {
			if(i == 0) {
				std::cout << "[";
			}
			if(i < size-1) {
				std::cout << nums[i] << ",";
			}
			if(i == size-1) {
				std::cout << nums[i] << "]";
			}
		}
	}

	if(choice == 1) {
		std::cout << "\n\nSorting with bubble sort...\n";
		start = std::chrono::system_clock::now();
		
		sort.bubbleSort(nums, size);
		
		end = std::chrono::system_clock::now();
		elapsed = (end - start);
	}

	else if(choice == 2) {
		std::cout << "\n\nSorting with insertion sort...\n";
		start = std::chrono::system_clock::now();
		
		sort.insertionSort(nums, size);
		
		end = std::chrono::system_clock::now();
		elapsed = (end - start);
	}

	else if(choice == 3) {
		std::cout << "\n\nSorting with selection sort...\n";
		start = std::chrono::system_clock::now();
		
		sort.selectionSort(nums, size);
		
		end = std::chrono::system_clock::now();
		elapsed = (end - start);
	}

	else if(choice == 4) {
		std::cout << "\n\nSorting with bogo sort...\n";
		start = std::chrono::system_clock::now();
		
		sort.bogoSort(nums, size);
		
		end = std::chrono::system_clock::now();
		elapsed = (end - start);
	}

	else {
		std::cout << "Invalid choice";
	}
	
	if(choice == 1 || choice == 2 || choice == 3 || choice == 4) {
		std::cout << "Do you want to print the sorted array? (y/n): ";
		std::cin >> stop;
		
		if(stop == 'y') {
			std::cout << "\nHere is the sorted array:\n";
			for(int i = 0; i < size; i++) {
				if(i == 0) {
					std::cout << "[";
				}
				if(i < size-1) {
					std::cout << nums[i] << ",";
				}
				if(i == size-1) {
					std::cout << nums[i] << "]";
				}
			}
		}
	} 	
	
	std::cout << "\n\n" << size << " numbers were sorted in " << elapsed.count() << " seconds";
	std::cout << "\n\nDo you want to quit? (y/n)";
	std::cin >> stop;
	delete [ ] nums;

}


};

#endif
