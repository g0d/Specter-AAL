:: Messages
@echo "************************************"
@echo "*           # Specter #            *"
@echo "*   Abstract Arithmetics Library   *"
@echo "*      Copyright (C) 2010-2025     *"
@echo "************************************"
@echo.
@echo "George Delaportas"
@echo "Copyright (C) 2010-2025"
@echo.
@echo "Installing..."

:: Compile
gcc -std=gnu99 -ansi -pedantic -O3 -Wno-int-conversion -c console.c aal.c specter.c benchmark.c

:: Link
gcc -W -o Specter console.o aal.o specter.o benchmark.o

:: Clean up
del *.o

:: Finalization
@echo "Done!"
