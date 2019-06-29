::
:: Deploys project and sources of the essentutils library to a given
:: directory. Will create a subdirectory for the library.
:: Example: > .\deploy_as_sources.bat C:\libs
::
@echo off

set outDir=%1
set thisDir=%~dp0

set src=%thisDir%..\..
set dest=%outDir%\essentutils

:: Deploy code.
mkdir %dest%
robocopy %src% %dest% *.h
robocopy %src% %dest% *.cpp

:: Deploy project.
set from=%src%\project\vs2019
set to=%dest%\project\vs2019
mkdir %to%
robocopy %from% %to% essentutils.vcxproj
robocopy %from% %to% essentutils.vcxproj.filters
