###########################################################################
## Makefile generated for component 'INCLASS_iterative_test_single'. 
## 
## Makefile     : INCLASS_iterative_test_single_rtw.mk
## Generated on : Mon Feb 26 11:11:47 2024
## Final product: ./INCLASS_iterative_test_single.a
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# MODELLIB                Static library target

PRODUCT_NAME              = INCLASS_iterative_test_single
MAKEFILE                  = INCLASS_iterative_test_single_rtw.mk
MATLAB_ROOT               = /Applications/MATLAB_R2023b.app
MATLAB_BIN                = /Applications/MATLAB_R2023b.app/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/maca64
START_DIR                 = /Users/yuxuan/Projects/23Fall/INCLASS/src_paper/extern_new
TGT_FCN_LIB               = ISO_C
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
C_STANDARD_OPTS           = -fno-common -fexceptions
CPP_STANDARD_OPTS         = -std=c++14 -fno-common -fexceptions
MODELLIB                  = INCLASS_iterative_test_single.a

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Xcode with Clang | gmake (64-bit Mac)
# Supported Version(s):    
# ToolchainInfo Version:   2023b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS

#-----------
# MACROS
#-----------

ARCHS             = arm64
XCODE_SDK_VER     = $(shell perl $(MATLAB_ROOT)/rtw/c/tools/macsdkver.pl)
XCODE_SDK         = MacOSX$(XCODE_SDK_VER).sdk
XCODE_DEVEL_DIR   = $(shell xcode-select -print-path)
XCODE_SDK_ROOT    = $(XCODE_DEVEL_DIR)/Platforms/MacOSX.platform/Developer/SDKs/$(XCODE_SDK)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Clang C Compiler
CC = xcrun clang

# Linker: Clang Linker
LD = xcrun clang++

# C++ Compiler: Clang C++ Compiler
CPP = xcrun clang++

# C++ Linker: Clang C++ Linker
CPP_LD = xcrun clang++

# Archiver: Clang Archiver
AR = xcrun ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/maca64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @rm -f
ECHO                = @echo
MV                  = @mv
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c -isysroot $(XCODE_SDK_ROOT) -arch $(ARCHS) $(C_STANDARD_OPTS) -mmacosx-version-min=11.0 \
                       -O3
CPPFLAGS             = -c -isysroot $(XCODE_SDK_ROOT) -arch $(ARCHS) $(CPP_STANDARD_OPTS) -mmacosx-version-min=11.0 \
                       -O3
