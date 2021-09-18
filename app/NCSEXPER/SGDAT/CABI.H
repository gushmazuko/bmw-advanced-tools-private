// $Header:   \\Sfiler\AEC_BMW_LateCfg\WinKFP32\B 11 Konfigurationmanagement\PVCS\sgdat\Cabi.h_v   1.3   Aug 12 2004 14:40:54   mw  $ 
//*************************************************************
// FIRMA   Softing GmbH   Dingolfinger Str. 2   81673 Muenchen
//         Softing GmbH   Richard-Reitzner-Allee 6   85540 Haar
//*************************************************************
//
// MODULNAME          C A B I . H
//
// COMPILER           CABI
//
// AUTOR              M. Steiniger / N. Leipold
//
// BESCHREIBUNG       CABI-Includedatei fuer  
//                    Codierdatenhandlerfunktionen (CDH) 
//
// ENTWICKLUNGSSTAND
//    V1.0  12.03.1996  Stei  Ersterstellung:
//                            Uebernahme von inpa.h und inpacdh.h
//    V1.1  24.04.1996  Stei  Stand Cabitest V1.0.0
//    V1.2  04.09.1996  Stei  CDHGetNettoMaskFromCbd integriert
//    V1.3  15.10.1996  Stei  CDHCheckIdent integriert
//    V1.4  01.08.1997  Kn    CDHGetApiJobByteData, CDHSetCabdWordPar,
//                            CDHGetCabdWordPar integriert
//    V1.5  15.10.1997  Sa    neue Funktionen fuer Winkfpt
//    V1.6  18.05.2000  Po    CDHCallAuthenticate integriert. 
//    V1.7  29.06.2000  Po    CDHCallAuthenticate Uebergabe-Parameter sind geaendert
//    V1.8  27.07.2000  Le    Merge mit dascod-Version: Erweiterung um CDHSetDataOrg()
//    V1.9  29.09.2000  Le    Erweiterung um SGVT und FA (Merge mit NCS-Expertentool),
//                            PVCS-Log integriert,
//                            fuer COAPI-Lib 3.0.0 und IPO-Format 1.2.0
//    V2.0  29.09.2000  Le    PVCS-Log wieder entfernt, da Probleme mit Kommentarzeichen,
//                            Abgleich mit COAPI.H/COAPIKF.H
//
//**************************************************************
//
// KEIN Log !!!
//
// *************************************************************
// COAPI - FEHLERNUMMERN 
// 
// ACHTUNG: Nummern nicht aendern. 
//          Werden auch in CDH, CABD und SGBD verwendet !!!
//
// Als absolute Referenz sind die Dateien COAPI.H und COAPIKF.H
// zu verwenden, d.h. CABI.H und CDH.H sind Untermengen dieser
// beiden Dateien.
//
// *************************************************************

// 1000..1499: Kernfunktionen, CDH- und CABD-Fehler ************

// 1000..1019: Allgemeine Fehler
int  COAPI_ERROR                    = 1000;  // Default Error
int  COAPI_INVALID_HANDLE           = 1001;  // Invalid Handle z.B. bei CDHBinBuf
int  COAPI_MEM_ERROR                = 1002;  // Memory-Allocation Error
int  COAPI_PAR_ERROR                = 1003;  // Aufrufparameter einer coapi-Funktion fehlerhaft

// 1020..1039: Dateifehler
int  COAPI_INPUT_FILE_NOT_FOUND     = 1020;  // Inputdatei kann nicht zum Lesen geoeffnet werden
int  COAPI_OUTPUT_FILE_NOT_FOUND    = 1021;  // Outputdatei kann nicht zum Schreiben geoeffnet werden
int  COAPI_READ_INPUT_FILE_ERROR    = 1022;  // Fehler beim Einlesen einer Datei 
int  COAPI_WRITE_OUTPUT_FILE_ERROR  = 1023;  // Fehler beim Schreiben in eine Datei 

// 1040..1059: Dateiverarbeitungsfehler (Syntaxfehler)
int  COAPI_FILE_ERROR               = 1040;  // Fehler in Dateiverarbeitung (Allgemein)
int  COAPI_ZST_FILE_ERROR           = 1041;  // Fehler in ZST-Datei Verarbeitung
int  COAPI_CVT_FILE_ERROR           = 1042;  // Fehler in CVT-Datei Verarbeitung
int  COAPI_CBD_FILE_ERROR           = 1043;  // Fehler in CBD-Datei Verarbeitung
int  COAPI_SGET_FILE_ERROR          = 1044;  // Fehler in SGET-Datei Verarbeitung
int  COAPI_SWT_FILE_ERROR           = 1045;  // Fehler in SWT-Datei Verarbeitung
int  COAPI_ZCSUT_FILE_ERROR         = 1046;  // Fehler in ZCSUT-Datei Verarbeitung
int  COAPI_VMGEN_ERROR              = 1047;  // Fehler bei VM-Programmgenerierung

