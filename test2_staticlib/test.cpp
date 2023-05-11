// test.cpp

#include <iostream>
#include "StaticMath.h"

int main(){

	double a=1.2;
	double b=2.4;
	std::cout<< "a+b="<<StaticMath::add(a,b)<<std::endl;
	//StaticMath::sub(b,a);
	return 0;

}
