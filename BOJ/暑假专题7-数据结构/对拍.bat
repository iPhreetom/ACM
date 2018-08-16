@echo off
:loop
    rand.exe %random% > data.in
    "A - std.exe"  <  data.in  >  "A - std.out"
    "A - stack.exe"  <  data.in  >  "A - stack.out"
    fc "A - stack.out" "A - std.out"
if not errorlevel 1 goto loop
pause
goto loop
