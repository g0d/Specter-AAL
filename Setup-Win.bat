#Messages
echo "************************************"
echo "*            # Specter #           *"
echo "*   Abstract Arithmetics Library   *"
echo "*      Copyright © 2010-2023       *"
echo "************************************"
echo ""
echo "George Delaportas"
echo "Copyright (C) 2010-2023"
echo ""
echo "Installing..."

:: Compile
gcc -std=gnu99 -ansi -pedantic -O3 -c console.c aal.c benchmark.c

:: Link
gcc -W -o Specter console.o aal.o benchmark.o

:: Clean up
del *.o

:: Finalization
echo "Done!"
