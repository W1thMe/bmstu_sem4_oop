QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    draw_arithmetic_oprs.cpp \
    draw_functions.cpp \
    initialize_funcs.cpp \
    io_stream_funcs.cpp \
    main.cpp \
    mainwindow.cpp \
    manager.cpp \
    mem.cpp \
    model_events.cpp \
    read_file.cpp \
    save_file.cpp \
    transform_arithmetic_oprs.cpp \
    transformation_funcs.cpp

HEADERS += \
    defines.h \
    draw_arithmetic_oprs.h \
    draw_functions.h \
    events_struct.h \
    initialize_funcs.h \
    io_stream_funcs.h \
    mainwindow.h \
    manager.h \
    mem.h \
    model_events.h \
    model_structs.h \
    rc.h \
    read_file.h \
    save_file.h \
    transform_arithmetic_oprs.h \
    transformation_funcs.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
