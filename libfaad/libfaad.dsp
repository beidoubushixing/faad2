# Microsoft Developer Studio Project File - Name="libfaad" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=libfaad - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "libfaad.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "libfaad.mak" CFG="libfaad - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "libfaad - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "libfaad - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=xicl6.exe
RSC=rc.exe

!IF  "$(CFG)" == "libfaad - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /G6 /W3 /GX /O2 /I "fftw" /D "NDEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "FFTW_ENABLE_FLOAT" /YX /FD /c
# ADD BASE RSC /l 0x413 /d "NDEBUG"
# ADD RSC /l 0x413 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=xilink6.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "libfaad - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "fftw" /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "FFTW_ENABLE_FLOAT" /YX /FD /GZ /c
# ADD BASE RSC /l 0x413 /d "_DEBUG"
# ADD RSC /l 0x413 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=xilink6.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "libfaad - Win32 Release"
# Name "libfaad - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "codebook"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\codebook\hcb_1.c
# End Source File
# Begin Source File

SOURCE=.\codebook\hcb_10.c
# End Source File
# Begin Source File

SOURCE=.\codebook\hcb_11.c
# End Source File
# Begin Source File

SOURCE=.\codebook\hcb_2.c
# End Source File
# Begin Source File

SOURCE=.\codebook\hcb_3.c
# End Source File
# Begin Source File

SOURCE=.\codebook\hcb_4.c
# End Source File
# Begin Source File

SOURCE=.\codebook\hcb_5.c
# End Source File
# Begin Source File

SOURCE=.\codebook\hcb_6.c
# End Source File
# Begin Source File

SOURCE=.\codebook\hcb_7.c
# End Source File
# Begin Source File

SOURCE=.\codebook\hcb_8.c
# End Source File
# Begin Source File

SOURCE=.\codebook\hcb_9.c
# End Source File
# Begin Source File

SOURCE=.\codebook\hcb_sf.c
# End Source File
# End Group
# Begin Group "fftw"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\fftw\config.c
# End Source File
# Begin Source File

SOURCE=.\fftw\executor.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fftwf77.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fftwnd.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fn_1.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fn_10.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fn_11.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fn_12.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fn_13.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fn_14.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fn_15.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fn_16.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fn_2.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fn_3.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fn_32.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fn_4.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fn_5.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fn_6.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fn_64.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fn_7.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fn_8.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fn_9.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fni_1.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fni_10.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fni_11.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fni_12.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fni_13.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fni_14.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fni_15.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fni_16.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fni_2.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fni_3.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fni_32.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fni_4.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fni_5.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fni_6.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fni_64.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fni_7.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fni_8.c
# End Source File
# Begin Source File

SOURCE=.\fftw\fni_9.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftw_10.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftw_16.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftw_2.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftw_3.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftw_32.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftw_4.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftw_5.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftw_6.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftw_64.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftw_7.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftw_8.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftw_9.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftwi_10.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftwi_16.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftwi_2.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftwi_3.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftwi_32.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftwi_4.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftwi_5.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftwi_6.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftwi_64.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftwi_7.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftwi_8.c
# End Source File
# Begin Source File

SOURCE=.\fftw\ftwi_9.c
# End Source File
# Begin Source File

SOURCE=.\fftw\generic.c
# End Source File
# Begin Source File

SOURCE=.\fftw\malloc.c
# End Source File
# Begin Source File

SOURCE=.\fftw\planner.c
# End Source File
# Begin Source File

SOURCE=.\fftw\putils.c
# End Source File
# Begin Source File

SOURCE=.\fftw\rader.c
# End Source File
# Begin Source File

SOURCE=.\fftw\timer.c
# End Source File
# Begin Source File

SOURCE=.\fftw\twiddle.c
# End Source File
# Begin Source File

SOURCE=.\fftw\wisdom.c
# End Source File
# Begin Source File

SOURCE=.\fftw\wisdomio.c
# End Source File
# End Group
# Begin Source File

