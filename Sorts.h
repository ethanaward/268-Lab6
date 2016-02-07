/**
*	@file : Sorts.h
*	@author : Ethan Ward
*	@date : 2015.04.02
*	@brief: Has 4 methods to sort arrays in a variety of ways, a boolean method to check if the array is sorted, and a private shuffle method to help bogo sort.
*/
#ifndef SORTS_H
#define SORTS_H

#include <random>
#include <ctime>
#include <cassert>

template <typename T>
class Sorts {

public:
/**
	*  @pre None
	*  @post The array passed in is sorted using the bubble sort algorithm.
	*  @return None
	*/
	static void bubbleSort(T arr[], int size);
/**
	*  @pre None
	*  @post The array passed in is sorted using the bogo sort algorithm.
	*  @return None
	*/
	static void bogoSort(T arr[], int size);
/**
	*  @pre None
	*  @post The array passed in is sorted using the insertion sort algorithm.
	*  @return None
	*/
	static void insertionSort(T arr[], int size);
/**
	*  @pre None
	*  @post The array passed in is sorted using the selection sort algorithm.
	*  @return None
	*/
	static void selectionSort(T arr[], int size);
/**
	*  @pre None
	*  @post None
	*  @return Returns true if the array is in ascending order, and false otherwise.
	*/
	static bool isSorted(T arr[], int size);
private:
/**
	*  @pre None
	*  @post The array passed in is shuffled randomly, with the value at each index in the array being swapped with the value at a random index.
	*  @return None
	*/
	static void shuffle(T arr[], int size, std::default_random_engine& generator);
};

#include "Sorts.hpp"

#endif
