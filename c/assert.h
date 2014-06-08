
/* general adivce when using printf statement with _LINE_ , _FILE_ 
 * use macro , for all other things use inline function */



#define ASSERT(cond) \
	if( !(cond) )\
	{\
		printf( "assertion error line %d, file(%s)\n",__LINE__, __FILE__ );\
	}


/* use this macro if the function where this macro 
 * is called should not return a value */
#define ASSERT_RET(cond,err_str) \
	if( !(cond) )\
	{\
		printf( "%s %d, file(%s)\n",err_str, __LINE__, __FILE__ );\
	}\
	return;

/* use this macro if the function where this macro 
 * is called must return a value */
#define ASSERT_RET_X(cond,X,err_str) \
	if( !(cond) )\
	{\
		printf( "%s %d, file(%s)\n", err_str,__LINE__, __FILE__ );\
	}\
	return X;

/* use this macro if the function where this macro 
 * is called must return a value */
#define ARG_CHECK_RET_X(cond,X) \
	ASSERT_RET_X(cond,X,"Input Argument error");

/* use this macro if the function where this macro 
 * is called must return a value */
#define ARG_CHECK_RET(cond,X) \
	ASSERT_RET(cond,X,"Input Argument error");

static inline void check(int line , char * file_name , int value ) 
{
	if ( !value )
	printf ("error %d, %s", line , file_name );
}

#define ARG_CHK(X) \
	check(__LINE__,__FILE__,(X))


