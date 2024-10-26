#include <stdio.h>

enum Pieces {EMPTY, wK, wQ, wR, wB, wN, wP, bK, bQ, bR, bB, bN, bP};
char Board[8][8] = {EMPTY};

void setBit(char coloumn, int row, enum Pieces piece){
    Board[8 - row][coloumn - 'A'] = piece;
}

void popBit(char coloumn, int row){
    Board[8 - row][coloumn - 'A'] = EMPTY;
}

void initilizeBoard(){
    // Black pieces
    setBit('A',8,bR); setBit('B',8,bN); setBit('C',8,bB); setBit('D',8,bQ);
    setBit('E',8,bK); setBit('F',8,bB); setBit('G',8,bN); setBit('H',8,bR);
    for(int i=0;i<8;i++){setBit('A'+ i,7,bP);}
    // White pieces
    setBit('A',1,wR); setBit('B',1,wN); setBit('C',1,wB); setBit('D',1,wQ);
    setBit('E',1,wK); setBit('F',1,wB); setBit('G',1,wN); setBit('H',1,wR);
    for(int i=0;i<8;i++){setBit('A'+ i,2,wP);}
}

void drawBoard(){

    for(int i=0; i < 8; i++){
        printf("\n");
        printf("%d    ", 8-i);
        for(int j=0; j<8; j++){
            //printf("%d ",Board[i][j]);
            char piecechar;
            switch(Board[i][j]){
                case wK: piecechar = 'K'; break;
                case wQ: piecechar = 'Q'; break;
                case wR: piecechar = 'R'; break;
                case wB: piecechar = 'B'; break;
                case wN: piecechar = 'N'; break;
                case wP: piecechar = 'P'; break;
                case bK: piecechar = 'k'; break;
                case bQ: piecechar = 'q'; break;
                case bR: piecechar = 'r'; break;
                case bB: piecechar = 'b'; break;
                case bN: piecechar = 'n'; break;
                case bP: piecechar = 'p'; break;
                default: piecechar = '.'; break;
            }
            printf("%c ",piecechar);
        }
        //printf("\n");
    }
    printf("\n\n");
    printf("     ");
    for(int i = 0; i< 8; i++){
        printf("%c ", i+65);
    }
    printf("\n\n");
}

void selectPiece(){
    char coloumn;
    int row;
    printf("Please select square: ");
    scanf("%c%d",&coloumn, &row);
    getchar();
    if(Board[8 - row][coloumn - 'A'] != EMPTY){
        popBit(coloumn,row);
        
    }
    drawBoard();
}

void main(){
    initilizeBoard();
    drawBoard();
    while (1){
        selectPiece();
    }
    //selectPiece();
}