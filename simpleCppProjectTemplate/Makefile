SRCS:= main.cc
TARGET:=main

OWN_CFLAGS:= -g -Wall
CFLAGS:= $(OWN_CFLAGS) 
LDFLAGS:=-lm ${CFLAGS}
ccx:=cc
CC := g++ 


DEPEND_FRAG:= makefile.dep

.PHONY: clean

OBJS:= $(subst .$(ccx),.o, $(SRCS))
DEPS:= $(subst .$(ccx),.dep, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS) $(DEPEND_FRAG)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

include $(DEPEND_FRAG)

%.o :%.$(ccx)
	$(CC) $(CFLAGS) -c $< 

%.dep : %.$(ccx)
	g++ -MM $(CFLAGS) $< > $@

$(DEPEND_FRAG): $(DEPS)
	cat $(DEPS) > $(DEPEND_FRAG)
	
clean:
	rm $(OBJS) $(DEPS) $(DEPEND_FRAG) 
	 	