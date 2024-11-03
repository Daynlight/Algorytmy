#include "Array.h"
template<typename T>
ARRAY<T>::ARRAY() {
}

template<typename T>
ARRAY<T>::ARRAY(std::initializer_list<T> inArr) {
	arr.reserve(inArr.size());
	for (const int el : inArr)
		arr.emplace_back(el);
}

template<typename T>
size_t ARRAY<T>::size() {
	return arr.size();
}

template<typename T>
void ARRAY<T>::reserve(int n) {
	arr.reserve(n);
}

template<typename T>
void ARRAY<T>::emplace_back(int n) {
	arr.emplace_back(n);
}

template<typename T>
inline T ARRAY<T>::operator[](size_t n){
	return arr[n];
}

template<typename T>
inline std::vector<T>::iterator ARRAY<T>::begin() {
	return arr.begin();
}

template<typename T>
inline std::vector<T>::iterator ARRAY<T>::end() {
	return arr.end();
}

template<typename T>
template<typename S>
S ARRAY<T>::HalfThreadSumReq() {
	return HalfThreadSumReqFun<S>(0, arr.size() - 1);
}

template<typename T>
template<typename S>
inline S ARRAY<T>::HalfThreadAndLineSum() {
	int x = 0, y = arr.size();

	if (y - x == 0) return arr[x];
	else if (y - x == 1) return arr[x] + arr[y];
	else if (y - x < 0) return 0;

	S a = 0, b = 0;
	if (ThreadsLevel < THREADSDEEPLEVEL) {
		std::future<S> eventA =
			std::async(std::launch::async, [this, &x, &y] { return HalfThreadSumReqFun<S>(x, (y - x) / 2 + x); });

		ThreadsLevel++;
		b = HalfThreadSumReqFun<S>((y - x) / 2 + x + 1, y);
		a = eventA.get();
	}
	else {
		a = LineSum<S>(x, (y - x) / 2 + x);
		b = LineSum<S>((y - x) / 2 + x + 1, y - 1);
	}

	return a + b;
}

template<typename T>
template<typename S>
inline S ARRAY<T>::LineSum(int x, int y) {
	S suma = 0;
	for (int i = x; i < y + 1; i++)
		suma += static_cast<S>(arr[i]);
	return suma;
}

template<typename T>
void ARRAY<T>::InsertionSort() {
	for (int i = 1; i < arr.size(); ++i) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

template<typename T>
template<typename S>
S ARRAY<T>::HalfThreadSumReqFun(int x, int y) {
	if (y - x == 0) return arr[x];
	else if (y - x == 1) return arr[x] + arr[y];
	else if (y - x < 0) return 0;

	S a = 0, b = 0;
	if (ThreadsLevel < THREADSDEEPLEVEL) {
    std::future<S> eventA = 
		std::async(std::launch::async, [this,&x,&y] { return HalfThreadSumReqFun<S>(x, (y - x) / 2 + x); });

		ThreadsLevel++;
		b = HalfThreadSumReqFun<S>((y - x) / 2 + x + 1, y);
		a = eventA.get();
	}
	else {
		a = HalfThreadSumReqFun<S>(x, (y - x) / 2 + x);
		b = HalfThreadSumReqFun<S>((y - x) / 2 + x + 1, y);
	}

	return a + b;
}
