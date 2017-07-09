#ifndef EDITHISTORYVIEWIMPL_H
#define EDITHISTORYVIEWIMPL_H

#include <qcompilerdetection.h>
#include <edit_history_view.hpp>

class QWidget;
class HistoryModel;
class QTableView;

class EditHistoryViewImpl : public edit_history_view
{
public:
    EditHistoryViewImpl(QWidget *parent, HistoryModel *model);

    void setHistoryTable(QTableView *historyTable);

    void add_history_line(int id, const std::string &url, http_method method);
    int get_current_id() const;
    void remove(int id);

    void show_message(error_message message);

private:
    QWidget * const m_parent;
    HistoryModel * const m_historyModel;
    QTableView *m_historyTable = Q_NULLPTR;
};

#endif // EDITHISTORYVIEWIMPL_H
