**GROUP PROJECT**<br />
**GROUP 127.** <br />
**Team Members:** <br />
Pallavi Goel - 3035663148 <br />
Aastha Goel - 3035662479 <br />

Game Name: <br />
**DOTS AND BOXES** <br />
<br />
**Objective of the game:** <br />
To take more boxes than your opponent to win. <br />
<br />
**Basics of the game:** <br />
It is a 2-player game <br />
•	Player 1 will be the user. <br />
•	Player 2 will be the computer. <br />

The players will be provided with a 6 by 6 grid, which will look something like this:


    A    B   C    D   E    F    

1 &nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  *
    
2  &nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  *

3  &nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  *
       
4  &nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  *

5  &nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  *

6  &nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  *


**How to play:**  <br />
1. Two players (user and computer) take turns adding a single horizontal or vertical line between two un-joined adjacent dots. <br />
2. The user can do this by selecting 2 points.<br />
3. There is a particular format of entering the points, each point should have a capital letter (A-F) followed by a number (1-6). Next the user must click "space" or "enter" button. After that the user must enter another point in the same manner to form a line.<br />
4. The computer will randomly generate its moves during its turn.<br />
5. A player who completes the fourth side of a 1×1 box first earns one point.<br />
6. The players play in their turn, but whenever a player makes a box/earns a point they must play the next move again.<br />
7. Each time a player makes a 1x1 box, its ID: U(User) or C(Computer) will appear in the center of that box.
8. The game is over when all the boxes (in this case 25) are taken.<br />
9. The player with the most point wins the game.<br />
<br />
However, the user can end the game in between by typing "EXIT" in its turn. In that situation the player with the most points at that given time wins.<br />

<br />
FUNCTIONS AND FEATURES WE PLAN TO IMPLEMENT:<br />
<br />
<ins>Generation of random game sets or events</ins><br />
•	The computer will generate its move using the random function.<br />
<br />
<ins>Data structures for storing game status</ins><br />
•	Data Structures such as arrays are used to store the moves used by the computer and the user. <br />
•   The values store in data structures help to join the two points in order to form a line. <br />
•   The data structures are also used to print the grid and store the updated grid after each players turn.<br />
<br />
<ins>Dynamic memory management</ins><br />
•	Dynamic memory management is used to user's new input as variable "ptr" and to store the player’s move in order to identify if the box is created by the user and to recognise which player is responsible for the next move in the form of vector.<br />
<br />
<ins> File input/output (e.g., for loading/saving game status)</ins><br />
•	File input/output to store the points of the players after their moves.<br />
•   The number of times the players have won will be read from the file score.txt and will be displayed at the end of the program. <br />
•   Once the game is over a file score.txt will be opened which stores 2 numbers : the number of times the user has won the game and the number of times the computer has won respectively. Each time a player wins the game, their value will be incremented by one and stored in the file score.txt. <br />
<br />
<ins>Program codes in multiple files</ins><br />
•	Form multiple files to implement different functions. In our case, we have created the file DrawBoard.cpp which will print the updated board after each player's move.<br />
<br />
<ins>Proper indentation and naming styles</ins><br />
•   Proper indentation with naming styles for ease of understanding the code of the game.<br />
•   Variables, files, and functions have been named based on their utility. This ensures better code readability and understanding. <br />
<br />
<ins>In-code documentation</ins><br />
•	Comments have been included to describe the usage of every function. Further comments have been included where explanation is required.  <br />
<br />
<br />
BUILD AND EXECUTE<br />

To use the system, simply follow the following steps:<br/>
1.  Clone this repository using the following command on your command line interface: <br />
git clone https://github.com/Aasthag2105/Project DotsAndBoxes <br />
2.  Go into the directory of the project:<br />
cd DotsAndBoxes<br />
3.  Build the executable through the make command. Our default executable generated is main:<br />
make Game<br />
4.  Execute main:<br />
./Game<br />

