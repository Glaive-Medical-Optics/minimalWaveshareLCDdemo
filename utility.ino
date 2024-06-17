 /*****************************************************************************
* | Author      :   Glaive Software team
* | Function    :   Utility routines
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

void turnOnPartialDisplayMode()
{
  LCD_Write_Command(TurnOnPartialDisplayMode);
}

void turnOnNormalDisplayMode()
{
  LCD_Write_Command(TurnOnNormalDisplayMode);
}

void setPartialArea(uint16_t x, uint16_t y)
{
    LCD_Write_Command(SetPartialArea);
    LCD_WriteData_Word(x);
    LCD_WriteData_Word(y);
}

void setColumnAddress(uint16_t firstCol, uint16_t lastCol)
{
    LCD_Write_Command(SetColumnAddress);
    LCD_WriteData_Word(firstCol);
    LCD_WriteData_Word(lastCol);
}

void setPageAddress(uint16_t firstRow, uint16_t lastRow)
{
    LCD_Write_Command(SetPageAddress);
    LCD_WriteData_Word(firstRow);
    LCD_WriteData_Word(lastRow);
}

void writeFrameMemory()
{
    LCD_Write_Command(WriteFrameMemory);
}
