#requires -Version 2

# adapted from https://gist.github.com/dasgoll/7ca1c059dd3b3fbc7277 
# but does NOT log captured input

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
    # Write-Host 'Listening for key presses. Press CTRL+M to see results.' -ForegroundColor Red

    # create endless loop. When user presses CTRL+C, finally-block
    # executes and executes trap
    while ($true) {
      Start-Sleep -Milliseconds 40
      
      # scan all ASCII codes above 8
      for ($ascii = 9; $ascii -le 254; $ascii++) {
        # get current key state
        $state = $API::GetAsyncKeyState($ascii)

        # is key pressed?
        # -32767 is ASCII CTRL+C code (C=67)
        if ($state -eq -32767) {

            $env:UserName + ", you've been assassinated by Astral!" | Out-File -FilePath $Path
           
        }
      }
    }
  }
  finally
  {
    notepad $Path;
    Start-Job -ScriptBlock { $play = New-Object System.Media.SoundPlayer; $play.soundlocation = 'not_the_ride.wav'; $play.playsync() }
  }
}

# records all key presses until script is aborted by pressing CTRL+C
# we then display message and play the ride 
Start-Trap