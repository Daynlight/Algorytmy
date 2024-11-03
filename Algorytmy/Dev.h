#pragma once
#include <future>
#include <random>
#include <ctime>
#include <functional>
#include <chrono>

static bool PRINT = 0;
static bool PRINTTESTS = 0;

template <typename T>
T Random(T x, T y);

class PROGRESSBAR {
public:
	PROGRESSBAR(int last = 100, int size = 50);
	void Render(int current);
private:
	int size = 50;
	float step = 1;
	int current_step = 0;
	int last = 100;
	float percentage = 0.0f;
	std::string res = "";
};

#include "Dev.hpp"