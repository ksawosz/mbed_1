#include "mbed.h"
#include "TS_DISCO_F429ZI.h"
#include "LCD_DISCO_F429ZI.h"

LCD_DISCO_F429ZI lcd;
TS_DISCO_F429ZI ts;

int main()
{
    TS_StateTypeDef TS_State;

    lcd.Clear(LCD_COLOR_BLACK);
    BSP_LCD_SetFont(&Font24);
    
    while(1)
    {
        for(uint8_t ucRectCounter = 0; ucRectCounter < 4; ucRectCounter++){
            lcd.SetTextColor(LCD_COLOR_BLUE);
            lcd.FillRect(0, ucRectCounter*80, 80, 80);
            lcd.SetTextColor(LCD_COLOR_GREEN);
            lcd.DrawRect(0, ucRectCounter*80, 80, 80);

            lcd.SetBackColor(LCD_COLOR_RED);
            lcd.SetTextColor(LCD_COLOR_WHITE);
            lcd.DisplayChar(0, ucRectCounter*80, ucRectCounter+48);
        }
      
      ts.GetState(&TS_State);      
      if (TS_State.TouchDetected)
      {

      }
      wait(0.1);
    }
}
