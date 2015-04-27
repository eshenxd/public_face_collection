@echo off
robocopy /s D:/photo D:/photocopy
del /f /s /q d:\photo\*.*
echo.&pause