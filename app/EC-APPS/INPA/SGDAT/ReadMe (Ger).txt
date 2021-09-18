TD-53x INPA Skript
------------------

1. Installation
---------------

Bitte gehen Sie zur Installation des TD-53x Skripts folgendermaßen
vor:
- Öffnen Sie das Installations Archiv mit Winzip
- Wählen Sie den Menüpunkt extrahieren
- Geben Sie beim Extrahieren folgende Optionen an
  * Extrahieren nach		: "C:\"
  * Dateien überschreiben 	: Ja
  * Pfadangaben verwenden	: Ja
  
Sollte auf ihrem Rechner INPA in dem Verzeichnis C:\EC-APPS\INPA installiert
sein, so müssen Sie noch den Inhalt des Verzeichnis C:\INPA nach C:\EC-APPS\INPA
verschieben.

Nachdem dies durchgeführt wurde befinden sich alle notwendigen 
Dateien in den entsprechenden Verzeichnissen. 

Zum Starten des TD-53x INPA Skripts muß eine Verknüpfung zu 
"C:\INPA\BIN\INPALOAD.EXE" erstellt werden und als Parameter in 
den Eigenschaften der Verknüpfung "TD-530.IPO" übergeben werden. 
Mit Hilfe dieser Verknüpfung kann dann das INPA Skript immer 
gestartet werden. Wollen Sie die englische Version des Skriptes
starten so müssen sie als Parameter "TD-530_ENG.IPO" angeben.


2. Arbeiten mit dem TD-53x INPA Skript
--------------------------------------

Hier einige Hinweise zum Arbeiten mit dem TD-53x INPA Skript

CheckIn:
Beim Durchführen eines kompletten CheckIn werden sämtliche Daten eines Fahrzeuges
festgehalten, die zu Beginn der Analyse an einem Fahrzeug benötigt werden.

CheckOut:
Beim Ausführen eines kompletten CheckOut wird das Fahrzeug unabhängig von den
zuvor durchgeführten Arbeiten wieder in einen Zustand gebracht in dem es gefahren
werden kann.

Trace:
Mit der Trace Funktionen können Aufzeichnungen von mehreren beliebigen Steuergeräte-Größen
gemacht werden. Über die Datei "TRACE.TST" wird festgelegt, aus welchen Steuergeräten welche
Parameter ausgelesen werden sollen. Diese Datei hat den gleichen Aufbau wie eine EDIABAS
Testdatei. Die Werte werden zyklisch ausgelesenen und in einer Ergebnisdatei abgelegt. 

Ergebnisdatei:
Beim Ausführen aller Aufgaben bzw. Jobs werden die Fahrzeugdaten immer in einer
Ergebnisdatei im Verzeichnis "C:\FAHRZEUG.DAT" abgespeichert. Der Name der Ergebnis-
datei setzt sich aus der Fahrgestellnummer und der durchgführten Aufgabe zusammen.
Der Name der Ergebnisdatei wird immer in der Kopfzeile des Fensters angezeigt.

Daten sichern:
Das TD-53x INPA Skript bietet die Möglichkeit, sämtliche Daten, die von einem Fahrzeug 
ausgelesen wurden und sich im Verzeichnis "C:\FAHRZEUG.DAT" befinden, zentral auf einem 
Serverlaufwerk zu speichern. Die dazu notwendige Funktionen können über den Menüpunkt
"F9" des Hauptmenüs aufgerufen werden. Die für die Sicherung der Daten notwendigen
Einstellungen können über die Dateien "TD-530.INI" (Konfiguration des Menüs), bzw. 
"TD-530.BAT" (Konfiguration der Sicherungs Verzeichnisse) gemacht werden.

Individuelle Einstellungen:
In der Datei TD-530.cfg ist es möglich, individuelle Einstellungen vorzunehmen. Nähere 
Informationen zu den einzelnen Einstellungen finden Sie in der Datei selbst. 


3. Probleme
-----------

Sollten Probleme beim Arbeiten mit dem TD-53x INPA Skript auftreten, so können Sie mir
durch folgende Vorgehensweise bei der Fehlerbeseitigung helfen:
- In der Datei "TD-530.CFG" unter der Rubrik "Parameter" den Parameter "Logging" auf "ON"
  stellen.
- Problem mit INPA Skript nachstellen.
- Die Dateien "TD-530.LOG" aus dem Verzeichnis "C:\FAHRZEUG.DAT" 
  zusammen mit der dazugehörenden Fehlerbeschreibung an mich senden.
  
  
4. Ansprechpartner
------------------

Autor     : Günter Straßer
Abteilung : TD-531
Telefon   : 08731/7629182
Handy     : 0179/4747804
Email     : guenter.strasser@bmw.de