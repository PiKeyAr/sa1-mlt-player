#------------------------------------------------------------------------------
# sequence.mak
#------------------------------------------------------------------------------

PROJECT	= sequence

PROJECT_OBJS	= \
		  $(OBJDIR)\main.obj\
		  $(OBJDIR)\sbinit.obj\
		  $(OBJDIR)\sndutls.obj\

PROJECT_LIBS	= \
				ninja,\
				sg_sd

GFX_API		= NINJA

OPTIMIZE        = 1

DEBUG           = TRUE
LIST            = FALSE
BIN             = FALSE
#GNU           = TRUE

include $(KATANA_ROOT)\sample\katana.inc
