
#include "demos/EntityDemo.h"

/*Misc TODO List :
 - Reorganize file structure in BCEngine (Folders, etc)
 - Look into RenderWindow/Env/InputBuffer making methods const, don't want to think about it yet
*/
int main(int argc, char* argv[])
{
	Demos::EntityDemo entityDemo;
	entityDemo.Start();

	return 0;
}