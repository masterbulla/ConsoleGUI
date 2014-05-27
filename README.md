ConsoleGUI
==========

Make an application as GUI and console mode

Steps:
a. Build as GUI application
b. Call editbin.exe to modify the application's subsystem setting
   Add the following command to Post-build event - 
   "C:\Program Files (x86)\Microsoft Visual Studio 9.0\VC\bin\amd64\editbin.exe" /subsystem:console $(TargetPath)
