#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include "DrawBoard.h"
 
using namespace std;
 
//Function to print the initial empty board
void printgrid(char arr[28][28]){
    int total = 20, no=1;
    char x;
    cout<<"    A       B       C       D       E       F"<<endl; //to know column number
    cout<<endl;
    for (int i=0; i<=total; i++){  // to go to the next row
        if (i%4==0){ // to know row number
            cout<<no<<"  ";
            no=no+1;
        }
        else{
            cout<<"   ";
        }
        for (int j=0; j<=total; j++){ // to go to the next column
            if (i%4==0 && j%4==0){
                x='*';
            }
            else{
                x=' ';
            }
            cout<< " "<<x;
            arr[i][j]=x;
        }
        cout<<endl;
    }
    cout<<endl;
}
 
//To check if the user has entered a valid string/ value
int checkifvalid(string m){
    string Moves[]={"A1","A2","A3","A4","A5","A6","B1","B2","B3","B4","B5","B6","C1","C2","C3","C4","C5","C6","D1","D2","D3","D4","D5","D6","E1","E2","E3","E6","E4","E5","F1","F2","F3","F4","F5","F6"};
        bool exists=std::find(std::begin(Moves), std::end(Moves),m)!=std::end(Moves); /* if the move exists in the array Moves, it is valid. Else, it is invalid and the user will have to enter the 2 points again(code for that in main function)*/
    if (exists==0){
        return 0;
    }
    else{
        return 1;
    }
}
 
//Function either RANDOMLY selects the computer’s move or chooses the computer's move so that it plays to win
string compinput(string CombinedMoves[], int size, vector<string> line){
    int possiblesol=0, i;
    string s;
    int ctr=0;
    vector<string> pseudoline= line;
    //The loop runs to check if there is any move that the computer can play in order to create a box
    for (int j=0; j<size; j++){
        s= CombinedMoves[j]; // refers to the move that can be played by the computer
        pseudoline.push_back(s); // potential move is added to pseudoline
        int l1=s[0]-64;
        int i1=s[1]-48;
        int i2=s[3]-48;
        int l2=s[2]-64;
        int i=i1+1;
        int k=i1-1;
        //Conversion of integers into strings
        string s1 = std::to_string(i1);
        string s2 = std::to_string(i);
        string sub = std::to_string(k);
        //Naming the adjacent dots to the line drawn
        string next1= s[0]+s1;
        string next2= s[0]+s2;
        string next3= s[2]+s1;
        string next4= s[2]+s2;
        string nextsub1= s[0]+sub;
        string nextsub2= s[2]+sub;
        //Conversion of adjacent letters to integers
        int fl1= s[0]+1;
        int fl2= s[2]-1;
        string nletter1, nletter2;
        nletter1= (char)fl1;
        nletter2= (char)fl2;
        //Naming the adjacent dots to the line drawn
        string vnext= nletter1+s1;
        string vnext2= nletter1+s2;
        string vnextsub1= nletter2+s1;
        string vnextsub2= nletter2+s2;
        //Lower side: checking if there is a possible box that can be made
        for (int j=1; j<6; j++){
            if (l1==j && l2==j+1){
                if (std::find(pseudoline.begin(), pseudoline.end(), next1+next2) != pseudoline.end()){
                    if (std::find(line.begin(), line.end(), next3+next4) != pseudoline.end()){
                        if (std::find(pseudoline.begin(), pseudoline.end(), next2+next4) != pseudoline.end()){
                            possiblesol=1;}}}}}
        //Upper side: checking if there is a possible box that can be made
        for (int j=1;j<7;j++){
            if (l1==j && l2==j+1){
                if (std::find(pseudoline.begin(), pseudoline.end(), nextsub1+nextsub2) != pseudoline.end()){
                    if (std::find(pseudoline.begin(), pseudoline.end(), nextsub1+next1) != pseudoline.end()){
                        if (std::find(pseudoline.begin(), pseudoline.end(), nextsub2+next3) != pseudoline.end()){
                            possiblesol=1;}}}}}
        //Right side: checking if there is a possible box that can be made
        for (int n=1; n<6;n++){
            if (l1==l2){
                if (i1==n && i2==n+1){
                    if (std::find(pseudoline.begin(), pseudoline.end(), next1+vnext) != pseudoline.end()){
                        if (std::find(pseudoline.begin(), pseudoline.end(), vnext+vnext2) != pseudoline.end()){
                            if (std::find(pseudoline.begin(), pseudoline.end(), next4+vnext2) != pseudoline.end()){
                                possiblesol=1;}}}}}}
        //Left side: checking if there is a possible box that can be made
        for (int n=1; n<7; n++){
            if (l1==l2){
                if (i1==n && i2==n+1){
                    if (std::find(pseudoline.begin(), pseudoline.end(), vnextsub1+next1) != pseudoline.end()){
                        if (std::find(pseudoline.begin(), pseudoline.end(), vnextsub1+vnextsub2) != pseudoline.end()){
                            if (std::find(pseudoline.begin(), pseudoline.end(), vnextsub2+next4) != pseudoline.end()){
                                possiblesol=1;}}}}}}
        //if a possible box can be made then it fulfills the if statement and breaks the loop
        if (possiblesol==1){
            break;
        }
        
        pseudoline.erase(std::remove(pseudoline.begin(), pseudoline.end(), s), pseudoline.end()); //the value added to vector string to check if a box can be created is deleted from that vector string after every loop
    
        ctr++;
    }
    if (possiblesol==1){
        i=ctr; //refers to the index of the move that should be played by the computer
    }
    else{
        i=rand()%size; //random value is generated by the computer if there is no possible value that lead to computer's victory
        
    }
    return CombinedMoves[i];
}
 