// 1060..1079: CABD-Dateiverarbeitungsfehler (Syntaxfehler)

int  COAPI_CABD_ERROR               = 1060;  // Fehler beim Einlesen, Syntaxpruefung eines CABD-Skripts 
int  COAPI_CABD_INIT_ERROR          = 1061;  // CABI wurde nicht initialisiert 
int  COAPI_CABD_RESULT_ERROR        = 1062;  // CABD-Resultfehler (CABD-Ergebnisparameter)
int  COAPI_CABD_PAR_ERROR           = 1063;  // CABD-Parameterfehler (CABD-Auftragsparameter)
int  COAPI_CABD_JOB_ERROR           = 1064;  // Interner Fehler im CABD-Job entdeckt
 
// 1080..1099: Codierschluessel- und Fahrgestellnummernfehler
int  COAPI_ZCS_ERROR                = 1080;  // ZCS fehlerhaft
int  COAPI_GM_KEY_ERROR             = 1081;  // GM-Schluessel fehlerhaft
int  COAPI_SA_KEY_ERROR             = 1082;  // SA-Schluessel fehlerhaft
int  COAPI_VN_KEY_ERROR             = 1083;  // VN-Schluessel fehlerhaft
int  COAPI_AM_KEY_ERROR             = 1084;  // AM-Schluessel fehlerhaft
int  COAPI_FG_KEY_ERROR             = 1085;  // FGNR fehlerhaft
int  COAPI_BR_ERROR                 = 1086;  // Baureihenbezeichnung fehlerhaft

// 1100..1119: 
int  COAPI_SG_NOT_IN_SGET           = 1100;  // Kein Auftrag: Das SG ist nicht in der SG-Ermittlung enthalten

// 1120..1139: 
int  COAPI_DATA_USED_ERROR          = 1120;  // Codierdaten wurden nicht benutzt


// 2000..2499: EDIABAS und SG spezifische Fehler

// 2000..2019: EDIABAS und SGBD-Aufruf-/Ergebnisfehler
int  COAPI_DIABAS_ERROR             = 2000;  // Fehler im DIABAS oder SG-Beschreibungsdatei
int  COAPI_DIABAS_INIT_ERROR        = 2001;  // DIABAS wurde nicht initialisiert (apiInit)
int  COAPI_DIABAS_RESULT_ERROR      = 2002;  // DIABAS-Resultfehler
int  COAPI_DIABAS_PAR_ERROR         = 2003;  // DIABAS-Parameterfehler (SGBD-Parameter)
int  COAPI_DIABAS_BINBUF_ERROR      = 2004;  // DIABAS-Parameterfehler, speziell Binaerbuffer
int  COAPI_DIABAS_JOB_ERROR         = 2005;  // Interner Fehler im SGBD-Job entdeckt

// 2020..2039: SG-Kommunikationsfehler
int  COAPI_ECU_TIMEOUT              = 2020;  // SG antwortet nicht
int  COAPI_ECU_TRANSMISSION_ERROR   = 2021;  // Datenuebertragung zum SG gestoert
int  COAPI_ECU_UBATT_ERROR          = 2022;  // Batteriespannung zu niedrig oder nicht vorhanden
int  COAPI_ECU_TEL_ERROR            = 2023;  // Fehlerhaftes Antworttelegramm 
int  COAPI_ECU_READ_BAUDRATE_ERROR  = 2024;  // Fehler bei Baudrate lesen 
int  COAPI_ECU_DELETE_DTC_ERROR     = 2025;  // Fehler bei FS loeschen 

// 2040..2059: SG-Identifikationsfehler
int  COAPI_ECU_ID_ERROR             = 2040;  // Falsche SG-Identifikation (allgemein)
int  COAPI_ECU_CDNR_ERROR           = 2041;  // Falscher SG-Codierindex
int  COAPI_ECU_HWNR_ERROR           = 2042;  // Falsche SG-Hardwarenummer
int  COAPI_ECU_SWNR_ERROR           = 2043;  // Falsche SG-Softwarenummer

