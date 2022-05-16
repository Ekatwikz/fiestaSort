#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define USAGE_STRING "min max sz"
#define ERR_MULTIPROCESS 0
#include "katwikOpsys.h"

void randArray(int* arr, size_t sz, int min, int max) {
	for (size_t i = 0; i < sz; ++i)
		arr[i] = min + rand() % (max - min + 1);
}

void printArray(int* arr, size_t sz) {
	for (size_t i = 0; i < sz; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

bool checkArray(int* arr, size_t sz) {
	for (size_t i = 1; i < sz; ++i)
		if (arr[i - 1] > arr[i])
			return false;
	return true;
}

// sorting with ZERO if statements, ZERO loops, and ZERO (explicit) swaps?!
// boutta do some devious shit xD
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsequence-point"
#pragma GCC diagnostic ignored "-Wparentheses"
#pragma GCC diagnostic ignored "-Wpedantic"
void fiestaSortCLEANISH(int* arr, size_t sz) {
	size_t i = 1, j = 1;

theWildestTernaryStatementIveEverWrittenLmfao:
	j ? // if j isnt 0,
		arr[j--] ^= // decrement j after (just one of many sequence point
			// abuses here xD) we:
			arr[j - 1] > arr[j] ?
			// check if the previous value is greater, and
				arr[j - 1] ^= arr[j] ^= arr[j - 1]
				// use this sexy XOR trick:
				// (x = x xor y; y = y xor x; x = x xor y;)
				// == swap(x, y)
				// notice how in all this, that implies it's still
				// a stable sort lmfao),
			: 0 // otherwise we don't swap
				// (NB: x XOR 0 == x, quite cute)
		: // but if j IS already 0,
			(j = ++i) // we increment i and set j to that,
			< sz ? : ({return;}) // and when they're equal to length
				// , we're done
	;

	goto theWildestTernaryStatementIveEverWrittenLmfao; // otherwise we
	    // keep going
}

void fiestaSortGOLFED(int* arr, size_t sz) {
	size_t i=1,j=1;
x:
	j?arr[j--]^=arr[j-1]>arr[j]?arr[j-1]^=arr[j]^=arr[j-1]:0:(j=++i)<sz?:({return;});
	goto x;
}
#pragma GCC diagnostic pop

int main(int argc, char** argv) {
	// setup
	USAGE(argc > 3);
	int min = atoi(argv[1]);
	int max = atoi(argv[2]);
	USAGE(min <= max);
	size_t sz = atoi(argv[3]);
	USAGE(sz > 1);

	// random numbers
	srand(time(NULL));
	int* arr = malloc(sz * sizeof(int));
	randArray(arr, sz, min, max);
	printArray(arr, sz);

	// sexiest sorting algorithm xD
	fiestaSortGOLFED(arr, sz);
	printArray(arr, sz);
	printf(checkArray(arr, sz) ? "Sorted!\n" : "OOPS!\n");

	FREE(arr);
	return EXIT_SUCCESS;
}
