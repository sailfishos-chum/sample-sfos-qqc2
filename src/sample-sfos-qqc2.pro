QT += quick

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
target.path = /usr/bin
desktop.path  = /usr/share/applications
desktop.files = *.desktop

icons.path    = /usr/share/icons/hicolor/86x86/apps/
icons.files   = sample-sfos-qqc2.png

qml.path    = /usr/share/$$TARGET/
qml.files   = qml/

INSTALLS += target desktop icons qml