//Function to delete the move already made by the user or the computer to avoid overlapping of moves by the computer
void delelement(string CombinedMoves[], int size, string mt){
    int i,flag=0,loc;
    for (i=0; i<size; i++){
        if (CombinedMoves[i]==mt){//first the move played is located in the array
            flag=1;
            loc=i;
            break;
        }
    }
    if (flag==1){
        for (i=loc; i<size-1;i++){ // after locating the move, it is removed from the array)
            CombinedMoves[i]=CombinedMoves[i+1];
        }
    }
}
 
//Functions to check if the box is made by any of the players
 
//Lower side: checking if box is made
string checkboxmadelower(vector<string> line, string mt){
    //Convert the string into integers using ASCII values
    string flag1="novalue";
    int l1=mt[0]-64;
    int i1=mt[1]-48;
    int l2=mt[2]-64;
    int i=i1+1;
    int k=i1-1;
    //Conversion of integers into strings
    string s1 = std::to_string(i1);
    string s2 = std::to_string(i);
    string sub = std::to_string(k);
    //Naming the adjacent dots to the line drawn
    string next1= mt[0]+s1;
    string next2= mt[0]+s2;
    string next3=mt[2]+s1;
    string next4=mt[2]+s2;
    string nextsub1=mt[0]+sub;
    string nextsub2=mt[2]+sub;
    //to check if box is made on the lower side
    for (int j=1; j<6; j++){
        if (l1==j && l2==j+1){
            if (std::find(line.begin(), line.end(), next1+next2) != line.end()){
                if (std::find(line.begin(), line.end(), next3+next4) != line.end()){
                    if (std::find(line.begin(), line.end(), next2+next4) != line.end()){
                        flag1=mt;}}}}}
    //Returning the values of the top most line of the box
    return flag1;
}
 
//Upper side: checking if box is made
string checkboxmadeupper(vector<string> line, string mt){
    //Convert the string into integers using ASCII values
    string flag2="novalue";
    int l1=mt[0]-64;
    int i1=mt[1]-48;
    int l2=mt[2]-64;
    int i=i1+1;
    int k=i1-1;
    //Conversion of integers into strings
    string s1 = std::to_string(i1);
    string s2 = std::to_string(i);
    string sub = std::to_string(k);
    //Naming the adjacent dots to the line drawn
    string next1= mt[0]+s1;
    string next2= mt[0]+s2;
    string next3=mt[2]+s1;
    string next4=mt[2]+s2;
    string nextsub1=mt[0]+sub;
    string nextsub2=mt[2]+sub;
    //to check if box is made on the upper side
    for (int j=1;j<7;j++){
        if (l1==j && l2==j+1){
            if (std::find(line.begin(), line.end(), nextsub1+nextsub2) != line.end()){
                if (std::find(line.begin(), line.end(), nextsub1+next1) != line.end()){
                    if (std::find(line.begin(), line.end(), nextsub2+next3) != line.end()){
                        flag2=nextsub1+nextsub2;}}}}}
    //Returning the values of the top most line of the box
    return flag2;
}
 
