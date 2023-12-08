CC=g++ #Name of compiler
FLAGS=-std=c++20 -w #Compiler flags (the s makes it silent)
TARGET=TestFunction #Executable name
OBJECTS=TestFunction.o FiniteFunctions.o CustomFunctions.o
LIBS=-I ../../GNUplot/ -lboost_iostreams

#First target in Makefile is default
${TARGET}:${OBJECTS} #Make target from objects
	@echo "Linking..."
	${CC} ${FLAGS} ${OBJECTS} ${LIBS} -o ${TARGET}
	@make clean

TestFunction.o : TestFunction.cxx FiniteFunctions.h
	${CC} ${FLAGS} ${LIBS} -c TestFunction.cxx

FiniteFunctions.o : FiniteFunctions.cxx FiniteFunctions.h
	${CC} ${FLAGS} ${LIBS} -c FiniteFunctions.cxx

CustomFunctions.o : CustomFunctions.cxx CustomFunctions.h
	${CC} ${FLAGS} ${LIBS} -c CustomFunctions.cxx

clean: #No targets just run shell command to rm object files and emacs backups
	@rm -f *.o *~

cleantarget: #Delete the exectuable
	@rm -f ${TARGET}
