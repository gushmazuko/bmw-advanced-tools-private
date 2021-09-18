@echo off
rem   ****************************************************
rem   * TD-530.BAT                                       *
rem   ****************************************************
rem   * Batch Datei zum Kopieren s‰mtlicher Daten zu     *
rem   * einer Fahrgestellnummer. Daten werden in einem   *
rem   * Unterverzeichnis mit dem jeweiligen Datum        *
rem   * abgelegt.                                        *
rem   ****************************************************
rem   * Bedeutung der Parameter                          *
rem   * ------------------------------------------------ *
rem   * %1 : Projekt (Serie, KNG, ZARZ, ...)             *
rem   * %2 : Baureihe                                    *
rem   * %3 : Fahrgestellnumer                            *
rem   * %4 : Datum und Uhrzeit als 15 Zeichen langer Text*
rem   * %5 : Datumsoption als Parameter f¸r XCOPY        *
rem   **************************************************** 

:init
@cls
@title TD-53x INPA Skript - Fahrzeugdaten Sicherung      (c) 2005 GÅnter Straﬂer TD-531

echo %1
echo %2
echo %3
echo %4
echo %5
pause

set VERSION=V104

set PROJEKT=%1\
set BAUREIHE=%2\
set FGNR=%3\
set FGNRNAME=%3
set DATUM=%4\
set DATUMOPT=%5
set FAHRZEUG=C:\Fahrzeug.dat\
set ROOT=P:\TD53\Analyse\
set TRIGGER=TRIGGER.TXT
set FZGDOKU=_Fahrzeug_Dokumente_und_Unterlagen\
set V104_ROOT=\\NV02003\W02-DATEN\TD-5_GesamtFZG_QM\40_Analyseprojekte\
set V104_DATUM=%4\

if %COMPUTERNAME%==WW02139680 call "C:\Analyse Tools\CCOconvert\Zippen.bat" %3_%4

if %VERSION%==V100 goto startV100
if %VERSION%==V101 goto startV101
if %VERSION%==V102 goto startV102
if %VERSION%==V103 goto startV103
if %VERSION%==V104 goto startV104

:startV104
@echo ****************************************************
@echo *                                                  *
@echo * Fahrzeugdaten werden auf Server gesichert !      *
@echo *                                                  *
@echo * Copyright (c) GÅnter Strasser TD-531             *
@echo * (V1.04)                                          *
@echo ****************************************************

:partV104_00
@echo Parameter werden ÅberprÅft!
if not exist %V104_ROOT% goto error1
if %PROJEKT%==\ goto error2
if %BAUREIHE%==\ goto error2
if %FGNR%==\ goto error2
if %DATUM%==\ goto error2

:partV104_10
@echo.
@echo Verzeichnisse werden erstellt!
SET DIR=%V104_ROOT%%PROJEKT%
if exist "%DIR%" goto partV104_11
@echo - %DIR%
md "%DIR%"
 
:partV104_11
SET DIR=%V104_ROOT%%PROJEKT%%BAUREIHE%
if exist "%DIR%" goto partV104_12
@echo - %DIR%
md "%DIR%"

:partV104_12
SET DIR=%V104_ROOT%%PROJEKT%%BAUREIHE%%FGNR%
if exist "%DIR%" goto partV104_13
@echo - %DIR%
md "%DIR%"

:partV104_13
SET DIR=%V104_ROOT%%PROJEKT%%BAUREIHE%%FGNR%%FZGDOKU%
if exist "%DIR%" goto partV104_14
@echo - %DIR%
md "%DIR%"

:partV104_14
SET DIR=%V104_ROOT%%PROJEKT%%BAUREIHE%%FGNR%%V104_DATUM%
if exist "%DIR%" goto partV104_30
@echo - %DIR%
md "%DIR%"

:partV104_30
@echo.
@echo CANcorder Traces werden auf manuellen Trigger ueberprueft!
SET SOURCEDIR=%FAHRZEUG%

:partV104_31
find /I "Trigger key" "%SOURCEDIR%%FGNRNAME%C01.ASC"
if errorlevel 1 goto partV104_32
  copy %SOURCEDIR%C01_%TRIGGER% %SOURCEDIR%%FGNRNAME%C01_TRIGGER.TXT
  notepad.exe "%SOURCEDIR%%FGNRNAME%C01_TRIGGER.TXT"

