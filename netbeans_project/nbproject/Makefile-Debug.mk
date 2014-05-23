#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1360937237/Art.o \
	${OBJECTDIR}/_ext/1360937237/CocktailProController.o \
	${OBJECTDIR}/_ext/1360937237/Dosierstation.o \
	${OBJECTDIR}/_ext/1360937237/Entleerer.o \
	${OBJECTDIR}/_ext/1360937237/MischbaresRezeptbuch.o \
	${OBJECTDIR}/_ext/1360937237/Mischer.o \
	${OBJECTDIR}/_ext/1360937237/ObserverWaage.o \
	${OBJECTDIR}/_ext/1360937237/RezeptbuchTest.o \
	${OBJECTDIR}/_ext/1360937237/Simulation.o \
	${OBJECTDIR}/_ext/1360937237/Stampfer.o \
	${OBJECTDIR}/_ext/1360937237/SubjectWaage.o \
	${OBJECTDIR}/_ext/1360937237/UserInterface.o \
	${OBJECTDIR}/_ext/1360937237/Waage.o \
	${OBJECTDIR}/_ext/1360937237/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-lcppunit
CXXFLAGS=-lcppunit

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../Resource/RezeptbuchBinaries_2014/Rezeptbuch_CASE_G++_Ubuntu.o

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/netbeans_project

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/netbeans_project: ../Resource/RezeptbuchBinaries_2014/Rezeptbuch_CASE_G++_Ubuntu.o

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/netbeans_project: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/netbeans_project ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1360937237/Art.o: ../src/Art.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1360937237/Art.o ../src/Art.cpp

${OBJECTDIR}/_ext/1360937237/CocktailProController.o: ../src/CocktailProController.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1360937237/CocktailProController.o ../src/CocktailProController.cpp

${OBJECTDIR}/_ext/1360937237/Dosierstation.o: ../src/Dosierstation.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1360937237/Dosierstation.o ../src/Dosierstation.cpp

${OBJECTDIR}/_ext/1360937237/Entleerer.o: ../src/Entleerer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1360937237/Entleerer.o ../src/Entleerer.cpp

${OBJECTDIR}/_ext/1360937237/MischbaresRezeptbuch.o: ../src/MischbaresRezeptbuch.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1360937237/MischbaresRezeptbuch.o ../src/MischbaresRezeptbuch.cpp

${OBJECTDIR}/_ext/1360937237/Mischer.o: ../src/Mischer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1360937237/Mischer.o ../src/Mischer.cpp

${OBJECTDIR}/_ext/1360937237/ObserverWaage.o: ../src/ObserverWaage.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1360937237/ObserverWaage.o ../src/ObserverWaage.cpp

${OBJECTDIR}/_ext/1360937237/RezeptbuchTest.o: ../src/RezeptbuchTest.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1360937237/RezeptbuchTest.o ../src/RezeptbuchTest.cpp

${OBJECTDIR}/_ext/1360937237/Simulation.o: ../src/Simulation.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1360937237/Simulation.o ../src/Simulation.cpp

${OBJECTDIR}/_ext/1360937237/Stampfer.o: ../src/Stampfer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1360937237/Stampfer.o ../src/Stampfer.cpp

${OBJECTDIR}/_ext/1360937237/SubjectWaage.o: ../src/SubjectWaage.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1360937237/SubjectWaage.o ../src/SubjectWaage.cpp

${OBJECTDIR}/_ext/1360937237/UserInterface.o: ../src/UserInterface.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1360937237/UserInterface.o ../src/UserInterface.cpp

${OBJECTDIR}/_ext/1360937237/Waage.o: ../src/Waage.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1360937237/Waage.o ../src/Waage.cpp

${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/netbeans_project

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
