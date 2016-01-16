// set this to the hardware serial port you wish to use
#define HWSERIAL Serial1


int amount_to_print = 0;
int currently_printing = 0;
int filling_slots = 0;
int toPrint[10000];
long last_print = 0;
long last_light = 0;
bool type_filler = false;
bool cmd = false;

void setup() {
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  Serial.begin(115200);
  HWSERIAL.begin(115200);
  last_print = millis();
  last_light = millis();
  for (int i = 0; i < 10000; i++) {
    toPrint[i] = -1;
  }
}

void loop() {
  int incomingByte;

  
  if (HWSERIAL.available() > 0) {
    
    incomingByte = HWSERIAL.read();
    //    Serial.println(incomingByte);
    //    printKey(incomingByte);
    toPrint[filling_slots] = incomingByte;
    
    digitalWrite(2, HIGH);
    last_light = millis();
    Serial.println(incomingByte);
    filling_slots++;

  }

  if(millis() - last_light >= 10){
    digitalWrite(2, LOW);
  }

  if (millis() - last_print >= 10) {
    //    if (amount_to_print >= 2) {
    //      for (int i = 0; i < amount_to_print; i++) {
    //        printKey(toPrint[i]);
    //      }
    //      amount_to_print = 0;
    //      last_print = millis();
    //    }
    if (toPrint[currently_printing] != -1) {
      if(toPrint[currently_printing] == 142){
        cmd = true;
      }else if(cmd && toPrint[currently_printing] == 99){
        Keyboard.set_modifier(MODIFIERKEY_GUI);
        Keyboard.send_now();
        Keyboard.set_key1(KEY_C);
        Keyboard.send_now();
        Keyboard.set_modifier(0);
        Keyboard.set_key1(0);
        Keyboard.send_now();
      }else if(cmd && toPrint[currently_printing] == 118){
        Keyboard.set_modifier(MODIFIERKEY_GUI);
        Keyboard.send_now();
        Keyboard.set_key1(KEY_V);
        Keyboard.send_now();
        Keyboard.set_modifier(0);
        Keyboard.set_key1(0);
        Keyboard.send_now();
      }else if(cmd && toPrint[currently_printing] == 97){
        Keyboard.set_modifier(MODIFIERKEY_GUI);
        Keyboard.send_now();
        Keyboard.set_key1(KEY_A);
        Keyboard.send_now();
        Keyboard.set_modifier(0);
        Keyboard.set_key1(0);
        Keyboard.send_now();
        cmd = false;
      }else if(cmd && toPrint[currently_printing] == 114){
        Keyboard.set_modifier(MODIFIERKEY_GUI);
        Keyboard.send_now();
        Keyboard.set_key1(KEY_R);
        Keyboard.send_now();
        Keyboard.set_modifier(0);
        Keyboard.set_key1(0);
        Keyboard.send_now();
        cmd = false;
      }else{
        printKey(toPrint[currently_printing]);
        cmd = false;
      }
      
      
//      if (toPrint[currently_printing] != 128 && toPrint[currently_printing] != 129 && toPrint[currently_printing] != 142) {
//        type_filler = true;
//      }
      type_filler = true;
      currently_printing++;
    
    } else if (type_filler) {
      //      Keyboard.set_modifier(MODIFIERKEY_SHIFT);
      //      Keyboard.send_now();
      //      Keyboard.set_modifier(0);
      //      Keyboard.send_now();

      Keyboard.set_key1(KEY_CAPS_LOCK);
      Keyboard.send_now();
      Keyboard.set_key1(0);
      Keyboard.send_now();
      Keyboard.set_key1(KEY_CAPS_LOCK);
      Keyboard.send_now();
      Keyboard.set_key1(0);
      Keyboard.send_now();

      type_filler = false;

    }
    last_print = millis();
    //    Keyboard.set_modifier(MODIFIERKEY_ALT);
    //    Keyboard.send_now();
    //    Keyboard.set_modifier(0);
    //    Keyboard.send_now();
  }





}


