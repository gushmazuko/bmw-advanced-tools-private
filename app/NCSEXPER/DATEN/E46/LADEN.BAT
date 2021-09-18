@set _BR_COD=E46
@echo off
REM ******************************************************************************************
REM *                                                                                        *
REM *  LADEN.BAT                                                                             *
REM *                                                                                        *
REM *----------------------------------------------------------------------------------------*
REM *  Lauffähige Betriebssysteme : WIN NT40, WIN95, XP                                      *
REM *----------------------------------------------------------------------------------------*
REM *                                                                                        *
REM *  Kopierfile zur Datenübertragung von Baureihen-Files und CBD-Files aus dem aktuellen   *
REM *  Verzeichnis heraus nach C:\CABI\DATEN oder D:\CABI\DATEN .                            *
REM *  Die Erkennung des Ziellaufwerkes erfolgt automatisch. Wird das CABI - System auf LW C *
REM *  erkannt, werden alle Files nach C kopiert, ansonsten nach LW D .                      *
REM *                                                                                        *
REM *  Die Baureihenbezeichnung (z.B. E38) ist variabel und kann beim Batch - Aufruf als     *
REM *  Argument übergeben werden. Die Baureihenbezeichnung wird automatisch in die Namens-   *
REM *  kennung der entsprechnden Files eingefügt, so daß nur die spezifischen Files der aus- *
REM *  gewählten Baureihe kopiert werden.                                                    *
REM *                                                                                        *
REM *  Wenn bei Aufruf dieses Files kein Argument übergeben wird, erfolgt die Auswahl der    *
REM *  Baureihe durch Setzen der der Systemvariable _BR_COD in der ersten Zeile des Files.   *
REM *  Wird hier eine gültige Baureihenbezeichnung zugewiesen, erfolgt das Einfügen der BR   *
REM *  in die Filenamen auch ohne BR-Argumentübergabe beim Aufruf. Weicht der Eintrag von    *
REM *  einer gültigen BR-Bezeichnung ab, wird (bei Aufruf ohne Argument) abgebrochen.        *
REM *                                                                                        *
REM *  Zusätzlich kann (nur) in der Eingabezeile das Argument HO übergeben werden. Wird es   *
REM *  erkannt, erfolgt die Umschaltung des Zielpfades auf das Verzeichnis:                  *
REM *                             P:\CODIERUN\codierda.ten\Versionen-HO\arbeitsstand\kompr   *
REM *  Weiterhin werden dabei die relevanten Ascii Dateien aus dem Quellverzeichnis :        *
REM *                             P:\CODIERUN\codierda.ten\ASCII\Exx   (Exx = Baureihe)      *
REM *                       nach  P:\CODIERUN\codierda.ten\Versionen-HO\arbeitsstand\ascii   *
REM *  kopiert.                                                                              *
REM *                                                                                        *
REM *  Eingabereihenfolge :   LADEN <Exx> <HO>     oder                                      *
REM *                         LADEN <HO>           oder                                      *
REM *                         LADEN                                                          *
REM *                                                                                        *
REM *----------------------------------------------------------------------------------------*
REM *                                                                                        *
REM *  BMW AG, EI - 73,    Haller     V 1.28   Stand: 11.03.2008                             *
REM *                                                                                        *
REM *----------------------------------------------------------------------------------------*
REM *  History                                                                               *
REM *                                                                                        *
REM *  V 1.0  24.01.2000   Erstellung, P. Hahn                                               *
REM *  V 1.1  24.01.2000   HO - Kopierfunktion durch zus. Argument eingearbeitet, P. Hahn    *
REM *  V 1.2  26.01.2000   Anpassung auf System WIN95 (geänderter DIR-Test), P. Hahn         *
REM *  V 1.3  27.01.2000   Quellpfad für ASCII Daten ´P:\CODIERUN\codierda.ten\ASCII\Exx´    *
REM *                      eingefügt, Funktionalität z. Kopieren der ASCII Daten real., Hahn *
REM *  V 1.4  17.11.2000   Verzeichnis in LW D:\auf NCSEXPER geändert, Bernhard Haller       *
REM *  V 1.5  19.01.2001   Kopieren der SWT*.TXT auf den HO-Arbeitsstand\ASCII ergänzt       *
REM *  V 1.6  24.01.2001   Baureihe R50 hinzu, zweisprachige Textausgaben (Wo)               *
REM *  V 1.7  21.02.2001   Baureihe E60 hinzu, P. Hahn                                       *
REM *  V 1.8  17.05.2001   Baureihe E85 hinzu, I. Rochal                                     *
REM *  V 1.9  08.11.2001   Kopieren der Daten auf alle angelegten Pfade, B. Haller           *
REM *                      BAUREIHE rr1 geränzt                                              *
REM *  V 1.10 15.02.2002   Baureihe E83 hinzu                                                *
REM *  V 1.11 18.02.2002   Baureihe E89 (PL2) hinzu                                          *
REM *  V 1.12 19.02.2002   Codierdatenverzeichnis carserver\daten hinzu                      *
REM *  V 1.13 21.03.2002   Baureihe E81 hinzu                                                *
REM *  V 1.14 27.05.2002   Baureihe E33 (Sachnummerncodierung) hinzu                         *
REM *  V 1.15 18.11.2002   Baureihe K24 (Motorrad) hinzu                                     *
REM *  V 1.16 04.02.2003   Auf BR-spezifische Ablage der Codierdaten im Zielsystem erweitert *
REM *  V 1.17 17.02.2003   AT/ZST-Tabelle auch nach *\DATEN                                  *
REM *  V 1.18 20.02.2003   AEDOC-Tabelle auch nach *\DATEN wegen ZEKO                        *
REM *  V 1.19 24.02.2003   Fehlerkorrektur bei HO-Paket erstellen                            *
REM *  V 1.20 06.03.2003   Verzeichnis für Carserver u. NCSExpert auf C:\EC-Apps erweitert   *
REM *  V 1.21 04.06.2003   Kopieren für HO auf BR-spezifische Unterverzeichnisse erweitert   *
REM *  V 1.22 24.11.2003   SELECT.* und VARIABLE.* wird auch nach \DATEN kopiert             *
REM *                      derzeit nur im Verifikationsmode im NCS-Expertentool genutzt      *
REM *  V 1.23 02.11.2004   Auf neue Verzeichnisstruktur auf \\gmuc0105 angepaßt              *
REM *  V 1.24 08.11.2004   Baureihe R56 ergänzt                                              *
REM *  V 1.25 21.02.2006   Baureihe E70 ergänzt, Baureihe E81 gelöscht                       *
REM *                      Pfad für Carserver "C:\EC-Apps\carserver\CarServer-Farm\daten"    *
REM *                      für das Kopieren der Codierdaten ergänzt                          *
REM *  V 1.26 05.04.2006   F01 hinzu                                                         *
REM *  V 1.27 30.01.2008   An neue Verzeichnisstruktur Carserver, CS14, angepasst            *
REM *  V 1.28 11.03.2008   Kopiert auch alle AT.M00 und AT.ZUS ins Zielverzeichnis           *
REM *                                                                                        *
REM *                                                                                        *
REM *                                                                                        *
REM ******************************************************************************************
REM
REM ******************************************************************************************
REM *                                                                                        *
REM * BESCHREIBUNG DES KOPIERBEFEHLS    - XCOPY -                                            *
REM *                                                                                        *
REM * Kopiert Dateien und Verzeichnisstrukturen.                                             *
REM *                                                                                        *
REM * XCOPY Quelle [Ziel] [/A | /M] [/D[:Datum]] [/P] [/S [/E]] [/V] [/W]                    *
REM *                     [/C] [/I] [/Q] [/F] [/L] [/H] [/R] [/T] [/U]                       *
REM *                     [/K] [/N] [/Z]                                                     *
REM *                                                                                        *
REM *   Quelle    Zu kopierende Dateien                                                      *
REM *   Ziel      Position und/oder Name der neuen Dateien                                   *
REM *   /A        Kopiert Dateien mit gesetztem Archivattribut,                              *
REM *             aendert das Attribut nicht                                                 *
REM *   /M        Kopiert Dateien mit gesetztem Archivattribut,                              *
REM *             setzt das Attribut nach dem Kopieren zurueck                               *
REM *   /D:M-T-J  Kopiert nur die an oder nach dem Datum geaenderten Dateien.                *
REM *             Ist kein Datum angegeben, werden nur Dateien kopiert,                      *
REM *             die neuer als die bestehenden Zieldateien sind                             *
REM *   /P        Fordert vor dem Erstellen jeder Zieldatei eine Bestaetigung                *
REM *   /S        Kopiert Verzeichnisse und Unterverzeichnisse, die nicht leer sind          *
REM *   /E        Kopiert alle Unterverzeichnisse (leer oder nicht leer).                    *
REM *             Mit dieser Option kann die Option /T modifiziert werden                    *
REM *   /V        ueberprueft jede neue Datei auf Korrektheit                                *
REM *   /W        Fordert vor dem Beginn des Kopierens zu einem Tastendruck auf              *
REM *   /C        Setzt das Kopieren fort, auch wenn Fehler auftreten                        *
REM *   /I        Falls Ziel nicht existiert und mehr als eine Datei kopiert werden,         *
REM *             nimmt XCOPY an, dass Ziel ein Verzeichnis ist                              *
REM *   /Q        Zeigt beim Kopieren keine Dateinamen an                                    *
REM *   /F        Zeigt die Namen der Quell- und Zieldateien beim Kopieren an                *
REM *   /L        Listet die Dateien auf, die kopiert wuerden                                *
REM *   /H        Kopiert auch Dateien mit den Attributen 'Versteckt' und 'System'           *
REM *   /R        Kopiert üeber schreibgeschuetzte Dateien                                   *
REM *   /T        Kopiert nur Unterverzeichnisstruktur, keine Dateien. Leere                 *
REM *             Verzeichnisse werden nicht kopiert. Um auch leere Verzeichnisse zu         *
REM *             kopieren, muessen Sie die Optionen /T /E angeben                           *
REM *   /U        Kopiert nur Dateien, die bereits im Zielverzeichnis vorhanden sind.        *
REM *   /K        Kopiert Attribute. Standardmaessig wird 'Schreibgeschuetzt' geloescht      *
REM *   /N        Beim Kopieren werden die erzeugten Kurznamen verwendet.                    *
REM *   /Z        Kopiert Dateien in einem Modus, der einen Neustart ermoeglicht.            *
REM *                                                                                        *
REM ******************************************************************************************
REM
REM In erter Zeile immer nur eine Baureihe eintragen ( E36 oder E46 oder E38 ... )
CLS

