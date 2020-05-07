#GROUP PROJECT
GROUP 127. 
Team Members:
Pallavi Goel - 3035663148
Aastha Goel - 3035662479

Game Name: 
DOTS AND BOXES

Objective of the game:
To take more boxes than your opponent.


Basics of the game:
It is a 2-player game
•	Player 1 will be the user.
•	Player 2 will be the computer.

The players will be provided with a 6 by 6 grid, which will look something like this:


    A   B   C   D   E   F    

1   *   *   *   *   *   *
    
2   *   *   *   *   *   *

3   *   *   *   *   *   *
       
4   *   *   *   *   *   *

5   *   *   *   *   *   *

6   *   *   *   *   *   *


How to play:
Two players (user and computer) take turns adding a single horizontal or vertical line between two un-joined adjacent dots. 

•	The user can do this by selecting 2 points.
There is a particular format of entering the points, each point should have a capital letter (A-F) followed by a number (1-6). Next the user must click "space" or "enter" button. After that the user must enter another point in the same manner to form a line.

•	The computer will randomly generate its moves during its turn.
A player who completes the fourth side of a 1×1 box first earns one point.
The players play in their turn, but whenever a player makes a box/earns a point they must play the next move again.
The game is over when all the boxes (in this case 25) are taken.
The player with the most point wins the game.

•	However, the user can end the game in between by typing "EXIT" in its turn. In that situation the player with the most points at that given time wins.


Function/Features we plan to implement:
•	The computer will generate its move using the random function.
•	Data Structures to store the moves available and moves used.
•	Form multiple files to implement different functions. In our case, we have created the file DrawBoard.cpp which will print the updated board after each player's move.
•	Use of in-code documentation and proper indentation with naming styles for ease of understanding the code of the game. 
•	Dynamic memory management is used to user's new input as variable "ptr" and to store the player’s move in order to identify if the box is created by the user and to recognise which player is responsible for the next move in the form of vector.
•	File input/output to store the points of the players after their moves.
•	Each time a player makes a 1x1 box, its ID: U(User) or C(Computer) will appear in the center of that box.


