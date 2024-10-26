// Imported Libraries and Modules:
#include <LiquidCrystal.h>
#include <Keypad.h>

// Keypad Set-Up:
const int Row_Num = 4; // 4 Rows.
const int Col_Num = 4; // 4 Columns.

char keys [Row_Num] [Col_Num] = {
  {'1','2','3','A'}, //Row 1.
  {'4','5','6','B'}, //Row 2.
  {'7','8','9','C'}, //Row 3.
  {'*','0','#','D'}  //Row 4.
};

byte Row_Pins[Row_Num] = {0,1,2,3};
byte Col_Pins[Col_Num] = {4,5,6,7};

Keypad keypad = Keypad(makeKeymap(keys),Row_Pins,Col_Pins,Row_Num,Col_Num);

// LCD Set-Up:
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 =  12, d7 = 13; //Pins to which LCD is connected
LiquidCrystal lcd(rs, en, d4, d5,  d6, d7);

// Miscelaneous Variable Declaration:
long Num1, Num2, Number;
char key,action;
boolean result = false;

void setup() {
  lcd.begin(16,2); // Starts up the 2x16 display.
  lcd.setCursor(0,0); // Set cursor position.
  lcd.print("DIY Calculator"); // Print "welcome message / title".
  delay(2500); // displays the message for 2.5 seconds (2500ms)
  
  lcd.clear(); // Clears the display.

}

void loop() {
  
key = keypad.getKey();
  //storing pressed key value in a char

if (key!=NO_KEY)
DetectButtons();

if
  (result==true)
CalculateResult();

DisplayResult();   
}

void
  DetectButtons()
{ 
     lcd.clear(); //Then clean it
    if (key=='*')
  //If cancel Button is pressed
    {Serial.println ("Button Cancel"); Number=Num1=Num2=0;
  result=false;}
    
     if (key == '1') //If Button 1 is pressed
    {Serial.println
  ("Button 1"); 
    if (Number==0)
    Number=1;
    else
    Number
  = (Number*10) + 1; //Pressed twice
    }
    
     if (key == '4') //If Button 4 is pressed
    {Serial.println ("Button 4"); 
    if (Number==0)

    Number=4;
    else
    Number = (Number*10) + 4; //Pressed twice
    }

    
     if (key == '7') //If Button 7 is pressed
    {Serial.println ("Button 7");
    if (Number==0)
    Number=7;
    else
    Number = (Number*10) + 7; //Pressed twice
    } 
  

    if (key == '0')
    {Serial.println
  ("Button 0"); //Button 0 is Pressed
    if (Number==0)
    Number=0;

    else
    Number = (Number*10) + 0; //Pressed twice
    }
    
     if
  (key == '2') //Button 2 is Pressed
    {Serial.println ("Button 2"); 
     if
  (Number==0)
    Number=2;
    else
    Number = (Number*10) + 2; //Pressed twice
    }
    
     if (key == '5')
    {Serial.println ("Button 5"); 
     if (Number==0)
    Number=5;
    else
    Number = (Number*10)
  + 5; //Pressed twice
    }
    
     if (key == '8')
    {Serial.println
  ("Button 8"); 
     if (Number==0)
    Number=8;
    else
    Number
  = (Number*10) + 8; //Pressed twice
    }   
  

    if (key == '#')

    {Serial.println ("Button Equal"); 
    Num2=Number;
    result = true;

    }
    
     if (key == '3')
    {Serial.println ("Button 3"); 

     if (Number==0)
    Number=3;
    else
    Number = (Number*10) + 3;
  //Pressed twice
    }
    
     if (key == '6')
    {Serial.println
  ("Button 6"); 
    if (Number==0)
    Number=6;
    else
    Number
  = (Number*10) + 6; //Pressed twice
    }
    
     if (key == '9')

    {Serial.println ("Button 9");
    if (Number==0)
    Number=9;
    else

    Number = (Number*10) + 9; //Pressed twice
    }  

      if (key ==
  'A' || key == 'B' || key == 'C' || key == 'D') //Detecting Buttons on Column 4

  {
    Num1 = Number;    
    Number =0;
    if (key == 'A')
    {Serial.println ("Addition"); action = '+';}
     if (key == 'B')
    {Serial.println ("Subtraction");
  action = '-'; }
     if (key == 'C')
    {Serial.println ("Multiplication");
  action = '*';}
     if (key == 'D')
    {Serial.println ("Division"); action
  = '/';}  

    delay(100);
  }
  
}

void CalculateResult()
{

  if (action=='+')
    Number = Num1+Num2;

  if (action=='-')
    Number
  = Num1-Num2;

  if (action=='*')
    Number = Num1*Num2;

  if (action=='/')

    Number = Num1/Num2; 
}

void DisplayResult()
{
  lcd.setCursor(0,0);   // set the cursor to column 0, line 1
  lcd.print(Num1); lcd.print(action);
  lcd.print(Num2); 
  
  if (result==true)
    {lcd.print(" = "); 
    lcd.print(Number);}
  
  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
  lcd.print(Number); //Display the result
}