// 2060..2079: Codierfehler
int  COAPI_ECU_CODING_ERROR         = 2060;  // Codierung fehlerhaft (allgemein)
int  COAPI_ECU_WRITE_DATA_ERROR     = 2061;  // Fehler beim Codierdaten schreiben
int  COAPI_ECU_READ_DATA_ERROR      = 2062;  // Fehler beim Codierdaten lesen
int  COAPI_ECU_COMPARE_DATA_ERROR   = 2063;  // Fehler beim Codierdaten vergleichen/verifizieren
int  COAPI_ECU_DELETE_DATA_ERROR    = 2064;  // Fehler beim Codierdaten loeschen (z.B. ZCS)
int  COAPI_ECU_CHECKSUM_ERROR       = 2065;  // SG-Checksummenfehler

// 2080..2099: Programmierfehler im Rahmen E65 ( TI435, Herr Drexel )
//int  COAPI_ECU_PROG_STATUS_ERROR             = 2080;  // Programmierstatus fehlerhaft
//int  COAPI_ECU_AUTHENTICATION_ERROR          = 2081;  // Authentisierungfehlerhaft
//int  COAPI_ECU_FLASH_ERASE_ERROR             = 2082;  // Flash löschen fehlerhaft
//int  COAPI_ECU_FLASH_REQUEST_DOWNLOAD_ERROR  = 2083;  // Flash Download vorbereiten fehlerhaft
//int  COAPI_ECU_FLASH_DOWNLOAD_ERROR          = 2084;  // Flash Download fehlerhaft
//int  COAPI_ECU_FLASH_TRANSFER_EXIT_ERROR     = 2085;  // Flash Download abschliessen fehlerhaft
//int  COAPI_ECU_SIGNATUR_ERROR                = 2086;  // Signaturpruefung fehlerhaft
//int  COAPI_ECU_READ_AIF                      = 2087;  // AIF lesen fehlerhaft
//int  COAPI_ECU_WRITE_AIF                     = 2088;  // AIF schreiben fehlerhaft
//int  COAPI_ECU_PROGRAMMING_MODE_ERROR        = 2089;  // Programmiermode umschalten fehlerhaft
//int  COAPI_ECU_AUTHENTICATION_FORMAT_ERROR   = 2090;  // Authentisierung Formatfehler
//int  COAPI_PROCESSOR_TYPE_ERROR              = 2099;  // Prozessortyp fehlerhaft


// 3000..3049: COAPIKF spezielle Fehler
int  COAPIKF_ZB_NOT_FOUND                    = 3000;  // Zusammenbaunummer in ZB-Vorschrift nicht gefunden
int  COAPI_ECU_CODING_ERROR_FL_LOESCHEN      = 3001;  // Codierung fehlerhaft (allgemein) bei Flash loeschen
int  COAPI_ECU_DELETE_DATA_ERROR_FL_LOESCHEN = 3002;  // Fehler beim Codierdaten loeschen (FLASH)
int  COAPI_ECU_UBATT_ERROR_FL_LOESCHEN       = 3003;  // Fehler UBatt (Flash loeschen)
int  COAPI_EWS_DME_ISN_ERROR                 = 3004;  // 
int  COAPI_DME_ISN_ERROR                     = 3005;  // 
int  COAPI_UNTERSCHIEDLICHE_STARTWERTE       = 3006;  // 
int  COAPI_EWS_SS_ERROR                      = 3007;  // 
int  COAPI_HANDSCHALTER_ERROR                = 3008;  // 


//**************************************************************
//* Allgemeine Funktionen
//**************************************************************

//////////////////////////////////
// Systemfunktionen
//////////////////////////////////
extern settimer( in: int timernum, in: int timeval );
extern testtimer( in: int timernum, out: bool expiredflag );

extern exit( );


//////////////////////////////////
// Konvertierfunktionen
//////////////////////////////////
extern realtostring( in: real r, in: string format, out: string s);
extern inttostring( in: int i, out: string s);
extern hexconvert( in: string HexString,
                   out: int high, out: int mid, out: int low, out: int seg);


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
// Dateizugriffsfunktionen
//////////////////////////////////
extern fileopen( in: string FileName, in: string OpenMode);
extern fileclose( );
extern filewrite( in: string str);
extern fileread( out: string str,
                 out: bool DateiEnde);


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

/// EDIABAS-Aufrufe mit CDH-Fehlerbehandlung
extern CDHapiInit( );
extern CDHapiEnd( );
extern CDHapiJob( in: string ecu, in: string job,
                  in: string para, in: string result );
