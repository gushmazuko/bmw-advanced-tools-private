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
  
Nachdem dies durchgeführt wurde befinden sich alle notwendigen 
Dateien in den entsprechenden Verzeichnissen.

Zum Starten des TD-53x INPA Skripts muß eine Verknüpfung zu 
"C:\INPA\BIN\INPALOAD.EXE" erstellt werden und als Parameter
"TD-530.IPO" übergeben werden. Mit Hilfe dieser Verknüpfung kann
dann das INPA Skript immer gestartet werden.


2. Arbeiten mit dem TD-53x INPA Skript
--------------------------------------

Hier einige Hinweise zum Arbeiten mit dem TD-53x INPA Skript

CheckIn:
Beim Durchführen eines kompletten CheckIn werden sämtliche Daten eines Fahrzeuges
festgehalten, die zum Beginn der Analyse an einem Fahrzeug benötigt werden.

CheckOut:
Beim Ausführen eines kompletten CheckOut wird das Fahrzeug unabhängig von den
zuvor durchgeführten Arbeiten wieder in einen Zustand gebracht in dem es gefahren
werden kann.

Trace:
Mit der Trace Funktionen können Aufzeichnungen von mehreren beliebigen Steuergeräte Größen
gemacht werden. Über die Datei "TRACE.TST" wird festgelegt aus welchen Steuergeräte welche
Parameter ausgelesen werden sollen. Diese Datei hat den gleichen Aufbau wie eine EDIABAS
Testdatei. Die Werte werden zyklisch ausgelesenen und in einer Ergebnisdatei abgelegt. 

Ergebnisdatei:
Beim Ausführen aller Aufgaben bzw. Jobs werden die Fahrzeugdaten immer in einer
Ergebnisdatei im Verzeichnis "C:\FAHRZEUG.DAT" abgespeichert. Der Name der Ergebnis-
datei setzt sich aus der Fahrgestellnummer und der durchgführten Aufgabe zusammen.
Der Name der Ergebnisdatei wird immer in der Kopfzeile des Fensters angezeigt.


3. Ansprechpartner
------------------

Autor     : Günter Straßer
Abteilung : TD-532
Telefon   : 08731/7629182
Handy     : 0179/4747804
Email     : guenter.strasser@bmw.de