:partV104_32
find /I "Trigger key" "%SOURCEDIR%%FGNRNAME%C02.ASC"
if errorlevel 1 goto partV104_33
  copy %SOURCEDIR%C02_%TRIGGER% %SOURCEDIR%%FGNRNAME%C02_TRIGGER.TXT"
  notepad.exe "%SOURCEDIR%%FGNRNAME%C02_TRIGGER.TXT"

:partV104_33
find /I "Trigger key" "%SOURCEDIR%%FGNRNAME%C03.ASC"
if errorlevel 1 goto partV104_34
  copy %SOURCEDIR%C03_%TRIGGER% %SOURCEDIR%%FGNRNAME%C03_TRIGGER.TXT"
  notepad.exe "%SOURCEDIR%%FGNRNAME%C03_TRIGGER.TXT"

:partV104_34
find /I "Trigger key" "%SOURCEDIR%%FGNRNAME%C04.ASC"
if errorlevel 1 goto partV104_35
  copy %SOURCEDIR%C04_%TRIGGER% %SOURCEDIR%%FGNRNAME%C04_TRIGGER.TXT"
  notepad.exe "%SOURCEDIR%%FGNRNAME%C04_TRIGGER.TXT"

:partV104_35
find /I "Trigger key" "%SOURCEDIR%%FGNRNAME%C05.ASC"
if errorlevel 1 goto partV104_40
  copy %SOURCEDIR%C05_%TRIGGER% %SOURCEDIR%%FGNRNAME%C05_TRIGGER.TXT"
  notepad.exe "%SOURCEDIR%%FGNRNAME%C05_TRIGGER.TXT"

:partV104_40
@echo.
@echo Fahrzeugdaten werden kopiert!
SET DESTDIR=%V104_ROOT%%PROJEKT%%BAUREIHE%%FGNR%%V104_DATUM%
SET SOURCEDIR=%FAHRZEUG%
xcopy "%SOURCEDIR%%FGNRNAME%*.*" "%DESTDIR%" /D /C /I /F /R

:partV104_50
@echo.
@echo Alte CANcorder Traces werden gelîscht!
SET SOURCEDIR=%FAHRZEUG%
del "%SOURCEDIR%%FGNRNAME%C*.*" /s
del "%SOURCEDIR%%FGNRNAME%_Trigger.txt" /s

:partV104_60
@echo.
@echo Alte ZIP Dateien werden gelîscht!
SET SOURCEDIR=%FAHRZEUG%
del "%SOURCEDIR%%FGNRNAME%*.ZIP" /s
goto ende


:startV103
@echo ****************************************************
@echo *                                                  *
@echo * Fahrzeugdaten werden auf Server gesichert !      *
@echo *                                                  *
@echo * Copyright (c) GÅnter Strasser TD-531             *
@echo * (V1.03)                                          *
@echo ****************************************************

:partV103_00
@echo.
@echo Checking parameters!
echo %PROJEKT%
echo %FGNR%
echo %DATUM%
if %PROJEKT%==\ goto error2
if %FGNR%==\ goto error2
if %DATUM%==\ goto error2

:partV103_10
@echo.
@echo Create directories!
SET DEST=%PROJEKT%

:partV103_11
SET DIR=%DEST%%FGNR%
if exist "%DIR%" goto partV103_12
@echo - %DIR%
md "%DIR%"

:partV103_12
SET DIR=%DEST%%FGNR%%DATUM%
if exist "%DIR%" goto partV103_20
@echo - %DIR%
md "%DIR%"

:partV103_20
@echo.
@echo Copying files!
SET DESTDIR=%DEST%%FGNR%%DATUM%
SET SOURCEDIR=%FAHRZEUG%
xcopy "%SOURCEDIR%%FGNRNAME%*.txt" "%DESTDIR%" /Y /D /C /I /F /R /S 

:partV103_Ende
goto ende1


:startV102
@echo ****************************************************
@echo *                                                  *
@echo * Fahrzeugdaten werden auf Server gesichert !      *
@echo *                                                  *
@echo * Copyright (c) GÅnter Strasser TD-531             *
@echo * (V1.02)                                          *
@echo ****************************************************

:partV102_00
@echo.
@echo Parameter werden ÅberprÅft!
if %PROJEKT%==\ goto error2
if %FGNR%==\ goto error2
if %DATUM%==\ goto error2