extern CDHapiJobData( in: string ecu, in: string job,
                      in: int BufHandle, in: int BufSize, in: string result );
extern CDHapiResultText( out: string ResultText,
                         in: string ApiResult,
                         in: int ApiSet,
                         in: string ApiFormat );
extern CDHapiResultDigital( out: bool ResultVal,
                            in: string ApiResult,
                            in: int ApiSet );
extern CDHapiResultInt( out: int ResultVal,
                        in: string ApiResult,
                        in: int ApiSet );
extern CDHapiResultSets( out: int sets );
extern CDHapiResultAnalog( out: real ResultVal,
                           in: string ApiResult,
                           in: int ApiSet );
extern CDHapiResultBinary( in:  int BufHandle, in:  string ApiResult, 
                           in:  int ApiSet,    out: int RetVal );
extern CDHapiCheckJobStatus( in: string RefStr );

extern CDHDelay( in: int d );

/// 1:1 - Anbindung (ohne Fehlerbehandlung)
extern apiInit( out: bool rc );
extern apiEnd( );
extern apiJob( in: string ecu, in: string job,
               in: string para, in: string result );
extern apiState( out: int ApiState );
extern apiResultText( out: bool rc,
                      out: string ResultText,
                      in: string ApiResult,
                      in: int ApiSet,
                      in: string ApiFormat );
extern apiResultInt( out: bool rc,
                     out: int ResultVal,
                     in: string ApiResult,
                     in: int ApiSet );
extern apiResultSets( out: bool rc,
                      out: int sets );
extern apiResultReal( out: bool rc,
                      out: real ResultVal,
                      in: string ApiResult,
                      in: int ApiSet );
extern apiErrorCode( out: int ErrorCode );
extern apiErrorText( out: string ErrorText );


/// Zugriffsfunktion auf Binärdatenpuffer
extern GetBinaryDataString( out: string DataString, out: int DataStringLen );


//////////////////////////////////
// Stringarray - Funktionen
//////////////////////////////////
extern StrArrayCreate( out: bool rc, out: int hStrArray );
extern StrArrayDestroy( in: int hStrArray );
extern StrArrayWrite( in: int hStrArray, in: int index, in: string str );
extern StrArrayRead( in: int hStrArray, in: int index, out: string str );
extern StrArrayGetElementCount( in: int hStrArray, out: int ElementCount );
extern StrArrayDelete( in: int hStrArray );



//**************************************************************
//* Codierdatenhandlerfunktionen
//**************************************************************

// Basisfunktion zum Initialisieren der Variablen 
// extern CDHInit( ); => ueber CDHGetFswPswFromZcs


// Basisfunktionen zum Setzen von Variablen und Einlesen der ZST, CVT           
extern CDHSetReturnVal( in: int Wert );
extern CDHGetFswPswFromZcs( in: string Gm, in: string Sa, in: string Vn, out: int RetVal );
extern CDHSetSystemData( in: string Bezeichner, in:  string Wert, out: int RetVal );
extern CDHGetSystemData( in: string Bezeichner, out: string Wert, out: int RetVal );
extern CDHGetFswPswFromCvt( out: int RetVal );


// Funktionen zum Austausch von Parametern zwischen CABD und CDH 
extern CDHSetCabdPar( in: string Bezeichner, in:  string Wert, out: int RetVal );
extern CDHGetCabdPar( in: string Bezeichner, out: string Wert, out: int RetVal );
extern CDHSetCabdWordPar( in: string Bezeichner, in:  int Wert, out: int RetVal );
extern CDHGetCabdWordPar( in: string Bezeichner, out: int Wert, out: int RetVal );


// Funktionen zur SG-Ermittlung 
extern CDHReadSget( out: string SgList, out: int RetVal );
extern CDHSetSgName( in: string SgName, out: int RetVal );
extern CDHGetSgbdName( out: string SgbdName, out: int RetVal );


// Funktionen zur Baureihen-Ermittlung 
extern CDHGetBaureiheFromZcs( in:  string Gm, in: string Sa, in: string Vn, 
                              out: string Baureihe, out: int RetVal );


// Funktionen zur Aenderung von Funktions- und Parameterschluesselwoertern 
extern CDHActivateFsw( in: string Fsw, out: int RetVal );
extern CDHInactivateFsw( in: string Fsw, out: int RetVal );
extern CDHActivateGrp( in: string Gruppe, out: int RetVal );
extern CDHInactivateGrp( in: string Gruppe, out: int RetVal );
extern CDHActivateAllFsw( );
extern CDHInactivateAllFsw( );

