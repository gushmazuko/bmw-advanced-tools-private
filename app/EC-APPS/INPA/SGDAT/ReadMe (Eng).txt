TD-53x INPA Script
------------------

1. Installation
---------------

Please do the following steps for installing the TD-53x INPA script:
- Open the ZIP archiv with winzip
- Choose the menu item "Extract"
- Set the following options
  * Extract to   		: "C:\"
  * Overwrite files	 	: Yes
  * Use path settings 		: Yes
  
If on your PC INPA is installed in the folder C:\EC-APPS\INPA you have to move all
files from the folder C:\INPA to C:\EC-APPS\INPA

After doing this, all needed files are in the right folders.

To start the TD-53x INPA script you have to create a shortcut (link)
to the file "C:\INPA\BIN\INPALOAD.EXE". As parameter in this 
shortcut you have to set "TD-530.IPO". With this shurtcut you are
able to start the INPA script. If you like to start the English
version of the script please set as parameter "TD-530_ENG.IPO".


2. Working with the TD-53x INPA Script
--------------------------------------

Here are some hints for working with the TD-53x INPA Script

CheckIn:
With doing a complete CheckIn the INPA script reads out all data of the vehicle
which is needed for starting analysis on a car.

CheckOut:
With doing a complete CheckOut the INPA script sets back all the parameters which
have been read out during the CheckIn.

Trace:
With the Trace function it is possible to make a measurement of user set device parameters.
In the file "TRACE.TST" you could specify the parameters which should be read out. This
file has the same format than a Toolset test file. The INPA script reads out the values
cyclic and stores them in a result file.

Result file:
On every executet job the INPA script stores the results inside a result file in 
the directory "C:\FAHRZEUG.DAT". The name of the result file is set with the VIN
and one charcter for the done job (i = CheckIn, o = CheckOut, ...)

Save data:
The TD-53x INPA Script gives you the possibilty to save all the data, which have been
read out from one car and which are stored in the directory "C:\FAHRZEUG.DAT", on a
central server directory. The functions for doing that you can call over the menu
item "F9" of the main menu. The settings for the data saving you can do in the file
"TD-530.INI" (configuration of the menu) and the file "TD-530.BAT" (configuration
of the destination directories).

Individuel settings:
The file TD-530.cfg gives you the possibilty to make your own settings. To get more information
open the file.

3. Problems
-----------

If you have any problems with the TD-53x INPA script, please do the following steps to
help me solving the problem:
- Open the file "TD-530.cfg" with a text editor and go to the rubric "Parameter". Set
  the parameter "Logging" to "ON".
- Run the INPA script into the problem.
- Please send an E-Mail containing the file "TD-530.LOG" of the directory "C:\FAHRZEUG.DAT" 
  and a detailed problem discription to me.


4. Contact
----------

Autor     : Günter Straßer
Abteilung : TD-531
Telefon   : 08731/7629182
Handy     : 0179/4747804
Email     : guenter.strasser@bmw.de