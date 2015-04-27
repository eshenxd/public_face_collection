@echo off
ipconfig >1.txt
for /f "tokens=2 delims=:" %%i in ('findstr "IPv4 " 1.txt') do echo %%i>2.txt

del /q 1.txt
