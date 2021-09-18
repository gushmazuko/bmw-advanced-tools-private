//////////////////////////////////////////////////////////////////////
///  I N P A  -  L I B R A R Y F U N K T I O N E N
//////////////////////////////////////////////////////////////////////

//////////////////////////////////
// Systemfunktionen
//////////////////////////////////

extern setmenu( in: MENU m);
extern setscreen( in: SCREEN s, in: bool FrequentFlag);
extern setmenutitle( in: string title);
extern settitle( in: string title);
extern setitem( in: int nr, in: string ItemName, in: bool mode);
extern setitemrepeat(in: int nr, in: bool enablefrequent);

extern setstate( in: STATE state);
extern setstatemachine( in: STATEMACHINE sm);
extern callstatemachine( in: STATEMACHINE sm);
extern returnstatemachine();

extern settimer( in: int timernum, in: int timeval);
extern testtimer( in: int timernum, out: bool expiredflag);

extern setjobstatus( in: int JobStatus);

extern exit();
extern exitwindows();
extern scriptselect( in: string ScriptSelectIniFile);
extern scriptchange( in: string NewScriptFile);

extern select( in: bool MultipleSelectFlag);
extern deselect();
extern control();
extern start();
extern stop();

extern getapistring( in: bool ArgNumFlag,
                     in: bool FullScreenFlag,out: string ApiString);
extern togglelist( in: bool MultipleSelectFlag, in: bool ArgNumFlag, out: string ApiToggleString);

extern printscreen();

extern printfile( out: int ErrorCode,
                  in: string FileName, 
                  in: string PrinterName,
                  in: string PrinterPort,
                  in: bool ErrorMsgFlag );

extern setcolor( in: int FgColor,
                 in: int BkColor);
extern delay( in: int Time);

extern getdate( out: string date);
extern gettime( out: string time);

//////////////////////////////////
// Konvertierfunktionen
//////////////////////////////////

extern realtostring( in: real r, in: string format, out: string s);
extern stringtoreal( in: string s, out: real r);
extern inttostring( in: int i, out: string s);
extern stringtoint( in: string s, out: int i);
extern hexconvert( in: string HexString,
                   out: int high, out: int mid, out: int low, out: int seg);
extern inttoreal( in: int i, out: real r);
extern realtoint( in: real r, out: int i);

extern bytetoint( in: byte b, out: int i);
extern inttolong( in: int i, out: long l);
extern longtoreal( in: long l, out: real r);

//////////////////////////////////
// Stringfunktionen
//////////////////////////////////

extern strcat( out: string DestStr,
               in: string SrcStr1, in: string SrcStr2);
extern strlen( out: int len,
               in: string str);
extern midstr( out: string ResultStr,
               in: string SrcStr,
               in: int FirstIndex,
               in: int Count);

//////////////////////////////////
// PEM - Libraryfunktionen
//////////////////////////////////
//
// Anmerkung: PEM-Funktionen nur aktiv bei WinEldi-Betrieb !!!

extern PEMInitialisiere (out: bool Result,
         in: string WinEldiVersion,
         in: string Pruefstand,
         in: string RechnerNr);

extern PEMProtokollKopf (out: bool Result,
         in: string Jobtabelle,
         in: string JAT_Version,
         in: string Datum,
         in: string Zeit,
         in: string FzgTyp,
         in: string FgNr);

extern PEMProtokollZeile (out: bool Result, in: string Zeile);

extern PEMSGZ_Kopfzeile(out: bool Result,
         in: string SGVar,
         in: string LogUnit,
         in: string ZeilenSG);

extern PEMTrennLinie(out: bool Result);

extern PEMEndLinie(out: bool Result);

extern PEMLoescheTabZeilenPuffer(out: bool Result);

extern PEMUebertrageTabZeilenPuffer(out: bool Result);

extern PEMProtokollAusgabe(out: bool Result);

extern PEMDruckeEtikett(out: bool Result,
         in: string Datum,
         in: string Zeit);

extern PEMPrintFormular( out: bool Result, 
                         in:  string FormularName);

extern PEMPrinter_ff(out: bool Result);

extern PEMFree_mem(out: bool Result);

extern PEMLoad_formular(out: bool Result,
         in: string FileName,
         in: string FormularName);

extern PEMDefault_druckfeld(out: bool Result,
         in: string DruckfeldName,
         in: string FormularName);

extern PEMDefault_besetzen(out: bool Result, in: string FormularName);

extern PEMForget_formular(out: bool Result, in: string FormularName);

extern PEMWrite_druckfeld(out: bool Result,
         in: string DruckfeldName,
         in: string FormularName,
         in: string instring);


//////////////////////////////////
// Eingabefunktionen
//////////////////////////////////

extern getinputstate( out: int InputState);
extern inputtext( out: string Text, in: string BoxTitle, in: string BoxText);
extern inputnum( out: real val, in: string BoxTitle, in: string BoxText,
                 in: real minval, in: real maxval);