//Right side: checking if box is made
string checkboxmaderight(vector<string> line, string mt){
    //Convert the string into integers using ASCII values
    string flag3="novalue";
    int l1=mt[0]-64;
    int i1=mt[1]-48;
    int l2=mt[2]-64;
    int i2=mt[3]-48;
    int i=i1+1;
    int k=i1-1;
    //Conversion of integers into strings
    string s1 = std::to_string(i1);
    string s2 = std::to_string(i);
    string sub = std::to_string(k);
    //Naming the adjacent dots to the line drawn
    string next1= mt[0]+s1;
    string next2= mt[0]+s2;
    string next3=mt[2]+s1;
    string next4=mt[2]+s2;
    string nextsub1=mt[0]+sub;
    string nextsub2=mt[2]+sub;
    //Conversion of adjacent letters to integers
    int fl1= mt[0]+1;
    int fl2= mt[2]-1;
    string nletter1, nletter2;
    nletter1= (char)fl1;
    nletter2= (char)fl2;
    //Naming the adjacent dots to the line drawn
    string vnext= nletter1+s1;
    string vnext2= nletter1+s2;
    string vnextsub1= nletter2+s1;
    string vnextsub2= nletter2+s2;
    //to check if box is made on the right side
    for (int n=1; n<6;n++){
        if (l1==l2){
            if (i1==n && i2==n+1){
                if (std::find(line.begin(), line.end(), next1+vnext) != line.end()){
                    if (std::find(line.begin(), line.end(), vnext+vnext2) != line.end()){
                        if (std::find(line.begin(), line.end(), next4+vnext2) != line.end()){
                            flag3= next1+vnext;}}}}}}
    //Returning the values of the top most line of the box
    return flag3;
}
 
