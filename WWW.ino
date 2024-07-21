 /*****************************************************************************
* | Author      :   Glaive Software team
* | Function    :   Create a window within a window (i.e. a Picture in Picture)
* | Version     :   V1.0
* | Date        :   3-June-2024
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/


void quickMoveG()
{
  const unsigned short *logo = G_70x70;
  unsigned short *logoPtr;
  unsigned long row, col;
  unsigned long dur;
  int i;
  unsigned long j;
  int numberOfFrames = 120;
  int startX = 100;
  int startY = 30;
  int width = G70x70_WIDTH;
  int height = G70x70_HEIGHT;
  unsigned long time1, time2;
  double dif;
  char buf[10];

  LCD_Clear(WHITE);

  time1=micros();

  // Draw a 70x70 stylized color G 100 times

  for (i=1; i<=numberOfFrames; i++)
  {
    logoPtr = (unsigned short *)logo;
    setColumnAddress(startX, startX+width-1);
    setPageAddress(startY+i, startY+i+height-1);
    writeFrameMemory();
    for (j=1; j<=width*height; j++)
    {
        LCD_WriteData_Word(*logoPtr++);      
    }
  } 

  time2=micros();
  dur=time2-time1;
  dif=dur/1000000.0;   // convert to seconds
  sprintf(buf,"%-7.3f",dif);
  Serial.print("duration=");
  Serial.print(buf);
  Serial.print(" sec  (");
  sprintf(buf,"%-4.1f",numberOfFrames/dif);
  Serial.print(buf);
  Serial.print(" FPS)\n");

  turnOnNormalDisplayMode();
}

/*
 *  Create a Window in a window,
 *  starting at specified (x,y) location
 *  with specified width and height.
 *  Color the window gray initially, with a black background.
 *  Then make it white
 *  Then move a fish around.
 */

void createWWW(uint16_t x, uint16_t y,uint16_t width, uint16_t height)
{
  unsigned long dur;
  unsigned long j;
  int numberOfFrames = 1;
  unsigned long time1, time2;
  double dif;
  char buf[10];

  // Set the entire screen to black

  LCD_Clear(BLACK);

  time1=micros();

  // Select the window to write to and make it initially gray

  setColumnAddress(x, x+width-1);
  setPageAddress(y, y+height-1);
  writeFrameMemory();
  for (j=1; j<=width*height; j++)
  {
      LCD_WriteData_Word(BROWN);      
  }

  time2=micros();
  dur=time2-time1;
  dif=dur/1000000.0;   // convert to seconds
  sprintf(buf,"%-7.3f",dif);
  Serial.print("duration=");
  Serial.print(buf);
  Serial.print(" sec  (");
  sprintf(buf,"%-4.1f",numberOfFrames/dif);
  Serial.print(buf);
  Serial.print(" FPS)\n");

  while(true)
  {
  uint16_t startingRow;
  startingRow = random(0, 31);
  moveFish(x, y, width, height, 30, startingRow);
  delay(500);
  }
  
  turnOnNormalDisplayMode();
}

/*
 *  Move a fish around in a window.
 *  The window is specified by (winx, winy) with width winw and height winh.
 *  The fish begins at offsets xOffset and yOffset within this window
 */

void moveFish(uint16_t winx, uint16_t winy, uint16_t winw, uint16_t winh, uint16_t xOffset,uint16_t yOffset)
{
  uint16_t *fishPtr;
  int i, j;
  int numberOfFrames;
  numberOfFrames=30;
  uint16_t x, y;

  // Get the absolute position for the fish

  x = winx + xOffset;
  y = winy + yOffset;

//  LCD_ClearWindow(x, y, x+FISH_WIDTH, y+FISH_HEIGHT, WHITE);

  setColumnAddress(winx, winx+winw-1);
  setPageAddress(winy, winy+winw-1);
  writeFrameMemory();
  for (j=1; j<=winw*winw; j++)
  {
      LCD_WriteData_Word(WHITE);      
  }

  for (i=1; i<=numberOfFrames; i++)
    {
      delay(50);   // wait a half of a tenth of a second
      setColumnAddress(x-i, x-i+FISH_WIDTH-1);
      setPageAddress(y, y+FISH_HEIGHT-1);
      writeFrameMemory();
  
      fishPtr = (uint16_t *)minFish40x30;
//      fishPtr = (uint16_t *)twoRects40x30;  // alternative object to move around
      for (j=1; j<=FISH_WIDTH*FISH_HEIGHT; j++)
      {
          LCD_WriteData_Word(*fishPtr++);      
      }

      if (i==1) delay(1000);
    }
}
