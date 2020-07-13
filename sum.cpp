#include "sum.h"
#include <stdio.h>
#include <netinet/in.h>



void sum(uint32_t* p1, uint32_t* p2 ){

        uint32_t n1 = ntohl(*p1); 
        uint32_t n2 = ntohl(*p2); 

        uint32_t n = n1 + n2;

	printf("%d(0x%x) + %d(0x%x)  = %d(0x%x)\n "
			, n1,n1,n2,n2,n,n);


}
