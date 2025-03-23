QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Home.cpp \
    Room.cpp \
    bed.cpp \
    bedroomdesign.cpp \
    bflooring1.cpp \
    bfurniture.cpp \
    bookshelf.cpp \
    btheme1.cpp \
    cabinet.cpp \
    coffeetable.cpp \
    countertop.cpp \
    decitems.cpp \
    deskchair.cpp \
    diningtable.cpp \
    floorrug.cpp \
    fridge.cpp \
    interiordesign.cpp \
    kelectronicitems.cpp \
    kelectronicitems1.cpp \
    kflooring.cpp \
    kfloorui.cpp \
    kfurniture.cpp \
    kfurui.cpp \
    kitchendesign.cpp \
    ktheme.cpp \
    kthemeui.cpp \
    lamps.cpp \
    ldecitems.cpp \
    lflooring.cpp \
    lfloorrug.cpp \
    lfloorui.cpp \
    lfurniture.cpp \
    lfurui.cpp \
    livingroomdesign.cpp \
    llamps.cpp \
    ltheme.cpp \
    lthemeui.cpp \
    main.cpp \
    mainwindow.cpp \
    oven.cpp \
    sink.cpp \
    sofa.cpp \
    stove.cpp \
    tvstand.cpp \
    viewbedroom.cpp \
    viewkitchen.cpp \
    viewlivingroom.cpp \
    wardrobe.cpp

HEADERS += \
    Flooring.h \
    Furniture.h \
    Home.h \
    Room.h \
    Theme.h \
    bed.h \
    bedroomdesign.h \
    bflooring1.h \
    bfurniture.h \
    bookshelf.h \
    btheme1.h \
    cabinet.h \
    coffeetable.h \
    countertop.h \
    decitems.h \
    deskchair.h \
    diningtable.h \
    floorrug.h \
    fridge.h \
    interiordesign.h \
    kelectronicitems.h \
    kelectronicitems1.h \
    kflooring.h \
    kfloorui.h \
    kfurniture.h \
    kfurui.h \
    kitchendesign.h \
    ktheme.h \
    kthemeui.h \
    lamps.h \
    ldecitems.h \
    lflooring.h \
    lfloorrug.h \
    lfloorui.h \
    lfurniture.h \
    lfurui.h \
    livingroomdesign.h \
    llamps.h \
    ltheme.h \
    lthemeui.h \
    mainwindow.h \
    oven.h \
    sink.h \
    sofa.h \
    stove.h \
    tvstand.h \
    viewbedroom.h \
    viewkitchen.h \
    viewlivingroom.h \
    wardrobe.h

FORMS += \
    bed.ui \
    bedroomdesign.ui \
    bflooring1.ui \
    bfurniture.ui \
    bookshelf.ui \
    btheme1.ui \
    cabinet.ui \
    coffeetable.ui \
    countertop.ui \
    decitems.ui \
    deskchair.ui \
    diningtable.ui \
    floorrug.ui \
    fridge.ui \
    interiordesign.ui \
    kelectronicitems1.ui \
    kfloorui.ui \
    kfurui.ui \
    kitchendesign.ui \
    kthemeui.ui \
    lamps.ui \
    ldecitems.ui \
    lfloorrug.ui \
    lfloorui.ui \
    lfurui.ui \
    livingroomdesign.ui \
    llamps.ui \
    lthemeui.ui \
    mainwindow.ui \
    oven.ui \
    sink.ui \
    sofa.ui \
    stove.ui \
    tvstand.ui \
    viewbedroom.ui \
    viewkitchen.ui \
    viewlivingroom.ui \
    wardrobe.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
