/*
 ============================================================================
 Name        : targil.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char buffer[100];
	//const char EndOfLine[2] = "\n";
	//char *token;

	printf("Enter a sentence. bye to terminate\n");
	fgets(buffer, sizeof(buffer),stdin);
	return EXIT_SUCCESS;
}
