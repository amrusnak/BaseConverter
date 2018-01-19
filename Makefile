GPP = g++ -O3 -Wall -std=c++11

OBJ = base_converter.o
SRC = base_converter.cc
HDR = base_converter.h

$(PRG) : $(OBJ)
	$(GPP) -o $(OBJ) -c $(SRC)	
$(OBJ): $(HDR) $(SRC)
	$(GPP) -o $(OBJ) -c $(SRC)

clean: 
	rm $(OBJ)