if x%1==xHO goto BR_TEST
if x%1==xho goto BR_TEST
if not x%1==x set _BR_COD=%1
:BR_TEST
REM ------------------ Syntaxüberprüfung der Baureihenkennung -----------------
if x%_BR_COD%==xE31 goto BR_OK
if x%_BR_COD%==xe31 goto BR_OK
if x%_BR_COD%==xE32 goto BR_OK
if x%_BR_COD%==xe32 goto BR_OK
if x%_BR_COD%==xE33 goto BR_OK
if x%_BR_COD%==xe33 goto BR_OK
if x%_BR_COD%==xE34 goto BR_OK
if x%_BR_COD%==xe34 goto BR_OK
if x%_BR_COD%==xE36 goto BR_OK
if x%_BR_COD%==xe36 goto BR_OK
if x%_BR_COD%==xE38 goto BR_OK
if x%_BR_COD%==xe38 goto BR_OK
if x%_BR_COD%==xE39 goto BR_OK
if x%_BR_COD%==xe39 goto BR_OK
if x%_BR_COD%==xE46 goto BR_OK
if x%_BR_COD%==xe46 goto BR_OK
if x%_BR_COD%==xE52 goto BR_OK
if x%_BR_COD%==xe52 goto BR_OK
if x%_BR_COD%==xE53 goto BR_OK
if x%_BR_COD%==xe53 goto BR_OK
if x%_BR_COD%==xE60 goto BR_OK
if x%_BR_COD%==xe60 goto BR_OK
if x%_BR_COD%==xE65 goto BR_OK
if x%_BR_COD%==xe65 goto BR_OK
if x%_BR_COD%==xE70 goto BR_OK
if x%_BR_COD%==xe70 goto BR_OK
if x%_BR_COD%==xE83 goto BR_OK
if x%_BR_COD%==xe83 goto BR_OK
if x%_BR_COD%==xE85 goto BR_OK
if x%_BR_COD%==xe85 goto BR_OK
if x%_BR_COD%==xE89 goto BR_OK
if x%_BR_COD%==xe89 goto BR_OK
if x%_BR_COD%==xK24 goto BR_OK
if x%_BR_COD%==xk24 goto BR_OK
if x%_BR_COD%==xRR1 goto BR_OK
if x%_BR_COD%==xrr1 goto BR_OK
if x%_BR_COD%==xR50 goto BR_OK
if x%_BR_COD%==xr50 goto BR_OK
if x%_BR_COD%==xR56 goto BR_OK
if x%_BR_COD%==xr56 goto BR_OK
if x%_BR_COD%==xF01 goto BR_OK
if x%_BR_COD%==xf01 goto BR_OK
goto ERR1_BREAK
REM ---------------------------------------------------------------------------

