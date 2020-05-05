#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <list>
#include <iomanip>
#include <set>
#include <map>
#include <iterator>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
 
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
 
//Function that RANDOMLY selects the computer’s move
string compinput(string CombinedMoves[], int size, vector<string> line){
    //
    int possiblesol=0, i;
    string s;
    int ctr=0;
    vector<string> pseudoline= line;
    for (int j=0; j<size; j++){
        s= CombinedMoves[j];
        pseudoline.push_back(s);
        int l1=s[0]-64;
        int i1=s[1]-48;
        int i2=s[3]-48;
        int l2=s[2]-64;
        int i=i1+1;
        int k=i1-1;
        //Conversion of integers into strings
        auto s1 = std::to_string(i1);
        auto s2 = std::to_string(i);
        auto sub = std::to_string(k);
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
        //Lower side: checking if box is made
        for (int j=1; j<6; j++){
            if (l1==j && l2==j+1){
                if (std::find(pseudoline.begin(), pseudoline.end(), next1+next2) != pseudoline.end()){
                    if (std::find(line.begin(), line.end(), next3+next4) != pseudoline.end()){
                        if (std::find(pseudoline.begin(), pseudoline.end(), next2+next4) != pseudoline.end()){
                            possiblesol=1;}}}}}
        //Upper side: checking if box is made
        for (int j=1;j<7;j++){
            if (l1==j && l2==j+1){
                if (std::find(pseudoline.begin(), pseudoline.end(), nextsub1+nextsub2) != pseudoline.end()){
                    if (std::find(pseudoline.begin(), pseudoline.end(), nextsub1+next1) != pseudoline.end()){
                        if (std::find(pseudoline.begin(), pseudoline.end(), nextsub2+next3) != pseudoline.end()){
                            possiblesol=1;}}}}}
        //Right side: checking if box is made
        for (int n=1; n<6;n++){
            if (l1==l2){
                if (i1==n && i2==n+1){
                    if (std::find(pseudoline.begin(), pseudoline.end(), next1+vnext) != pseudoline.end()){
                        if (std::find(pseudoline.begin(), pseudoline.end(), vnext+vnext2) != pseudoline.end()){
                            if (std::find(pseudoline.begin(), pseudoline.end(), next4+vnext2) != pseudoline.end()){
                                possiblesol=1;}}}}}}
        //Left side: checking if box is made
        for (int n=1; n<7; n++){
            if (l1==l2){
                if (i1==n && i2==n+1){
                    if (std::find(pseudoline.begin(), pseudoline.end(), vnextsub1+next1) != pseudoline.end()){
                        if (std::find(pseudoline.begin(), pseudoline.end(), vnextsub1+vnextsub2) != pseudoline.end()){
                            if (std::find(pseudoline.begin(), pseudoline.end(), vnextsub2+next4) != pseudoline.end()){
                                possiblesol=1;}}}}}}
        if (possiblesol==1){
            break;
        }
        pseudoline.erase(std::remove(pseudoline.begin(), pseudoline.end(), s), pseudoline.end());
        ctr++;
    }
    if (possiblesol==1){
        i=ctr;
    }
    else{
        i=rand()%size;}
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
 
//Function to check if the box is made by any of the players
string checkboxmadelower(vector<string> line, string mt){
    //Convert the string into integers using ASCII values
    string flag1="novalue";
    int l1=mt[0]-64;
    int i1=mt[1]-48;
    int l2=mt[2]-64;
    int i=i1+1;
    int k=i1-1;
    //Conversion of integers into strings
    auto s1 = std::to_string(i1);
    auto s2 = std::to_string(i);
    auto sub = std::to_string(k);
    //Naming the adjacent dots to the line drawn
    string next1= mt[0]+s1;
    string next2= mt[0]+s2;
    string next3=mt[2]+s1;
    string next4=mt[2]+s2;
    string nextsub1=mt[0]+sub;
    string nextsub2=mt[2]+sub;
    //Lower side: checking if box is made
    for (int j=1; j<6; j++){
        if (l1==j && l2==j+1){
            if (std::find(line.begin(), line.end(), next1+next2) != line.end()){
                if (std::find(line.begin(), line.end(), next3+next4) != line.end()){
                    if (std::find(line.begin(), line.end(), next2+next4) != line.end()){
                        flag1=mt;}}}}}
    return flag1;
}

string checkboxmadeupper(vector<string> line, string mt){
    //Convert the string into integers using ASCII values
    string flag2="novalue";
    int l1=mt[0]-64;
    int i1=mt[1]-48;
    int l2=mt[2]-64;
    int i=i1+1;
    int k=i1-1;
    //Conversion of integers into strings
    auto s1 = std::to_string(i1);
    auto s2 = std::to_string(i);
    auto sub = std::to_string(k);
    //Naming the adjacent dots to the line drawn
    string next1= mt[0]+s1;
    string next2= mt[0]+s2;
    string next3=mt[2]+s1;
    string next4=mt[2]+s2;
    string nextsub1=mt[0]+sub;
    string nextsub2=mt[2]+sub;
    //Upper side: checking if box is made
    for (int j=1;j<7;j++){
        if (l1==j && l2==j+1){
            if (std::find(line.begin(), line.end(), nextsub1+nextsub2) != line.end()){
                if (std::find(line.begin(), line.end(), nextsub1+next1) != line.end()){
                    if (std::find(line.begin(), line.end(), nextsub2+next3) != line.end()){
                        flag2=nextsub1+nextsub2;}}}}}
    return flag2;
}

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
    auto s1 = std::to_string(i1);
    auto s2 = std::to_string(i);
    auto sub = std::to_string(k);
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
    //Right side: checking if box is made
    for (int n=1; n<6;n++){
        if (l1==l2){
            if (i1==n && i2==n+1){
                if (std::find(line.begin(), line.end(), next1+vnext) != line.end()){
                    if (std::find(line.begin(), line.end(), vnext+vnext2) != line.end()){
                        if (std::find(line.begin(), line.end(), next4+vnext2) != line.end()){
                            flag3= next1+vnext;}}}}}}
    return flag3;
}
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
    auto s1 = std::to_string(i1);
    auto s2 = std::to_string(i);
    auto sub = std::to_string(k);
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
    //Left side: checking if box is made
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

 
//Function to draw the board after each player’s move
void DrawBoard(char arr[28][28],int gridSize, int cellSize, string m1, string m2, string p1, string p2, char cen){
    int total = gridSize*cellSize, no=1,i,j;
    cout<<"    A       B       C       D       E       F"<<endl;
    cout<<endl;
//in the following if else statements the points are connected and the values are updated in the array arr
//if the 2 points when joined form a horizontal line the following if statement is executed
    if (m1[1]==m2[1]){    //HORIZONTAL
        int c1=(m1[0]-65)*4;
        int c2=(m2[0]-65)*4;
        for ( i=0; i<=total; i++){
            for ( j=0; j<=total; j++){
                if (i%cellSize==0 && j%cellSize==0){
                    arr[i][j]='*';
                }
                else if ((i%4==0)&&((i/4)+1==m1[1]-48) && (j>c1 && j<c2)){
                    arr[i][j]='*';
                }
            }
        }
    }
//if the 2 points when joined form a vertical line the following else if statement is executed
    else if (m1[0]==m2[0]){  //VERTICAL
        for ( i=0; i<=total; i++){
            for ( j=0; j<=total; j++){
                if (i%cellSize==0 && j%cellSize==0){
                    arr[i][j]='*';
                }
                
                else if ((j%4==0)&&((j/4)+1==m1[0]-64) && (i>((m1[1]-49)*4) && i<((m2[1]-49)*4))){
                    arr[i][j]='*';
                }
            }
        }
    }
//if a box is made the following code is run to print the person’s respective letter who made the box in the center
    if (p1!="novalue"){
/*to find the location of the center of a box made using the top left corner of that box*/
        int a=(4*(p1[1]-49))+2;
        int b=(4*(p1[0]-65))+2;
        if (cen!=' '){
            arr[a][b]=cen;
        }
    }
    if (p2!="empty"){
            int a=(4*(p2[1]-49))+2;
            int b=(4*(p2[0]-65))+2;
            if (cen!=' '){
                arr[a][b]=cen;
            }
        }
 
// the array arr is printed to show the to show the dots and boxes updated grid
    for ( i=0; i<=total; i++){
        if (i%4==0){
            cout<<no<<"  ";
            no=no+1;
        }
        else{
            cout<<"   ";
        }
        for ( j=0; j<=total; j++){
            cout<<" "<<arr[i][j];
        }
        cout<<endl;
    }
    
}
 
 
 
 
int main(){
    int tot=0,up=0,cp=0,turn=0,valid1, valid2,top=0,ct=0,x;
/* tot= sum of user’s score and computer’s score
up=to keep track of user’s points
cp=to keep track of computer’s points
turn= to keep track of whose turn it is to make a move
valid1, valid2 = to check if the user’s moves are valid
top= to keep track of the size of array IsPlayed
ct= to keep track of number of moves played by the user, right and wrong */
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
 //----------------------------------------------------------------------------
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
        //Adding the moves of the user into the vector string
        line.push_back(mt);
/*the next line calls function checkboxmade, and if a box is made it returns the 2 top points of the box formed. Else, it returns ’novalue’ indicating box is not formed*/
        flag1= checkboxmadelower(line, mt);
        flag2= checkboxmadeupper(line, mt);
        flag3= checkboxmaderight(line, mt);
        flag4= checkboxmadeleft(line, mt);
        
       
/*if a box is formed the following part of the program will be executed.*/
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
            //p1=p;//the top left corner of the box formed
/*depending on whose turn it was, user or computer a character will be passed ‘U’ or ‘C’ respectively
Also, since a box is made, the player who made the box will get one more turn, so we are increasing turn by 2 instead of one*/
            if (turn%2==0){
                if (x==2){
                    up+=2;
                    tot+=1;
                }
                else{
                    up+=1;
                }
                cen='U';
                turn+=2;
            }
            else{
                if (x==2){
                    cp+=2;
                    tot+=1;
                }
                else{
                    cp+=1;
                }
                cen='C';
                turn+=2;
            }
        }
/*if no box is formed then there will be a space instead of a letter and turn will be incremented by 1 only */
        else{
            cen=' ';
            turn+=1;
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
/*once the board is fully filled, the winner will be displayed and by how many points they won*/
    if (up>cp){
        cout<<"USER wins by "<<up-cp<<" points!"<<endl;
    }
    else{
        cout<<"COMPUTER wins by "<<cp-up<<" points!"<<endl;
    }

}
 


