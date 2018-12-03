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
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/59a77b5e/BFS_Solver.o \
	${OBJECTDIR}/_ext/59a77b5e/DFS_Solver.o \
	${OBJECTDIR}/_ext/59a77b5e/Grid.o \
	${OBJECTDIR}/_ext/59a77b5e/Node.o \
	${OBJECTDIR}/_ext/59a77b5e/Solver.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/C/SFML-2.5.1/lib -lsfml-system-d -lsfml-window-d -lsfml-graphics-d

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sokoban_sfml.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sokoban_sfml.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sokoban_sfml ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/59a77b5e/BFS_Solver.o: /C/Users/Lefa/Documents/NetBeansProjects/Sokoban_SFML/BFS_Solver.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/59a77b5e
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/C/SFML-2.5.1/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/59a77b5e/BFS_Solver.o /C/Users/Lefa/Documents/NetBeansProjects/Sokoban_SFML/BFS_Solver.cpp

${OBJECTDIR}/_ext/59a77b5e/DFS_Solver.o: /C/Users/Lefa/Documents/NetBeansProjects/Sokoban_SFML/DFS_Solver.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/59a77b5e
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/C/SFML-2.5.1/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/59a77b5e/DFS_Solver.o /C/Users/Lefa/Documents/NetBeansProjects/Sokoban_SFML/DFS_Solver.cpp

${OBJECTDIR}/_ext/59a77b5e/Grid.o: /C/Users/Lefa/Documents/NetBeansProjects/Sokoban_SFML/Grid.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/59a77b5e
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/C/SFML-2.5.1/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/59a77b5e/Grid.o /C/Users/Lefa/Documents/NetBeansProjects/Sokoban_SFML/Grid.cpp

${OBJECTDIR}/_ext/59a77b5e/Node.o: /C/Users/Lefa/Documents/NetBeansProjects/Sokoban_SFML/Node.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/59a77b5e
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/C/SFML-2.5.1/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/59a77b5e/Node.o /C/Users/Lefa/Documents/NetBeansProjects/Sokoban_SFML/Node.cpp

${OBJECTDIR}/_ext/59a77b5e/Solver.o: /C/Users/Lefa/Documents/NetBeansProjects/Sokoban_SFML/Solver.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/59a77b5e
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/C/SFML-2.5.1/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/59a77b5e/Solver.o /C/Users/Lefa/Documents/NetBeansProjects/Sokoban_SFML/Solver.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/C/SFML-2.5.1/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
