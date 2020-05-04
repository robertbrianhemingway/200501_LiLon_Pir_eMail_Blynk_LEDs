void setup() {
   Serial.begin(115200);
   Blynk.begin(auth,ssid,pass);

    pinMode(sirenPin, OUTPUT);  // simple signaller ATT
		pinMode(D3,OUTPUT);		// flashing LED that signals loop() is running
    flash13(times);   // flashes pin 13 high/low
    sirenValue = 50;
    lastSirenValue = sirenValue;
    Blynk.virtualWrite(V0,sirenValue);
    Blynk.virtualWrite(V1,false);
}