:BR_OK
set kopieren=niO
if x%1==xHO goto HO_COD1
if x%1==xho goto HO_COD1
if x%2==xHO goto HO_COD1
if x%2==xho goto HO_COD1

REM Pfad ´C:\CABI\BIN\... ´ prüfen
set _LW_COD=C
set _DPA_COD=:\CABI
set _UDPA_COD=\BIN
echo %_LW_COD%%_DPA_COD%%_UDPA_COD%
ver > %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
if not exist %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP goto C2_LW_TEST
del %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
set _SPRUNG=C2_LW_TEST
goto DIR_DAT_TEST

:C2_LW_TEST
REM Pfad ´C:\NCSEXPER\BIN\... ´ prüfen
set _LW_COD=C
set _DPA_COD=:\NCSEXPER
set _UDPA_COD=\BIN
echo %_LW_COD%%_DPA_COD%%_UDPA_COD%
ver > %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
if not exist %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP goto C3_LW_TEST
del %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
set _SPRUNG=C3_LW_TEST
goto DIR_DAT_TEST

:C3_LW_TEST
REM Pfad ´C:\CARSERVER\BIN\... ´ prüfen
set _LW_COD=C
set _DPA_COD=:\CARSERVER
set _UDPA_COD=\DATEN
echo %_LW_COD%%_DPA_COD%%_UDPA_COD%
ver > %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
if not exist %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP goto C4_LW_TEST
del %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
set _SPRUNG=C4_LW_TEST
goto DIR_DAT_TEST

