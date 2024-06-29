QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    mainwindow.cpp \
    game_src/Inventario.cpp \
    game_src/Mascota.cpp \
    game_src/Item.cpp \
    game_src/Items.cpp \


HEADERS += mainwindow.h \
    game_headers/Inventario.h \
    game_headers/Mascota.h \
    game_headers/Item.h \
    game_headers/Juguete.h \
    game_headers/Comida.h \
    game_headers/Medicina.h


FORMS += mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += recursos.qrc
