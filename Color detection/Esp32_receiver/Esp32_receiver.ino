#include <esp_now.h>
#include <WiFi.h>

#define S0_PIN 2
#define S1_PIN 4
#define S2_PIN 25
#define S3_PIN 26
#define OUT_PIN 27

uint8_t broadcastAddress[] = {0x30, 0xC6, 0xF7, 0x23, 0xC8, 0xE4};
typedef struct struct_message 
{
  int a;
  int b;
  int c;
  char d[32];
} struct_message;
struct_message myData;
esp_now_peer_info_t peerInfo;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void setup()
{
  // Set the S0, S1, S2, S3 Pins as Output
  WiFi.mode(WIFI_STA);

  pinMode(S0_PIN, OUTPUT);
  pinMode(S1_PIN, OUTPUT);
  pinMode(S2_PIN, OUTPUT);
  pinMode(S3_PIN, OUTPUT);

  //Set OUT_PIN as Input
  pinMode(OUT_PIN, INPUT);

  // Set Pulse Width scaling to 20%
  digitalWrite(S0_PIN, HIGH);
  digitalWrite(S1_PIN, LOW);

  // Enabl UART for Debugging
  Serial.begin(9600);
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_register_send_cb(OnDataSent);
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}

void loop()
{
  int r, g, b;

  r = process_red_value();
  delay(200);
  g = process_green_value();
  delay(200);
  b = process_blue_value();
  delay(200);

  Serial.print("r = ");
  Serial.print(r);
  Serial.print(" ");
  Serial.print("g = ");
  Serial.print(g);
  Serial.print(" ");
  Serial.print("b = ");
  Serial.print(b);
  Serial.print(" ");
  Serial.println();
  myData.a = r;
  myData.b = g;
  myData.c = b;

  
  if (r > 26 && r < 64 && g > 130 && g < 140 && b > 95 && b < 115 )
  {
    Serial.println("Red color");
    strcpy(myData.d, "Red color");
  }
  else if (r > 22 && r < 35 && g > 32 && g < 68 && b > 50 && b < 98 )
  {
    Serial.println("Yellow color");
    strcpy(myData.d, "Yellow color");
  }
  else if (r > 160 && r < 205 && g > 180 && g < 240 && b > 148 && b < 195 )
  {
    Serial.println("black color");
    strcpy(myData.d, "black color");
  }
  else if (r > 130 && r < 170 && g > 150 && g < 190 && b > 120 && b < 160 )
  {
    Serial.println("grey color");
    strcpy(myData.d, "grey color");
  }
  else if (r > 15 && r < 24 && g > 18 && g < 28 && b > 14 && b < 25 )
  {
    Serial.println("white color");
    strcpy(myData.d, "white color");
  }
  else if (r > 140 && r < 162 && g > 125 && g < 135 && b > 55 && b < 66 )
  {
    Serial.println("blue color");
    strcpy(myData.d, "blue color");
  }
  else if (r > 140 && r < 162 && g > 75 && g < 90 && b > 55 && b < 66 )
  {
    Serial.println("light blue color");
    strcpy(myData.d, "light blue color");
  }
  else if (r > 110 && r < 210 && g > 120 && g < 155 && b > 70 && b < 100 )
  {
    Serial.println("dark blue color");
    strcpy(myData.d, "dark blue color");
  }
  else if (r > 50 && r < 70 && g > 80 && g < 100 && b > 40 && b < 60 )
  {
    Serial.println("violet color");
    strcpy(myData.d, "violet color");
  }
  else if (r > 80 && r < 145 && g >=b && g <=(b+10) && b >= g && b <= (g+10) )
  {
    Serial.println("green color");
    strcpy(myData.d, "green color");
  }
  // else if (r > 80 && r < 85 && g > 45 && g < 63 && b > 50 && b < 55 )
  // {
  //   Serial.println("green");
  //   strcpy(myData.d, "Red color");
  // }
  else if (r > 145 && r < 150 && g > 100 && g < 110 && b > 114 && b < 120 )
  {
    Serial.println("light green color");
    strcpy(myData.d, "light green color");
  }
  else if (r > 130 && r < 150 && g > 60 && g < 78 && b > 60 && b < 80 )
  {
    Serial.println("dark green color");
    strcpy(myData.d, "dark green color");
  }
  else if (r > 25 && r < 35 && g > 65 && g < 75 && b > 35 && b < 45 )
  {
    Serial.println("pink color");
    strcpy(myData.d, "pink color");
  }
  else if (r > 35 && r < 55 && g > 55 && g < 75 && b > 55 && b < 75 )
  {
    Serial.println("brown color");
    strcpy(myData.d, "brown color");
  }
  else if (r > 65 && r < 75 && g > 165 && g < 185 && b > 120 && b < 140 )
  {
    Serial.println("maroon color");
    strcpy(myData.d, "maroon color");
  }
  else if (r > 30 && r < 55 && g > 90 && g < 145 && b > 95 && b < 145 )
  {
    Serial.println("orange color");
    strcpy(myData.d, "orange color");
  }

  else if(r<22 & r>20 & g<29 & g>27)
  {
    Serial.println("Red color");
    strcpy(myData.d, "Red color");
  }
  else if(g<25 & g>22 & b<22 &b>19)
  {
    Serial.println("Orange color");
    strcpy(myData.d, "orange color");
  }
  else if(r<21 & r>20 & g<28 & g>25)
  {
    Serial.println("green color");
    strcpy(myData.d, "green color");
  }
  else if(r<38 & r>24 & g<44 & g>30)
  {
    Serial.println("Yellow color");
    strcpy(myData.d, "Yellow color");
  }
  else if (r>65 & r<90 & g>30 & g<50 & b>18 & b<30)
  {
    Serial.println("blue  color");
    strcpy(myData.d, "blue color");
  }

  else if (r < 42)
  {
    Serial.println("looks like Pink color");
    strcpy(myData.d, "looks like Pink color");
  }
  else if (g < 63)
  {
    Serial.println("looks like Green color");
    strcpy(myData.d, "looks like Green color");
  }
  else if (r < 64)
  {
    Serial.println("looks like Red color");
    strcpy(myData.d, "looks like Red color");
  }
  else if (b < 64)
  {
    Serial.println("looks like blue color");
    strcpy(myData.d, "looks like blue color");
  }
  else if (r > 370 && r < 385 && g > 430 && g < 460 && b > 340 && b < 370 )
  {
    Serial.println("Color out of range");
    strcpy(myData.d, "Color out of range");
  }
  else
  {
    Serial.println("No object detected");
    strcpy(myData.d, "No object detected");
  }

  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
   
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
  delay(650);
}


int process_red_value()
{
  digitalWrite(S2_PIN, LOW);
  digitalWrite(S3_PIN, LOW);

  int pulse_length = pulseIn(OUT_PIN, LOW);
  return pulse_length;
}

int process_green_value()
{
  digitalWrite(S2_PIN, HIGH);
  digitalWrite(S3_PIN, HIGH);

  int pulse_length = pulseIn(OUT_PIN, LOW);
  return pulse_length;

}

int process_blue_value()
{
  digitalWrite(S2_PIN, LOW);
  digitalWrite(S3_PIN, HIGH);

  int pulse_length = pulseIn(OUT_PIN, LOW);
  return pulse_length;
}