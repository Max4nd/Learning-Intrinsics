#include <iostream>
#include <immintrin.h>
using namespace std;

//Function to add 2 floats 8 times simultaneously
//This is completly useless and has no real world application whatsoever 
float* addSimultaneously(float a, float b) {
	//Registers
	__m256 _x, _y, _mask;

	//Set the values of the registers
	_x = _mm256_set1_ps(a);
	_y = _mm256_set1_ps(b);

	//Format: __mm<size>_<operation>_<datatype>
	//This just adds the 2 vectors
	_mask = _mm256_add_ps(_x, _y);

	//Cast the adress of the __m256 type to a float pointer to access
	return (float*)&_mask;
}

int main() {

	//print 
	for (int i = 0; i < 8; i++)
		cout << addSimultaneously(5, 5)[i] << " ";

	return 0;
}