SOURCE=.\bits.c
# End Source File
# Begin Source File

SOURCE=.\common.c
# End Source File
# Begin Source File

SOURCE=.\data.c
# End Source File
# Begin Source File

SOURCE=.\decoder.c
# End Source File
# Begin Source File

SOURCE=.\drc.c
# End Source File
# Begin Source File

SOURCE=.\error.c
# End Source File
# Begin Source File

SOURCE=.\filtbank.c
# End Source File
# Begin Source File

SOURCE=.\ic_predict.c
# End Source File
# Begin Source File

SOURCE=.\is.c
# End Source File
# Begin Source File

SOURCE=.\lt_predict.c
# End Source File
# Begin Source File

SOURCE=.\mdct.c
# End Source File
# Begin Source File

SOURCE=.\mp4.c
# End Source File
# Begin Source File

SOURCE=.\ms.c
# End Source File
# Begin Source File

SOURCE=.\output.c
# End Source File
# Begin Source File

SOURCE=.\pns.c
# End Source File
# Begin Source File

SOURCE=.\pulse.c
# End Source File
# Begin Source File

SOURCE=.\reordered_spectral_data.c
# End Source File
# Begin Source File

SOURCE=.\sbr_dec.c
# End Source File
# Begin Source File

SOURCE=.\sbr_huff.c
# End Source File
# Begin Source File

SOURCE=.\sbr_qmf.c
# End Source File
# Begin Source File

SOURCE=.\sbr_syntax.c
# End Source File
# Begin Source File

SOURCE=.\specrec.c
# End Source File
# Begin Source File

SOURCE=.\syntax.c
# End Source File
# Begin Source File

SOURCE=.\tns.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\analysis.h
# End Source File
# Begin Source File

SOURCE=.\bits.h
# End Source File
# Begin Source File

SOURCE=.\common.h
# End Source File
# Begin Source File

SOURCE=.\fftw\config.h
# End Source File
# Begin Source File

SOURCE=.\data.h
# End Source File
# Begin Source File

SOURCE=.\decoder.h
# End Source File
# Begin Source File

SOURCE=.\drc.h
# End Source File
# Begin Source File

SOURCE=.\error.h
# End Source File
# Begin Source File

SOURCE=.\fftw\f77_func.h
# End Source File
# Begin Source File

SOURCE=".\fftw\fftw-int.h"
# End Source File
# Begin Source File

SOURCE=.\fftw\fftw.h
# End Source File
# Begin Source File

SOURCE=.\filtbank.h
# End Source File
# Begin Source File

SOURCE=.\codebook\hcb.h
# End Source File
# Begin Source File

SOURCE=.\huffman.h
# End Source File
# Begin Source File

SOURCE=.\ic_predict.h
# End Source File
# Begin Source File

SOURCE=.\is.h
# End Source File
# Begin Source File

SOURCE=.\kbd_win.h
# End Source File
# Begin Source File

SOURCE=.\lt_predict.h
# End Source File
# Begin Source File

SOURCE=.\mdct.h
# End Source File
# Begin Source File

SOURCE=.\mp4.h
# End Source File
# Begin Source File

SOURCE=.\ms.h
# End Source File
# Begin Source File

SOURCE=.\output.h
# End Source File
# Begin Source File

SOURCE=.\pns.h
# End Source File
# Begin Source File

SOURCE=.\pulse.h
# End Source File
# Begin Source File

SOURCE=.\sbr_dec.h
# End Source File
# Begin Source File

SOURCE=.\sbr_huff.h
# End Source File
# Begin Source File

SOURCE=.\sbr_qmf.h
# End Source File
# Begin Source File

SOURCE=.\sbr_syntax.h
# End Source File
# Begin Source File

SOURCE=.\specrec.h
# End Source File
# Begin Source File

SOURCE=.\syntax.h
# End Source File
# Begin Source File

SOURCE=.\tns.h
# End Source File
# End Group
# End Target
# End Project
