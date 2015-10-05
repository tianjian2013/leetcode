CPPFLAGS= -g -I../headers
VPATH=../headers
OBJ=LargestNumber.o\
    help.o
SOURCE=$(patsubst %.o,%.cpp,$(OBJ))


main: $(OBJ)
	$(CXX) $(CPPFLAGS) $^ -o $@
$(OBJ) : $(SOURCE) 
	g++ $(CPPFLAGS)  -c $^ 
 
clean:
	rm main $(OBJ)
 
