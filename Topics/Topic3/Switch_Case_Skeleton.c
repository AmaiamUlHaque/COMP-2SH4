#include <stdio.h>

int main(void)
{
	char cmd;

	printf("Provide a character command: ");
	scanf("%c", &cmd);

	// Try switching on w, a, s, d, W, A, S, D

	switch(cmd){
		case 'W':
		case 'w':
			printf("going up\n");
			break;

		case 'A':
		case 'a':
			printf("going left\n");
			break;

		case 'S':
		case 's':
			printf("going down\n");
			break;

		case 'D':
		case 'd':
			printf("going right\n");
			break;

		default:
			printf("unrecognised key. only: WwAaSsDd");
			break;
		



	}

	return 0;
}