//**********************************************************************
//*
//* INPA Library-Funktionen PA1500.H
//*
//* mindestens INPA 4.4.2
//*
//**********************************************************************
//* Winkler TP-421
//**********************************************************************
//* History:
//* 26.09.97 HJW V0.01 Erstellung
//**********************************************************************

//**********************************************************************
// DLL-Funktionen Parameter siehe Technisches Referenzhandbuch
// ADDINUM PA1500 Addi-Data Digital-IO-Karte 
//**********************************************************************

// Initialisieren der Karte 
// Achtung: ui_Address und b_AccessMode sind auf der IO-Karte
//          codiert, muessen in der Applikation mit den identischen
//          Werten benutzt werden !!!!!!!
import pascal lib "pa1500.dll"   i_PA1500_SetBoardAddress
					(in:	   int	  ui_Address,
					 in:	   byte	  b_AccessMode,
					 out:	   byte	  pb_BoardHandle,
					 returns:  int	  ReturnedValue);

// Freigeben des Ports 
import pascal lib "pa1500.dll"   i_PA1500_CloseBoardHandle
					(in:	   byte	  b_BoardHandle,
					 returns:  int	  ReturnedValue);



// Daten über einen der beiden DigIn-Ports einlesen 
import pascal lib "pa1500.dll"   i_PA1500_Read8DigitalInput
					(in:	   byte	  pb_BoardHandle,
					 in:	   byte	  b_Port,
					 out:	   byte	  pb_PortValue,
					 returns:  int	  ReturnedValue);

// DigOut-Daten sind absolute Ausgaben
import pascal lib "pa1500.dll"   i_PA1500_SetOutputMemoryOff
					(in:	   byte	  b_BoardHandle,
					 returns:  int	  ReturnedValue);

// Daten über einen der beiden DigOut-Ports ausgeben 
import pascal lib "pa1500.dll"   i_PA1500_Set8DigitalOutputOn
					(in:	   byte	  b_BoardHandle,
					 in:	   byte	  b_Port,
					 in:	   byte	  b_Value,
					 returns:  int	  ReturnedValue);


// -- EOF --