//https://www.pjrc.com/teensy/td_keyboard.html
void printKey(byte incoming) {
  //  Keyboard.print("works:");
  //  Keyboard.print(incoming);

  //  if(incoming == 8){
  //    Keyboard.set_key1(KEY_BACKSPACE);
  //    Keyboard.send_now();
  //  }

  if (incoming == 32) {
    Keyboard.print(" ");
  } else if (incoming == 33) {
    Keyboard.print("!");
  } else if (incoming == 34) {
    Keyboard.print('"');
  } else if (incoming == 35) {
    Keyboard.print("#");
  } else if (incoming == 36) {
    Keyboard.print("$");
  } else if (incoming == 37) {
    Keyboard.print("%");
  } else if (incoming == 38) {
    Keyboard.print("&");
  } else if (incoming == 39) {
    Keyboard.print("'");
  } else if (incoming == 40) {
    Keyboard.print("(");
  } else if (incoming == 41) {
    Keyboard.print(")");
  } else if (incoming == 42) {
    Keyboard.print("*");
  } else if (incoming == 43) {
    Keyboard.print("+");
  } else if (incoming == 44) {
    Keyboard.print(",");
  } else if (incoming == 45) {
    Keyboard.print("-");
  } else if (incoming == 46) {
    Keyboard.print(".");
  } else if (incoming == 47) {
    Keyboard.print("/");
  } else if (incoming == 48) {
    Keyboard.print("0");
  } else if (incoming == 49) {
    Keyboard.print("1");
  } else if (incoming == 50) {
    Keyboard.print("2");
  } else if (incoming == 51) {
    Keyboard.print("3");
  } else if (incoming == 52) {
    Keyboard.print("4");
  } else if (incoming == 53) {
    Keyboard.print("5");
  } else if (incoming == 54) {
    Keyboard.print("6");
  } else if (incoming == 55) {
    Keyboard.print("7");
  } else if (incoming == 56) {
    Keyboard.print("8");
  } else if (incoming == 57) {
    Keyboard.print("9");
  } else if (incoming == 58) {
    Keyboard.print(":");
  } else if (incoming == 59) {
    Keyboard.print(";");
  } else if (incoming == 60) {
    Keyboard.print("<");
  } else if (incoming == 61) {
    Keyboard.print("=");
  } else if (incoming == 62) {
    Keyboard.print(">");
  } else if (incoming == 63) {
    Keyboard.print("?");
  } else if (incoming == 64) {
    Keyboard.print("@");
  } else if (incoming == 65) {
    Keyboard.print("A");
  } else if (incoming == 66) {
    Keyboard.print("B");
  } else if (incoming == 67) {
    Keyboard.print("C");
  } else if (incoming == 68) {
    Keyboard.print("D");
  } else if (incoming == 69) {
    Keyboard.print("E");
  } else if (incoming == 70) {
    Keyboard.print("F");
  } else if (incoming == 71) {
    Keyboard.print("G");
  } else if (incoming == 72) {
    Keyboard.print("H");
  } else if (incoming == 73) {
    Keyboard.print("I");
  } else if (incoming == 74) {
    Keyboard.print("J");
  } else if (incoming == 75) {
    Keyboard.print("K");
  } else if (incoming == 76) {
    Keyboard.print("L");
  } else if (incoming == 77) {
    Keyboard.print("M");
  } else if (incoming == 78) {
    Keyboard.print("N");
  } else if (incoming == 79) {
    Keyboard.print("O");
  } else if (incoming == 80) {
    Keyboard.print("P");
  } else if (incoming == 81) {
    Keyboard.print("Q");
  } else if (incoming == 82) {
    Keyboard.print("R");
  } else if (incoming == 83) {
    Keyboard.print("S");
  } else if (incoming == 84) {
    Keyboard.print("T");
  } else if (incoming == 85) {
    Keyboard.print("U");
  } else if (incoming == 86) {
    Keyboard.print("V");
  } else if (incoming == 87) {
    Keyboard.print("W");
  } else if (incoming == 88) {
    Keyboard.print("X");
  } else if (incoming == 89) {
    Keyboard.print("Y");
  } else if (incoming == 90) {
    Keyboard.print("Z");
  } else if (incoming == 91) {
    Keyboard.print("[");
  } else if (incoming == 92) {
    Keyboard.print("\\");
  } else if (incoming == 93) {
    Keyboard.print("]");
  } else if (incoming == 94) {
    Keyboard.print("^");
  } else if (incoming == 95) {
    Keyboard.print("_");
  } else if (incoming == 96) {
    Keyboard.print("`");
  } else if (incoming == 97) {
    Keyboard.print("a");
  } else if (incoming == 98) {
    Keyboard.print("b");
  } else if (incoming == 99) {
    Keyboard.print("c");
  } else if (incoming == 100) {
    Keyboard.print("d");
  } else if (incoming == 101) {
    Keyboard.print("e");
  } else if (incoming == 102) {
    Keyboard.print("f");
  } else if (incoming == 103) {
    Keyboard.print("g");
  } else if (incoming == 104) {
    Keyboard.print("h");
  } else if (incoming == 105) {
    Keyboard.print("i");
  } else if (incoming == 106) {
    Keyboard.print("j");
  } else if (incoming == 107) {
    Keyboard.print("k");
  } else if (incoming == 108) {
    Keyboard.print("l");
  } else if (incoming == 109) {
    Keyboard.print("m");
  } else if (incoming == 110) {
    Keyboard.print("n");
  } else if (incoming == 111) {
    Keyboard.print("o");
  } else if (incoming == 112) {
    Keyboard.print("p");
  } else if (incoming == 113) {
    Keyboard.print("q");
  } else if (incoming == 114) {
    Keyboard.print("r");
  } else if (incoming == 115) {
    Keyboard.print("s");
  } else if (incoming == 116) {
    Keyboard.print("t");
  } else if (incoming == 117) {
    Keyboard.print("u");
  } else if (incoming == 118) {
    Keyboard.print("v");
  } else if (incoming == 119) {
    Keyboard.print("w");
  } else if (incoming == 120) {
    Keyboard.print("x");
  } else if (incoming == 121) {
    Keyboard.print("y");
  } else if (incoming == 122) {
    Keyboard.print("z");
  } else if (incoming == 123) {
    Keyboard.print("{");
  } else if (incoming == 124) {
    Keyboard.print("|");
  } else if (incoming == 125) {
    Keyboard.print("}");
  } else if (incoming == 126) {
    Keyboard.print("~");
  } else if (incoming == 8) {
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<---- special keys
    Keyboard.set_key1(KEY_BACKSPACE);
    Keyboard.send_now();
    Keyboard.set_key1(0);
    Keyboard.send_now();
  } else if (incoming == 218) {
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<---- special keys
    Keyboard.set_key1(KEY_DOWN);
    Keyboard.send_now();
    Keyboard.set_key1(0);
    Keyboard.send_now();
  } else if (incoming == 219) {
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<---- special keys
    Keyboard.set_key1(KEY_LEFT);
    Keyboard.send_now();
    Keyboard.set_key1(0);
    Keyboard.send_now();
  } else if (incoming == 220) {
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<---- special keys
    Keyboard.set_key1(KEY_DOWN);
    Keyboard.send_now();
    Keyboard.set_key1(0);
    Keyboard.send_now();
  } else if (incoming == 221) {
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<---- special keys
    Keyboard.set_key1(KEY_RIGHT);
    Keyboard.send_now();
    Keyboard.set_key1(0);
    Keyboard.send_now();
  } else if (incoming == 0) {
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<---- special keys
    // commented out because it would bring the user to a different text area.
//    Keyboard.set_key1(KEY_TAB);
//    Keyboard.send_now();
//    Keyboard.set_key1(0);
//    Keyboard.send_now();

  }else if (incoming == 13) {
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<---- special keys
    
    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    Keyboard.set_key1(0);
    Keyboard.send_now();

  }




}

