COMPILE.c?=$(CC) -c $(CPPFLAGS) $(CFLAGS)
COMPILE.S?=$(CC) -c $(CPPFLAGS) $(ASFLAGS)
RUMPOBJ?=../../rumpobj
OBJDIR=$(RUMPOBJ)/franken
ifneq ($(OS),darwin)
OBJ=$(OBJDIR)/makecontext.o $(OBJDIR)/getcontext.o $(OBJDIR)/swapcontext.o
CPPFLAGS+=-nostdinc $(INCLUDES)
endif
INCLUDES=-I../include -I.
CFLAGS+=-fno-stack-protector

default:			$(OBJ)
ifeq ($(OS),darwin)
	$(MAKE) -C x86_64/darwin
endif

$(OBJDIR)/getcontext.o:		getcontext.c
				@mkdir -p $(OBJDIR)
				$(COMPILE.c) -o $@ getcontext.c

$(OBJDIR)/makecontext.o:	makecontext.c
				@mkdir -p $(OBJDIR)
				$(COMPILE.c) -o $@ makecontext.c

$(OBJDIR)/swapcontext.o:	swapcontext.S
				@mkdir -p $(OBJDIR)
				$(COMPILE.S) -o $@ swapcontext.S

.PHONY:				clean
clean:		
				rm -f $(OBJ)
