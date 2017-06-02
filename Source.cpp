/*Author: David Wigelius
------------------------
A simple organizer that lets a user add participants for a race,
the participants can be either joggers or professionals. The user
is presented with a simple menu that lets them organize all of the
entered participants in alphabetical order. It also allows them to
edit the existing participants.
------------------------
*/

#include<string>
#include<iostream>
#include "Registry.h"
#include "Menu.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Menu menu;
	menu.run();
	return 0;
}