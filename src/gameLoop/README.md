#gameLoop
The intent is to create a game loop to animate against. I am not sure it needs to be all encompasing or not yet.
The idea will be to have a function that takes two arguments, a pointer to your update function and a pointer to 
your draw function. The reason for this is because I would like the option for text based interaction in the form
of both a menu and open ended response one would require a loop to check for keypresses to navigate a menue
while the other would simply use the ncurses built in functions to retrive keyboard imput from the user.
Becuse of this I do not need an all encompassing game loop running all the time. This is the idea of course
and it may be very wrong and maybe I do need a more standard looping method for this application. 
   //This is the gist of it
   void gameLoop(int * update(), void draw())
    {
    	int exit=0;
	//frame skip logic
	// ...
	//goes here

    	while(exit==0)
	{
		exit=update();
		draw();
	}
    }
