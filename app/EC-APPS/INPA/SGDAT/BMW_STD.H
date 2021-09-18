//**********************************************************************
//*
//* INPA Library-Funktionen BMW_STD.H
//*
//* mindestens INPA 5.0.1
//*
//**********************************************************************
//* Gall TI-430
//**********************************************************************
//* History:
//* 05.04.2000 rd V0.01 Ersterstellung
//* 23.06.2000 rd V0.02 Überarbeitung für E65 und E85
//* 21.11.2000 rd V0.03 AnsiUpper, AnsiLower neu dazu
//* 16.02.2004 rd V2.00 Umstellung auf 32-Bit Version
//* 30.03.2006 GA V3.00 Erweiterung auf UDS (ISO 14229)
//* 14.03.2008 GA V3.01 GetCommandLine dazu
//**********************************************************************

//**********************************************************************
//*
//* Globale Variablen
//*
//**********************************************************************
long   GlobalBuffer=0;   // fuer Strukturzugriffe
string CR="?";           // reserviert fuer carrige return
string LF="?";           // reserviert fuer line feed
string CRLF="?";         // reserviert fuer CR + LF
string HT="?";           // reserviert fuer horizontal tab

//**********************************************************************
//*
//* Deklaration der Funktionen
//*
//**********************************************************************
extern chrinit();

extern chr(in: byte b, inout: string s);

extern asc(in: string s, inout: byte b);

extern filedelete(in: string FileName, inout: int ErrorCode);

extern fileexist(in: string FileName, inout: int ErrorCode);

extern bytetohexstring(in: byte zahl, in: int laenge, out: string text);

extern inttohexstring(in: int zahl, in: int laenge, out: string text);

extern longtohexstring(in: long zahl, in: int laenge, out: string text);

extern ausgabe_formatiert( in: string text, in: int row, in: int col,
                           in: int textsize, in: int textattr,
                           in: int digit, in: int step);

extern instr(out: int pos, in: int ab , in: string Text, in: string Suchtext);

extern trimstr(inout: string Text);

extern space(inout: string Text, in:int nr);

extern ExtraScript(in: string Script, out: bool Flag);

//**********************************************************************
// DLL-Funktionen Parameter siehe Windows WINAPI
//**********************************************************************
import32 "C" lib "kernel32::GetPrivateProfileStringA"   GetPrivateProfileString
                                                        (in:      string    Section,
                                                         in:      string    Entry,
                                                         in:      string    Default,
                                                         out:     string    ReturnedString,
                                                         in:      int       Size,
                                                         in:      string    FileName,
                                                         returns: int       ReturnedSize);

import32 "C" lib "kernel32::GetPrivateProfileIntA"      GetPrivateProfileInt
                                                        (in:      string    Section,
                                                         in:      string    Entry,
                                                         in:      int       Default,
                                                         in:      string    FileName,
                                                         returns: int       ReturnedValue);

import32 "C" lib "kernel32::WritePrivateProfileStringA" WritePrivateProfileString
                                                        (in:      string    Section,
                                                         in:      string    Entry,
                                                         in:      string    String,
                                                         in:      string    FileName,
                                                         returns: bool      ReturnedValue);

import32 "C" lib "kernel32"                             OpenFile
                                                        (in:      string    FileName,
                                                         inout:   structure ReOpenBuff,
                                                         in:      int       Style,
                                                         returns: int       ReturnedValue);

import32 "C" lib "user32::wvsprintfA"                   wvsprintf
                                                        (inout:   string    ReturnedString,
                                                         in:      string    Format,
                                                         inout:   structure ArgList,
                                                         returns: int       ReturnedValue);

import32 "C" lib "user32::CharUpperA"                   AnsiUpper
                                                        (in:      string    lpString,
                                                         returns: string    ret_string);

import32 "C" lib "user32::CharLowerA"                   AnsiLower
                                                        (in:      string    lpString,
                                                         returns: string    ret_string);

import32 "C" lib "kernel32::GetWindowsDirectoryA"       GetWindowsDirectory
                                                        (inout:   string    lpString,
                                                         in:      int       nSize,
                                                         returns: int       ReturnedValue);

import32 "C" lib "kernel32::GetCurrentDirectoryA"       GetCurrentDirectory
                                                        (in:      long      nSize,
                                                         inout:   string    lpString,
                                                         returns: int       ReturnedValue);

import32 "C" lib "kernel32::SetCurrentDirectoryA"       SetCurrentDirectory
                                                        (in:      string    lpString,
                                                         returns: int       ReturnedValue);


import32 "C" lib "kernel32::GetCommandLineA"            GetCommandLine
                                                        (returns: string    ret_string);
//**********************************************************************
// DLL-Funktionen EDIABAS - XTRACT32.DLL
//**********************************************************************

import32 "C" lib "XTRACT32.DLL"                         XTRACT
                                                        (in:      string    FileName,
                                                         in:      int       Mode,
                                                         inout:   string    Buffer,
                                                         in:      long      Size,
                                                         returns: int       ReturnedValue);