:partV102_10
@echo.
@echo Verzeichnisse werden erstellt!
SET DIR=%PROJEKT%
if exist "%DIR%" goto partV102_11
@echo - %DIR%
md "%DIR%"
 
:partV102_11
SET DIR=%PROJEKT%%FGNR%
if exist "%DIR%" goto partV102_12
@echo - %DIR%
md "%DIR%"

:partV102_12
SET DIR=%PROJEKT%%FGNR%%DATUM%
if exist "%DIR%" goto partV102_20
@echo - %DIR%
md "%DIR%"

:partV102_20
@echo.
@echo CANcorder Traces werden auf manuellen Trigger ÅberprÅft!
SET SOURCEDIR=%FAHRZEUG%

:partV102_21
find /I "Trigger key" "%SOURCEDIR%%FGNRNAME%C01.ASC"
if errorlevel 1 goto partV102_22
  copy %SOURCEDIR%C01_%TRIGGER% %SOURCEDIR%%FGNRNAME%C01_TRIGGER.TXT
  notepad.exe "%SOURCEDIR%%FGNRNAME%C01_TRIGGER.TXT"

:partV102_22
find /I "Trigger key" "%SOURCEDIR%%FGNRNAME%C02.ASC"
if errorlevel 1 goto partV102_23
  copy %SOURCEDIR%C02_%TRIGGER% %SOURCEDIR%%FGNRNAME%C02_TRIGGER.TXT"
  notepad.exe "%SOURCEDIR%%FGNRNAME%C02_TRIGGER.TXT"

:partV102_23
find /I "Trigger key" "%SOURCEDIR%%FGNRNAME%C02.ASC"
if errorlevel 1 goto partV102_24
  copy %SOURCEDIR%C02_%TRIGGER% %SOURCEDIR%%FGNRNAME%C02_TRIGGER.TXT"
  notepad.exe "%SOURCEDIR%%FGNRNAME%C02_TRIGGER.TXT"

:partV102_24
find /I "Trigger key" "%SOURCEDIR%%FGNRNAME%C02.ASC"
if errorlevel 1 goto partV102_25
  copy %SOURCEDIR%C02_%TRIGGER% %SOURCEDIR%%FGNRNAME%C02_TRIGGER.TXT"
  notepad.exe "%SOURCEDIR%%FGNRNAME%C02_TRIGGER.TXT"

:partV102_25
find /I "Trigger key" "%SOURCEDIR%%FGNRNAME%C02.ASC"
if errorlevel 1 goto partV102_30
  copy %SOURCEDIR%C02_%TRIGGER% %SOURCEDIR%%FGNRNAME%C02_TRIGGER.TXT"
  notepad.exe "%SOURCEDIR%%FGNRNAME%C02_TRIGGER.TXT"

:partV102_30
@echo.
@echo Fahrzeugdaten werden kopiert!
SET DESTDIR=%PROJEKT%%FGNR%%DATUM%
SET SOURCEDIR=%FAHRZEUG%
xcopy "%SOURCEDIR%%FGNRNAME%*.*" "%DESTDIR%" /D /C /I /F /R /S

:partV102_40
@echo.
@echo Alte CANcorder Traces werden gelîscht!
SET SOURCEDIR=%FAHRZEUG%
del "%SOURCEDIR%%FGNRNAME%C*.*" /s
del "%SOURCEDIR%%FGNRNAME%_Trigger.txt" /s

:partV102_50
@echo.
@echo Alte RPA Daten werden gelîscht!
SET SOURCEDIR=%FAHRZEUG%
del "%SOURCEDIR%%FGNRNAME%_RPA.*" /s

:partV102_Ende
goto ende


:startV101
@echo ****************************************************
@echo *                                                  *
@echo * Fahrzeugdaten werden auf Server gesichert !      *
@echo *                                                  *
@echo * Copyright (c) GÅnter Strasser TD-531             *
@echo * (V1.01)                                          *
@echo ****************************************************

:part0
if not exist %ROOT% goto error1
if %PROJEKT%==\ goto error2
if %BAUREIHE%==\ goto error2
if %FGNR%==\ goto error2
if %DATUM%==\ goto error2

:part1
@echo.
@echo Verzeichnisse werden erstellt!
SET DIR=%ROOT%
if exist "%DIR%" goto part11
@echo - %DIR%
md "%DIR%"
 
