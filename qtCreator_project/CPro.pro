TEMPLATE = app
CONFIG += console
CONFIG -= qt

INCLUDEPATH += ../include

HEADERS += \
    ../include/Rezeptbuch.h \
    ../include/Waage.h \
    ../include/UserInterface.h \
    ../include/SubjectWaage.h \
    ../include/Stampfer.h \
    ../include/Simulation.h \
    ../include/RezeptbuchTest.h \
    ../include/ObserverWaage.h \
    ../include/Mischer.h \
    ../include/MischbaresRezeptbuch.h \
    ../include/Entleerer.h \
    ../include/Dosierstation.h \
    ../include/CocktailProController.h \
    ../include/Art.h

SOURCES += \
    ../src/main.cpp \
    ../src/Waage.cpp \
    ../src/UserInterface.cpp \
    ../src/SubjectWaage.cpp \
    ../src/Stampfer.cpp \
    ../src/Simulation.cpp \
    ../src/RezeptbuchTest.cpp \
    ../src/ObserverWaage.cpp \
    ../src/Mischer.cpp \
    ../src/MischbaresRezeptbuch.cpp \
    ../src/Entleerer.cpp \
    ../src/Dosierstation.cpp \
    ../src/CocktailProController.cpp \
    ../src/Art.cpp

OTHER_FILES +=

LIBS += ../libs/Rezeptbuch_CASE_G++_Ubuntu.o

LIBS += -lcppunit
