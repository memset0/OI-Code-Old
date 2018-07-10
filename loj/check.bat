@echo off
:loop
"6277 数列分块入门 1 - DATA.exe" > data.txt
"6277 数列分块入门 1.exe" < data.txt > out1.txt
"6277 数列分块入门 1 - STD.exe" < data.txt > out2.txt
fc out1.txt out2.txt
if errorlevel 1 (
	echo WRONG
	pause
) else echo PASS
goto loop