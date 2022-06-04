#define USAGE_STRING "min max sz\n"\
	"min - lower bound for randomizer in test\n"\
	"max - upper \"\n"\
	"sz - amount of random numbers"
#define ERR_MULTIPROCESS 0
#include "katwikOpsys.h"

// you can ignore this chunk, it doesn't actually compile anything extra,
// but it asks GCC to shut up just for these functions, because parts of this are
// just borderline undefined behaviour lol
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsequence-point"
#pragma GCC diagnostic ignored "-Wparentheses"
#pragma GCC diagnostic ignored "-Wpedantic"

void fiestaSort(int* arr, size_t sz) {
	size_t i=1,j=0;
x:
	j?arr[j--]^=arr[j-1]>arr[j]?arr[j-1]^=arr[j]^=arr[j-1]:0:(j=++i)<sz?:({return;});
	goto x;
}

void fiestaSortCLEANISH(int* arr, size_t sz) {
	size_t i = 1, j = 0;

bigTernary:
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
				// kinda a stable sort lmfao),
			: 0 // otherwise we don't swap
				// (NB: x XOR 0 == x, quite cute)
		: // but if j IS already 0,
			(j = ++i) // we increment i and set j to that,
			< sz ? : ({return;}) // and when they're equal to length
				// , we're done
	;

	goto bigTernary; // otherwise we
	    // keep going
}

// and now we're done clowning lol
#pragma GCC diagnostic pop

// stuff for testing
void randArray(int* arr, size_t sz, int min, int max);
void printArray(int* arr, size_t sz);
bool checkArray(int* arr, size_t sz);

int main(int argc, char** argv) {
	// get arguments and setup
	USAGE(argc > 3);
	int min = atoi(argv[1]);
	int max = atoi(argv[2]);
	USAGE(min <= max);
	int sz = atoi(argv[3]);
	USAGE(sz > 0);

	// make and print array of random numbers
	srand(time(NULL));
	int* arr = malloc_(sz * sizeof(int));
	randArray(arr, sz, min, max);
	printArray(arr, sz);

	// sort the array and print it
	fiestaSort(arr, sz);
	printArray(arr, sz);
	
	// test if it's actually sorted
	bool arrayWasSorted = checkArray(arr, sz);
	printf_(arrayWasSorted ? "Sorted!\n" : "OOPS!\n");

	// cleanup and exit
	FREE(arr);
	return arrayWasSorted ? EXIT_SUCCESS : EXIT_FAILURE;
}

void randArray(int* arr, size_t sz, int min, int max) {
	for (size_t i = 0; i < sz; ++i) {
		arr[i] = myRand(min, max);
	}
}

void printArray(int* arr, size_t sz) {
	for (size_t i = 0; i < sz; ++i) {
		printf_("%d ", arr[i]);
	}

	printf_("\n");
}

bool checkArray(int* arr, size_t sz) {
	for (size_t i = 1; i < sz; ++i) {
		if (arr[i - 1] > arr[i]) {
			return false;
		}
	}

	return true;
}
