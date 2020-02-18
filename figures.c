 #define X_SIZE 27
 #define Y_SIZE 27
 
 int table[X_SIZE][Y_SIZE] = {0};
 
 int delay = 100;


 void xprintfTable(){
	for(int i = 0; i<X_SIZE; i++){
		for(int j = 0; j<Y_SIZE; j++){
			if(table[i][j]) xprintf("Not 0: %d %d", i, j);
			//xprintf("%d ", table[i][j]);
		}
	}
 }
 
 void clearTable(){
	for(int i=0; i<X_SIZE; i++){
		for(int j=0; j<Y_SIZE; j++){
			table[i][j] = 0;
		}
	}


  }
  
  void setGameOfLife(){
        clearTable();
		delay = 100;
        table[4][6] = 1;
        table[4][7] = 1;
        table[4][8] = 1;
        table[4][9] = 1;
        table[4][17] = 1;
        table[4][18] = 1;
        table[4][19] = 1;
        table[4][20] = 1;
        table[4][21] = 1;
        table[5][5] = 1;
        table[5][9] = 1;
        table[5][21] = 1;
        table[6][5] = 1;
        table[6][9] = 1;
        table[6][21] = 1;
        table[7][5] = 1;
        table[7][7] = 1;
        table[7][8] = 1;
        table[7][9] = 1;
        table[7][21] = 1;
        table[9][5] = 1;
        table[9][6] = 1;
        table[9][7] = 1;
        table[9][8] = 1;
        table[9][9] = 1;
        table[9][11] = 1;
        table[9][12] = 1;
        table[9][13] = 1;
        table[9][14] = 1;
        table[9][15] = 1;
        table[10][5] = 1;
        table[10][7] = 1;
        table[10][11] = 1;
        table[10][15] = 1;
        table[10][17] = 1;
        table[10][18] = 1;
        table[10][19] = 1;
        table[10][20] = 1;
        table[10][21] = 1;
        table[11][5] = 1;
        table[11][6] = 1;
        table[11][7] = 1;
        table[11][8] = 1;
        table[11][9] = 1;
        table[11][11] = 1;
        table[11][12] = 1;
        table[11][13] = 1;
        table[11][14] = 1;
        table[11][15] = 1;
        table[13][5] = 1;
        table[13][6] = 1;
        table[13][7] = 1;
        table[13][8] = 1;
        table[13][9] = 1;
        table[13][11] = 1;
        table[13][12] = 1;
        table[13][13] = 1;
        table[13][14] = 1;
        table[13][15] = 1;
        table[13][17] = 1;
        table[13][18] = 1;
        table[13][19] = 1;
        table[13][20] = 1;
        table[13][21] = 1;
        table[14][5] = 1;
        table[14][11] = 1;
        table[14][13] = 1;
        table[14][17] = 1;
        table[14][19] = 1;
        table[15][6] = 1;
        table[15][11] = 1;
        table[15][13] = 1;
        table[15][17] = 1;
        table[15][19] = 1;
        table[16][5] = 1;
        table[17][5] = 1;
        table[17][6] = 1;
        table[17][7] = 1;
        table[17][8] = 1;
        table[17][9] = 1;
        table[19][5] = 1;
        table[19][6] = 1;
        table[19][7] = 1;
        table[19][8] = 1;
        table[19][9] = 1;
        table[19][17] = 1;
        table[19][18] = 1;
        table[19][19] = 1;
        table[19][20] = 1;
        table[19][21] = 1;
        table[20][5] = 1;
        table[20][7] = 1;
        table[20][9] = 1;
        table[20][17] = 1;
        table[20][19] = 1;
        table[20][21] = 1;
        table[21][5] = 1;
        table[21][7] = 1;
        table[21][9] = 1;
        table[21][17] = 1;
        table[21][19] = 1;
        table[21][21] = 1;
}

void setEvolution(){
        clearTable();
		delay = 300;
        table[10][10] = 1;
        table[10][11] = 1;
        table[10][12] = 1;
        table[11][10] = 1;
        table[11][12] = 1;
        table[12][10] = 1;
        table[12][11] = 1;
        table[12][12] = 1;
}

void setDiamond(){
        clearTable();
        table[10][11] = 1;
        table[10][12] = 1;
        table[11][10] = 1;
        table[11][13] = 1;
        table[12][9] = 1;
        table[12][14] = 1;
        table[13][8] = 1;
        table[13][15] = 1;
        table[14][8] = 1;
        table[14][15] = 1;
        table[15][9] = 1;
        table[15][14] = 1;
        table[16][10] = 1;
        table[16][13] = 1;
        table[17][11] = 1;
        table[17][12] = 1;
}

