APPNAME=libgraphs.so
STATICLIB=libgraphs.a
include Makefile.inc 

export ROOT=$(PWD)
export GRAPHS_INC=$(PWD)/$(INC_DIR)
export GRAPTH_LIB_PATH=$(ROOT)
export GRAPTH_LIB_NAME=graphs

CFLAGS+=-fPIC
LFLAGS+=-shared -lm

all: directories $(APPNAME) $(STATICLIB) test 

test: $(APPNAME)
	make -C $(TEST_DIR) all

$(STATICLIB): $(OBJ)
	ar rvs $(STATICLIB) $(OBJ)

$(APPNAME): $(OBJ)
	$(QUIET)echo Linkging $(APPNAME)
	$(QUIET)$(CC) $(LFLAGS) $(LIBS) -o $(APPNAME) $(OBJ)  

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(QUIET)echo Compiling $< 
	$(QUIET)$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(QUIET)echo Cleaning
	$(QUIET)make -C $(TEST_DIR) clean
	$(QUIET)rm -rf $(OBJ_DIR)
	$(QUIET)rm $(APPNAME)


