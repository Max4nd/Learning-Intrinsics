#include <iostream>
#include <immintrin.h>
using namespace std;

float* addSimultaneously(float a, float b) {
	__m256 _x, _y, _mask;

	_x = _mm256_set1_ps(a);
	_y = _mm256_set1_ps(b);

	_mask = _mm256_add_ps(_x, _y);

	return (float*)&_mask;
}

int main() {

	for (int i = 0; i < 8; i++)
		cout << addSimultaneously(5, 5)[i] << " ";

	return 0;
}