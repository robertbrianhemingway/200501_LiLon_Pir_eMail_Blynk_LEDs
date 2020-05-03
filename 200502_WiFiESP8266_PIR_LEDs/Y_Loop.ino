void loop() {
    Blynk.run();

    // first check for manualOnOffButton getPirPinState
    if (manualOnOffButton) {
        // manually force LEDs on
        setSirenOn();
        Front.setOn();
        Back.setOn();
    } else {
        // poll the pirPins
        flash13(1);
        if (Front.getPirPinState()) Front_ISR();
        if (Back.getPirPinState()) Back_ISR();

        // check if leds on, and if so is time up
        bool front = Front.isPirTimeUp();
        bool back = Back.isPirTimeUp();
        if (!(front || back)) setSirenOff();
        if (lastSirenValue != sirenValue) {
          // change since last check
          Blynk.virtualWrite(V0,sirenValue);
          lastSirenValue = sirenValue;
          if (sirenValue > 200) {
             if (eMailButtonState) Blynk.email("Subject: Outside LEDs","Outside PIRs activated");
             terminalWrite(" Outside LEDs ON");
          }
        }
    }
}
