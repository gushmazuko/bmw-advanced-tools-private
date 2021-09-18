//**********************************************************************
//*
//* INPA Library-Funktionen BMWLIB.H
//*
//* mindestens INPA 4.4.2
//*
//**********************************************************************
//* Drexel TI-433
//**********************************************************************
//* History:
//* 09.02.96 rd V0.01 Erstellung
//* 01.03.96 rd V1.00 Freigabe   
//* 24.07.96 rd V1.01 ExtraScript neu dazu
//* 29.07.96 rd V1.02 inttohexstring neu dazu
//* 19.08.96 rd V1.03 Deklaration neu dazu
//* 12.11.96 rd V1.04 Bei Eldi-Auftrag auch Ausgabe der Motornummer
//* 14.04.97 rd V1.05 mindestens INPA 4.4.2
//*                   bytetohexstring, longtohexstring,
//*                   filedelete, fileexist,
//*                   DLL-Funktionen neu dazu
//* 29.04.97 rd V1.06 WritePrivateProfilString neu dazu
//* 05.03.98 rd V1.07 Bei Eldi-Auftrag kein Zündungstest
//* 28.05.99 rd V1.08 Neu chr Funktion wandelt Byte b in string s
//*                   globale Variable CR, LF, CRLF und HT neu
//*                   Initialisierung der Variablen durch chrinit
//* 23.07.99 rd V1.09 Neu show_battery_ignition Funktion
//* 21.11.00 rd V1.10 AnsiUpper, AnsiLower neu dazu
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

extern filedelete(in: string FileName, inout: int ErrorCode);

extern fileexist(in: string FileName, inout: int ErrorCode);

extern ausgabe_formatiert( in: string text, in: int row, in: int col,
                           in: int textsize, in: int textattr,
                           in: int digit, in: int step);

extern bytetohexstring(in: byte zahl, in: int laenge, out: string text);

extern inttohexstring(in: int zahl, in: int laenge, out: string text);

extern longtohexstring(in: long zahl, in: int laenge, out: string text);

extern instr(out: int pos, in: int ab , in: string Text, in: string Suchtext);

extern trimstr(inout: string Text);

extern EldiAuftragLesen(in: string sprache);

extern EldiAuftragEingeben(in: string sprache);

extern ExtraScript(in: string Script, out: bool Flag);

//**********************************************************************
// DLL-Funktionen Parameter siehe Windows WINAPI
//**********************************************************************
import pascal lib "kernel"   GetPrivateProfileString(in:      string    Section,
                                                     in:      string    Entry, 
                                                     in:      string    Default,
                                                     out:     string    ReturnedString,
                                                     in:      int       Size,
                                                     in:      string    FileName,
                                                     returns: int       ReturnedSize);

import pascal lib "kernel"      GetPrivateProfileInt(in:      string    Section,
                                                     in:      string    Entry, 
                                                     in:      int       Default,
                                                     in:      string    FileName,
                                                     returns: int       ReturnedValue);

import pascal lib "kernel" WritePrivateProfileString(in:      string    Section,
                                                     in:      string    Entry, 
                                                     in:      string    String,
                                                     in:      string    FileName,
                                                     returns: bool      ReturnedValue);

import pascal lib "kernel"                  OpenFile(in:      string    FileName,
                                                     in:      structure ReOpenBuff,
                                                     in:      int       Style,
                                                     returns: int       ReturnedValue);

import pascal lib "user"                   wvsprintf(inout:   string    ReturnedString,
                                                     in:      string    Format, 
                                                     in:      structure ArgList,
                                                     returns: int       ReturnedValue);

import pascal lib "user"                   AnsiUpper(in:      string    lpString,
                                                     returns: string    ret_string);

import pascal lib "user"                   AnsiLower(in:      string    lpString,
                                                     returns: string    ret_string);

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
//* show_battery_ignition
//*
//* Anzeige des Batterie- und Zündungs-Status
//*
//**********************************************************************
show_battery_ignition(in: string sprache)
{
  bool   fehlerflag;    // Fehler aufgetreten
  bool   zuendung;      // Zündung ein/aus
  bool   batterie;      // Batterie ein/aus
  int    wert;          // allgemeine Variable

  if (sprache=="deutsch")
  {
    ftextout("Batterie :", 0,5,1,0);
    ftextout("Zündung  :", 0,45,1,0);
  }
  else
  {
    ftextout("Battery  :", 0,5,1,0);
    ftextout("Ignition :", 0,45,1,0);
  }
  INPAapiJob("UTILITY","STATUS_UBATT","","");
  INP1apiResultInt(fehlerflag,wert,"STAT_UBATT",1);
  if ((fehlerflag!=TRUE) || (wert==0))
  {
    batterie=FALSE;
    zuendung=FALSE;
  }
  else 
  {
    batterie=TRUE;
    INPAapiJob("UTILITY","STATUS_ZUENDUNG","","");
    INP1apiResultInt(fehlerflag,wert,"STAT_ZUENDUNG",1);
    if ((fehlerflag!=TRUE) || (wert==0))
      zuendung=FALSE;
    else
      zuendung=TRUE;
  }

  digitalout(batterie, 0,20,"","");
  if (batterie==TRUE)
    if (sprache=="deutsch") ftextout("ein  ", 0,25,1,0);
    else                    ftextout("on   ", 0,25,1,0);
  else
    if (sprache=="deutsch") ftextout("aus  ", 0,25,1,0);
    else                    ftextout("off  ", 0,25,1,0);
  
  digitalout(zuendung, 0,62,"","");
  if (zuendung==TRUE)
    if (sprache=="deutsch") ftextout("ein  ", 0,67,1,0);
    else                    ftextout("on   ", 0,67,1,0);
  else
    if (sprache=="deutsch") ftextout("aus  ", 0,67,1,0);
    else                    ftextout("off  ", 0,67,1,0);
}

//**********************************************************************
//*
//* EldiAuftragLesen
//*
//* Ausgabe der Fahrgestellnummer bei gültigem ELDI-Auftrag
//* in einer userbox rechts oben
//*
//**********************************************************************
EldiAuftragLesen(in: string sprache)
{
  string FG_NR;
  string MOTOR_NR;

  // Box-Nummer 7 reserviert
  DTMGetVarWert(FG_NR,"FG_NR");
  DTMGetVarWert(MOTOR_NR,"MOTOR_NR");
  userboxclose(7);
  if (FG_NR != "")
  {
    userboxopen(7,0,71,2,25,"","");
    userboxsetcolor(7,1,10); // schwarz, grün
    if (sprache=="deutsch")
    {
      userboxftextout(7," FG-Nr.: "+FG_NR,0,0,0,1);
      userboxftextout(7," Motor : "+MOTOR_NR,1,0,0,1);
    }
    else
    {
      userboxftextout(7," VIN   : "+FG_NR,0,0,0,1);
      userboxftextout(7," Engine: "+MOTOR_NR,1,0,0,1);
    }
  }
  else
  {
    userboxopen(7,0,71,1,25,"","");
    userboxsetcolor(7,0, 4); // weiß, rot
    if (sprache=="deutsch")
      userboxftextout(7," ohne ELDI-Auftrag",0,0,0,1);                 
    else
      userboxftextout(7," no ELDI order",0,0,0,1);                 
  }
}

//**********************************************************************
//*
//* EldiAuftragEingeben
//*
//**********************************************************************
EldiAuftragEingeben(in: string sprache)
{
  int    EldiResultCode;

  userboxclose(7);
  ELDIOpenStartDialog("PZ=NEIN ZD=NEIN",EldiResultCode);
  
  EldiAuftragLesen(sprache);
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