extern inputint( out: int val, in: string BoxTitle, in: string BoxText,
                 in:  int minval, in: int maxval);
extern inputhex( out: string hexstr, in: string BoxTitle, in: string BoxText,
                 in: string MinHexStr, in: string MaxHexStr);
extern inputdigital( out: bool val, in: string BoxTitle, in: string BoxText,
                     in: string FalseStr, in: string TrueStr);

extern input2text( out: string str1, out: string str2,
                   in: string BoxTitle, in: string BoxText,
                   in: string BoxStr1, in: string BoxStr2);
extern input2hexnum( out: string hexstr, out: int num,
                     in: string BoxTitle, in: string BoxText,
                     in: string BoxStr1, in: string BoxStr2,
                     in: string MinHexStr, in: string MaxHexStr,
                     in: int minnum, in: int maxnum);
extern input2int( out: int val1, out: int val2,
                  in: string BoxTitle, in: string BoxText,
                  in: string BoxStr1, in: string BoxStr2,
                  in: int min1, in: int max1,
                  in: int min2, in: int max2);
extern input2hex( out: string hexstr1, out: string hexstr2,
                  in: string BoxTitle, in: string BoxText,
                  in: string BoxStr1, in: string BoxStr2,
                  in: string MinHexStr1, in: string MaxHexStr1,
                  in: string MinHexStr2, in: string MaxHexStr2 );

//////////////////////////////////
// Ausgabefunktionen
//////////////////////////////////

extern text( in: int row, in: int col, in: string text);
extern textout( in: string text, in: int row, in: int col);
extern ftextout( in: string text, in: int row, in: int col,
                 in: int textsize, in: int textattr );
extern digitalout( in: bool val,
                   in: int row, in: int col,
                   in: string TrueText, in: string FalseText);
extern analogout( in: real val,
                  in: int row, in: int col,
                  in: real min, in: real max,
                  in: real minvalid, in: real maxvalid,
                  in: string format);
extern multianalogout( in: real val,
                  in: int row, in: int col,
                  in: real min, in: real max,
                  in: real minvalid, in: real maxvalid,
                  in: string format,
                  in: int mode);

extern hexdump( in: string StartAdr, in: int numbytes,
                in: int row, in: int col);

extern ftextclear(  in: string text, in: int row, in: int col,
                    in: int textsize, in: int textattr );
extern clearrect(   in: int row, in: int col,
                    in: int height, in: int width);
extern blankscreen();
extern messagebox( in: string Title, in: string Text);
extern infobox( in: string Title, in: string Text);


//////////////////////////////////
// Dateizugriffsfunktionen
//////////////////////////////////

extern fileopen( in: string FileName, in: string OpenMode);
extern fileclose();
extern filewrite( in: string str);
extern fileread( out: string str, out: bool EOF);

//////////////////////////////////
// Userboxfunktionen
//////////////////////////////////

extern userboxopen( in: int BoxNum,
                    in: int row, in: int col,
                    in: int height, in: int width,
                    in: string TitleStr, in: string TextStr);
extern userboxclose( in: int BoxNum);
extern userboxftextout( in: int BoxNum, in: string text, 
                        in: int row, in: int col,
                        in: int textsize, in: int textattr );
extern userboxclear( in: int BoxNum);
extern userboxsetcolor( in: int BoxNum,
                        in: int FgColor,
                        in: int BkColor);


//////////////////////////////////
// Schnittstellenfunktionen
//////////////////////////////////

extern winhelp( in: string helpfile);
extern winhelpkey( in: string helpfile, in: string key);
extern callwin( in: string cmdline);


//////////////////////////////////
// Fileviewer - Funktionen
//////////////////////////////////

extern viewopen( in: string FileNameStr, in: string TitleStr);
extern viewclose();


//////////////////////////////////
// Simulationsfunktionen
//////////////////////////////////

extern simnum( out: real val, in: string BoxTitle, in: string BoxText,
               in: real minval, in: real maxval);
extern simdigital( out: bool val, in: string BoxTitle, in: string BoxText,
                   in: string FalseStr, in: string TrueStr);


//////////////////////////////////
// EDIABAS - Funktionen
//////////////////////////////////

/// INPA - Anbindung ///

extern INPAapiInit();
extern INPAapiEnd();
extern INPAapiJob( in: string ecu, in: string job,
                   in: string para, in: string result);
extern INPAapiResultText( out: string ResultText,
                          in: string ApiResult,
                          in: int ApiSet,
                          in: string ApiFormat);
extern INPAapiResultDigital( out: bool ResultVal,
                             in: string ApiResult,
                             in: int ApiSet );
extern INPAapiResultInt( out: int ResultVal,
                         in: string ApiResult,
                         in: int ApiSet );
extern INPAapiResultSets( out: int sets);
extern INPAapiResultAnalog( out: real ResultVal,
                            in: string ApiResult,
                            in: int ApiSet );
