/*
	simpler form of the macro can be as below
*/

#include <stdio.h>
#include <string.h>

typedef struct test {
    int dummy[10];
} TST;


int send_req_cfg ( int msg_id, TST * tst, int tst_sz );

#define ODU_MESSAGE_CFG_RFBAND (1)
#define ODU_MESSAGE_CFG_UPPERLOWERBAND (2)
#define ODU_MESSAGE_CFG_TRSPACING (3)
#define ODU_MESSAGE_CFG_TXPOWERMIN (4)
#define ODU_MESSAGE_CFG_TXPOWERMAX (5)
#define ODU_MESSAGE_CFG_RXFREQMIN (6)
#define ODU_MESSAGE_CFG_RXFREQMAX (7)
#define ODU_MESSAGE_CFG_TXFREQMIN (8)
#define ODU_MESSAGE_CFG_TXFREQMAX (9)
#define ODU_MESSAGE_CFG_SERIAL (10)
 

#define SEND_REQ_CFG(a,b,c,d,e,f,g,h,i,j) {((send_req_cfg(ODU_MESSAGE_CFG_RFBAND, &a, sizeof(a)) ==0 ) \
&& ( send_req_cfg(ODU_MESSAGE_CFG_UPPERLOWERBAND, &b, sizeof(b)) == 0 ) \
&& ( send_req_cfg(ODU_MESSAGE_CFG_TRSPACING, &c, sizeof(c)) ==0 ) \
&& ( send_req_cfg(ODU_MESSAGE_CFG_TXPOWERMIN, &d, sizeof(d)) ==0 ) \
&& ( send_req_cfg(ODU_MESSAGE_CFG_TXPOWERMAX, &e, sizeof(e)) ==0 ) \
&& ( send_req_cfg(ODU_MESSAGE_CFG_RXFREQMIN, &f, sizeof(f)) ==0 ) \
&& ( send_req_cfg(ODU_MESSAGE_CFG_RXFREQMAX, &g, sizeof(g)) ==0 ) \
&& ( send_req_cfg(ODU_MESSAGE_CFG_TXFREQMIN, &h, sizeof(h)) ==0 ) \
&& ( send_req_cfg(ODU_MESSAGE_CFG_TXFREQMAX, &i, sizeof(i)) ==0 ) \
&& ( send_req_cfg(ODU_MESSAGE_CFG_SERIAL, &j, sizeof(j)) ==0 ) );} 

int send_req_cfg ( int msg_id, TST * tst, int tst_sz )
{
    return 0; 
}

TST rf_band, upper_lower, spacing, tx_power_min, tx_power_max, rx_freq_min, rx_freq_max, tx_freq_min, tx_freq_max, serial;

int init_cfg(void)   
{
   return ( SEND_REQ_CFG( rf_band, upper_lower, spacing, tx_power_min, tx_power_max, rx_freq_min, rx_freq_max, tx_freq_min, tx_freq_max, serial));
}

int main (void )
{
    init_cfg();
	
	return 0;
}



