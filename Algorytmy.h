#pragma once
#include <vector>
#include <thread>
#include <future>

class Array {
public:
	std::vector<int> arr;	
	int sumaBaseReq();
	int sumaThreadReq();
private:
	int sumaBaseReqFun(int x);
	int sumaThreadReqFun(int x, int y);
};