:C4_LW_TEST
REM Pfad ´C:\EC-Apps\NCSEXPER\BIN\... ´ prüfen
set _LW_COD=C
set _DPA_COD=:\EC-Apps\NCSEXPER
set _UDPA_COD=\BIN
echo %_LW_COD%%_DPA_COD%%_UDPA_COD%
ver > %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
if not exist %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP goto C5_LW_TEST
del %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
set _SPRUNG=C5_LW_TEST
goto DIR_DAT_TEST

:C5_LW_TEST
REM Pfad ´C:\EC-Apps\CARSERVER\BIN\... ´ prüfen
set _LW_COD=C
set _DPA_COD=:\EC-Apps\CARSERVER
set _UDPA_COD=\DATEN
echo %_LW_COD%%_DPA_COD%%_UDPA_COD%
ver > %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
if not exist %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP goto C6_LW_TEST
del %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
set _SPRUNG=C6_LW_TEST
goto DIR_DAT_TEST

:C6_LW_TEST
REM Pfad ´C:\EC-Apps\CARSERVER\CarServer-Farm\Daten\... ´ prüfen
set _LW_COD=C
set _DPA_COD=:\EC-Apps\CARSERVER\CarServer-Farm
set _UDPA_COD=\Daten
echo %_LW_COD%%_DPA_COD%%_UDPA_COD%
ver > %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
if not exist %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP goto D1_LW_TEST
del %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
set _SPRUNG=D1_LW_TEST
goto DIR_DAT_TEST

