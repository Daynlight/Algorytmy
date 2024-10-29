#pragma once
#include <vector>
#include <future>

class Suma {
public:
	Suma();
	Suma(std::initializer_list<int> inArr);
	int sumaBaseReq();
	int sumaThreadReq();
	size_t size();
	void reserve(int n);
	void emplace_back(int n);
	int THREADSDEEPLEVEL = 0;
private:
	int ThreadsLevel = 0;
	std::vector<int> arr;
	int sumaBaseReqFun(int x);
	int sumaThreadReqFun(int x, int y);
};