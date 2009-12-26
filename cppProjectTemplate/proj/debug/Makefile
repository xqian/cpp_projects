OWN_CFLAGS:= -g -WALL
ccx:=cc

MK_DEBUG := true 
# if uncomment the above line, some debug info will display

################################## dir and app name
SRC_OTHERS := ../../src
SRC_MAIN := ..
SRCPATH :=  $(SRC_OTHERS) $(SRC_MAIN) 
OBJDIR := ./

VPATH := $(SRCPATH) $(OBJDIR) 

################################## app name
include mk.appvar
ifdef MK_DEBUG
$(warning  $(APP))
endif
########this sequence is important
all: $(APP)


#######################################dependence defination
MAKE_DEPEND_CMD :=  $(CC) -MM
SOURCE_DEPEND_FRAG := mk.source_depend_list

###################################generate/include the source list
include  $(SOURCE_DEPEND_FRAG)
OBJ_FILES := $(subst .$(ccx),.o, $(SRC_FILES)) 
DEP_FILES := $(subst .$(ccx),.dep, $(SRC_FILES))
#patten match cannot work here
ifdef MK_DEBUG
$(warning source list: $(SRC_FILES) )
$(warning object list: $(OBJ_FILES) )
$(warning dep list: $(DEP_FILES) )
endif

################ compiling tools and compiling opitions
CFLAGS:= $(OWN_CFLAGS) -I$(SRC_OTHERS) 
LDFLAGS:=-lm ${CFLAGS}
CC := g++ 
#$(warning CFLAGS: $(CFLAGS) )


################

.PHONY: clean 
.PHONY: flush

test: $(APP)	
	./$(APP)
	
$(APP): $(OBJ_FILES) $(DEPEND_FRAG)
#	$(warning  link the files)
	$(CC) $(LDFLAGS) -o  $(APP)   $(OBJ_FILES) 

%.o :%.$(ccx)
	$(CC) $(CFLAGS) -c $<    

%.dep : %.$(ccx)
	$(MAKE_DEPEND_CMD) $(CFLAGS) $< > $@    
    
mk.source_list: 
#	$(warning  flush the mk.source_list)
	export temp_var=$$PWD ; cd $(SRC_MAIN) ; ls *.$(ccx) -1 > $$temp_var/mk.cpp_list; cd  $$temp_var 
	export temp_var=$$PWD ; cd $(SRC_OTHERS) ; ls *.$(ccx) -1 >> $$temp_var/mk.cpp_list; cd  $$temp_var 
#generate cpp file list
	sed '1,$$s/$$/ \\/' mk.cpp_list| sed '$$s/\\//' | sed '1s/^/SRC_FILES := /' > mk.source_list
#generate the source file that will be include in the make file
#	rm mk.cpp_list

mk.appvar: 
#	$(warning  flush the app_var file)
	export temp_var=$$PWD; cd ../; pwd | sed '1s/.*\///' | sed '1s/^/ APP :=/'  > $$temp_var/mk.appvar;

clean:
	rm $(OBJ_FILES) $(DEP_FILES) $(APP) $(APP).exe mk.appvar mk.source_list mk.cpp_list $(SOURCE_DEPEND_FRAG)

flush: 
	make mk.source_list 
	make mk.appvar 
	make $(DEPEND_FRAG) 

$(SOURCE_DEPEND_FRAG): mk.source_list $(DEP_FILES)
	echo  >>  $(SOURCE_DEPEND_FRAG)
	cat mk.source_list $(DEP_FILES) >> $(SOURCE_DEPEND_FRAG)
	echo "" >> $(SOURCE_DEPEND_FRAG)

