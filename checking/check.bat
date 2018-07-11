@echo off
:loop
3373data > data.txt
3373a < data.txt > 1.txt
3373b < data.txt > 2.txt
fc 1.txt 2.txt
if errorlevel 1 pause
goto loop