@echo off

setlocal enabledelayedexpansion

set picPath=D:\FacesData\

set romPath=DATA1

set ftpUser=hfga_wb

set ftpPasswd=hfga

echo ��һ�����б�����ʱ��������ļ���begin_send1.ini����������ʼ�ļ�����ţ�

set /p begin=<../config/begin_send1.ini

set /p ip=<../config/ipconfig.txt

echo ��ʼ�ļ������Ϊ%begin%

rem for /f "delims="  %%i in ('dir %picPath% /ad /o:d /b') do echo %%i>>�ļ���Ŀ¼.txt

for /f "delims="  %%i in ('dir %picPath%\%ip% /ad /o:d /b') do echo %%i>>�ļ���Ŀ¼.txt

for /f %%i in (�ļ���Ŀ¼.txt) do set  end=%%i
                                                   
echo ��β�ļ������Ϊ%end%

del �ļ���Ŀ¼.txt

rem if %begin%==%end%  goto end

set /a mark=1

set /a last=end

set /a t=end+1

echo !t!>../config/begin_send1.ini

rem do (7z.exe a -tzip "%zipPath%" "%picPath%\%%x")

if %begin%==%mark% (

echo ��ʼ�ϴ�...

if exist ftpin del ftpin

echo open 114.214.167.95> ftpin

echo %ftpUser%>>ftpin

echo %ftpPasswd%>>ftpin

echo mkdir %romPath%>>ftpin

echo bin>>ftpin

echo bye>>ftpin

echo ��ʼ�ϴ�

ftp -i -s:ftpin

echo �ϴ����

del ftpin

)

for /l %%x in (%begin%,1,%last%) do (

echo ��ʼ�ϴ�...

if exist ftpin del ftpin

echo open 114.214.167.95> ftpin

echo %ftpUser%>>ftpin

echo %ftpPasswd%>>ftpin

echo cd %romPath%>>ftpin

echo mkdir %ip% >>ftpin

echo cd %ip%>>ftpin

echo mkdir %%x>>ftpin

echo cd %%x>>ftpin

echo bin>>ftpin

echo mput %picPath%\%ip%\%%x\*.jpg>>ftpin

echo bye>>ftpin

echo ��ʼ�ϴ�

ftp -i -s:ftpin

echo �ϴ����

del ftpin

)

echo.&pause