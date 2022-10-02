#include <SPI.h>
#include <MFRC522.h> 
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

#define SS_PIN 10
#define RST_PIN 9

int screenWidth = 16;
int screenHeight = 2;
int stringStart, stringStop = 0;
int scrollCursor = screenWidth;

String line1 = "BY ROBOTICS & CIRCUITS ";
  
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
  int red= 4;
  int green= 3;

void setup() 
{

   lcd.begin(16,2);
  Serial.begin(9600);   // Initiate a serial communication
 lcd.setCursor(0, 0);
 lcd.print("INITIALIZING...");
 delay(200);
  lcd.setCursor(0, 1);
  lcd.print("PLEASE WAIT");
  delay(700);
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  
  Serial.println();
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
lcd.clear();
}
void loop() 
{
lcd.setCursor(0,0);
lcd.print("Flash Your Card");
lcd.setCursor(1,1);
scroll();
{
  lcd.print(line1.substring(stringStart,stringStop));
}
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "B6 A9 03 73") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("UNMESH,RNC");
    Serial.println();
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    delay(3000);
    digitalWrite(red,LOW);
  }
 else if (content.substring(1) == "FE 3C 1B 6A")
  {
    lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("UNMESH");
     lcd.setCursor(0, 1);
     lcd.print("RNC");
    Serial.println("UNMESH,RNC");
    Serial.println();
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    delay(3000);
    digitalWrite(green,LOW);
  }
 else if (content.substring(1) == "17 20 E9 19")
  {
    Serial.println("ADIL,RNC");
    Serial.println();
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    delay(3000);
    digitalWrite(green,LOW);
  }
  else if (content.substring(1) == "2E CA A1 7A")
  {
    Serial.println("MAHESH,RNC");
    lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("MAHESH");
     lcd.setCursor(0, 1);
     lcd.print("RNC");
    Serial.println();
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    delay(3000);
    digitalWrite(green,LOW);
    lcd.clear();
     
  }
   else if (content.substring(1) == "0E D4 A1 7A")
  {
    Serial.println("RUDRANEEL,RNC");
    Serial.println();
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    delay(3000);
    digitalWrite(red,LOW);
  }
   else if (content.substring(1) == "2E C1 1B 6A")
  {
    Serial.println("VARUN,RNC");
    Serial.println();
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    delay(3000);
    digitalWrite(red,LOW);
  }
   else if (content.substring(1) == "FE 0A A2 7A")
  {
    Serial.println("VISHAL,RNC");
    Serial.println();
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    delay(3000);
    digitalWrite(red,LOW);
  }
   else if (content.substring(1) == "9E F6 1B 6A")
  {
    Serial.println("KAUSTUBH,RNC");
    Serial.println();
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    delay(3000);
    digitalWrite(red,LOW);
  }
   else if (content.substring(1) == "36 04 F9 73")
  {
    Serial.println("VIVIAN,RNC");
    Serial.println();
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    delay(3000);
    digitalWrite(red,LOW);
  } 
   else if (content.substring(1) == "5E F2 1B 6A")
  {
    Serial.println("ABDUL,RNC");
    Serial.println();
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    delay(3000);
    digitalWrite(red,LOW);
  }
   else if (content.substring(1) == "AE FD 1B 6A")
  {
    Serial.println("SHIVANSH,RNC");
    Serial.println();
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    delay(3000);
    digitalWrite(red,LOW);
  }
  else if (content.substring(1) == "5E 75 1B 6A")
  {
    Serial.println("NIKUNJ,RNC");
    Serial.println();
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    delay(3000);
    digitalWrite(red,LOW);
  }
  else if (content.substring(1) == "1E 6F 1A 6A")
  {
    Serial.println("ADIT,RNC");
    Serial.println();
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    delay(3000);
    digitalWrite(red,LOW);
  }
  else if (content.substring(1) == "DE BA A0 7A")
  {
    Serial.println("MUKUL,RNC");
    Serial.println();
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    delay(3000);
    digitalWrite(red,LOW);
  }
  else if (content.substring(1) == "46 6C FC 73")
  {
    Serial.println("SANDIPAN,RNC");
    Serial.println();
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    delay(3000);
    digitalWrite(red,LOW);
  }
  else if (content.substring(1) == "4E C7 1B 6A")
  {
    Serial.println("DARSH,RNC");
    Serial.println();
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    delay(3000);
    digitalWrite(red,LOW);
  }
                                                                                                                                                                                                                           
 else   {
    Serial.println("Unknown Card!");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Access Denied!!");
     lcd.setCursor(0,1);
     lcd.print("NO ENTRY");
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    delay(1500);
    digitalWrite(red,LOW);
    lcd.clear();
  }
} 

int str_length()
{
  if(line1)
  {
    return line1.length();
  }
}

void scroll()
{
  lcd.setCursor(scrollCursor, 1);
   if(stringStart == 0 && scrollCursor > 0){
    scrollCursor--;
    stringStop++;
  } else if (stringStart == stringStop){
    stringStart = stringStop = 0;
    scrollCursor = screenWidth;
  } else if (stringStop == str_length() && scrollCursor == 0) {
    stringStart++;
  } else {
    stringStart++;
    stringStop++;
  }
  delay(300);
}

