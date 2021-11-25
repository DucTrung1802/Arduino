#define LED_1 1   // Bit 7 (1000 0000)
#define LED_2 2   // Bit 6 (0100 0000)

#define LED_4 4   // Bit 5 (0010 0000)
#define LED_5 5   // Bit 4 (0001 0000)

#define LED_6 6   // Bit 3 (0000 1000)
#define LED_7 7   // Bit 2 (0000 0100)

#define LED_9 9   // Bit 1 (0000 0010)
#define LED_10 10 // Bit 0 (0000 0001)

/*
   0: BIT 1,2,4,6,7,9 = 1110 1110 = 238
   1: BIT 4,6 = 0010 1000 = 40
   2: BIT 1,2,6,7,10 = 1100 1101 = 205
   3: BIT 2,4,6,7,10 = 0110 1101 = 109
   4: BIT
*/


unsigned char arr[] = {238, 40, 205, 109, };

void display_led(unsigned char value)
{
  digitalWrite(LED_1, 1 & (value >> 7));
  digitalWrite(LED_2, 1 & (value >> 6));
}


void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
  pinMode(LED_6, OUTPUT);
  pinMode(LED_7, OUTPUT);
  pinMode(LED_9, OUTPUT);
  pinMode(LED_10, OUTPUT);
}

void loop() {
  for (int i = 0; i < 10; i++)
  {
    display_led(arr[i]);
    delay(300);
  }
}
