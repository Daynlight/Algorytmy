#pragma once
#include <future>
#include <random>
#include <ctime>
#include <functional>
#include <chrono>

static bool PRINT = 0;

template <typename T>
T Random(T x, T y);

#include "Dev.hpp"