//**********************************************************************
// DLL-Funktionen BMW INPA-Lib INPA_LIB32.DLL
//**********************************************************************

import32 "C" lib "INPA_LIB32.DLL"                       SaveAsDialogBox
                                                        (in:      string    Title,
                                                         inout:   string    lpString,
                                                         in:      int       Size,
                                                         returns: int       ReturnedValue);

//**********************************************************************
//
//  initialisiert globale Variable CR LF HT CRLF
//
//**********************************************************************
chrinit()
{
  chr( 9 , HT );
  chr( 10, LF );
  chr( 13, CR );
  CRLF = CR + LF;
}

//**********************************************************************
//
//  chr wandelt Byte b in string s
//
//**********************************************************************
chr(in: byte b, inout: string s)
{
  byte Null=0;

  if (GlobalBuffer==0) CreateStructure(GlobalBuffer,1024);
  if (GlobalBuffer==0) messagebox("chr","Error: Handle"); // sollte nie kommen
  SetStructureMode(0); // schreiben
  StructureByte(GlobalBuffer,0,b);
  StructureByte(GlobalBuffer,1,Null);
  SetStructureMode(1); // lesen
  StructureString(GlobalBuffer,0,0,s);
}

//**********************************************************************
//
//  asc wandelt das erste Zeichen von string s in Byte b
//
//**********************************************************************
asc(in: string s, inout: byte b)
{
  byte Null=0;

  if (GlobalBuffer==0) CreateStructure(GlobalBuffer,1024);
  if (GlobalBuffer==0) messagebox("asc","Error: Handle"); // sollte nie kommen
  SetStructureMode(0); // schreiben
  StructureString(GlobalBuffer,0,1,s);
  SetStructureMode(1); // lesen
  StructureByte(GlobalBuffer,0,b);
}

//**********************************************************************
//
//  Löscht die angegebene Datei
//  ErrorCode=0 : Datei gelöscht
//
//**********************************************************************
filedelete(in: string FileName, inout: int ErrorCode)
{
  int    ReturnedValue;
  int    Style=0x0200; // Delete

  if (GlobalBuffer==0) CreateStructure(GlobalBuffer,1024);
  if (GlobalBuffer==0) messagebox("filedelete","Error: Handle"); // sollte nie kommen
  OpenFile(FileName,GlobalBuffer,Style,ReturnedValue);
  SetStructureMode(1); // lesen
  StructureInt(GlobalBuffer,2,ErrorCode);
}

//**********************************************************************
//
//  Sieht nach ob die angegebene Datei existiert
//  ErrorCode=0 : Datei existiert
//
//**********************************************************************
fileexist(in: string FileName, inout: int ErrorCode)
{
  int    ReturnedValue;
  int    Style=0x4000; // Exist

  if (GlobalBuffer==0) CreateStructure(GlobalBuffer,1024);
  if (GlobalBuffer==0) messagebox("fileexist","Error: Handle"); // sollte nie kommen
  OpenFile(FileName,GlobalBuffer,Style,ReturnedValue);
  SetStructureMode(1); // lesen
  StructureInt(GlobalBuffer,2,ErrorCode);
}

//**********************************************************************
//*
//* bytetohexstring
//*
//* siehe longtohexstring
//*
//**********************************************************************
bytetohexstring(in: byte zahl, in: int laenge, out: string text)
{
  int  i;
  long wert;
  string temp;

  bytetoint(zahl,i);
  inttolong(i,wert);
  if (wert<0) wert=wert+256;
  longtohexstring(wert, laenge, temp);
  text=temp;
}

//**********************************************************************
//*
//* inttohexstring
//*
//* siehe longtohexstring
//*
//**********************************************************************
inttohexstring(in: int zahl, in: int laenge, out: string text)
{
  long wert;
  string temp;

  inttolong(zahl,wert);
  if (wert<0) wert=wert+65536;
  longtohexstring(wert, laenge, temp);
  text=temp;
}

//**********************************************************************
//*
//* longtohexstring
//*
//* Die Zahl zahl wird in einen Hex-String gewandelt mit der Länge laenge.
//* ( Maximallänge = 8 ). Das Ergebnis steht in text.
//* Die Länge wird automatisch angepasst, wenn das Ergebnis mehr Platz
//* benötigt. Es werden führende '0' vorangestellt.
//*
//**********************************************************************
longtohexstring(in: long zahl, in: int laenge, out: string text)
{
  int    ReturnedValue;
  string ReturnedString="        ";
  string Temp;

  if (laenge<1) Temp="1"; else inttostring(laenge,Temp);
  // maximal 8 stellen
  if (laenge>8) Temp="8";

  if (GlobalBuffer==0) CreateStructure(GlobalBuffer,1024);
  if (GlobalBuffer==0) messagebox("longtohexstring","Error: Handle"); // sollte nie kommen
  SetStructureMode(0); // schreiben
  StructureLong(GlobalBuffer,0,zahl);
  wvsprintf(ReturnedString, "%0"+Temp+"lX",GlobalBuffer, ReturnedValue);
  if (ReturnedValue>0) text=ReturnedString; else text="";
}

