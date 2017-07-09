#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <edit_body_presenter.hpp>
#include <edit_history_presenter.hpp>
#include <edit_request_presenter.hpp>
#include <response_body_presenter.hpp>
#include <history_repository.hpp>
#include <request_sender.hpp>
#include <ui_handler.hpp>
#include <QSortFilterProxyModel>

#include "editbodyviewimpl.h"
#include "edithistoryviewimpl.h"
#include "editrequestviewimpl.h"
#include "responsebodyviewimpl.h"
#include "historymodel.h"

namespace Ui {
class MainWindow;
}

class QueuedProxyFunction : public QObject
{
    Q_OBJECT

public:
    explicit QueuedProxyFunction(std::function<void()> func, QObject *parent = Q_NULLPTR);

signals:
    void invoke();

private slots:
    void onInvoke();

private:
    std::function<void()> m_func;
};

class MainWindow : public QMainWindow, public ui_handler
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void run_on_ui(handler_func handler);

private:
    Ui::MainWindow *ui;
    HistoryModel m_historyModel;
    EditRequestViewImpl m_editRequestViewImpl;
    EditBodyViewImpl m_editBodyViewImpl;
    ResponseBodyViewImpl m_responseBodyViewImpl;
    EditHistoryViewImpl m_editHistoryViewImpl;
    request_sender m_request_sender;
    history_repository m_history_repository;
    edit_request_presenter m_edit_request_presenter;
    edit_body_presenter m_edit_body_presenter;
    response_body_presenter m_response_body_presenter;
    edit_history_presenter m_edit_history_presenter;
    QSortFilterProxyModel m_sortProxyHistoryModel;
};

#endif // MAINWINDOW_H