extern INPAapiResultBinary( in: string ApiResult, in: int ApiSet);
extern INPAapiCheckJobStatus( in: string RefStr);
extern INPAapiFsLesen( in: string ecu, in: string FileName);
extern INPAapiFsLesen2( in: string ecu, in: string FileName);
extern INPAapiFsMode(  in: int FsMode, in: string FsFileMode,
                       in: string PreInfoFile, in: string PostInfoFile,
                       in: string ApiFsJobName);



/// 1:1 - Anbindung ///

extern INP1apiInit( out: bool rc);
extern INP1apiEnd();
extern INP1apiJob( in: string ecu, in: string job,
                   in: string para, in: string result);
extern INP1apiState( out: int ApiState);
extern INP1apiResultText( out: bool rc,
                          out: string ResultText,
                          in: string ApiResult,
                          in: int ApiSet,
                          in: string ApiFormat);
extern INP1apiResultInt( out: bool rc,
                         out: int ResultVal,
                         in: string ApiResult,
                         in: int ApiSet );
extern INP1apiResultSets( out: bool rc,
                          out: int sets);
extern INP1apiResultReal( out: bool rc,
                          out: real ResultVal,
                          in: string ApiResult,
                          in: int ApiSet );
extern INP1apiResultBinary( out: bool rc,
                            in: string ApiResult,
                            in: int ApiSet);
extern INP1apiErrorCode( out: int ErrorCode);
extern INP1apiErrorText( out: string ErrorText);


/// Zugriffsfunktion auf Binärdatenpuffer

extern GetBinaryDataString( out: string DataString, out: int DataStringLen);



//////////////////////////////////
// DTM - Funktionen
//////////////////////////////////
//
// Anmerkung: DTM-Funktionen nur aktiv bei WinEldi-Betrieb !!!
//            Ab Version 5.0.0 nicht mehr unterstützt!

extern DTMFindLogUnit (out: bool rc,  in: string LogUnit);
extern DTMGetSGVar (out: string SGVar,  in: string SGArt);
extern DTMGetSGArt (out: string SGArt,  in: string SGVar);
extern DTMGetVarWert (out: string VarWert,  in: string VarName);
extern DTMSetupGetVarWert (out: string VarWert, in: string VarName);
extern DTMSetupGetStartPosition ();
extern DTMSetupGetNextAssoc ( out: bool rc, inout: string VarName, inout: string VarWert);
extern DTMLogUnitEintragen (in: string LogUnit);
extern DTMSGEintragen (in: string SGArt,  in: string SGVar);
extern DTMLoescheAuftrag ();
extern DTMVariableEintragen (in: string VarName, in: string VarWert);
extern DTMVariableLoeschen (out: bool rc,  in: string VarName);
extern DTMLoescheAlleVariablen ();
extern DTMSetupVariableEintragen (in: string VarName, in: string VarWert);
extern DTMSetupVariableLoeschen (out: bool rc,  in: string VarName);



//////////////////////////////////
// Stringarray - Funktionen
//////////////////////////////////

extern StrArrayCreate(out: bool rc, out: int hStrArray);
extern StrArrayDestroy( in: int hStrArray);
extern StrArrayWrite( in: int hStrArray, in: int index, in: string str);
extern StrArrayRead( in: int hStrArray, in: int index, out: string str);
extern StrArrayGetElementCount( in: int hStrArray, out: int ElementCount);
extern StrArrayDelete( in: int hStrArray);


//////////////////////////////////
// RK512 u. FAB - Funktionen
//////////////////////////////////
//
// Anmerkung: Ab Version 5.0.0 nicht mehr unterstützt!

extern SPSInit( out: int komstatus, in: string device, 
                in: string file, in: int count, in: int msgbox);
extern SPSEnd( out: int komstatus);
extern SPSLeseVonSPS( out: int komstatus, out: int spsstatus, 
                      out: int check, out: real vakuum1, out: real vakuum2);
extern SPSSendeAnSPS( out: int komstatus,  in: int fehler, in : int sg);
extern SPSLeseVakWerte( out: int komstatus, out: int check, 
                        out: real vakuum1, out: real vakuum2);
extern ApiJobFsLesenFAB   (out: int rc, in: string sgvar, out: int edifehler,
                           out: string jobstatus,out: int fehler, out: int saetze);
extern ApiResultFsLesenFAB(out: int rc, out: int ausgeblendet, in: int satz);

//////////////////////////////////
// WINELDI-Funktion(en)
//////////////////////////////////
//
// Anmerkung: Ab Version 5.0.0 nicht mehr unterstützt!

extern ELDIOpenStartDialog(in: string CommandParameter, out: int ResultCode);

//////////////////////////////////
// Struktur / Memory Funktionen
//////////////////////////////////

extern CreateStructure ( out: long handle, in: int length);
extern SetStructureMode( in:  int ReadWrite );

extern StructureByte ( in: long handle, in: int Offset, inout: byte value );
extern StructureInt  ( in: long handle, in: int Offset, inout: int  value );
extern StructureLong ( in: long handle, in: int Offset, inout: long value );
extern StructureString ( in: long handle, in: int Offset, in: int length, inout: string value );


