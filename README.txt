================================== EX03-OOP ===================================
                                                                           
 #      ###### #    # ###### #         ###### #####  # #####  ####  #####  
 #      #      #    # #      #         #      #    # #   #   #    # #    # 
 #      #####  #    # #####  #         #####  #    # #   #   #    # #    # 
 #      #      #    # #      #         #      #    # #   #   #    # #####  
 #      #       #  #  #      #         #      #    # #   #   #    # #   #  
 ###### ######   ##   ###### ######    ###### #####  #   #    ####  #    #
                                                            

name: Valeri Materman
name: David Yudin

===============================================================================

In this exercise we were asked to implement a level editor
using the SFML library. Our level editor is capable to edit
and create a level from scratch. The Widnow will contain
a side bar with six figures - Player, Enemy, Coins, Wall, Ground, Ladder and Pole,
which represent the whole game, and three buttons: 
* Delete - as it pressed we can delete each tile from the map 
untill we release it by clicking on other buttons. 
* Reset - Resets the whole level back to scratch which means you will be able
to see only a clear white wall.
* Save - saves the current state of the level in Board.txt file for further use
in the future. 
In addition we have the main window next to the side bar where we can see
all the changes happen real time.
Once we entered and there is no map waiting for us in the file, we will  receive
a small window which asks for width and height, and then generates it to blank level.

===============================================================================
More tehnical stuff:


===============================================================================
Design:
We used the simple forms of SFML objects such as: rectangles, windows and sprites,
and created with it buttoms, editting screen and figures.
For example: Button <- SpriteButton
	     Window <- Intro
===============================================================================
classes and theyr uses:

---------main:
_________main.cpp_________
runs the game editor, doesnt have a unique ability.

_________Window.cpp + .h_________
stores the height and the width for the main screen.

_________SidePannel.cpp + .h_________
stores the height and the width of the side bar.

_________Button.cpp + .h_________
stores the height, width and vector of x,y axis for a specific button.

_________IntroButton.cpp + .h_________
inheriting from button, in addition stores text and functions 
which make him clickable for special use.

_________AddButton.cpp + .h_________
inheriting from button, in addition stores text, scale, color,
and functions which make him clickable for special use.

_________SpriteButton.cpp + .h_________
inheriting from button, in addition stores textures
and functions which make him clickable for special use.

_________Intro.cpp + .h_________
inheriting from Window, in addition stores the location of
input boxes and the send button. typically waits till the user
enters values and then sends it to the main task.

_________Map.cpp + .h_________
this class is in charge of the map functionality. by using this 
class we can draw, reset, save, remove, etc... which are 
essential for the use of the level editor.

_________Ui.cpp + .h_________
this class is in charge of the user interface. by using this 
class we get that fine experience, when we click on the buttons
on the side window

_________Executable.cpp + .h_________
that namespace is in charge to combine all the classes together
and run it.

---------helpers:
_________macros.h_________
stores define values for textures,const and enums etc


===============================================================================
The Main data structure:
We used the modern data structures, which are strings and vectors,
and combined them with SFML variables in order to use complex yet 
understanable form of GUI
===============================================================================
Agoithms: -None-
Bugs: -None-

enjoy the editor :)

