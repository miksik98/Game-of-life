#include "gameOfLife.c"
#define LCD_X_SIZE      RK043FN48H_WIDTH
#define LCD_Y_SIZE      RK043FN48H_HEIGHT

int state = 0;
int state_changed = 0;
int drawing_state = 0;
int stopped = 1;

//[rmv]
uint16_t ABS(uint16_t x){
	return x<0?(-1)*x:x;
}

static void FillTriangle(uint16_t x1, uint16_t x2, uint16_t x3, uint16_t y1, uint16_t y2, uint16_t y3)
{ 
  int16_t deltax = 0, deltay = 0, x = 0, y = 0, xinc1 = 0, xinc2 = 0, 
  yinc1 = 0, yinc2 = 0, den = 0, num = 0, num_add = 0, num_pixels = 0,
  curpixel = 0;
  
  deltax = ABS(x2 - x1);        /* The difference between the x's */
  deltay = ABS(y2 - y1);        /* The difference between the y's */
  x = x1;                       /* Start x off at the first pixel */
  y = y1;                       /* Start y off at the first pixel */
  
  if (x2 >= x1)                 /* The x-values are increasing */
  {
    xinc1 = 1;
    xinc2 = 1;
  }
  else                          /* The x-values are decreasing */
  {
    xinc1 = -1;
    xinc2 = -1;
  }
  
  if (y2 >= y1)                 /* The y-values are increasing */
  {
    yinc1 = 1;
    yinc2 = 1;
  }
  else                          /* The y-values are decreasing */
  {
    yinc1 = -1;
    yinc2 = -1;
  }
  
  if (deltax >= deltay)         /* There is at least one x-value for every y-value */
  {
    xinc1 = 0;                  /* Don't change the x when numerator >= denominator */
    yinc2 = 0;                  /* Don't change the y for every iteration */
    den = deltax;
    num = deltax / 2;
    num_add = deltay;
    num_pixels = deltax;         /* There are more x-values than y-values */
  }
  else                          /* There is at least one y-value for every x-value */
  {
    xinc2 = 0;                  /* Don't change the x for every iteration */
    yinc1 = 0;                  /* Don't change the y when numerator >= denominator */
    den = deltay;
    num = deltay / 2;
    num_add = deltax;
    num_pixels = deltay;         /* There are more y-values than x-values */
  }
  
  for (curpixel = 0; curpixel <= num_pixels; curpixel++)
  {
    BSP_LCD_DrawLine(x, y, x3, y3);
    
    num += num_add;              /* Increase the numerator by the top of the fraction */
    if (num >= den)             /* Check if numerator >= denominator */
    {
      num -= den;               /* Calculate the new numerator value */
      x += xinc1;               /* Change the x as appropriate */
      y += yinc1;               /* Change the y as appropriate */
    }
    x += xinc2;                 /* Change the x as appropriate */
    y += yinc2;                 /* Change the y as appropriate */
  } 
}

int initialize_touchscreen(void)
{
  uint8_t  status = 0;
  status = BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
  if(status != TS_OK) return -1;
  return 0;
}
//[rmv]
void init_background(){
	switch(state){
		case 0:
			BSP_LCD_SelectLayer(0);
			BSP_LCD_Clear(LCD_COLOR_WHITE);
			BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
			BSP_LCD_DisplayStringAt(175,50,"Pulsar",CENTER_MODE);
			BSP_LCD_DisplayStringAt(150,100,"Evolution",CENTER_MODE);
			BSP_LCD_DisplayStringAt(160,150,"Fountain",CENTER_MODE);
			BSP_LCD_DisplayStringAt(150,200,"Crocodile",CENTER_MODE);
			BSP_LCD_SetTextColor(LCD_COLOR_RED);
			BSP_LCD_DisplayStringAt(70,0,"NEXT",CENTER_MODE);
			break;
		case 1:
			BSP_LCD_SelectLayer(0);
			BSP_LCD_Clear(LCD_COLOR_WHITE);
			BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
			BSP_LCD_DisplayStringAt(185,50,"Hertz",CENTER_MODE);
			BSP_LCD_DisplayStringAt(140,100,"Copperhead",CENTER_MODE);
			BSP_LCD_DisplayStringAt(185,150,"Eight",CENTER_MODE);
			BSP_LCD_DisplayStringAt(160,200,"QueenBee",CENTER_MODE);
			BSP_LCD_SetTextColor(LCD_COLOR_RED);
			BSP_LCD_DisplayStringAt(70,0,"NEXT",CENTER_MODE);
			BSP_LCD_DisplayStringAt(70,250,"PREV",CENTER_MODE);
			break;
		case 2:
			BSP_LCD_SelectLayer(0);
			BSP_LCD_Clear(LCD_COLOR_WHITE);
			BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
			BSP_LCD_DisplayStringAt(191,50,"LWSS",CENTER_MODE);
			BSP_LCD_DisplayStringAt(142,100,"Cloverleaf",CENTER_MODE);
			BSP_LCD_DisplayStringAt(177,150,"Beacon",CENTER_MODE);
			BSP_LCD_DisplayStringAt(145,200,"GameOfLife",CENTER_MODE);
			BSP_LCD_SetTextColor(LCD_COLOR_RED);
			BSP_LCD_DisplayStringAt(70,250,"PREV",CENTER_MODE);
			break;
	}
	BSP_LCD_DrawRect(280,40,190,190);
	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	FillTriangle(460,460,475,1,21,11);
	FillTriangle(440,440,455,1,21,11);
	if(stopped){
	  BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	}
	BSP_LCD_FillRect(410,1,7,21);
	BSP_LCD_FillRect(423,1,7,21);
	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	FillTriangle(400,400,385,1,21,11);
	FillTriangle(380,380,365,1,21,11);
	for (int i = 0; i < X_SIZE; i++){
		for (int j = 0; j < Y_SIZE; j++){
			BSP_LCD_DrawRect(LCD_X_SIZE+i*10,LCD_Y_SIZE+j*10,10,10);
			
		}
	}
	
	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	BSP_LCD_DisplayStringAt(200,250,"DRAW",CENTER_MODE);
}

