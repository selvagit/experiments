/* test code for testing the various assert 
 * function and macros that are created */

#include "stdio.h"
#include "./assert.h"

int main ( int argc , char *argv[] )
{

	ASSERT(0);
	ASSERT(1);

	ASSERT_RET_X(0,1, "Assert failure" )
	ASSERT_RET_X(1,1, "Assert failure" )

	ASSERT(0);

	return 1;
}


