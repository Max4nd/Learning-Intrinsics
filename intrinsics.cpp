#include <iostream>
#include <immintrin.h>
using namespace std;

//Simplifies __m128 operations
struct fourValues {
	float a, b, c, d;
	fourValues(float setA, float setB, float setC, float setD) {
		a = setA;
		b = setB;
		c = setC;
		d = setD;
	}
};

//Simplifies __m256 operations
struct eightValues {
	float a, b, c, d, e, f, g, h;
	eightValues(float setA, float setB, float setC, float setD, float setE, float setF, float setG, float setH) {
		a = setA;
		b = setB;
		c = setC;
		d = setD;
		e = setE;
		f = setF;
		g = setG;
		h = setH;
	}
};

//Function to add 2 floats 8 times simultaneously
//This is completly useless and has no real world application whatsoever 
float* addSimultaneously(eightValues a, eightValues b) {
	//Registers
	__m256 _x, _y, _mask;

	//Set the values of the registers
	_x = _mm256_set_ps(a.a, a.b, a.c, a.d, a.e, a.f, a.g, a.h);
	_y = _mm256_set_ps(b.a, b.b, b.c, b.d, b.e, b.f, b.g, a.h);

	//Format: __mm<size>_<operation>_<datatype>
	//This just adds the 2 vectors
	_mask = _mm256_add_ps(_x, _y);

	//Cast the adress of the __m256 type to a float pointer to access
	return (float*)&_mask;
}

int main() {

	//pass in some values
	eightValues test1(3.0, 6.0, 8.0, 9.0, 100.0, 12.0, 7.0, 8.0);
	eightValues test2(3.0, 6.0, 8.0, 9.0, 100.0, 12.0, 7.0, 8.0);

	//print 
	for (int i = 0; i < 8; i++)
		cout << addSimultaneously(test1, test2)[i] << " ";

	return 0;
}