#include "common.h"
#include "myLib.h"
#include "sprite.h"

int main()
{
	ncursesInit();
	getStdScr();

	sprite * test;
	sprite * test1;
	test=malloc(sizeof(sprite));
	test1=malloc(sizeof(sprite));
	_sprite(test, 0);
	_sprite(test1, 1);
	test->offset.x=(stdx/2) -40;
	test->offset.y=10;
	test->color=1;
	test1->color=2;


	 
	// ----23--- char each
	_spritePushRow(test," ___________  __    __    _______       _______       __       ___      ___   _______ \0");
	_spritePushRow(test,"(\"     _   \")/\" |  | \"\\  /\"     \"|     /\" _   \"|     /\"\"\\     |\"  \\    /\"  | /\"     \"|\0");
	_spritePushRow(test," )__/  \\\\__/(:  (__)  :)(: ______)    (: ( \\___)    /    \\     \\   \\  //   |(: ______)\0");
	_spritePushRow(test,"    \\\\_ /    \\/      \\/  \\/    |       \\/ \\        /' /\\  \\    /\\\\  \\/.    | \\/    |  \0");
	_spritePushRow(test,"    |.  |    //  __  \\\\  // ___)_      //  \\ ___  //  __'  \\  |: \\.        | // ___)_ \0");
	_spritePushRow(test,"    \\:  |   (:  (  )  :)(:      \"|    (:   _(  _|/   /  \\\\  \\ |.  \\    /:  |(:      \"|\0");
	_spritePushRow(test,"     \\__|    \\__|  |__/  \\_______)     \\_______)(___/    \\___)|___|\\__/|___| \\_______)\0");             
	_spritePushRow(test," _____________________________________________________________________________________\0") ;
	_spritePushRow(test,"                           ---Press any key to continue---\0");
    
	 _spritePushRow(test1,"HELLO\0");
	wrapper();

	test1->offset.y=test->offset.y+1;
	test1->offset.x=test->offset.x-2;
	
	test->rotate(test,100);
	test->draw(test);
	test1->draw(test1);
	test->offset.y+=20;
	test->reset(test);
	test->draw(test);
	sprite_(test);
	sprite_(test1);
	free(test);
	free(test1);
	getch();
	quit();
	return 0;
}
