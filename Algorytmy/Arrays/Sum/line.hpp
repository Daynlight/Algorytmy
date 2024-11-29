#include "../Array.h"

template<typename T>
inline T Array<T>::lineSum(const size_t x, const size_t y) {
	T suma = 0;
	for (size_t i = x; i < y; i++)
		suma += data_array[i];
	return suma;
}
