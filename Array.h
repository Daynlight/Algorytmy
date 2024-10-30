#pragma once
#include <vector>
#include <future>

template<typename T>
class Array {
public:
	Array();
	Array(std::initializer_list<T> inArr);
	size_t size();
	void reserve(int n);
	void emplace_back(int n);
	int THREADSDEEPLEVEL = 0;
	template<typename S>
	S sumaBaseReq();
	template<typename S>
	S sumaThreadReq();
private:
	int ThreadsLevel = 0;
	std::vector<T> arr;
	template<typename S>
	S sumaBaseReqFun(int x);
	template<typename S>
	S sumaThreadReqFun(int x, int y);
};

template<typename T>
Array<T>::Array() {
}

template<typename T>
Array<T>::Array(std::initializer_list<T> inArr) {
	arr.reserve(inArr.size());
	for (const int el : inArr)
		arr.emplace_back(el);
}

template<typename T>
template<typename S>
S Array<T>::sumaBaseReq() {
	return sumaBaseReqFun(0);
}

template<typename T>
template<typename S>
S Array<T>::sumaBaseReqFun(int x) {
	if (x >= arr.size()) return 0;
	return arr[x] + sumaBaseReqFun(x + 1);
}

template<typename T>
size_t Array<T>::size() {
	return arr.size();
}

template<typename T>
void Array<T>::reserve(int n) {
	arr.reserve(n);
}

template<typename T>
void Array<T>::emplace_back(int n) {
	arr.emplace_back(n);
}

template<typename T>
template<typename S>
S Array<T>::sumaThreadReq() {
	return sumaThreadReqFun<S>(0, arr.size() - 1);
}

template<typename T>
template<typename S>
S Array<T>::sumaThreadReqFun(int x, int y) {
	if (y - x == 0) return arr[x];
	else if (y - x == 1) return arr[x] + arr[y];
	else if (y - x < 0) return 0;

	S a = 0, b = 0;
	if (ThreadsLevel < THREADSDEEPLEVEL) {
		std::future<S> eventA = std::async(std::launch::async, [this](int a, int b) { return sumaThreadReqFun<S>(a, b); }, x, (y - x) / 2 + x);

		ThreadsLevel++;
		b = sumaThreadReqFun<S>((y - x) / 2 + x + 1, y);
		a = eventA.get();
		ThreadsLevel--;
	}
	else {
		a = sumaThreadReqFun<S>(x, (y - x) / 2 + x);
		b = sumaThreadReqFun<S>((y - x) / 2 + x + 1, y);
	}

	return a + b;
}