//**********************************************************************
//*
//* ausgabe_formatiert
//*
//* Ausgabe von Text text in Zeile row und Spalte col mit
//* Textgröße textsize und Textattribut textattr.
//*
//* Der Textstring wird zu jeweils digit Zeichen im Abstand von step
//* ausgegeben.
//*
//* Beispiel: ausgabe_formatiert("abcdefghi",3,5,0,0,2,3)
//* Ausgabe in Zeile 3 Spalte 5 in normaler Größe mit je 2 Digit und einem
//* Abstand von 3.
//* 1234567890
//* 2
//* 3   ab cd ef gh i
//*
//**********************************************************************
ausgabe_formatiert( in: string text, in: int row, in: int col,
                    in: int textsize, in: int textattr,
                    in: int digit, in: int step)
{
  int    laenge;
  string temp;
  int    spalte;
  int    i;

  strlen(laenge,text);
  spalte=col;
  i=0;
  while (i<laenge)
  {
    midstr(temp,text,i,digit);
    ftextout(temp+" ",row,spalte,textsize,textattr);
    i=i+digit;
    spalte=spalte+step;
  }
}

//**********************************************************************
//*
//* instr
//*
//* Der Suchtext wird ab der Position ab im Text gesucht.
//* pos =-1 wenn der Text im Suchtext nicht enthalten ist,
//*         sonst die Position ab der der Suchtext in Text gefunden wurde.
//*         Die Position beginnt mit 0.
//*
//**********************************************************************
instr(out: int pos, in: int ab , in: string Text, in: string Suchtext)
{
  string Temp;
  int    Textlen;
  int    Suchtextlen;
  int    i;
  bool   gefunden;

  // default nicht gefunden
  pos=-1;

  strlen(Textlen,Text);
  // Text kein Leersting
  if (Textlen>0)
  {
    strlen(Suchtextlen,Suchtext);
    // Suchtext kein Leersting
    if (Suchtextlen>0)
    {
      // Suche sinnvoll
      if (Textlen-ab>=Suchtextlen)
      {
        // Suche kann beginnen
        i=ab-1;
        gefunden=FALSE;
        while (gefunden==FALSE && i<Textlen-Suchtextlen)
        {
          i=i+1;
          midstr(Temp,Text,i,Suchtextlen);
          if (Temp==Suchtext)
          {
            gefunden=TRUE;
            pos=i;
          }
        }
      }
    }
  }
}

//**********************************************************************
//*
//* trimstr
//*
//* Die Funktion entfernt alle links- und rechtsbündige Leerzeichen
//*
//**********************************************************************
trimstr(inout: string Text)
{
  string Temp;
  string Char;
  int    len;
  int    von;
  int    bis;

  strlen(len,Text);
  // Text kein Leersting
  if (len>0)
  {
    Temp=Text;
    Char=" ";
    von =-1;
    while (Char==" ")
    {
      von=von+1;
      midstr(Char,Temp,von,1);
    }
    if (von<len)
    {
      Char=" ";
      bis =len;
      while (Char==" ")
      {
        bis=bis-1;
        midstr(Char,Temp,bis,1);
      }
      midstr(Text,Temp,von,bis-von+1);
    }
    else
    {
      Text="";
    }
  }
}

//**********************************************************************
//*
//* space
//*
//* String Text wird mit nr Leerzeichen gefüllt
//*
//**********************************************************************
space(inout: string Text, in:int nr)
{
  string s100="                                                                                                    ";
  string s10 ="          ";
  string s1  =" ";
  int i;

  Text="";
  i=0;
  while (i+100 <= nr)
  {
    Text=Text+s100;
    i=i+100;
  }
  while (i+10 <= nr)
  {
    Text=Text+s10;
    i=i+10;
  }
  while (i < nr)
  {
    Text=Text+s1;
    i=i+1;
  }
}

//**********************************************************************
//*
//* ExtraScript
//*
//* Es wird der Scriptname Script übergeben. Die Funktion überprüft
//* die Einträge in der Datei INPA.INI
//*
//* Flag= FALSE Standardversion für die Nacharbeit
//*       TRUE  Spezialversion für Entwickler
//*
//**********************************************************************
ExtraScript(in: string Script, out: bool Flag)
{
  string ReturnedString="                                                            ";
  int    ReturnedSize;
  int    i;

  Flag=FALSE;
  strlen(i,ReturnedString);
  GetPrivateProfileString("EXTRA","SCRIPTS","NoEntry",ReturnedString,i,
                          "..\CFGDAT\INPA.INI",ReturnedSize);

  if (ReturnedString!="NoEntry")
  {
    // Extra für alle Dateien
    if (ReturnedString=="*")
    {
      Flag=TRUE;
    }
    else
    {
      // Suche nach Script
      // Der Name muß exakt stimmen
      instr(i,0,","+ReturnedString+",",","+Script+",");
      if (i>=0)
      {
        Flag=TRUE;
      }
    }
  }
}

// -- EOF --
