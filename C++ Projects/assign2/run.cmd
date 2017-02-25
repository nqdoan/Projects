cl /I "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\UnitTest\include" /I src src\*.cpp test\*.cpp /LD /Feassign2.dll /Zi /link /LIBPATH:"C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\UnitTest\lib" 
vstest.console.exe/Enablecodecoverage /Logger:trx /UseVsixExtensions:true assign2.dll
