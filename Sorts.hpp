/**
*	@file : Sorts.hpp
*	@author : Ethan Ward
*	@date : 2015.04.02
*	@brief: Implements the methods described in Sorts.h.
*/
template <typename T>
void Sorts<T>::bubbleSort(T arr[], int size) {

	bool isSorted = false;
	T tempValue = T();
	
	while(!isSorted) {
		isSorted = true;

		for(int i = 0; i < size; i++) {
			if(arr[i] > arr[i+1]) {
				tempValue = arr[i+1];
				arr[i+1] = arr[i];
				arr[i] = tempValue;
				isSorted = false;
			}
		}
	}


	assert( Sorts<T>::isSorted(arr, size) );
}

template <typename T>
void Sorts<T>::bogoSort(T arr[], int size) {

	std::default_random_engine generator(time(nullptr));

	while(!isSorted(arr, size)) {
		shuffle(arr, size, generator);
	}
	
	assert( Sorts<T>::isSorted(arr, size) );
}

template <typename T>
void Sorts<T>::insertionSort(T arr[], int size) {

	T tempValue = T();
	int j;

	for(int i = 1; i < size; i++) {
		j = i-1;
		tempValue = arr[i];
		while(j >= 0 && arr[j] > tempValue) {
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = tempValue;
	}

	assert( Sorts<T>::isSorted(arr, size) );
}

template <typename T>
void Sorts<T>::selectionSort(T arr[], int size) {

	T minValue = T();
	T tempValue = T();	

	for(int i = 0; i < size; i++) {
		minValue = i;
		for(int j = i; j < size; j++) {
			if(arr[j] < arr[minValue]) {
				minValue = j;
			}
		}	
		tempValue = arr[i];
		arr[i] = arr[minValue];
		arr[minValue] = tempValue;
	}

	assert( Sorts<T>::isSorted(arr, size) );
}

template <typename T>
bool Sorts<T>::isSorted(T arr[], int size) {

	if(size <=1) {
		return(true);
	}

	for(int i = 0; i < size-1; i++) {
		if(arr[i] > arr[i+1]) {
			return false;
		}
	}

	
	return(true);
	
}

template <typename T>
void Sorts<T>::shuffle(T arr[], int size, std::default_random_engine& generator) {

	T tempValue = T();
	int tempPlace = 0;
	std::uniform_int_distribution<int> distribution(0,size-1);

	for(int i = 0; i < size; i++) {
		tempPlace = distribution(generator);
		tempValue = arr[tempPlace];
		arr[tempPlace] = arr[i];
		arr[i] = tempValue;
	}
}
