#include "edithistoryviewimpl.h"

#include <QApplication>
#include <QMessageBox>
#include <QTableView>

#include "historymodel.h"

EditHistoryViewImpl::EditHistoryViewImpl(QWidget *parent, HistoryModel *model)
    : m_parent(parent),
      m_historyModel(model)
{
}

void EditHistoryViewImpl::setHistoryTable(QTableView *historyTable)
{
    m_historyTable = historyTable;
}

void EditHistoryViewImpl::add_history_line(int id, const std::string &url, http_method method)
{
    m_historyModel->addHistory(id, QString::fromStdString(url), method);
}

int EditHistoryViewImpl::get_current_id() const
{
    return m_historyTable->model()->index(m_historyTable->currentIndex().row(), HistoryModel::ColumnId).data().toInt();
}

void EditHistoryViewImpl::remove(int id)
{
    m_historyModel->removeHistory(id);
}

void EditHistoryViewImpl::show_message(error_message message)
{
    switch (message)
    {
    case error_message::INDEX_OUT_OF_BOUNDS:
        QMessageBox::warning(m_parent, QApplication::applicationName(), QObject::tr("Index out of bounds"));
        break;
    default:
        QMessageBox::warning(m_parent, QApplication::applicationName(), QObject::tr("Unknown error"));
        break;
    }
}
