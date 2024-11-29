#include "../Array.h"

template<typename T>
inline T Array<T>::lineSum(const size_t x, const size_t y) {
	T sum = 0;
	for (size_t i = x; i < y; i++)
		sum += data_array[i];
	return sum;
}