:D1_LW_TEST
REM Pfad ´D:\NCSEXPER\BIN\... ´ prüfen
echo.
set _LW_COD=D
set _DPA_COD=:\NCSEXPER
set _UDPA_COD=\BIN
echo %_LW_COD%%_DPA_COD%%_UDPA_COD%
ver > %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
if not exist %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP goto D2_LW_TEST
del %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
set _SPRUNG=D2_LW_TEST
goto DIR_DAT_TEST

:D2_LW_TEST
REM Pfad ´D:\CABI\BIN\... ´ prüfen
echo.
set _LW_COD=D
set _DPA_COD=:\CABI
set _UDPA_COD=\BIN
echo %_LW_COD%%_DPA_COD%%_UDPA_COD%
ver > %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
if not exist %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP goto ERR2_BREAK
del %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
set _SPRUNG=COPY_OK
goto DIR_DAT_TEST

:HO_COD1
REM Pfad ´...\Arbeitsstand\kompr\... ´ für HO-CD prüfen
set _LW_COD=P
set _DPA_COD=:\SW_Logistik\Produktdaten\05-Freigabe\Cod_HO_CD\arbeitsstand
set _UDPA_COD=\kompr
ver > %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
if not exist %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP goto ERR3_BREAK
del %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
ver > %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%\$$DIRTST.TMP
if exist %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%\$$DIRTST.TMP goto weiter2
md %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%
ver > %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%\$$DIRTST.TMP
:weiter2
del %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%\$$DIRTST.TMP
echo Kopieren (Abbruch mit [Ctrl] [C]) vom aktuellen Verzeichnis nach :
echo %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%
pause
set _SPRUNG=HO_COD2
goto COPY_COD_HO

:HO_COD2
echo.
REM Pfad ´...\Arbeitsstand\ascii\... ´ für HO-CD prüfen
set _DPA_COD=:\SW_Logistik\Produktdaten\05-Freigabe\Cod_HO_CD\arbeitsstand
set _UDPA_COD=\ascii
REM Source - Pfad der ASCII Daten für HO-CD prüfen
set _SPA_COD=:\SW_Logistik\Produktdaten\05-Freigabe\Cod_ASCII\%_BR_COD%\
ver > %_LW_COD%%_SPA_COD%$$DIRTST.TMP
if not exist %_LW_COD%%_SPA_COD%$$DIRTST.TMP goto ERR4_BREAK
del %_LW_COD%%_SPA_COD%$$DIRTST.TMP
ver > %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%\$$DIRTST.TMP
if exist %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%\$$DIRTST.TMP goto weiter3
md %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%
ver > %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%\$$DIRTST.TMP
:weiter3
del %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%\$$DIRTST.TMP
echo Kopieren (Abbruch mit [Ctrl] [C]) vom Quell - Verzeichnis :
echo %_LW_COD%%_SPA_COD%...
echo zum Zielverzeichnis :
echo %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_CD%
pause
set _SPA_COD=%_LW_COD%%_SPA_COD%
set _SPRUNG=COPY_OK_HO
goto COPY_COD_HO

:DIR_DAT_TEST
REM Pfad ´..DATEN\... ´ prüfen
set _UDPA_COD=\DATEN

