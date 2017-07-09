TEMPLATE = subdirs

SUBDIRS = \
    qt-rester \
    rester

qt-rester.subdir = src/qt-rester
rester.subdir  = src/rester

qt-rester.depends = rester
