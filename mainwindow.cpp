#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_editHistoryViewImpl(this, &m_historyModel),
    m_request_sender(this),
    m_history_repository("history.db"),
    m_edit_request_presenter(&m_editRequestViewImpl, &m_request_sender, &m_history_repository),
    m_edit_body_presenter(&m_editBodyViewImpl),
    m_response_body_presenter(&m_responseBodyViewImpl),
    m_edit_history_presenter(&m_editHistoryViewImpl, &m_history_repository)
{
    ui->setupUi(this);

    m_sortProxyHistoryModel.setSourceModel(&m_historyModel);
    m_sortProxyHistoryModel.sort(HistoryModel::ColumnId, Qt::DescendingOrder);
    ui->historyTable->setModel(&m_sortProxyHistoryModel);

    m_editRequestViewImpl.setUrlEdit(ui->urlEdit);
    m_editRequestViewImpl.setMethodCombo(ui->methodCombo);
    m_editRequestViewImpl.setSendButton(ui->requestButtons->button(QDialogButtonBox::Ok));

    m_editHistoryViewImpl.setHistoryTable(ui->historyTable);

    m_editBodyViewImpl.setBodyText(ui->bodyText);
    m_responseBodyViewImpl.setResponseText(ui->responseText);

    m_edit_request_presenter.set_edit_body_view(&m_editBodyViewImpl);
    m_edit_request_presenter.set_response_body_view(&m_responseBodyViewImpl);
    m_edit_request_presenter.set_edit_history_view(&m_editHistoryViewImpl);

    m_edit_history_presenter.set_edit_request_view(&m_editRequestViewImpl);
    m_edit_history_presenter.set_edit_body_view(&m_editBodyViewImpl);
    m_edit_history_presenter.set_response_body_view(&m_responseBodyViewImpl);

    connect(ui->requestButtons, &QDialogButtonBox::clicked, [this] (auto button) {
        if (ui->requestButtons->buttonRole(button) == QDialogButtonBox::ResetRole)
            m_edit_request_presenter.on_clear_clicked();
        else if (ui->requestButtons->buttonRole(button) == QDialogButtonBox::AcceptRole)
            m_edit_request_presenter.on_send_request_clicked();
    });

    connect(ui->bodyButtons, &QDialogButtonBox::clicked, [this] (auto button) {
        if (ui->bodyButtons->buttonRole(button) == QDialogButtonBox::ResetRole)
            m_edit_body_presenter.on_clear_clicked();
    });

    connect(ui->responseButtons, &QDialogButtonBox::clicked, [this] (auto button) {
        if (ui->responseButtons->buttonRole(button) == QDialogButtonBox::ResetRole)
            m_response_body_presenter.on_clear_clicked();
    });

    connect(ui->historyTable, &QTableView::activated, [this] {
        m_edit_history_presenter.on_item_clicked();
    });

    connect(ui->removeHistoryButton, &QToolButton::clicked, [this] {
        m_edit_history_presenter.on_remove_clicked();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::run_on_ui(ui_handler::handler_func handler)
{
    QueuedProxyFunction *proxyFunction = new QueuedProxyFunction(handler);
    proxyFunction->moveToThread(qApp->thread());
    proxyFunction->invoke();
    proxyFunction->deleteLater();
}

QueuedProxyFunction::QueuedProxyFunction(std::function<void ()> func, QObject *parent)
    : QObject(parent),
      m_func(func)
{
    connect(this, SIGNAL(invoke()), SLOT(onInvoke()), Qt::QueuedConnection);
}

void QueuedProxyFunction::onInvoke()
{
    m_func();
}