void setQueenBee(){
		delay = 100;
        clearTable();
        table[10][10] = 1;
        table[11][8] = 1;
        table[11][10] = 1;
        table[12][7] = 1;
        table[12][9] = 1;
        table[13][1] = 1;
        table[13][2] = 1;
        table[13][6] = 1;
        table[13][9] = 1;
        table[13][21] = 1;
        table[13][22] = 1;
        table[14][1] = 1;
        table[14][2] = 1;
        table[14][7] = 1;
        table[14][9] = 1;
        table[14][21] = 1;
        table[14][22] = 1;
        table[15][8] = 1;
        table[15][10] = 1;
        table[16][10] = 1;
}

void setHertzOscillator(){
		delay = 800;
        clearTable();
        table[5][11] = 1;
        table[5][12] = 1;
        table[5][14] = 1;
        table[6][11] = 1;
        table[6][13] = 1;
        table[6][14] = 1;
        table[8][12] = 1;
        table[8][13] = 1;
        table[8][14] = 1;
        table[9][11] = 1;
        table[9][13] = 1;
        table[9][15] = 1;
        table[9][17] = 1;
        table[9][18] = 1;
        table[10][11] = 1;
        table[10][15] = 1;
        table[10][17] = 1;
        table[10][18] = 1;
        table[11][8] = 1;
        table[11][9] = 1;
        table[11][11] = 1;
        table[11][15] = 1;
        table[12][8] = 1;
        table[12][9] = 1;
        table[12][11] = 1;
        table[12][15] = 1;
        table[13][12] = 1;
        table[13][13] = 1;
        table[13][14] = 1;
        table[15][12] = 1;
        table[15][13] = 1;
        table[15][15] = 1;
        table[16][12] = 1;
        table[16][14] = 1;
        table[16][15] = 1;
}

void setFigureEigth(){
		delay = 600;
        clearTable();
        table[9][10] = 1;
        table[9][11] = 1;
        table[9][12] = 1;
        table[10][10] = 1;
        table[10][11] = 1;
        table[10][12] = 1;
        table[11][10] = 1;
        table[11][11] = 1;
        table[11][12] = 1;
        table[12][13] = 1;
        table[12][14] = 1;
        table[12][15] = 1;
        table[13][13] = 1;
        table[13][14] = 1;
        table[13][15] = 1;
        table[14][13] = 1;
        table[14][14] = 1;
        table[14][15] = 1;
}

void setCopperhead(){
		delay = 100;
        clearTable();
        table[12][12] = 1;
        table[12][13] = 1;
        table[13][12] = 1;
        table[13][13] = 1;
        table[14][11] = 1;
        table[14][14] = 1;
        table[15][11] = 1;
        table[15][12] = 1;
        table[15][13] = 1;
        table[15][14] = 1;
        table[16][10] = 1;
        table[16][12] = 1;
        table[16][13] = 1;
        table[16][15] = 1;
        table[17][11] = 1;
        table[17][14] = 1;
        table[19][10] = 1;
        table[19][11] = 1;
        table[19][14] = 1;
        table[19][15] = 1;
        table[20][9] = 1;
        table[20][16] = 1;
        table[22][10] = 1;
        table[22][15] = 1;
        table[23][11] = 1;
        table[23][14] = 1;
        table[24][12] = 1;
        table[24][13] = 1;
}

void setCloverleaf(){
		delay = 800;
        clearTable();
        table[9][12] = 1;
        table[9][14] = 1;
        table[10][10] = 1;
        table[10][11] = 1;
        table[10][12] = 1;
        table[10][14] = 1;
        table[10][15] = 1;
        table[10][16] = 1;
        table[11][9] = 1;
        table[11][13] = 1;
        table[11][17] = 1;
        table[12][9] = 1;
        table[12][11] = 1;
        table[12][15] = 1;
        table[12][17] = 1;
        table[13][10] = 1;
        table[13][11] = 1;
        table[13][13] = 1;
        table[13][15] = 1;
        table[13][16] = 1;
        table[15][10] = 1;
        table[15][11] = 1;
        table[15][13] = 1;
        table[15][15] = 1;
        table[15][16] = 1;
        table[16][9] = 1;
        table[16][11] = 1;
        table[16][15] = 1;
        table[16][17] = 1;
        table[17][9] = 1;
        table[17][13] = 1;
        table[17][17] = 1;
        table[18][10] = 1;
        table[18][11] = 1;
        table[18][12] = 1;
        table[18][14] = 1;
        table[18][15] = 1;
        table[18][16] = 1;
        table[19][12] = 1;
        table[19][14] = 1;
}

