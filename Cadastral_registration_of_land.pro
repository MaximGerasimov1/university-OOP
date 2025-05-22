QT += core widgets

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++17

SOURCES += \
        main.cpp \
        menu.cpp \
        rwFunc.cpp

HEADERS += \
    menu.hpp \
    rwFunc.hpp

DISTFILES += \
    earth.db \
    earth_en.db \
    main.txt
