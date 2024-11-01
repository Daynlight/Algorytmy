#pragma once
#include <future>
#include <functional>
#include <chrono>

template <typename T>
class THREAD{
public:
  THREAD(std::function<T()> fun);
	T get();
private:
	std::future<T> e;
};

void Time(std::function<void()> fun);

#include "Dev.hpp"