extern CDHChangePsw( in: string Fsw, in: string Psw, out: int RetVal );

extern CDHSaveFswPswList( out: int RetVal );
extern CDHRestoreFswPswList( out: int RetVal );


// Funktionen zur Ermittlung der Nettodaten und Info's aus der CBD 
extern CDHSetCbdName( in: string CbdName );
extern CDHGetInfo( in: string Bezeichner, in: int InfoNr, 
                   out: string Info, out: int NrOfInfo, out: int RetVal );
extern CDHCheckIdent( in: string Bezeichner, in: string Id1, in: string Id2,
                      out: int RetVal );

extern CDHGetFswDataFromCbd( in: string Fsw, out: int RetVal );
extern CDHGetFswPswDataFromCbd( in: string Fsw, in: string Psw, out: int RetVal );
extern CDHGetGrpDataFromCbd( in: string Gruppe, out: int RetVal );
extern CDHGetNettoDataFromCbd( out: int RetVal );
extern CDHGetNettoMaskFromCbd( out: int RetVal );


// Funktionen zur Rueckkonvertierung
extern CDHGetFswPswFromNettoData( in:  string OutFileName, out: int RetVal );


// CDHDATA und CDHDIABAS Funktionen 
extern CDHResetApiJobData( );
extern CDHGetApiJobData( in:  int  MaxData,  in: int BufHandle, out: int BufSize,
                         out: int NrOfData, out: int DataType,  out: int RetVal );
extern CDHCheckDataUsed( out: int RetVal );
extern CDHBinBufToNettoData( in: int BufHandle, out: int RetVal );
extern CDHGetApiJobByteData( in:  int  MaxData,  in: int BufHandle, out: int BufSize,
                             out: int NrOfData, out: int RetVal );


// Binaerbuffer-Funktionen 
extern CDHBinBufCreate( out: int BufHandle, out: int RetVal );
extern CDHBinBufDelete( in:  int BufHandle, out: int RetVal );

extern CDHBinBufWriteByte( in:  int BufHandle, in:  int ByteVal, 
                           in:  int Position,  out: int RetVal );
extern CDHBinBufWriteWord( in:  int BufHandle, in:  int WordVal, 
                           in:  int Position,  out: int RetVal );
extern CDHBinBufReadByte( in:  int BufHandle, out: int ByteVal, 
                          in:  int Position,  out: int RetVal );
extern CDHBinBufReadWord( in:  int BufHandle, out: int WordVal, 
                          in:  int Position,  out: int RetVal );

extern CDHBinBufToStr( in: int BufHandle, out: string BinBufStr, out: int RetVal );

extern CDHBinBufAppend( in: int SrcBufHandle, in: int DestBufHandle, 
                        in: int SrcPosition , in: int NrOfBytes, out: int RetVal );

extern CDHBinBufCopy( in: int SrcBufHandle, in: int DestBufHandle, 
                      in: int SrcPosition , in: int DestPosition,
					  in: int NrOfBytes,   out: int RetVal );


// Authentisierung
extern CDHCallAuthenticate( in: string SgFamilie,
             in: string UserId, in: string StgId, in: string Type,
                            in: int SgrndHdl, in: string Level,
                            in: int ResponseHdl,
             out: int ResponseLen, out: int RetVal );

extern CDHAuthGetRandom( out: string RndBin, out: string RndAsc );


// Fehlerfunktionen
extern CDHResetError( );
extern CDHSetError( in: int ErrNr, in: string ModulName, in: string ProcName, in: int LineNr,
                    in: string ErrorInfo );
extern CDHTestError( out: int ErrNr );


// Flashprogrammierung
extern CDHSetDataOrg( in: int WortBreite, in: int ByteFolge, in: int AdrMode, out: int RetVal);


//"SGVT"-Verarbeitung
extern CDHIdReady( out: bool IdReady);

//FA-Codierung
extern CDHGetFaVersion( out: string Version, out: int RetVal );
extern CDHGetAnzahlFaElemente( out: int Anzahl );
extern CDHGetFaElement( in: string Typ, in: bool FirstElement, out: string Element );
extern CDHCheckIdent2( in: string Bezeichner, in: int Id1, out: int RetVal );

//**********************************************************************
// END OF MODUL ********************************************************
//**********************************************************************
