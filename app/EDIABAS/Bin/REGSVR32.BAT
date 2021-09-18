@echo off
echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
echo !!!                                               !!!
echo !!! TOOL32 installation Version 2.0               !!!
echo !!!                                               !!!
echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
if exist c:\EDIABAS\BIN\TOOL32.EXE             goto tool1a
if exist c:\EC-APPS\EDIABAS\BIN\TOOL32.EXE     goto tool2a
echo !!!                                               !!!
echo !!! error: TOOL32 not found                       !!!
echo !!!                                               !!!
echo !!! TOOL32 in 'c:\ediabas\bin'         not found  !!!
echo !!! TOOL32 in 'c:\ec-apps\ediabas\bin' not found  !!!
goto problem

:tool1a
if not exist c:\EC-APPS\EDIABAS\BIN\TOOL32.EXE goto tool1b
echo !!!                                               !!!
echo !!! error: more than one TOOL32 found             !!!
echo !!!                                               !!!
echo !!! TOOL32 in 'c:\ediabas\bin'         found      !!!
echo !!! TOOL32 in 'c:\ec-apps\ediabas\bin' found      !!!
goto problem

:tool1b
set tool32path=C:\EDIABAS\BIN\
echo !!!                                               !!!
echo !!! TOOL32 in 'c:\ediabas\bin'         found      !!!
goto msflx

:tool2a
set tool32path=C:\EC-APPS\EDIABAS\BIN\
echo !!!                                               !!!
echo !!! TOOL32 in 'c:\ec-apps\ediabas\bin' found      !!!
goto msflx

:msflx
%tool32path%regsvr32.exe %tool32path%msflxgrd.ocx /s
if errorlevel 1 goto msflx_problem
echo !!!                                               !!!
echo !!! MSFLXGRD                        registered    !!!
goto richtx

:msflx_problem
echo !!!                                               !!!
echo !!! error: can not register MSFLXGRD.OCX          !!!
goto problem

:richtx
%tool32path%regsvr32.exe %tool32path%richtx32.ocx /s
if errorlevel 1 goto richtx_problem
echo !!!                                               !!!
echo !!! RICHTX32                        registered    !!!
goto done

:richtx_problem
echo !!!                                               !!!
echo !!! error: can not register RICHTX32.OCX          !!!
goto problem

:done
echo !!!                                               !!!
echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
echo !!!                                               !!!
echo !!! TOOL32                          installed     !!!
echo !!!                                               !!!
echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
rem auto close in 5 seconds
ping 1.1.1.1 -n 1 -w 1000 1>nul: 2>nul:
set /p=.<nul
ping 1.1.1.1 -n 1 -w 1000 1>nul: 2>nul:
set /p=.<nul
ping 1.1.1.1 -n 1 -w 1000 1>nul: 2>nul:
set /p=.<nul
ping 1.1.1.1 -n 1 -w 1000 1>nul: 2>nul:
set /p=.<nul
ping 1.1.1.1 -n 1 -w 1000 1>nul: 2>nul:
set /p=.<nul
goto end

:problem
echo !!!                                               !!!
echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
echo !!!                                               !!!
echo !!! TOOL32                          not installed !!!
echo !!!                                               !!!
echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
pause
goto end

:end
