@echo off
rem forѭ����  ����ֻ����һ����ĸ

set /p ip=< ../config/ipconfig.txt

set address=D:\FacesData\%ip%\

set /p begin_delete1=< ../config/begin_delete1.ini

set /p end_delete1=< ../config/begin_send1.ini

echo %begin_delete1%

echo %end_delete1%

for /l  %%i in (%begin_delete1%,1,%end_delete1%) do rd %address%\%%i /s /q

set /a var=end_delete1

rem д��ini�У�������">"֮������һ���ո� ��д��txt������Ҫ

echo %var% > ../config/begin_delete1.ini

