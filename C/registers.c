/* You have 2 functions:getReg and setReg. 
They convert from Big Endian to Little Endian */
#include <stdio.h>
#include "main.h"

#define getReg(addr) (*((volatile U32 *)addr))


U32 getLittleReg(volatile U32 *); //Returns converted to Little Endian format
void setReg(volatile U32 *, U32 val);

void main()
{
	U32 val;
	
	printf("Current content of the register is:0x%x\n", getReg(REG));
	printf("Current content of the register in Little Endian is:0x%x\n", getLittleReg(REG));
	printf("Now enter value to set register\n");
	scanf("%x", &val);
	setReg(REG,val);
	printf("Current content of the register is:0x%x\n", getReg(REG));
	printf("Current content of the register in Little Endian is:0x%x\n", getLittleReg(REG));
}



U32 getLittleReg(volatile U32 *preg)
{
	U32 temp = *preg<<24;	
	temp |= ((*preg<<8) & 0x00FF0000);
	temp |= ((*preg>>8) & 0x0000ff00);
	temp |= ((*preg>>24) & 0x000000ff);
	return temp;
}

void setReg(volatile U32 *preg, U32 val)
{
	getReg(preg) = val;
	getReg(preg) = getLittleReg(preg);
}