void draw_background(void)
{
  /* Select the LCD Background Layer  */
  BSP_LCD_SelectLayer(0);
  BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
  if(stopped){
	  BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	}
	BSP_LCD_FillRect(410,1,7,21);
	BSP_LCD_FillRect(423,1,7,21);
  for (int i = 0; i < X_SIZE; i++){
	for (int j = 0; j < Y_SIZE; j++){
		if(table[i][j] == 1) {
			BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
			BSP_LCD_FillRect(LCD_X_SIZE+i*10,LCD_Y_SIZE+j*10,10,10);
		}
		else 
		{
			BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
			BSP_LCD_FillRect(LCD_X_SIZE+i*10,LCD_Y_SIZE+j*10,10,10);
		}
		BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
		BSP_LCD_DrawRect(LCD_X_SIZE+i*10,LCD_Y_SIZE+j*10,10,10);
	}
  }
  if(!stopped){
	update_table();
  } 
}

void init_drawingbackground(){
	/* Select the LCD Background Layer  */
  delay = 100;
  stopped = 0;
  BSP_LCD_SelectLayer(0);  
  BSP_LCD_Clear(LCD_COLOR_WHITE);
  BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
  for (int i = 0; i < X_SIZE; i++){
	for (int j = 0; j < Y_SIZE; j++){
		BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
		BSP_LCD_FillRect(LCD_X_SIZE+i*10,LCD_Y_SIZE+j*10,10,10);
		BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
		BSP_LCD_DrawRect(LCD_X_SIZE+i*10,LCD_Y_SIZE+j*10,10,10);
	}
  }
  
	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	for (int i = 9; i < 18; i++){
		for (int j = 9; j < 18; j++){
			BSP_LCD_DrawRect(LCD_X_SIZE+i*10,LCD_Y_SIZE+j*10,10,10);
		}
	}
	
	vTaskDelay(1000);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	for (int i = 0; i < X_SIZE; i++){
		for (int j = 0; j < Y_SIZE; j++){
			BSP_LCD_DrawRect(LCD_X_SIZE+i*10,LCD_Y_SIZE+j*10,10,10);
		}
	}
	clearTable();
	drawing_state = 1;
	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			BSP_LCD_DrawRect(LCD_X_SIZE+i*30,LCD_Y_SIZE+j*30,30,30);
		}
	}
	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	FillTriangle(400,400,385,1,21,11);
	FillTriangle(380,380,365,1,21,11);
	FillTriangle(460,460,475,1,21,11);
	FillTriangle(440,440,455,1,21,11);
	BSP_LCD_FillRect(410,1,7,21);
	BSP_LCD_FillRect(423,1,7,21);
	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	BSP_LCD_DisplayStringAt(200,250,"DONE",CENTER_MODE);
}

void draw_drawingbackground(){
    char bufor[] = {0};
    sprintf(bufor, "Delay: %d", delay);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_FillRect(270,60,200,30);
	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
    BSP_LCD_DisplayStringAt(130, 65, (uint8_t*) bufor, CENTER_MODE);
	if(stopped){
	  BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	}
	BSP_LCD_FillRect(410,1,7,21);
	BSP_LCD_FillRect(423,1,7,21);
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			if(table[9+i][9+j] == 1) 
				BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
			else 
				BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
			BSP_LCD_FillRect(LCD_X_SIZE+i*30,LCD_Y_SIZE+j*30,30,30);
			BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
			BSP_LCD_DrawRect(LCD_X_SIZE+i*30,LCD_Y_SIZE+j*30,30,30);
		}
	}
}