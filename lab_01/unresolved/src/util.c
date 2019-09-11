#include "util.h"
#include "io.h"

#include<stdio.h>

int max(int a, int b){
	logDebug('m');
	if (a >= b)
		return a;
	return b;
}
