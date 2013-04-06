TEMPLATE      = lib
QT += core dbus
CONFIG       += plugin gui meegotouch link_pkgconfig
PKGCONFIG += gq-gconf

INCLUDEPATH += $$(SYSROOT_DIR)/usr/include/meegotouch
INCLUDEPATH += $$(SYSROOT_DIR)/usr/include/system-ui/statusindicatormenu

TARGET        = statusindicatormenu-brightness
target.path = /usr/lib/meegotouch/applicationextensions

desktop.files = statusindicatormenu-brightness.desktop
desktop.path = /usr/share/meegotouch/applicationextensions

png.files = icon-brightness-alpha.png
png.path = /usr/share/themes/blanco/meegotouch/icons

hacky.files = set_brightness.sh
hacky.path = /opt/system-ui-brightness/bin

INSTALLS += target desktop png hacky

HEADERS += \
    MBExtensionPlugin.h \
    MBExtensionController.h \
    MBrightnessLabel.h \
    MBrightnessBar.h

SOURCES += \
    MBExtensionController.cpp \
    MBExtensionPlugin.cpp \
    MBrightnessLabel.cpp \
    MBrightnessBar.cpp

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog \
    qtc_packaging/debian_harmattan/preinst \
    qtc_packaging/debian_harmattan/postrm \
    qtc_packaging/debian_harmattan/postinst \
    qtc_packaging/debian_harmattan/prerm \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog \
    qtc_packaging/debian_harmattan/prerm \
    qtc_packaging/debian_harmattan/preinst \
    qtc_packaging/debian_harmattan/postrm \
    qtc_packaging/debian_harmattan/postinst
