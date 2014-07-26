/*
Comment on the use of macros in the following code
Is there a more elegant solution?

#if PLATFORM_A
unsigned int channels;
#else
unsigned char channels;
#endif

#if PLATFORM_A
void init_channels(unsigned int num_channels)
#else
void init_channels(unsigned char num_channels)
#endif
{
   channels = num_channels;
}

void reset(void)
{
   init();
   
   int i;
#if PLATFORM_A
   for (i = 0; i < 9; i++)
      clear_channel(i);
#elif PLATFORM_B
   for (i = 10; i < 19; i++)
      clear_channel(i);
#elif PLATFORM_C
   for (i = 0; i < 29; i++)
      clear_channel(i);
#endif
   
#if PLATFORM_B
   int flush_timeout = 20;
#else
   int flush_timeout = 10;
#endif
   
   while (fifo_is_full())
   {
      flush_queues();
      
#if PLATFORM_C
      clear_cache();
#endif
      
      if (--flush_timeout < 0)
         break;
   }
   
#if PLATFORM_A
   printlog("reset done on platform");
#elif PLATFORM_B
   printlog("reset done on new system");
#elif PLATFORM_C
   printlog("reset done on gen3");
#endif   
}
*/

/*
	the macro are distributed across the code instead
	can be represented as below
*/


#if PLATFOM_A

typedef unsigned int chn_type;  
#define LOWER_LIMIT  (0)
#define UPPER_LIMIT  (9)
#define TIME_OUT     (10)
#define RST_STR      "reset done on platform"   

#elif PLATFORM_B

typedef unsigned char chn_type;  
#define LOWER_LIMIT  (10)
#define UPPER_LIMIT  (19)
#define TIME_OUT     (20)
#define RST_STR      "reset done on new system"   

#else

typedef unsigned char chn_type;  
#define LOWER_LIMIT  (0)
#define UPPER_LIMIT  (29)
#define TIME_OUT     (10)
#define RST_STR      "reset done on gen3"   

#endif

chn_type channels;
void init_channels(chn_type num_channels)
{
   channels = num_channels;
}

void flush_queues (void)
{
	;
}

void printlog (char *ptr)
{
	;
}

void init(void)
{
	;	
}

void clear_cache(void)
{
	;
}

void clear_channel ( int i)
{
	;
}

int fifo_is_full (void)
{
	return 0;
}

void reset(void)
{
   init();
   
   int i;
   
   for (i = LOWER_LIMIT ; i < UPPER_LIMIT; i++)
      clear_channel(i);
  
   int flush_timeout = TIME_OUT;
   
   while (fifo_is_full())
   {
      flush_queues();
      
#if PLATFORM_C
      clear_cache();
#endif
      
      if (--flush_timeout < 0)
         break;
   }
   
   printlog(RST_STR);
}


int main ( int argc , char *argv[] )
{
	reset();
	return 0;
}





