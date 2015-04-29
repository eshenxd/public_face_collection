@echo off
rem for循环中  变量只能是一个字母

set /p ip=< ../config/ipconfig.txt

set address=D:\FacesData\%ip%\

set /p begin_delete1=< ../config/begin_delete1.ini

set /p end_delete1=< ../config/begin_send1.ini

echo %begin_delete1%

echo %end_delete1%

for /l  %%i in (%begin_delete1%,1,%end_delete1%) do rd %address%\%%i /s /q

set /a var=end_delete1

rem 写进ini中，变量与">"之间与留一个空格 而写进txt中则不需要

echo %var% > ../config/begin_delete1.ini

