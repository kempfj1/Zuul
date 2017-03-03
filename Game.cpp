#include "Game.h"
/**

 *  This class is the main class of the "World of Zuul" application.
 *  "World of Zuul" is a very simple, text based adventure game.  Users
 *  can walk around some scenery. That's all. It should really be extended
 *  to make it more interesting!
 *
 *  To play this game, create an instance of this class and call the "play"
 *  method.
 *
 *  This main class creates and initialises all the others: it creates all
 *  rooms, creates the parser and starts the game.  It also evaluates and
 *  executes the commands that the parser returns.
 *
 //Zuul Conversion to C++
 //@author Julia Kempf
 //@version 2016.10.05
 */
     /**
     * Create the game and initialise its internal map.
     */
    Game::Game()
    {
        createRooms();
        parser = Parser();
    }



    /**
     * Create all the rooms and link their exits together.
     */
    void Game::createRooms()
    {

        // create the rooms
        Room* grandmasHouse = new Room("you are at grandmas! you're her favorite grandkid, she told you.");
        Room* scaryAssHouse = new Room("you walk up to a really scary ass house");
        Room* reallySmallHouse = new Room("it's a very small house, but they givin out full size bars tho");
        Room* reallyBigHouse = new Room("wow that is a huge house! clearly rich people, but they are probably gluten free, whole grain, anti-vax, soy based vegans");
        Room* fireStation = new Room("the fire station?? this candy bout to be fire");

        // initialise room exits
        grandmasHouse->setExit("east", scaryAssHouse);
        grandmasHouse->setExit("south", reallyBigHouse);
        grandmasHouse->setExit("west", reallySmallHouse);

        scaryAssHouse->setExit("west", grandmasHouse);

        reallySmallHouse->setExit("east", grandmasHouse);

        reallyBigHouse->setExit("north", grandmasHouse);
        reallyBigHouse->setExit("east", fireStation);

        fireStation->setExit("west", reallyBigHouse);

        currentRoom = grandmasHouse;  // start game outside

        Candy* skittles= new Candy("skittles: a delicious multicolored treat (that apparently represents Syrians)");
        Candy* kitkat= new Candy("kitkat: the big kind. not the minis");
        Candy* licorice= new Candy("licorice? nahhhh");
        Candy* kaleChips= new Candy("kaleChips. why would someone give out chips on halloween");
        Candy* starbursts= new Candy("starbursts, supah tasty");

        grandmasHouse->setCandy(skittles);
        scaryAssHouse->setCandy(licorice);
        reallySmallHouse->setCandy(kitkat);
        reallyBigHouse->setCandy(kaleChips);
        fireStation->setCandy(starbursts);
    }



    /**
     *  Main play routine.  Loops until end of play.
     */
    void Game::play()
    {
        printWelcome();

        // Enter the main command loop.  Here we repeatedly read commands and
        // execute them until the game is over.

        bool finished = false;
        while (! finished) {
            Command* command = parser.getCommand();
            finished = processCommand(*command);
        }
        cout <<"Thank you for playing, you have many cavities." << endl;
    }

    /**
     * Print out the opening message for the player.
     */
    void Game::printWelcome()
    {
        cout<<endl;
        cout << "It is October 31st and you know what that means!" << endl;
        cout << "Time to go get candy from your creepy ass neighbors." << endl;
        cout << "Type 'help' if you need help, but hopefully you won't." << endl;
        cout<<endl;
        cout << currentRoom->getLongDescription() << endl;
    }

    /**
     * Given a command, process (that is: execute) the command.
     * @param command The command to be processed.
     * @return true If the command ends the game, false otherwise.
     */
    bool Game::processCommand(Command command)
    {
        bool wantToQuit = false;

        if(command.isUnknown()) {
            cout << "I don't know what you mean..." << endl;
            return false;
        }

        string commandWord = command.getCommandWord();
        if (commandWord=="help") {
            printHelp();
        }
        else if (commandWord=="go") {
            goRoom(command);
        }
        else if(commandWord=="take") {
          printCandy(command);
        }
        else if (commandWord=="quit") {
            wantToQuit = quit(command);
        }
        // else command not recognised.
        return wantToQuit;
    }

    // implementations of user commands:

    /**
     * Print out some help information.
     * Here we print some stupid, cryptic message and a list of the
     * command words.
     */
    void Game::printHelp()
    {
        cout << "You are lost. You are alone. You wander to the house" << endl;
        cout << "of the man who isn't allowed to be within 100 feet of a playground" << endl;
        cout<<endl;
        cout << "Your command words are:" << endl;
        parser.showCommands();
    }

    void Game::printCandy(Command command){//defines all types of candy and removes them using take
      string candyWord= command.getSecondWord();

      if(!command.hasSecondWord()){
        cout << "take what?" << endl;//if no second word is included
      }
      else if(candyWord=="skittles"){
        currentRoom->remove("skittles");
      }
      else if(candyWord=="licorice"){
        currentRoom->remove("licorice");
      }
      else if(candyWord=="kaleChips"){
        currentRoom->remove("kaleChips");
      }
      else if(candyWord=="starbursts"){
        currentRoom->remove("starbursts");
      }
      else if(candyWord=="kitkat"){
        currentRoom->remove("kitkat");
      }
      else{
        cout<<"that candy isn't here"<<endl;
      }
      cout<<"oh look a delicious piece of candy" <<endl;
      cout<< currentRoom->getLongDescription()<< endl;
    }

    /**
     * Try to in to one direction. If there is an exit, enter the new
     * room, otherwise print an error message.
     */
    void Game::goRoom(Command command)
    {

        if(!command.hasSecondWord()) {
            // if there is no second word, we don't know where to go...
            cout << "Go where?" << endl;
            return;
        }

        string direction = command.getSecondWord();
        // Try to leave current room.
        Room* nextRoom = currentRoom->getExit(direction);


        if (nextRoom == NULL) {

            cout << "There is no house!" << endl;
        }
        else {

            currentRoom = nextRoom;

            cout << currentRoom->getLongDescription() << endl;
        }

    }

    /**
     * "Quit" was entered. Check the rest of the command to see
     * whether we really quit the game.
     * @return true, if this command quits the game, false otherwise.
     */
    bool Game::quit(Command command)
    {
        if(command.hasSecondWord()) {
            cout << "Quit what?" << endl;
            return false;
        }
        else {
            return true;  // signal that we want to quit
        }
    }
