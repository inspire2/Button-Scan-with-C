#include <stdio.h>
#include <stdlib.h>

#ifndef __MYBOOL_H
#define __MYBOOL_H
typedef enum {
	false = 0,
	true  = 1,
} bool;
#endif

/******************************************************************************
Typedef definitions
******************************************************************************/
#ifndef __TYPEDEF__
typedef signed char         int8_t;
typedef unsigned char       uint8_t;
typedef signed short        int16_t;
typedef unsigned short      uint16_t;
typedef signed long         int32_t;
typedef unsigned long       uint32_t;
typedef signed long long    int64_t;
typedef unsigned long long  uint64_t;
#define __TYPEDEF__
#endif /* __TYPEDEF__ */

#define FLASH_ERROR              			0x5A5A

typedef enum {
	FLASH_OK,
	FLASH_ERROR_READ,
	FLASH_ERROR_WRITE,
	FLASH_ERROR_TIMEOUT,
	FLASH_ERROR_PAGE_SIZE,
}FLASHReturnInfo;

static FLASHReturnInfo Flashx;

uint16_t spi_flash_error = 0;

bool spi_flash_test(void)
{
   uint8_t data[4] = {0x78, 0x56, 0x34, 0x12};
   spi_flash_error = FLASH_ERROR;

   if(data[2] == 0x06)
        {
        Flashx = FLASH_ERROR_READ;
      spi_flash_error = 0;
      return true;
   }
   else
      return false;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
