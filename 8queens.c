#include <stdio.h>

#define SIZE 8
typedef enum { FREE, QUEEN, ATTACK } TSQUARE;

void start_chess_board(TSQUARE[][SIZE]);
void set_queens(TSQUARE[][SIZE], int);
void copy_chess_board(TSQUARE[][SIZE], TSQUARE[][SIZE]);
void print_chess_board(TSQUARE[][SIZE]);

int main(void){
	printf("---- begin 8queens ----\n");
	TSQUARE board [SIZE] [SIZE];
	start_chess_board(board);
	set_queens(board, 0);
	printf("---- end 8queens ----\n");
	return 0;
}

void start_chess_board(TSQUARE pboard[][SIZE]){
	unsigned int l, c;
	for(l = 0; l < SIZE; l++){
		for(c = 0; c < SIZE; c++){
			pboard[l][c] = FREE;
		}
	}
}

void copy_chess_board(TSQUARE psrc[][SIZE], TSQUARE pdest[][SIZE]){
	unsigned int l, c;
	for(l = 0; l < SIZE; l++){
		for(c = 0; c < SIZE; c++){
			pdest[l][c] = psrc[l][c];
		}
	}
}

void print_chess_board(TSQUARE pboard[][SIZE]){
	unsigned int l, c;
	printf("Printing queens configuration...\n");
	printf("========\n");
	char columns[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	for(l = 0; l < SIZE; l++){
		for(c = 0; c < SIZE; c++){
			if(pboard[l][c] == QUEEN) printf(" - %c%d \n", columns[c], l+1);
		}
	}
}

void set_queens(TSQUARE pboard[][SIZE], int pqueens){
	unsigned int l, c; int da, dd;
	TSQUARE auxboard[SIZE][SIZE];
	if(pqueens == SIZE){
		print_chess_board(pboard);
	} else {
		l = 0;
		while(l < SIZE){
			while(pboard[l][pqueens] != FREE && l < SIZE) l++;
			if(l < SIZE){
				copy_chess_board(pboard, auxboard);
				pboard[l][pqueens] = QUEEN;
				da = l-1;
				dd = l+1;
				for(c = pqueens + 1; c < SIZE; c++, da--, dd++){
					pboard[l][c] = ATTACK;
					if(da >= 0) pboard[da][c] = ATTACK;
					if(dd < SIZE) pboard[dd][c] = ATTACK;
				}	

				set_queens(pboard, pqueens+1);
				// if this fails, we move to the previous config
				copy_chess_board(auxboard, pboard);
				pboard[l][pqueens] = ATTACK;
				l++;
			}
		}
	}
}