:part11
SET DIR=%ROOT%%PROJEKT%
if exist "%DIR%" goto part12
@echo - %DIR%
md "%DIR%"

:part12
SET DIR=%ROOT%%PROJEKT%%ARCHIV%
if exist "%DIR%" goto part13
@echo - %DIR%
md "%DIR%"

:part13
SET DIR=%ROOT%%PROJEKT%%EINSTEUERUNG%
if exist "%DIR%" goto part14
@echo - %DIR%
md "%DIR%"


:part14
SET DIR=%ROOT%%PROJEKT%%AKTUELL%
if exist "%DIR%" goto part15
@echo - %DIR%
md "%DIR%"

:part15
SET DIR=%ROOT%%PROJEKT%%AKTUELL%%BAUREIHE%
if exist "%DIR%" goto part16
@echo - %DIR%
md "%DIR%"

:part16
SET DIR=%ROOT%%PROJEKT%%AKTUELL%%BAUREIHE%%FGNR%
if exist "%DIR%" goto part17
@echo - %DIR%
md "%DIR%"

:part17
SET DIR=%ROOT%%PROJEKT%%AKTUELL%%BAUREIHE%%FGNR%%FEHLER%
if exist "%DIR%" goto part18
@echo - %DIR%
md "%DIR%"

:part18
SET DIR=%ROOT%%PROJEKT%%AKTUELL%%BAUREIHE%%FGNR%%DATEN%
if exist "%DIR%" goto part19
@echo - %DIR%
md "%DIR%"

:part19
SET DIR=%ROOT%%PROJEKT%%AKTUELL%%BAUREIHE%%FGNR%%DATEN%%DATUM%
if exist "%DIR%" goto part2
@echo - %DIR%
md "%DIR%"

:part2
@echo.
@echo Vorlagen werden kopiert!
SET SOURCEDIR=%ROOT%%PROJEKT%%VORLAGEN%
SET DESTDIR=%ROOT%%PROJEKT%%AKTUELL%%BAUREIHE%%FGNR%
xcopy "%SOURCEDIR%*.*" "%DESTDIR%" /D /C /I /F /R 

:part3
@echo.
@echo CANcorder Traces werden auf manuellen Trigger ueberprueft!
SET SOURCEDIR=%FAHRZEUG%

:part31
find /I "Trigger key" "%SOURCEDIR%%FGNRNAME%C01.ASC"
if errorlevel 1 goto part32
  copy %SOURCEDIR%C01_%TRIGGER% %SOURCEDIR%%FGNRNAME%C01_TRIGGER.TXT
  notepad.exe "%SOURCEDIR%%FGNRNAME%C01_TRIGGER.TXT"

:part32
find /I "Trigger key" "%SOURCEDIR%%FGNRNAME%C02.ASC"
if errorlevel 1 goto part33
  copy %SOURCEDIR%C02_%TRIGGER% %SOURCEDIR%%FGNRNAME%C02_TRIGGER.TXT"
  notepad.exe "%SOURCEDIR%%FGNRNAME%C02_TRIGGER.TXT"

:part33
find /I "Trigger key" "%SOURCEDIR%%FGNRNAME%C03.ASC"
if errorlevel 1 goto part34
  copy %SOURCEDIR%C03_%TRIGGER% %SOURCEDIR%%FGNRNAME%C03_TRIGGER.TXT"
  notepad.exe "%SOURCEDIR%%FGNRNAME%C03_TRIGGER.TXT"

:part34
find /I "Trigger key" "%SOURCEDIR%%FGNRNAME%C04.ASC"
if errorlevel 1 goto part35
  copy %SOURCEDIR%C04_%TRIGGER% %SOURCEDIR%%FGNRNAME%C04_TRIGGER.TXT"
  notepad.exe "%SOURCEDIR%%FGNRNAME%C04_TRIGGER.TXT"

:part35
find /I "Trigger key" "%SOURCEDIR%%FGNRNAME%C05.ASC"
if errorlevel 1 goto part4
  copy %SOURCEDIR%C05_%TRIGGER% %SOURCEDIR%%FGNRNAME%C05_TRIGGER.TXT"
  notepad.exe "%SOURCEDIR%%FGNRNAME%C05_TRIGGER.TXT"

