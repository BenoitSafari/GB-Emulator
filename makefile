# Makefile settings
APPNAME = build/app
EXT = .c
SRCDIR = src
OBJDIR = build/obj
DEPDIR = build/dep
INCDIR = include
SDL2LIB = /usr/include/SDL2
CLEAN_CMD = rm -f $(OBJDIR)/*.o $(DEPDIR)/*.d $(APPNAME) 

# Adapt paths and cmd for Windows OS
ifeq ($(OS),Windows_NT)
	APPNAME := $(subst /,\,$(APPNAME))
	OBJDIR := $(subst /,\,$(OBJDIR))
	DEPDIR := $(subst /,\,$(DEPDIR))
	CLEAN_CMD := del /Q $(OBJDIR)\*.o $(DEPDIR)\*.d $(APPNAME)
endif

# Compiler settings
CC = gcc
CXXFLAGS = -std=gnu17 -Wall -g -I$(SDL2LIB) -I$(INCDIR) 
LDFLAGS = -lSDL2

# Output settings
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(SRC:$(SRCDIR)/%$(EXT)=$(DEPDIR)/%.d)

########################################################################
####################### Targets beginning here #########################
########################################################################

# Build app
all: $(APPNAME)

$(APPNAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(DEPDIR)/%.d: $(SRCDIR)/%$(EXT)
	@$(CPP) $(CXXFLAGS) $< -MM -MT $(@:$(DEPDIR)/%.d=$(OBJDIR)/%.o) > $@

-include $(DEP)

$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	$(CC) $(CXXFLAGS) -o $@ -c $<

# Clean build directory
clean: 
	$(CLEAN_CMD)
