#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h> //for ntohs, ntohl
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <fstream> //binary 파일 읽기 
#include "sum.h"

int main(int argc, char *argv[])
{
        int i = argc;//명령줄 인수

	if ( argc < 3 ) { //명령줄 인수 3개가 안되면 오류 
                printf("명령 인수 부족\n");
		return 0;
	}
	
	FILE *fd1=NULL;
        FILE *fd2=NULL;
        
	int len1;
        int len2;

	fd1 = fopen(argv[1], "rb");
	fd2 = fopen(argv[2], "rb");
	

        uint32_t binary_buffer1[32]={0,};

        len1 = fread(binary_buffer1, 1, sizeof(uint32_t), fd1); 
        binary_buffer1[len1] = '\0';        

        uint32_t* p1 = reinterpret_cast<uint32_t*>(binary_buffer1);


        uint32_t binary_buffer2[32]={0,};
        
        len2 = fread(binary_buffer2, 1, sizeof(uint32_t), fd2);
        binary_buffer2[len2] = '\0';        

        uint32_t* p2 = reinterpret_cast<uint32_t*>(binary_buffer2);

        sum(p1, p2);

	fclose(fd2);
	fclose(fd1);

	return 0;
   
     }