:part4
@echo.
@echo Fahrzeugdaten werden kopiert!
SET DESTDIR=%ROOT%%PROJEKT%%AKTUELL%%BAUREIHE%%FGNR%%DATEN%%DATUM%
SET SOURCEDIR=C:\
xcopy "%SOURCEDIR%%FGNRNAME%*.*" "%DESTDIR%" /D /C /I /F /R
SET SOURCEDIR=%FAHRZEUG%
xcopy "%SOURCEDIR%%FGNRNAME%*.*" "%DESTDIR%" /D /C /I /F /R

:part5
@echo.
@echo Alte CANcorder Traces werden gelîscht!
SET SOURCEDIR=%FAHRZEUG%
del "%SOURCEDIR%%FGNRNAME%C*.*" /s
del "%SOURCEDIR%%FGNRNAME%_Trigger.txt" /s

:part6
@echo.
@echo Alte RPA Daten werden gelîscht!
SET SOURCEDIR=%FAHRZEUG%
del "%SOURCEDIR%%FGNRNAME%_RPA.*" /s
goto ende

:error1
@echo
@echo ****************************************************
@echo *                                                  *
@echo * Fehler !                                         *
@echo *                                                  *
@echo * Auf das Verzeichnis %ROOT%             *
@echo * kann nicht zugegriffen werden!                   *
@echo *                                                  *
@echo * Bitte das Laufwerk verbinden und Sicherung       *
@echo * nochmals durchfuehren                            *
@echo *                                                  *
@echo * GÅnter Strasser - Tel.08731 / 76 - 29182         *
@echo ****************************************************
pause
goto ende1

:error2
@echo.
@echo ****************************************************
@echo *                                                  *
@echo * Fehler !                                         *
@echo *                                                  *
@echo * Die Åbergebenen Parameter sind falsch !          *
@echo *                                                  *
@echo * GÅnter Strasser - Tel.08731 / 76 - 29182         *
@echo ****************************************************
goto ende1

:startV100
@echo ****************************************************
@echo *                                                  *
@echo * Fahrzeugdaten werden auf Server gesichert !      *
@echo *                                                  *
@echo * Copyright (c) GÅnter Strasser TD-531             *
@echo * (V1.00)                                          *
@echo ****************************************************
if %PROJEKT%==SERIE\   set DESTDIR=P:\TD53\E65_KUNDENFAHRZEUGE\ZARZ-FAHRZEUGE\SERIENFAHRZEUGE\
if %PROJEKT%==ZARZ\    set DESTDIR=P:\TD53\E65_KUNDENFAHRZEUGE\ZARZ-FAHRZEUGE\KUNDENFAHRZEUGE\
if %PROJEKT%==ERSATZ\  set DESTDIR=P:\TD53\E65_KUNDENFAHRZEUGE\ZARZ-FAHRZEUGE\KUNDENERSATZFAHRZEUGE\
if %PROJEKT%==KNG_E60\ set DESTDIR=P:\TD53\KNG\KNG-FAHRZEUGE\
if %PROJEKT%==KNG_CCC\ set DESTDIR=P:\TD53\KNG\KNG-FAHRZEUGE\
if %PROJEKT%==KNG_E63\ set DESTDIR=P:\TD53\KNG\KNG-FAHRZEUGE\
set DESTDIR=%DESTDIR%%FGNR%%DATUM%
set SOURCEDIR=%FAHRZEUG%
xcopy "%SOURCEDIR%%FGNRNAME%*.*" "%DESTDIR%" /D /C /I /F /R /Y
goto ende

:ende
@echo.
@echo ****************************************************
@echo *                                                  *
@echo * Achtung!!!                                       *
@echo *                                                  *
@echo * Saemtliche Fahrzeug Daten werden seit 04.08.2003 *
@echo * in folgendem neuen Verzeichnis abgelegt:         *
@echo *                                                  *
@echo * P:\TD53\Analyse                                  *
@echo *                                                  *
@echo * Die Namen der dort darin enthaltenen Unterver-   *
@echo * zeichnisse sind selbsterklaerend. Bitte in Zu-   *
@echo * kunft saemtliche Daten zu einem Fahrzeug dort    *
@echo * abspeichern                                      *
@echo *                                                  *
@echo * Copyright (c) Guenter Strasser TD-531            *
@echo *                                                  *
@echo ****************************************************

:ende1
@echo.
@echo --- ENDE ---
@echo.
pause