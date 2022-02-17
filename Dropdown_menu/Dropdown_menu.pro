TEMPLATE = app
CONFIG += console c++11
#CONFIG -= app_bundle

#since we want to use qDebug, we
#will not subtract qt.
#CONFIG -= qt

CONFIG += c++11
#------------------------------------------
##Add these lines for SFML:



#WINDOWS
LIBS += -L"C:\SFML-2.5.1\lib" #change this
LIBS += -L"C:\SFML-2.5.1\bin" #change this



CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
INCLUDEPATH += "C:\SFML-2.5.1\include" #change this
DEPENDPATH  += "C:\SFML-2.5.1\include" #change this


SOURCES += \
        button.cpp \
        control_panel.cpp \
        cursor.cpp \
        dashboard.cpp \
        dropdown_menu.cpp \
        evenhandler.cpp \
        fileitem.cpp \
        filenode.cpp \
        filetree.cpp \
        font.cpp \
        guicomponent.cpp \
        history.cpp \
        image.cpp \
        item.cpp \
        itemlist.cpp \
        keyshortcuts.cpp \
        label.cpp \
        main.cpp \
        menu.cpp \
        menubar.cpp \
        mouseevents.cpp \
        multi_text.cpp \
        single_term.cpp \
        snapshot.cpp \
        snapshotinterface.cpp \
        states.cpp \
        text_input.cpp \
        textbox.cpp \
        typing.cpp

HEADERS += \
    button.h \
    constansts.h \
    control_panel.h \
    cursor.h \
    dashboard.h \
    dropdown_menu.h \
    evenhandler.h \
    fileitem.h \
    filenode.h \
    filetree.h \
    font.h \
    guicomponent.h \
    history.h \
    image.h \
    item.h \
    itemlist.h \
    keyshortcuts.h \
    label.h \
    menu.h \
    menubar.h \
    mouseevents.h \
    multi_text.h \
    single_term.h \
    snapshot.h \
    snapshotinterface.h \
    states.h \
    text_input.h \
    textbox.h \
    typing.h
