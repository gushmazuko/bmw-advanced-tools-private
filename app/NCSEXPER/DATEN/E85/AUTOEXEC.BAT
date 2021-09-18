CLS
REM.
REM Codierdaten werden auf die Festplatte kopiert
REM.
COPY E83*.* C:\CABI\DATEN
REPLACE *.ASC C:\CABI\DATEN /u /r
REPLACE *.ASC C:\CABI\DATEN /a
REPLACE *.DAT C:\CABI\DATEN /u /r
REPLACE *.DAT C:\CABI\DATEN /a
REPLACE *.C* C:\CABI\DATEN /u /r
REPLACE *.C* C:\CABI\DATEN /a
REM.
REM Die Konfigurationsdatei wird auf die Festplatte kopiert
REM.
rem COPY E83_CONF.BAP C:\CABI\TAB
REM.
REM Die Steuerdateien werden auf die Festplatte kopiert
REM.
CD \CABI\STDAT
COPY E83*.SSD C:\CABI\STDAT

ECHO OFF
REM.
REM Die FahrzeugschlÅsseldateien werden auf die Festplatte kopiert
REM.
REM COPY \A*.FZS C:\WINELDI\AUFTRAG
REM.
ECHO ON

REM.
REM Kopiervorgang beendet. Bitte Diskette aus Laufwerk A entfernen
REM und Warmstart durchfÅhren.