CPP_LDFLAGS          = -arch $(ARCHS) -isysroot $(XCODE_SDK_ROOT) -Wl,-rpath,@executable_path -Wl,-rpath,@executable_path/$(RELATIVE_PATH_TO_ANCHOR)
CPP_SHAREDLIB_LDFLAGS  = -arch $(ARCHS)  \
                         -dynamiclib -install_name @rpath/$(notdir $(PRODUCT)) -isysroot $(XCODE_SDK_ROOT) \
                         -Wl,$(LD_NAMESPACE) $(LD_UNDEFS)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -arch $(ARCHS) -isysroot $(XCODE_SDK_ROOT) -Wl,-rpath,@executable_path -Wl,-rpath,@executable_path/$(RELATIVE_PATH_TO_ANCHOR)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -arch $(ARCHS)  \
                       -dynamiclib -install_name @rpath/$(notdir $(PRODUCT)) -isysroot $(XCODE_SDK_ROOT) \
                       -Wl,$(LD_NAMESPACE) $(LD_UNDEFS)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./INCLASS_iterative_test_single.a
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR)/codegen/lib/INCLASS_iterative_test_single -I$(START_DIR) -I$(MATLAB_ROOT)/extern/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=INCLASS_iterative_test_single

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/coder_posix_time.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/rt_nonfinite.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/rtGetNaN.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/rtGetInf.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/INCLASS_iterative_test_single_initialize.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/INCLASS_iterative_test_single_terminate.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/INCLASS_iterative_test_single.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/isnan.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/ifWhileCond.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/CompactClassificationEnsemble.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/isfinite.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/isinf.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/floor.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/eye.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/lower.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/eml_string_transform.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/clock.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/datetime.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/getLocalTime.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/CoderTimeAPI.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/createFromDateVec.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/split.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/abs.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/abs1.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/times.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/two_prod.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/plus.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/two_sum.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/getDateVec.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/divmod.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/divide.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/two_diff.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/floor1.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/minus.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/floorFrac.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/days2ymd.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/idivide.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/fix.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/rem.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/rem1.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/secs2hms.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sum.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/combineVectorElements.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/blockedSummation.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/bitsra.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/minOrMax.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/any.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/round.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/xdlapy2.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/mean.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/filter.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/power.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/ixfun.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/findpeaks.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/isrow.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/eml_setop.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/relop.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sortLE.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sortDescendLE.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/length.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/nextpow2.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/nextpow21.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/stack.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/diff.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/unique.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sortIdx.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sortAscendLE.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/movmedian.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/movfunDispatch.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/movsortfun.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/SortedBuffer.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/std.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/varstd.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/vvarstd.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/xnrm2.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/plomb.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/convertStringsToChars.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/find.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/nullAssignment.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/mrdivide_helper.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/lusolve.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/var.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/log2.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sinpi.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sinpi1.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/cospiAndSinpi.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/cospi.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/cospi1.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/atan2.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/atan21.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/mod.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/mod1.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/colon.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/prod.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/fft.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/FFTImplementationCallback.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sizeIsPow2.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/bluesteinSetup.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/bandpower.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/mtimes.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/mtimes1.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/nonzeros.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/nnz.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/repmat.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/table2PredictMatrix.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/CompactClassificationTree.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/CompactTree.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/findNode.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/CompactClassificationModel.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/bsxfun.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/all.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/movsum.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/indexIntRelop.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/movSumProdOrMean.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/applyVectorFunctionNoCopy.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/mpower.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/strcmp.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/ismember.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/applyVectorFunction.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/floor2.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/CompactEnsemble.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/addToLoAndAdjust.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/fix1.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/cos.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/exp.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/round1.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/mergesort.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/insertionsort.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/introsort.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/heapsort.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sortpartition.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sumprod.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sqrt.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sqrt1.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/log10.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/log101.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/cos1.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sin.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sin1.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/exp1.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sign.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sign1.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/aggregatePredict.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/predictOneWithCache.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/updateCache.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/eml_mtimes_helper.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/div.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/INCLASS_iterative_test_single_emxutil.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/INCLASS_iterative_test_single_emxAPI.c $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/INCLASS_iterative_test_single_rtwutil.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = coder_posix_time.o rt_nonfinite.o rtGetNaN.o rtGetInf.o INCLASS_iterative_test_single_initialize.o INCLASS_iterative_test_single_terminate.o INCLASS_iterative_test_single.o isnan.o ifWhileCond.o CompactClassificationEnsemble.o isfinite.o isinf.o floor.o eye.o lower.o eml_string_transform.o clock.o datetime.o getLocalTime.o CoderTimeAPI.o createFromDateVec.o split.o abs.o abs1.o times.o two_prod.o plus.o two_sum.o getDateVec.o divmod.o divide.o two_diff.o floor1.o minus.o floorFrac.o days2ymd.o idivide.o fix.o rem.o rem1.o secs2hms.o sum.o combineVectorElements.o blockedSummation.o bitsra.o minOrMax.o any.o round.o xdlapy2.o mean.o filter.o power.o ixfun.o findpeaks.o isrow.o eml_setop.o relop.o sortLE.o sortDescendLE.o length.o nextpow2.o nextpow21.o stack.o diff.o unique.o sortIdx.o sortAscendLE.o movmedian.o movfunDispatch.o movsortfun.o SortedBuffer.o std.o varstd.o vvarstd.o xnrm2.o plomb.o convertStringsToChars.o find.o nullAssignment.o mrdivide_helper.o lusolve.o var.o log2.o sinpi.o sinpi1.o cospiAndSinpi.o cospi.o cospi1.o atan2.o atan21.o mod.o mod1.o colon.o prod.o fft.o FFTImplementationCallback.o sizeIsPow2.o bluesteinSetup.o bandpower.o mtimes.o mtimes1.o nonzeros.o nnz.o repmat.o table2PredictMatrix.o CompactClassificationTree.o CompactTree.o findNode.o CompactClassificationModel.o bsxfun.o all.o movsum.o indexIntRelop.o movSumProdOrMean.o applyVectorFunctionNoCopy.o mpower.o strcmp.o ismember.o applyVectorFunction.o floor2.o CompactEnsemble.o addToLoAndAdjust.o fix1.o cos.o exp.o round1.o mergesort.o insertionsort.o introsort.o heapsort.o sortpartition.o sumprod.o sqrt.o sqrt1.o log10.o log101.o cos1.o sin.o sin1.o exp1.o sign.o sign1.o aggregatePredict.o predictOneWithCache.o updateCache.o eml_mtimes_helper.o div.o INCLASS_iterative_test_single_emxutil.o INCLASS_iterative_test_single_emxAPI.o INCLASS_iterative_test_single_rtwutil.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS =  -lm

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) $(OBJS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.CC
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.C++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.CXX
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.CC
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.C++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.CXX
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/%.CC
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/%.C++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/%.CXX
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.CC
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.C++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.CXX
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


coder_posix_time.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/coder_posix_time.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_nonfinite.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/rt_nonfinite.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetNaN.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/rtGetNaN.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetInf.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/rtGetInf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


INCLASS_iterative_test_single_initialize.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/INCLASS_iterative_test_single_initialize.c
	$(CC) $(CFLAGS) -o "$@" "$<"


INCLASS_iterative_test_single_terminate.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/INCLASS_iterative_test_single_terminate.c
	$(CC) $(CFLAGS) -o "$@" "$<"


INCLASS_iterative_test_single.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/INCLASS_iterative_test_single.c
	$(CC) $(CFLAGS) -o "$@" "$<"


isnan.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/isnan.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ifWhileCond.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/ifWhileCond.c
	$(CC) $(CFLAGS) -o "$@" "$<"


CompactClassificationEnsemble.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/CompactClassificationEnsemble.c
	$(CC) $(CFLAGS) -o "$@" "$<"


isfinite.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/isfinite.c
	$(CC) $(CFLAGS) -o "$@" "$<"


isinf.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/isinf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


floor.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/floor.c
	$(CC) $(CFLAGS) -o "$@" "$<"


eye.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/eye.c
	$(CC) $(CFLAGS) -o "$@" "$<"


lower.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/lower.c
	$(CC) $(CFLAGS) -o "$@" "$<"


eml_string_transform.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/eml_string_transform.c
	$(CC) $(CFLAGS) -o "$@" "$<"


clock.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/clock.c
	$(CC) $(CFLAGS) -o "$@" "$<"


datetime.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/datetime.c
	$(CC) $(CFLAGS) -o "$@" "$<"


getLocalTime.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/getLocalTime.c
	$(CC) $(CFLAGS) -o "$@" "$<"


CoderTimeAPI.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/CoderTimeAPI.c
	$(CC) $(CFLAGS) -o "$@" "$<"


createFromDateVec.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/createFromDateVec.c
	$(CC) $(CFLAGS) -o "$@" "$<"


split.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/split.c
	$(CC) $(CFLAGS) -o "$@" "$<"


abs.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/abs.c
	$(CC) $(CFLAGS) -o "$@" "$<"


abs1.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/abs1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


times.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/times.c
	$(CC) $(CFLAGS) -o "$@" "$<"


two_prod.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/two_prod.c
	$(CC) $(CFLAGS) -o "$@" "$<"


plus.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/plus.c
	$(CC) $(CFLAGS) -o "$@" "$<"


two_sum.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/two_sum.c
	$(CC) $(CFLAGS) -o "$@" "$<"


getDateVec.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/getDateVec.c
	$(CC) $(CFLAGS) -o "$@" "$<"


divmod.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/divmod.c
	$(CC) $(CFLAGS) -o "$@" "$<"


divide.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/divide.c
	$(CC) $(CFLAGS) -o "$@" "$<"


two_diff.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/two_diff.c
	$(CC) $(CFLAGS) -o "$@" "$<"


floor1.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/floor1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


minus.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/minus.c
	$(CC) $(CFLAGS) -o "$@" "$<"


floorFrac.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/floorFrac.c
	$(CC) $(CFLAGS) -o "$@" "$<"


days2ymd.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/days2ymd.c
	$(CC) $(CFLAGS) -o "$@" "$<"


idivide.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/idivide.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fix.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/fix.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rem.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/rem.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rem1.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/rem1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


secs2hms.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/secs2hms.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sum.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sum.c
	$(CC) $(CFLAGS) -o "$@" "$<"


combineVectorElements.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/combineVectorElements.c
	$(CC) $(CFLAGS) -o "$@" "$<"


blockedSummation.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/blockedSummation.c
	$(CC) $(CFLAGS) -o "$@" "$<"


bitsra.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/bitsra.c
	$(CC) $(CFLAGS) -o "$@" "$<"


minOrMax.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/minOrMax.c
	$(CC) $(CFLAGS) -o "$@" "$<"


any.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/any.c
	$(CC) $(CFLAGS) -o "$@" "$<"


round.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/round.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xdlapy2.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/xdlapy2.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mean.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/mean.c
	$(CC) $(CFLAGS) -o "$@" "$<"


filter.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/filter.c
	$(CC) $(CFLAGS) -o "$@" "$<"


power.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/power.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ixfun.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/ixfun.c
	$(CC) $(CFLAGS) -o "$@" "$<"


findpeaks.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/findpeaks.c
	$(CC) $(CFLAGS) -o "$@" "$<"


isrow.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/isrow.c
	$(CC) $(CFLAGS) -o "$@" "$<"


eml_setop.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/eml_setop.c
	$(CC) $(CFLAGS) -o "$@" "$<"


relop.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/relop.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sortLE.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sortLE.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sortDescendLE.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sortDescendLE.c
	$(CC) $(CFLAGS) -o "$@" "$<"


length.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/length.c
	$(CC) $(CFLAGS) -o "$@" "$<"


nextpow2.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/nextpow2.c
	$(CC) $(CFLAGS) -o "$@" "$<"


nextpow21.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/nextpow21.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stack.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/stack.c
	$(CC) $(CFLAGS) -o "$@" "$<"


diff.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/diff.c
	$(CC) $(CFLAGS) -o "$@" "$<"


unique.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/unique.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sortIdx.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sortIdx.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sortAscendLE.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sortAscendLE.c
	$(CC) $(CFLAGS) -o "$@" "$<"


movmedian.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/movmedian.c
	$(CC) $(CFLAGS) -o "$@" "$<"


movfunDispatch.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/movfunDispatch.c
	$(CC) $(CFLAGS) -o "$@" "$<"


movsortfun.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/movsortfun.c
	$(CC) $(CFLAGS) -o "$@" "$<"


SortedBuffer.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/SortedBuffer.c
	$(CC) $(CFLAGS) -o "$@" "$<"


std.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/std.c
	$(CC) $(CFLAGS) -o "$@" "$<"


varstd.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/varstd.c
	$(CC) $(CFLAGS) -o "$@" "$<"


vvarstd.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/vvarstd.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xnrm2.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/xnrm2.c
	$(CC) $(CFLAGS) -o "$@" "$<"


plomb.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/plomb.c
	$(CC) $(CFLAGS) -o "$@" "$<"


convertStringsToChars.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/convertStringsToChars.c
	$(CC) $(CFLAGS) -o "$@" "$<"


find.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/find.c
	$(CC) $(CFLAGS) -o "$@" "$<"


nullAssignment.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/nullAssignment.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mrdivide_helper.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/mrdivide_helper.c
	$(CC) $(CFLAGS) -o "$@" "$<"


lusolve.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/lusolve.c
	$(CC) $(CFLAGS) -o "$@" "$<"


var.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/var.c
	$(CC) $(CFLAGS) -o "$@" "$<"


log2.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/log2.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sinpi.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sinpi.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sinpi1.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sinpi1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cospiAndSinpi.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/cospiAndSinpi.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cospi.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/cospi.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cospi1.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/cospi1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


atan2.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/atan2.c
	$(CC) $(CFLAGS) -o "$@" "$<"


atan21.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/atan21.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mod.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/mod.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mod1.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/mod1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


colon.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/colon.c
	$(CC) $(CFLAGS) -o "$@" "$<"


prod.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/prod.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fft.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/fft.c
	$(CC) $(CFLAGS) -o "$@" "$<"


FFTImplementationCallback.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/FFTImplementationCallback.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sizeIsPow2.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sizeIsPow2.c
	$(CC) $(CFLAGS) -o "$@" "$<"


bluesteinSetup.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/bluesteinSetup.c
	$(CC) $(CFLAGS) -o "$@" "$<"


bandpower.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/bandpower.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mtimes.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/mtimes.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mtimes1.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/mtimes1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


nonzeros.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/nonzeros.c
	$(CC) $(CFLAGS) -o "$@" "$<"


nnz.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/nnz.c
	$(CC) $(CFLAGS) -o "$@" "$<"


repmat.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/repmat.c
	$(CC) $(CFLAGS) -o "$@" "$<"


table2PredictMatrix.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/table2PredictMatrix.c
	$(CC) $(CFLAGS) -o "$@" "$<"


CompactClassificationTree.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/CompactClassificationTree.c
	$(CC) $(CFLAGS) -o "$@" "$<"


CompactTree.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/CompactTree.c
	$(CC) $(CFLAGS) -o "$@" "$<"


findNode.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/findNode.c
	$(CC) $(CFLAGS) -o "$@" "$<"


CompactClassificationModel.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/CompactClassificationModel.c
	$(CC) $(CFLAGS) -o "$@" "$<"


bsxfun.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/bsxfun.c
	$(CC) $(CFLAGS) -o "$@" "$<"


all.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/all.c
	$(CC) $(CFLAGS) -o "$@" "$<"


movsum.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/movsum.c
	$(CC) $(CFLAGS) -o "$@" "$<"


indexIntRelop.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/indexIntRelop.c
	$(CC) $(CFLAGS) -o "$@" "$<"


movSumProdOrMean.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/movSumProdOrMean.c
	$(CC) $(CFLAGS) -o "$@" "$<"


applyVectorFunctionNoCopy.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/applyVectorFunctionNoCopy.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mpower.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/mpower.c
	$(CC) $(CFLAGS) -o "$@" "$<"


strcmp.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/strcmp.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ismember.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/ismember.c
	$(CC) $(CFLAGS) -o "$@" "$<"


applyVectorFunction.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/applyVectorFunction.c
	$(CC) $(CFLAGS) -o "$@" "$<"


floor2.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/floor2.c
	$(CC) $(CFLAGS) -o "$@" "$<"


CompactEnsemble.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/CompactEnsemble.c
	$(CC) $(CFLAGS) -o "$@" "$<"


addToLoAndAdjust.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/addToLoAndAdjust.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fix1.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/fix1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cos.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/cos.c
	$(CC) $(CFLAGS) -o "$@" "$<"


exp.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/exp.c
	$(CC) $(CFLAGS) -o "$@" "$<"


round1.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/round1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mergesort.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/mergesort.c
	$(CC) $(CFLAGS) -o "$@" "$<"


insertionsort.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/insertionsort.c
	$(CC) $(CFLAGS) -o "$@" "$<"


introsort.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/introsort.c
	$(CC) $(CFLAGS) -o "$@" "$<"


heapsort.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/heapsort.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sortpartition.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sortpartition.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sumprod.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sumprod.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sqrt.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sqrt.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sqrt1.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sqrt1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


log10.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/log10.c
	$(CC) $(CFLAGS) -o "$@" "$<"


log101.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/log101.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cos1.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/cos1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sin.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sin.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sin1.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sin1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


exp1.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/exp1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sign.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sign.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sign1.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/sign1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


aggregatePredict.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/aggregatePredict.c
	$(CC) $(CFLAGS) -o "$@" "$<"


predictOneWithCache.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/predictOneWithCache.c
	$(CC) $(CFLAGS) -o "$@" "$<"


updateCache.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/updateCache.c
	$(CC) $(CFLAGS) -o "$@" "$<"


eml_mtimes_helper.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/eml_mtimes_helper.c
	$(CC) $(CFLAGS) -o "$@" "$<"


div.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/div.c
	$(CC) $(CFLAGS) -o "$@" "$<"


INCLASS_iterative_test_single_emxutil.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/INCLASS_iterative_test_single_emxutil.c
	$(CC) $(CFLAGS) -o "$@" "$<"


INCLASS_iterative_test_single_emxAPI.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/INCLASS_iterative_test_single_emxAPI.c
	$(CC) $(CFLAGS) -o "$@" "$<"


INCLASS_iterative_test_single_rtwutil.o : $(START_DIR)/codegen/lib/INCLASS_iterative_test_single/INCLASS_iterative_test_single_rtwutil.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


