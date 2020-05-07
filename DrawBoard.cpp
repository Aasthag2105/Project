#include <iostream>
#include "DrawBoard.h"
using namespace std;
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
            arr[a][b]=cen; //center position of the box made will get the player's letter
        }
    }
    if (p2!="empty"){//if 2 boxes are made from one line the following part of the code will be executed to print the players letter in the middle
            int a=(4*(p2[1]-49))+2;
            int b=(4*(p2[0]-65))+2;
            if (cen!=' '){
                arr[a][b]=cen;//center position of the second box made will also get the player's letter
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