:COPY_COD
ver > %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
if not exist %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP goto ERR3_BREAK
ver > %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%\$$DIRTST.TMP
if exist %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%\$$DIRTST.TMP goto weiter1
md %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%
ver > %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%\$$DIRTST.TMP
ver > %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%\$$NEUDIR.TMP

:weiter1
echo Codierdaten %_BR_COD% kopieren nach %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%\...
echo Copying Codingdata %_BR_COD% to %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%\...
del %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
del %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%\$$DIRTST.TMP

echo.
REM ---------------------------------------------------------------------------
REM -------------------- Hier Copierfunktionen eintragen ----------------------

REM     QuelPath  Quellfiles           Zielverzeichnis                                Argumente von XCOPY

XCOPY   %_SPA_COD%%_BR_COD%*.*         %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%       /C /I /F /R
XCOPY   %_SPA_COD%*.M00                %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%       /D /C /I /F /R
XCOPY   %_SPA_COD%*.ZUS                %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%       /D /C /I /F /R
XCOPY   %_SPA_COD%*.ASC                %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%       /D /C /I /F /R
XCOPY   %_SPA_COD%*.DAT                %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%       /D /C /I /F /R
XCOPY   %_SPA_COD%*.C*                 %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%       /D /C /I /F /R
XCOPY   %_SPA_COD%BR_REF.DAT           %_LW_COD%%_DPA_COD%%_UDPA_COD%                 /D /C /I /F /R
XCOPY   %_SPA_COD%%_BR_COD%AEDOC.000   %_LW_COD%%_DPA_COD%%_UDPA_COD%                 /D /C /I /F /R
XCOPY   %_SPA_COD%SELECT.*             %_LW_COD%%_DPA_COD%%_UDPA_COD%                 /D /C /I /F /R
XCOPY   %_SPA_COD%VARIABLE.*           %_LW_COD%%_DPA_COD%%_UDPA_COD%                 /D /C /I /F /R

if exist %_SPA_COD%*.txt               XCOPY   %_SPA_COD%*.txt               %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%   /D /C /I /F /R
if exist %_SPA_COD%%_BR_COD%AT.000     XCOPY   %_SPA_COD%%_BR_COD%AT.000     %_LW_COD%%_DPA_COD%%_UDPA_COD%             /D /C /I /F /R
if exist %_SPA_COD%%_BR_COD%ZST.000    XCOPY   %_SPA_COD%%_BR_COD%ZST.000    %_LW_COD%%_DPA_COD%%_UDPA_COD%             /D /C /I /F /R

if exist %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%CVT.000       ren %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%CVT.000      %_BR_COD%CVT.ALT
if exist %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%SGET.000      ren %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%SGET.000     %_BR_COD%SGET.ALT
if exist %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%SGVT.000      ren %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%SGVT.000     %_BR_COD%SGVT.ALT
if exist %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%DST.000       ren %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%DST.000      %_BR_COD%DST.ALT
if exist %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%*.dat         ren %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%*.dat        %_BR_COD%*.DLT
if exist %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%*.bap         ren %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%*.bap        %_BR_COD%*.BLT
REM ------------------------ Ende Codierfunktionen ----------------------------
REM ---------------------------------------------------------------------------
set _LW_NEU=%_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%
set _LW_PFAD_NEU=%_LW_COD%%_DPA_COD%
set kopieren=iO
goto %_SPRUNG%


:COPY_COD_HO
ver > %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
if not exist %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP goto ERR3_BREAK
echo Codierdaten %_BR_COD% kopieren nach %_LW_COD%%_DPA_COD%%_UDPA_COD%\...
echo Copying Codingdata %_BR_COD% to %_LW_COD%%_DPA_COD%%_UDPA_COD%\...
del %_LW_COD%%_DPA_COD%%_UDPA_COD%\$$DIRTST.TMP
echo.
REM ---------------------------------------------------------------------------
REM -------------------- Hier Copierfunktionen HO eintragen ----------------------

