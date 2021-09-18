//**********************************************************************
//*
//* INPA Library-Funktionen COMMLIB.H
//*
//* mindestens INPA 5.0.1
//*
//**********************************************************************
//* Gall TI-430
//**********************************************************************
//* History:
//* 28.11.1997 rd V0.01 Erstellung
//* 28.05.1999 rd V1.00 Freigabe
//* 21.02.2000 rd V1.01 INPAReadCommBinary, INPAWriteCommBinary neu dazu
//* 01.03.2000 rd V1.02 INPACloseComm
//* 16.02.2004 rd V2.00 Umstellung auf 32-Bit Version
//* 30.03.2006 GA V3.00 Erweiterung auf UDS (ISO 14229)
//**********************************************************************

//**********************************************************************
//*
//* Globale Variablen
//*
//**********************************************************************
long   CommBuffer=0;   // fuer Strukturzugriffe

//**********************************************************************
//*
//* Deklaration der Funktionen
//*
//**********************************************************************
extern INPAGetCommError(in:    int  CID,
                        inout: byte Flags,
                        inout: int  InQue,
                        inout: int  OutQue,
                        inout: int  ErrorCode);

extern INPAGetCommState(in:    int  CID,
                        inout: int  BaudRate,
                        inout: byte ByteSize,
                        inout: byte Parity,
                        inout: byte StopBits,
                        inout: int  Flags,
                        inout: int  ErrorCode);

extern INPASetCommState(in:    int  CID,
                        in:    int  BaudRate,
                        in:    byte ByteSize,
                        in:    byte Parity,
                        in:    byte StopBits,
                        in:    int  Flags,
                        inout: int  ErrorCode);

//**********************************************************************
// DLL-Funktionen Parameter siehe Windows WINAPI
//**********************************************************************
import pascal lib "user::OpenComm"  INPAOpenComm       (in:      string    ComName,
                                                        in:      int       InQueue,
                                                        in:      int       OutQueue,
                                                        returns: int       CID);

import pascal lib "user::ReadComm"  INPAReadComm       (in:      int       CID,
                                                        inout:   string    Buffer,
                                                        in:      int       BufferSize,
                                                        returns: int       ReturnedSize);

import pascal lib "user::WriteComm" INPAWriteComm      (in:      int       CID,
                                                        in:      string    Buffer,
                                                        in:      int       BufferSize,
                                                        returns: int       ReturnedSize);

import pascal lib "user::ReadComm"  INPAReadCommBinary (in:      int       CID,
                                                        inout:   structure Buffer,
                                                        in:      int       BufferSize,
                                                        returns: int       ReturnedSize);

import pascal lib "user::WriteComm" INPAWriteCommBinary(in:      int       CID,
                                                        inout:   structure Buffer,
                                                        in:      int       BufferSize,
                                                        returns: int       ReturnedSize);

import pascal lib "user::CloseComm" INPACloseComm      (in:      int       CID,
                                                        returns: int       ErrorCode);

import pascal lib "user" GetCommState(in:      int       CID,
                                      inout:   structure DCB,
                                      returns: int       ErrorCode);

import pascal lib "user" SetCommState(inout:   structure DCB,
                                      returns: int       ErrorCode);

import pascal lib "user" GetCommError(in:      int       CID,
                                      inout:   structure COMSTAT,
                                      returns: int       ErrorCode);

//**********************************************************************
//
//  Schnittstellen Fehlerflags
//
//**********************************************************************
INPAGetCommError(in:    int  CID,
                 inout: byte Flags,
                 inout: int  InQue,
                 inout: int  OutQue,
                 inout: int  ErrorCode)
{
  if (CommBuffer==0) CreateStructure(CommBuffer,1024);
  if (CommBuffer==0) messagebox("INPAGetCommError","Error: Handle"); // sollte nie kommen
  GetCommError(CID, CommBuffer , ErrorCode);
  SetStructureMode(1); // lesen
  StructureByte(CommBuffer,0,Flags);
  StructureInt(CommBuffer,1,InQue);
  StructureInt(CommBuffer,3,OutQue);
}

//**********************************************************************
//
//  Schnittstellen Status lesen
//
//**********************************************************************
INPAGetCommState(in:    int  CID,
                 inout: int  BaudRate,
                 inout: byte ByteSize,
                 inout: byte Parity,
                 inout: byte StopBits,
                 inout: int  Flags,
                 inout: int  ErrorCode)
{
  if (CommBuffer==0) CreateStructure(CommBuffer,1024);
  if (CommBuffer==0) messagebox("INPAGetCommState","Error: Handle"); // sollte nie kommen
  GetCommState(CID, CommBuffer , ErrorCode);
  SetStructureMode(1); // lesen
  // Byte 0 ID byte
  StructureInt(CommBuffer,1,BaudRate);
  StructureByte(CommBuffer,3,ByteSize);
  StructureByte(CommBuffer,4,Parity);
  StructureByte(CommBuffer,5,StopBits);
  // Byte 6 RlsTimeout int
  // Byte 8 CtsTimeout int
  // Byte 10 DsrTimeout int
  StructureInt(CommBuffer,12,Flags);
  // Byte 14 XonChar byte
  // Byte 15 XoffChar byte
  // Byte 16 XonLim int
  // Byte 18 XoffLim int
  // Byte 20 PeChar byte
  // Byte 21 EofChar byte
  // Byte 22 EvtChar byte
  // Byte 23 TxDelay int
}

//**********************************************************************
//
//  Schnittstellen Status vorgeben
//
//**********************************************************************
INPASetCommState(in:    int  CID,
                 in:    int  BaudRate,
                 in:    byte ByteSize,
                 in:    byte Parity,
                 in:    byte StopBits,
                 in:    int  Flags,
                 inout: int  ErrorCode)
{
  byte ID;
  int  Ident;

  if (CommBuffer==0) CreateStructure(CommBuffer,1024);
  if (CommBuffer==0) messagebox("INPASetCommState","Error: Handle"); // sollte nie kommen
  // Status erst lesen
  GetCommState(CID, CommBuffer , ErrorCode);
  SetStructureMode(1); // lesen
  StructureByte(CommBuffer,0,ID);
  bytetoint(ID,Ident);
  if (Ident != CID) messagebox("INPASetCommState","ID-Fehler"); // sollte nie kommen

  // Werte eintragen
  SetStructureMode(0); // schreiben
  StructureInt(CommBuffer,1,BaudRate);
  StructureByte(CommBuffer,3,ByteSize);
  StructureByte(CommBuffer,4,Parity);
  StructureByte(CommBuffer,5,StopBits);
  // Byte 6 RlsTimeout int
  // Byte 8 CtsTimeout int
  // Byte 10 DsrTimeout int
  StructureInt(CommBuffer,12,Flags);
  // Byte 14 XonChar byte
  // Byte 15 XoffChar byte
  // Byte 16 XonLim int
  // Byte 18 XoffLim int
  // Byte 20 PeChar byte
  // Byte 21 EofChar byte
  // Byte 22 EvtChar byte
  // Byte 23 TxDelay int
  SetCommState(CommBuffer , ErrorCode);
}

// -- EOF --
