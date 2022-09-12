@ECHO OFF

SET sourceExtension=cpp
SET executableExtension=exe
SET sourceFileName=%1.%sourceExtension%
SET executableFileName=%1.%executableExtension%

g++ -o %1 %sourceFileName%
%executableFileName% < input.in > output.out
DEL %executableFileName%
