::
:: Deploys binaries and headers of the essentutils library to a given
:: directory. Will create a subdirectory for the library.
:: Example: > .\deploy_as_binaries.bat C:\libs
::
@echo off

set outDir=%1
set thisDir=%~dp0

set inclSrc=%thisDir%..\..
set binSrc=%thisDir%
set inclDest=%outDir%\essentutils
set binDest=%outDir%\essentutils\bin

:: Deploy includes.
mkdir %inclDest%
robocopy %inclSrc% %inclDest% *.h

:: Deploy binaries.
set from="%binSrc%\Release DLL"
set to=%binDest%\x86\rel_dll
mkdir %to%
robocopy %from% %to% essentutils.dll
robocopy %from% %to% essentutils.lib
robocopy %from% %to% essentutils.pdb

set from="%binSrc%\Debug DLL"
set to=%binDest%\x86\dbg_dll
mkdir %to%
robocopy %from% %to% essentutils.dll
robocopy %from% %to% essentutils.lib
robocopy %from% %to% essentutils.pdb

set from="%binSrc%\Release Lib"
set to=%binDest%\x86\rel_lib
mkdir %to%
robocopy %from% %to% essentutils.lib
robocopy %from% %to% essentutils.pdb

set from="%binSrc%\Debug Lib"
set to=%binDest%\x86\dbg_lib
mkdir %to%
robocopy %from% %to% essentutils.lib
robocopy %from% %to% essentutils.pdb

set from="%binSrc%\x64\Release DLL"
set to=%binDest%\x64\rel_dll
mkdir %to%
robocopy %from% %to% essentutils.dll
robocopy %from% %to% essentutils.lib
robocopy %from% %to% essentutils.pdb

set from="%binSrc%\x64\Debug DLL"
set to=%binDest%\x64\dbg_dll
mkdir %to%
robocopy %from% %to% essentutils.dll
robocopy %from% %to% essentutils.lib
robocopy %from% %to% essentutils.pdb

set from="%binSrc%\x64\Release Lib"
set to=%binDest%\x64\rel_lib
mkdir %to%
robocopy %from% %to% essentutils.lib
robocopy %from% %to% essentutils.pdb

set from="%binSrc%\x64\Debug Lib"
set to=%binDest%\x64\dbg_lib
mkdir %to%
robocopy %from% %to% essentutils.lib
robocopy %from% %to% essentutils.pdb
