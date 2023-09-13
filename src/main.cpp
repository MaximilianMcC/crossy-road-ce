#include <ti/screen.h>
#include <ti/getcsc.h>
#include <stdlib.h>

int main()
{
	// Hello world
	os_ClrHome();	
	os_PutStrFull("Hello, world!");

	

	// Exit after a key is pressed
	while (!os_GetCSC());
	return 0;
}