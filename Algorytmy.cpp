#include "Algorytmy.h"

template<typename T>
T Array<T>::sumaBaseReq()
{
	return sumaBaseReqFun(0);
}

template<typename T>
inline T Array<T>::sumaBaseReqFun(int x) {
	if (x > arr.size()) return 0;
	return arr[x] + sumaBaseReqFun(x + 1);
}
