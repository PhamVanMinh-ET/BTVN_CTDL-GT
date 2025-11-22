@echo off
echo === Compiling... ===

g++ Source\*.cpp -I Header -o run.exe

if %errorlevel% neq 0 (
    echo ----------------------------------------
    echo LOI: Bien dich that bai!
    echo ----------------------------------------
    pause
    exit /b
)

echo ----------------------------------------
echo Bien dich thanh cong!
echo Dang chay chuong trinh...
echo ----------------------------------------

run.exe
pause
