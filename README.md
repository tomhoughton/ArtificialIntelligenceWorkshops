# ArtificialIntelligenceWorkshops

These are the notes for my artificial intelligence work

# Notes:

## Main.cpp
- defines the main function (entry point of the program)
- Kiads graphics, creates main game objects)
- The main program runs in a while loop (LINE 90)
- (LINE 84) the bot object is created, which is the type cBotRandom.
- Line 70 loads the map from a txt file definition '0.txt'

## Level .h/.cpp
- Contains the code for the cLevel class, which loads the txt file map and turns it into a 2D grid representing the level.
- Positions in the grid are recorded where (0,0) is in the top left and (39,39) is the in the botton right
- The axis remmain x 'horizontal' and y 'verticle'
- NO NEED TO CHANGE THIS CLASS!!!

## Dynamic .h/.cpp
- This animates the player and bot classes. 
- All moving objects ingherit from this class.
- Set a new grid position for a dynamic object using the 'SetNext()' function.
    - This smoothly moves the object from one position to the other. This takes half a second and is controlled by the Update() function.
- NOTE: the new location must be a grid location that is adjacent to its current position.
- NO NEED TO CHANGE THIS CLASS !!!

## Botbase.h
- This is a base class for the other AI bot classes.
    - As a base class you cannot create an object of this type directly.
    - It inherits from the Dynamic class.
    - A key part of this class is the virtual function 'ChooseNextGridPosition().
        - This is called automatically when the bot arrives at a new grid location.
        - This decides which location to mave to next. 
        - Since this is called automatically the bots are always moving.
- To make new bot classes we inherit from this class.
    - Then write a new version of 'ChooseNextGridPosition()' to control its devision making process.
- NO NEED TO CHANGE THIS CLASS !!!

## Bots.h and botRandom.cpp
- Bots.h contains the definition for the class cBotRandom.
    - This is an example bot class
    - This is intantiated in the main function.
- All bot classes inherit from BotBase.h
- All that is required to make the BotRandom class is to write the definition in bot.h, then write its 'ChooseNextGridPosition()' function.
    - The while loop in this function is only there incase an invalid position is chosen.
    
## Creating bots
- When creating a new bot class you need to follow this process:
    - Define a new class in bots.h
    - Write a corresponding 'ChooseNextGridPosition()'

# Workshop 01 Tasks:
## Task A: 
## Create a new bot class that moves towards the player.
- Define a new bot class in bot.h
    - Can call it cBotSimple.
- Must inherit from cBotBase, just like cBotRandom does.
- Make a new source file called botSimple.cpp
- Define the ChooseNextGridPosition()
    - Should look like
    ```cpp
    void cBotSimple::ChooseNextGridPosition() {
        // Code goes here
    }
    ```
## Add code insde the function that chooses to move either left/right/up/down so it moves closer to the player.
- To find the coordinates of the bot use:
    ```cpp
    PositionX();
    PositionY();
    ```
- To find the coordinates of the target use:
    ```cpp
    gTarget.PositionX();
    gTarget.PositionY();
    ```

- The function needs tochoose a sqaure adjacent to the current bot position.
    - The bot can only move one sqaure at a time.
    - Define two integer variables to hold the new location: initialise them to be the current location of the bot.

- Work out which direnction you want to move by compare the current positon to the target positon.
    - Add/Subtract to the new coordiante depending on the chosen direction.

- Finally call ChosseNextGridPosition() and pass the new location's x and y coorinates as parameters. 
    - Look at the BotRandom class to see how to do this.

- You can detect if a specific grid position is blocked or out of range in two ways:
    - ChosseNextGridPosition() will return false if th enew grid location is blocked
    - You can call gLevel.isValid(x,y) to test the new grid position (it will return false if block)

- Next tell the programm to use your new class instead of the BotRandomClass:
    ```cpp
    cBotBase* pBot = new cBotSimple();
    ```

## Task B: Create a better Bot Class:
- rUN 1.TXT
- Diagonal movement
- Remember direction of the target
    - Need class variables
- Continue to move in current direction
- When it hits a wall or map edge then pick a new direction  at 90 degrees, which direction is best is based on the current direction.
- Can check with is ChooseNextGridPosition() will return false
- you can call glevel.isValid()