REM     QuelPat   Quellfiles     Zielverzeichnis                      Argumente von XCOPY

XCOPY   %_SPA_COD%%_BR_COD%*.*         %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%          /C /I /F /R
XCOPY   %_SPA_COD%*.ASC                %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%       /D /C /I /F /R
XCOPY   %_SPA_COD%*.DAT                %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%       /D /C /I /F /R
XCOPY   %_SPA_COD%*.C*                 %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%       /D /C /I /F /R

XCOPY   %_SPA_COD%BR_REF.DAT           %_LW_COD%%_DPA_COD%%_UDPA_COD%                 /D /C /I /F /R
XCOPY   %_SPA_COD%%_BR_COD%AEDOC.000   %_LW_COD%%_DPA_COD%%_UDPA_COD%                 /D /C /I /F /R

if exist %_SPA_COD%*.txt XCOPY   %_SPA_COD%*.txt           %_LW_COD%%_DPA_COD%%_UDPA_COD%\%_BR_COD%       /D /C /I /F /R

REM ------------------------ Ende Codierfunktionen ----------------------------
REM ---------------------------------------------------------------------------
goto %_SPRUNG%


:ERR1_BREAK
echo Keine oder falsche Baureihe eingetragen/uebergeben *** Abbruch *** !
echo Unknown series! *** Operation cancelled *** !
pause
goto END

:ERR2_BREAK
if x%kopieren%==xiO goto END
echo Kein Zugriff auf Verzeichnis ..%_DPA_COD%%_UDPA_COD%\... *** Abbruch *** !
echo Access denied on ..%_DPA_COD%%_UDPA_COD%\... *** Operation cancelled *** !
goto COPY_OK

:ERR3_BREAK
echo Kein Zugriff auf Verzeichnis %_LW_COD%%_DPA_COD%%_UDPA_COD% *** Abbruch *** !
echo Access denied on %_LW_COD%%_DPA_COD%%_UDPA_COD% *** Operation cancelled *** !
pause
goto END

:ERR4_BREAK
set _DPA_COD=%_SPA_COD%
goto ERR3_BREAK


:COPY_OK
if exist %_LW_NEU%\$$NEUDIR.TMP goto NEUDIR
echo Kopiervorgang beendet.
echo Copying complete.
goto END

:COPY_OK_HO
echo Kopiervorgang beendet.
echo Copying complete.
goto END

:NEUDIR
del %_LW_NEU%\$$NEUDIR.TMP
cls
echo.
echo.
echo ACHTUNG / ATTENTION
echo.
echo Baureihenspezifisches Verzeichnis %_LW_NEU% wurde neu angelegt
echo New subdirectory %_LW_NEU% created
echo.
echo Bitte die Datei %_LW_PFAD_NEU%\CFGDAT\COAPI.INI wie folgt aendern:
echo.Please change the file %_LW_PFAD_NEU%\CFGDAT\COAPI.INI as follows:
echo.
echo.
echo Zeile   "%_BR_COD%_PFAD_DATEN = ..\daten"  in  "%_BR_COD%_PFAD_DATEN = ..\daten\%_BR_COD%"
echo line    "%_BR_COD%_PFAD_DATEN = ..\daten"  to  "%_BR_COD%_PFAD_DATEN = ..\daten\%_BR_COD%"
echo.
echo und / and
echo.
echo Zeile   "%_BR_COD%_PFAD_TAB = ..\daten"  in  "%_BR_COD%_PFAD_TAB = ..\daten\%_BR_COD%"
echo line    "%_BR_COD%_PFAD_TAB = ..\daten"  to  "%_BR_COD%_PFAD_TAB = ..\daten\%_BR_COD%"
echo.
echo.
echo.
pause

:END
echo.
echo Auftrag ausgefuehrt
set _BR_COD=
set _LW_COD=
set _DPA_COD=
set _UDPA_COD=
set _SPA_COD=
set _LW_NEU=
set _LW_PFAD_NEU=
set kopieren=

@echo on