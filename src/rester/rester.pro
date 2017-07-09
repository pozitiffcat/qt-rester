TARGET = rester
TEMPLATE = lib

SOURCES = \
    rester/src/database_table.cpp \
    rester/src/edit_body_presenter.cpp \
    rester/src/edit_body_view.cpp \
    rester/src/edit_history_presenter.cpp \
    rester/src/edit_history_view.cpp \
    rester/src/edit_request_presenter.cpp \
    rester/src/edit_request_view.cpp \
    rester/src/error_message.cpp \
    rester/src/history_repository.cpp \
    rester/src/http_method.cpp \
    rester/src/request_sender.cpp \
    rester/src/response_body_presenter.cpp \
    rester/src/response_body_view.cpp \
    rester/src/ui_handler.cpp

LIBS += \
    -lsqlite3 \
    -lcurl
