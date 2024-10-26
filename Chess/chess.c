#include <stdio.h>

enum Pieces {EMPTY, wK, wQ, wR, wB, wN, wP, bK, bQ, bR, bB, bN, bP};
char Board[8][8] = {EMPTY};

void drawBoard(){

    for(int i=0; i < 8; i++){
        printf("\n");
        printf("%d    ", 8-i);
        for(int j=0; j<8; j++){
            printf("%d ",Board[i][j]);
        }
    }
    printf("\n\n");
    printf("     ");
    for(int i = 0; i< 8; i++){
        printf("%c ", i+65);
    }
    printf("\n\n");
}

void setBit(char coloumn, int row){
    Board[8 - row][coloumn - 'A'] = 1;
}

void popBit(char coloumn, int row){
    Board[8 - row][coloumn - 'A'] = EMPTY;
}

void selectPiece(){
    char coloumn;
    int row;
    printf("Please select square: ");
    scanf("%c%d",&coloumn, &row);
    getchar();
    if(Board[8 - row][coloumn - 'A'] == 0){
        setBit(coloumn,row);
    }else{
        popBit(coloumn,row);
    }
    drawBoard();
}


void main(){
    drawBoard();
    while (1){
        selectPiece();
    }
    //selectPiece();
}