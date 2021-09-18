@echo off
echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
echo !!!                                               !!!
echo !!! NFS installation Version 2.0                  !!!
echo !!!                                               !!!
echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
if exist C:\NFS\BIN\NFS.EXE                     goto nfs1a
if exist C:\EC-APPS\NFS\BIN\NFS.EXE             goto nfs2a
echo !!!                                               !!!
echo !!! error: NFS not found                          !!!
echo !!!                                               !!!
echo !!! NFS in 'c:\nfs'                 not found     !!!
echo !!! NFS in 'c:\ec-apps\nfs'         not found     !!!
goto problem

:nfs1a
if not exist C:\EC-APPS\NFS\BIN\NFS.EXE         goto nfs1b
echo !!!                                               !!!
echo !!! error: more than one NFS found                !!!
echo !!!                                               !!!
echo !!! NFS in 'c:\nfs'                 found         !!!
echo !!! NFS in 'c:\ec-apps\nfs'         found         !!!
goto problem

:nfs1b
set nfspath=C:\NFS\BIN\
echo !!!                                               !!!
echo !!! NFS in 'c:\nfs'                 found         !!!
goto vcredist_install

:nfs2a
set nfspath=C:\EC-APPS\NFS\BIN\
echo !!!                                               !!!
echo !!! NFS in 'c:\ec-apps\nfs'         found         !!!
goto vcredist_install

:vcredist_install
if exist %nfspath%vcredist_x86.installed goto vcredist_installed
msiexec.exe /i %nfspath%vcredist.msi /passive
if errorlevel 1 goto vcredist_uninstall
goto vcredist_weiter

:vcredist_uninstall
msiexec.exe /x %nfspath%vcredist.msi /passive
msiexec.exe /i %nfspath%vcredist.msi /passive
if errorlevel 1 goto vcredist_problem
goto vcredist_weiter

:vcredist_weiter
echo %nfspath%vcredist_x86.installed > %nfspath%vcredist_x86.installed
if errorlevel 1 goto vcredist_problem
if not exist %nfspath%vcredist_x86.installed goto vcredist_problem
echo !!!                                               !!!
echo !!! MFC80                           installed     !!!
echo !!! file vcredist_x86.installed created           !!!
goto kmm

:vcredist_installed
echo !!!                                               !!!
echo !!! file vcredist_x86.installed     found         !!!
echo !!! MFC80 allready installed                      !!!
goto kmm

:vcredist_problem
echo !!!                                               !!!
echo !!! error: can not install MFC80                  !!!
echo !!! Administrator rights required for installation!!!
goto problem

:kmm
%nfspath%regsvr32.exe %nfspath%kmmsrv.dll /s
if errorlevel 1 goto kmm_problem
echo !!!                                               !!!
echo !!! KMM                             registered    !!!
goto richtx

:kmm_problem
echo !!!                                               !!!
echo !!! error: can not register KMMSRV.DLL            !!!
goto problem

:richtx
%nfspath%regsvr32.exe %nfspath%richtx32.ocx /s
if errorlevel 1 goto richtx_problem
echo !!!                                               !!!
echo !!! NFS                             registered    !!!
goto done

:richtx_problem
echo !!!                                               !!!
echo !!! error: can not register RICHTX32.OCX          !!!
goto problem

:done
echo !!!                                               !!!
echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
echo !!!                                               !!!
echo !!! NFS                             installed     !!!
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
echo !!! NFS                             not installed !!!
echo !!!                                               !!!
echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
pause
goto end

:end
