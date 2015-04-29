@echo off

for /d %%x in (D:\FacesData\*) do echo %%~nxx>../config/ipconfig.txt
