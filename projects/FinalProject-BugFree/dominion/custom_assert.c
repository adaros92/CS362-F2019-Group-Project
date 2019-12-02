#include "custom_assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* assert(int val1, int val2)
{
	if (val1 == val2) {
		return "true";
	}
	else {
		return "false";
	}
}