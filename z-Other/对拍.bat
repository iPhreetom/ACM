@echo off
:loop
    rand.exe %random% > data.in
    "std.exe"  <  data.in  >  "std.out"
    "your.exe"  <  data.in  >  "your.out"
    fc "your.out" "std.out"
if not errorlevel 1 goto loop
pause
goto loop