//Left side: checking if box is made
string checkboxmadeleft(vector<string> line, string mt){
    //Convert the string into integers using ASCII values
    string flag4="novalue";
    int l1=mt[0]-64;
    int i1=mt[1]-48;
    int l2=mt[2]-64;
    int i2=mt[3]-48;
    int i=i1+1;
    int k=i1-1;
    //Conversion of integers into strings
    string s1 = std::to_string(i1);
    string s2 = std::to_string(i);
    string sub = std::to_string(k);
    //Naming the adjacent dots to the line drawn
    string next1= mt[0]+s1;
    string next2= mt[0]+s2;
    string next3=mt[2]+s1;
    string next4=mt[2]+s2;
    string nextsub1=mt[0]+sub;
    string nextsub2=mt[2]+sub;
    //Conversion of adjacent letters to integers
    int fl1= mt[0]+1;
    int fl2= mt[2]-1;
    string nletter1, nletter2;
    nletter1= (char)fl1;
    nletter2= (char)fl2;
    //Naming the adjacent dots to the line drawn
    string vnext= nletter1+s1;
    string vnext2= nletter1+s2;
    string vnextsub1= nletter2+s1;
    string vnextsub2= nletter2+s2;
    //to check if box is made on the left side
    for (int n=1; n<7; n++){
        if (l1==l2){
            if (i1==n && i2==n+1){
                if (std::find(line.begin(), line.end(), vnextsub1+next1) != line.end()){
                    if (std::find(line.begin(), line.end(), vnextsub1+vnextsub2) != line.end()){
                        if (std::find(line.begin(), line.end(), vnextsub2+next4) != line.end()){
                            flag4=vnextsub1+next1;}}}}}}
    //Returning the values of the top most line of the box
    return flag4;
 
}
 

 
int main(){

    cout<<"\nWELCOME TO DOTS AND BOXES\n"<<endl;
    cout<<"Rules of the game:"<<endl;
    cout<<"1. The objective of the game is to create maximum number of boxes.\n2. The two players in the game are the user and the computer.\n3. The first turn is always played by the user.\n";
    cout<< "4. The user has to input the two points.\nEach point should start with a capital letter between A and F, followed by a number between 1 and 6.\n5. Both the points should be separated by a space. \n6. The two points should be adjacent to each other. Eg: A1 A2\n7. No other format would be recognized by the system. "<< endl;
    cout<<endl;
    cout<<"To stop the game in the middle, type 'EXIT' during User’s Move.\n\n\n"<<endl;
    int tot=0,up=0,cp=0,turn=0,valid1, valid2,top=0,ct=0,x;
/* tot= sum of user’s score and computer’s score
up=to keep track of user’s points
cp=to keep track of computer’s points
turn= to keep track of whose turn it is to make a move
valid1, valid2 = to check if the user’s moves are valid
top= to keep track of the size of array IsPlayed
ct= to keep track of number of moves played by the user, right and wrong 
x= to check the number of boxes made in each turn*/
    char cen, arr[28][28];
/*cen= to pass the winner’s letter to print in the middle of the box when needed
arr=stores the characters of the grid*/
    string flag1, flag2, flag3, flag4, flag;
    string m1,m2,t,mt,p1,p2;
/*m1=first point user inputs to form a joining line
m2=second point user inputs to form a joining line
t= to swap the 2 points when they are not in increasing order
mt=combined version of the 2 points
p1=when a box is formed this point store the 2 upper points of the box*/
    vector<string> line;
    srand( (unsigned int) time(NULL) );
    string CombinedMoves[]={"A1A2","A2A3","A3A4","A4A5","A5A6","B1B2","B2B3","B3B4","B4B5","B5B6","C1C2","C2C3","C3C4","C4C5","C5C6","D1D2","D2D3","D3D4","D4D5","D5D6","E1E2","E2E3","E3E4","E4E5","E5E6","F1F2","F2F3","F3F4","F4F5","F5F6","A1B1","B1C1","C1D1","D1E1","E1F1","A2B2","B2C2","C2D2","D2E2","E2F2","A3B3","B3C3","C3D3","D3E3","E3F3","A4B4","B4C4","C4D4","D4E4","E4F4","A5B5","B5C5","C5D5","D5E5","E5F5","A6B6","B6C6","C6D6","D6E6","E6F6"}; //this array will be modified after each valid move and is also used by the computer to RANDOMLY pick a value
    string Checkadjacent[]={"A1A2","A2A3","A3A4","A4A5","A5A6","B1B2","B2B3","B3B4","B4B5","B5B6","C1C2","C2C3","C3C4","C4C5","C5C6","D1D2","D2D3","D3D4","D4D5","D5D6","E1E2","E2E3","E3E4","E4E5","E5E6","F1F2","F2F3","F3F4","F4F5","F5F6","A1B1","B1C1","C1D1","D1E1","E1F1","A2B2","B2C2","C2D2","D2E2","E2F2","A3B3","B3C3","C3D3","D3E3","E3F3","A4B4","B4C4","C4D4","D4E4","E4F4","A5B5","B5C5","C5D5","D5E5","E5F5","A6B6","B6C6","C6D6","D6E6","E6F6"}; // this is to check if the moves given by the user are valid
    string IsPlayed[60]; // this array is to store all the moves played by the user and computer
    
    int size=sizeof(CombinedMoves)/sizeof(CombinedMoves[0]);
    string *ptr = new string(); // DYNAMIC MEMORY to store the users moves
    
    //print grid
    printgrid(arr);
    cout<<endl;
	
    while(tot!=25){
        p2="empty";
        if (turn==0){
            ptr=new string[size];
        }
        x=0;
        //user's turn PART.1
/*if turn is even it is the user’s turn*/
        if (turn%2==0){
            cout<<"User's Move: ";
            cin>>ptr[ct];
            m1=ptr[ct];
if (m1=="EXIT"){
break;}
            ct++;
            cin>>ptr[ct];
            m2=ptr[ct];
            ct++;
            valid1=checkifvalid(m1);
            valid2=checkifvalid(m2);
/* to check if the 2 points enter are valid or not. If they are not valid the loop will not go any further and start again*/
            if (valid1==0 || valid2==0){
                cout<<"Invalid move as the point does not exist. Enter values again!"<<endl;
                continue;
            }
/*to check if the user has entered 2 similar points. In that case a line cannot be made and the loop will not go any further and start again*/
            if(m1==m2){
                cout<<"Invalid move as both points are the same. Enter values again!"<<endl;
                continue;
            }
/*the next if and else if statements are 2 arrange the 2 points in lexicographical order*/
            if(m1[0]>m2[0]){
                t=m1;
                m1=m2;
                m2=t;
            }
            else if(m1[0]==m2[0]){
                if(m1[1]>m2[1]){
                    t=m1;
                    m1=m2;
                    m2=t;
                }
            }
            // mt is to combine the 2 points as one string
            mt=m1+m2;
/*next statement is to check if the 2 points are adjacent to each other or not. If they are not adjacent  the loop will not go any further and start again*/
            bool exist=std::find(std::begin(Checkadjacent), std::end(Checkadjacent),mt)!=std::end(Checkadjacent);
            if (exist==0){
                cout<<"Invalid move because these 2 points are not adjacent. Enter values again!"<<endl;
                continue;
            }
/*next statement is to check if the 2 adjacent points have already been played .If they are have already been played the loop will not go any further and start again*/
            bool exist2=std::find(std::begin(IsPlayed), std::end(IsPlayed),mt)!=std::end(IsPlayed);
            if (exist2==1){
                cout<<"Invalid because this move has already been played. Enter values again!"<<endl;
                continue;
            }
/*if the program reaches here that means the 2 points entered by the user are valid*/
        }
        
        //computer's turn PART.1
/*if turn is not even it is the computer’s turn*/
        else if (turn%2!=0){
            cout<<"Computer's Move: ";
            mt=compinput(CombinedMoves,size,line);
/*function to find the computer's move. It will return 2 points combined as one string which will be separated into 2 points in the next 2 statements*/
            std::string a=mt[0]+std::to_string(mt[1]-48);//a=first point
            std::string b=mt[2]+std::to_string(mt[3]-48);//b=second point
            m1=a;m2=b; // m1 and m2 are assigned the 2 points as those are the variables used to call function DrawBoard later
            cout<<a<<" "<<b<<endl;// computer’s moves are being printed
        }
        //array with used elements
        IsPlayed[top]=mt;//array IsPlayed stored all the valid moves being played by user and computer
        top++;
        
        // delete used element(mt) from array CombinedMoves
/*this function removes the already played move from the array CombinedMoves and also reduces the size of the array by 1*/
        delelement(CombinedMoves, size, mt);
        size--;
        
        cout<<endl; // for formatting purposes
        
        line.push_back(mt); //Adding the moves of the user or the computer into the vector string
/*the next line calls function checkboxmade, and if a box is made it returns the 2 top points of the box formed. Else, it returns ’novalue’ indicating box is not formed*/
        flag1= checkboxmadelower(line, mt);
        flag2= checkboxmadeupper(line, mt);
        flag3= checkboxmaderight(line, mt);
        flag4= checkboxmadeleft(line, mt);
        
       
/*the following part of the code is to check the number of boxes that are made- atmost 2 boxes can be made with one line at a time
and at which position they are made to the last printed line; left, right, top or bottom*/
        if(flag1!="novalue"){
            std::string p=flag1[0]+std::to_string(flag1[1]-48);
            p1=p;
            x++;
            if (flag2!="novalue"){
                std::string p=flag2[0]+std::to_string(flag2[1]-48);
                p2=p;
                x++;
            }
            else if(flag3!="novalue"){
                std::string p=flag3[0]+std::to_string(flag3[1]-48);
                p2=p;
                x++;
            }
            else if (flag4!="novalue"){
                std::string p=flag4[0]+std::to_string(flag4[1]-48);
                p2=p;
                x++;
            }
        }
        else if(flag2!="novalue"){
            std::string p=flag2[0]+std::to_string(flag2[1]-48);
            p1=p;
            x++;
            if (flag3!="novalue"){
                std::string p=flag3[0]+std::to_string(flag3[1]-48);
                p2=p;
                x++;
            }
            else if(flag4!="novalue"){
                std::string p=flag4[0]+std::to_string(flag4[1]-48);
                p2=p;
                x++;
            }
        }
        else if(flag3!="novalue"){
            std::string p=flag3[0]+std::to_string(flag3[1]-48);
            p1=p;
            x++;
            if(flag4!="novalue"){
                std::string p=flag4[0]+std::to_string(flag4[1]-48);
                p2=p;
                x++;
            }
        }
        else if(flag4!="novalue"){
            std::string p=flag4[0]+std::to_string(flag4[1]-48);
            p1=p;
            x++;
        }
        if (x!=0){
            tot+=1;//to keep track of the number of boxes made
            //std::string p=flag[0]+std::to_string(flag[1]-48);//to find the top left point of the box made
/*depending on whose turn it was, user or computer a character will be passed ‘U’ or ‘C’ respectively
Also, since a box is made, the player who made the box will get one more turn, so we are increasing turn by 2 instead of one*/
            if (turn%2==0){
                if (x==2){//in situations where 2 boxes are made with just one line the user will get 2 points and total will increase by 1 again.
                    up+=2;
                    tot+=1;
                }
                else{//if only one box is made user gets one point
                    up+=1;
                }
                cen='U';//since the user made a box letter U will be passed to the function DrawBoard to be printed in the centre of the box made
                turn+=2;//since a box is made by the user, he/she will play again
            }
            else{
                if (x==2){//in situations where 2 boxes are made with just one line the computer will get 2 points and total will increase by 1 again.
                    cp+=2;
                    tot+=1;
                }
                else{//if only one box is made computer gets one point
                    cp+=1;
                }
                cen='C';//since the computer made a box letter C will be passed to the function DrawBoard to be printed in the centre of the box made
                turn+=2;//since a box is made by the computer, it will play again
            }
        }
/*if no box is formed then there will be a space instead of a letter and turn will be incremented by 1 only */
        else{
            cen=' ';//if no box is made nothing will be printed in the centre of any box
            turn+=1;//if no box is made it will be the other players turn
        }
        
        //print grid PART.3
/*we are calling function DrawBoard to print the updated board with new moves and a letter in the middle if a box is made*/
        DrawBoard(arr,5,4,m1,m2,p1,p2,cen);
        cout<<endl;
        //display points PART.4
//after each round the points of the player will be displayed
        cout<<"USER'S Score:"<<up<<endl;
        cout<<"COMPUTER'S Score:"<<cp<<endl;
        cout<<endl;
    }
    cout<<endl;
    cout<<"GAME OVER"<<endl;
/*once the board is fully filled or the game has ended, the winner will be displayed and by how many points they won*/
/*once the game is over a file score.txt will be opened
it stores 2 numbers, which are: the number of times the user has won the game and the number of times the computer has won respectively.
each time a player wins the game, their value will be incremented by one and stored in the file score.txt*/
	fstream f;
	f.open("score.txt", ios::in|ios::out);

	int ugw = 0, cgw = 0;
//ugw=number of times the user has wom the game
//cgw=number of times the computer has wom the game
	if (f) {
		//file reads the number of times players have won the games each
		f >> ugw;
		f >> cgw;
	}

	f.close();

    if (up>cp){
        cout<<"USER wins by "<<up-cp<<" points!"<<endl;
		ugw++;
    }
    else if (cp>up){
        cout<<"COMPUTER wins by "<<cp-up<<" points!"<<endl;
		cgw++;
    }
else{
    cout<<"It is a TIE!"<<endl;
}
/*the number of times the players have won will be read from the file score.txt and will be displayed at the end of the program*/
	cout << endl;
	cout << "You have won a total of: " << ugw << " games!" << endl;
	cout << "Computer has won a total of: " << cgw << " games!" << endl;
//the new values of the number of times players have won are updated in the file score.txt
	f.open("score.txt", ios::out|ios::trunc);
	f << ugw << " " << cgw;
	f.close();
	cout<<endl;

}
