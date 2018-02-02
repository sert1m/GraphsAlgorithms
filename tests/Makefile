APPNAME=test
include ../Makefile.inc

INC=-I$(GRAPHS_INC)
LFLAGS+=-lpthread 

all: directories $(APPNAME)

$(APPNAME): $(OBJ)
	$(QUIET)echo Linkging $(APPNAME)
	$(QUIET)$(CC) $(LFLAGS) $(LIBS) -o $(APPNAME) $(OBJ) -lgtest -L$(GRAPTH_LIB_PATH) -l$(GRAPTH_LIB_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(QUIET)echo Compiling $< 
	$(QUIET)$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(QUIET)echo Cleaning
	$(QUIET)rm -rf $(OBJ_DIR)
	$(QUIET)rm $(APPNAME)
