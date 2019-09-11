#include "io.h"
#include <stdio.h>

void logDebug(char c){
	printf("%c", c);
}

int max(int a, int b){
        logDebug('m');
        if (a >= b)
                return a;
        return b;
}

