#include "figures.c"

int count_neighbours(int x, int y){
	int sum = 0;
	int a = x - 1;
	int b = y - 1;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			sum += table[(X_SIZE+a+i)%X_SIZE][(Y_SIZE+b+j)%Y_SIZE];
		}
	}
	sum -= table[x][y];
	return sum;
}

void update_table(){
	int neigh[X_SIZE][Y_SIZE] = {0};
	for (int i = 0; i < X_SIZE; i++){
	for (int j = 0; j < Y_SIZE; j++){
		neigh[i][j] = count_neighbours(i,j);
		}}
	for (int i = 0; i < X_SIZE; i++){
	for (int j = 0; j < Y_SIZE; j++){
		if (table[i][j] == 1){
			if(neigh[i][j] != 2 && neigh[i][j] != 3){
				table[i][j] = 0;
			}
	        else{
				table[i][j] = 1;
			}
		}
		else{
			if(neigh[i][j] == 3){
				table[i][j] = 1;
			}
			else{
				table[i][j] = 0;
			}
		}
	}
  }
} 
