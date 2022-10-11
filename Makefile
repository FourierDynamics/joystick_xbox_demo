CC=gcc

SRCDIR = 				\
		./src				

INCDIR = \
		

OUTDIR = output
OBJDIR = $(OUTDIR)/build
BINDIR = $(OUTDIR)/bin
BINAME = app

INCLUDES += $(foreach n,$(INCDIR),-I $(n))

TARGET = $(BINDIR)/$(BINAME)
SRCS = $(foreach n,$(SRCDIR),$(n)/*.c)
SRCS := $(wildcard $(SRCS)) 
OBJS = $(SRCS:.c=.o)
OBJS :=$(notdir $(OBJS))  
OBJS := $(foreach n,$(OBJS),$(OBJDIR)/$(n))
CCFLAGS = -pthread


$(shell if [ ! -e $(OBJDIR) ];then mkdir -p $(OBJDIR); fi)
$(shell if [ ! -e $(BINDIR) ];then mkdir -p $(BINDIR); fi)


$(TARGET):$(OBJS)
	$(CC) $(CCFLAGS) -o $@ $(OBJS)

# @echo $(filter %$(notdir $(@:.o=.c)),$(SRCS))
# @echo LIBFILE: $(LIBFILE)
# @echo SRCS: $(SRCS)
# @echo OBJS: $(OBJS)
$(OBJS):$(SRCS)
	$(CC) $(CCFLAGS) -o $@ -c $(filter %/$(notdir $(@:.o=.c)),$(SRCS)) $(INCLUDES)

clean:	
	rm $(OBJDIR)/*
