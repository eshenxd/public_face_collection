@echo off

setlocal enabledelayedexpansion

set picPath=D:\FacesData\

set romPath=DATA1

set ftpUser=hfga_wb

set ftpPasswd=hfga

echo 第一次运行本程序时请务必在文件“begin_send1.ini”中设置起始文件夹序号！

set /p begin=<../config/begin_send1.ini

set /p ip=<../config/ipconfig.txt

echo 起始文件夹序号为%begin%

rem for /f "delims="  %%i in ('dir %picPath% /ad /o:d /b') do echo %%i>>文件夹目录.txt

for /f "delims="  %%i in ('dir %picPath%\%ip% /ad /o:d /b') do echo %%i>>文件夹目录.txt

for /f %%i in (文件夹目录.txt) do set  end=%%i
                                                   
echo 结尾文件夹序号为%end%

del 文件夹目录.txt

rem if %begin%==%end%  goto end

set /a mark=1

set /a last=end

set /a t=end+1

echo !t!>../config/begin_send1.ini

rem do (7z.exe a -tzip "%zipPath%" "%picPath%\%%x")

if %begin%==%mark% (

echo 开始上传...

if exist ftpin del ftpin

echo open 114.214.167.95> ftpin

echo %ftpUser%>>ftpin

echo %ftpPasswd%>>ftpin

echo mkdir %romPath%>>ftpin

echo bin>>ftpin

echo bye>>ftpin

echo 开始上传

ftp -i -s:ftpin

echo 上传完成

del ftpin

)

for /l %%x in (%begin%,1,%last%) do (

echo 开始上传...

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

echo 开始上传

ftp -i -s:ftpin

echo 上传完成

del ftpin

)

echo.&pause