void setLWSS(){
		delay = 100;
        clearTable();
        table[7][3] = 1;
        table[7][4] = 1;
        table[8][1] = 1;
        table[8][2] = 1;
        table[8][4] = 1;
        table[8][5] = 1;
        table[9][1] = 1;
        table[9][2] = 1;
        table[9][3] = 1;
        table[9][4] = 1;
        table[10][2] = 1;
        table[10][3] = 1;
}

void setBeacon(){
		delay = 1000;
        clearTable();
        table[12][11] = 1;
        table[12][12] = 1;
        table[13][11] = 1;
        table[14][14] = 1;
        table[15][13] = 1;
        table[15][14] = 1;
}

void setPulsar(){
		delay = 800;
        clearTable();
        table[6][9] = 1;
        table[6][10] = 1;
        table[6][11] = 1;
        table[6][15] = 1;
        table[6][16] = 1;
        table[6][17] = 1;
        table[8][7] = 1;
        table[8][12] = 1;
        table[8][14] = 1;
        table[8][19] = 1;
        table[9][7] = 1;
        table[9][12] = 1;
        table[9][14] = 1;
        table[9][19] = 1;
        table[10][7] = 1;
        table[10][12] = 1;
        table[10][14] = 1;
        table[10][19] = 1;
        table[11][9] = 1;
        table[11][10] = 1;
        table[11][11] = 1;
        table[11][15] = 1;
        table[11][16] = 1;
        table[11][17] = 1;
        table[13][9] = 1;
        table[13][10] = 1;
        table[13][11] = 1;
        table[13][15] = 1;
        table[13][16] = 1;
        table[13][17] = 1;
        table[14][7] = 1;
        table[14][12] = 1;
        table[14][14] = 1;
        table[14][19] = 1;
        table[15][7] = 1;
        table[15][12] = 1;
        table[15][14] = 1;
        table[15][19] = 1;
        table[16][7] = 1;
        table[16][12] = 1;
        table[16][14] = 1;
        table[16][19] = 1;
        table[18][9] = 1;
        table[18][10] = 1;
        table[18][11] = 1;
        table[18][15] = 1;
        table[18][16] = 1;
        table[18][17] = 1;
}

  void setCrocodile(){
	delay = 300;
	clearTable();
	table[8][13]=1;
	table[9][12]=1;
	table[10][11]=1;
	table[11][11]=1;
	table[12][11]=1;
	table[13][11]=1;
	table[14][11]=1;
	table[15][11]=1;
	table[16][12]=1;
	table[17][13]=1;
	table[16][14]=1;
	table[15][15]=1;
	table[14][15]=1;
	table[13][15]=1;
	table[12][15]=1;
	table[11][15]=1;
	table[9][14]=1;
	table[10][15]=1;
  }
  
  void setFountain(){
	delay = 150;
  	clearTable();
	table[9][15]=1;
	table[10][16]=1;
	table[11][15]=1;
	table[11][14]=1;
	table[12][14]=1;
	table[10][13]=1;
	table[11][13]=1;
	table[11][12]=1;
	table[12][12]=1;
	table[14][12]=1;
	table[15][12]=1;
	table[15][13]=1;
	table[16][13]=1;
	table[14][14]=1;
	table[15][14]=1;
	table[15][15]=1;
	table[17][15]=1;
	table[16][16]=1;
  }
  
  void setGun(){
  	clearTable();

	table[2][12]=1;
	table[2][13]=1;
	table[3][12]=1;
	table[3][13]=1;

	table[12][12]=1;
	table[12][13]=1;
	table[12][14]=1;
	table[13][11]=1;
	table[13][15]=1;
	table[14][16]=1;
	table[15][16]=1;
	table[14][10]=1;
	table[15][10]=1;
	table[16][13]=1; 
	table[17][11]=1;
	table[18][12]=1;
	table[18][13]=1;
	table[18][14]=1;
	table[19][13]=1;
	table[17][15]=1;

	table[22][10]=1;
	table[22][11]=1;
	table[22][12]=1;
	table[23][10]=1;
	table[23][11]=1;
	table[23][12]=1;
	table[24][9]=1;
	table[24][13]=1;
	table[26][8]=1;
	table[26][9]=1;
	table[26][13]=1;
	table[26][14]=1;

	table[36][10]=1;
	table[36][11]=1;
	table[37][10]=1;
	table[37][11]=1;
  
  }