CC=g++
CFLAGS=-c -Wall
LFLAGS=
LIB= 
QUIET=@
SRC_DIR=src
OBJ_DIR=obj
INC_DIR=include
TEST_DIR=tests

SRC_DIRS=$(shell find $(SRC_DIR) -type d)
OBJ_DIRS=$(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRC_DIRS))

INC=-I$(INC_DIR)
SRC=$(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))
OBJ=$(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRC))

directories: 
	$(QUIET)echo Making dirs
	$(foreach dir,$(OBJ_DIRS), $(shell mkdir -p $(dir))) 

$(APPNAME): $(OBJ)
	$(QUIET)echo Linkging $(APPNAME)
	$(QUIET)$(CC) $(LFLAGS) $(LIBS) -o $(APPNAME) $(OBJ)  

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(QUIET)echo Compiling $< 
	$(QUIET)$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(QUIET)echo Cleaning
	$(QUIET)rm -rf $(OBJ_DIR)
	$(QUIET)rm $(APPNAME)