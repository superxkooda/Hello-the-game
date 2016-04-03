//main menu
void gameObj::mainMenu()
{
    wrapper();
    int key;
    int selected=0;
    int exit=0;
    x=0;
    y=0;
    iterations=0;
    time=0;
    std::string mainOptions[]=
    {
        "New Game",
        "Continue",
        "High Score",
        "Exit"
    };

    menu main(true,1,4, mainOptions);
    //start our main loop for the menu
    while(exit==0)
    {


        x=(stdx/2)-2;

//draw our items and hilight the selected element

        main.draw(win,selected, 36, 10);
        wrefresh(win);
        //timeout(0);
        key=getch();


        switch(key)
        {
        case KEY_UP:
            if(selected>0)
            {
                selected--;
            }
            break;

        case KEY_DOWN:
            if(selected<3)
            {
                selected++;
            }
            break;

        case KEY_ENTER:
        case 10:
        case 13:

            exit=1;
            break;

        default:
            break;


        }


    SLEEP();

    }
    timeout(-1);

    //process the output
    switch(selected)
    {
    case 0: //"New Game":
        newGame();
        //TBA("New Game");
        break;

    case 1: // "Continue":
        TBA("Continue");
        break;
    case 2:// "High Score"
        //    highScore(); // bring to high score screen
        TBA("High Score");
        break;

    case 3: //"Exit":
        quit();

        break;
    }
}
