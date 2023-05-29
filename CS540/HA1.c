/*
AlligatorTaffy
February 4th 2019
Homework Assignment #1
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Global Constant Definitions
#define TOKEN_SIZE 64
#define TOKEN_DELIM " \t\n"

// Global Variable to control state of program 
int status = 1;

// Function Definitions
char **words(char *str) {
	int buffer_size = TOKEN_SIZE, i = 0;
	char **tokens = malloc(buffer_size * sizeof(char*));  // Heap array of characters created
	char *token;  // Temporary variable to hold result from strtok

	if(!tokens) {
		printf("Memory Allocation Error!\n");  // Test to make sure malloc was successful
		exit(EXIT_FAILURE);
	}

	token = strtok(str, TOKEN_DELIM);  // First word of string assigned to token
	if(token == NULL) {
		status = 0;  // if NULL is found in intial string, quit program
	}

	while(token != NULL || i <= 63) {  // Cycle through all of the string and separating each word into token and assigning to each slot in array
		tokens[i] = token;
		i++;
		token = strtok(NULL, TOKEN_DELIM);  
	}
	tokens[i] = NULL;  // Endcap the array with NULL pointer

	return tokens;
}

int main () {
    char buf[64];
    while(status) {
    	printf("Brice> ");
    	fgets(buf, 64, stdin);
    	char **command = words(buf);  // Returned tokens assigned to command
    	if(fork() != 0) {
    		waitpid(-1, NULL, 0);
    		free(command);
    	} else {
    		execvp(command[0], command);
    	}
    }

    return 0;
}
