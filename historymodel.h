#ifndef HISTORYMODEL_H
#define HISTORYMODEL_H

#include <QAbstractTableModel>

#include <http_method.hpp>

class HistoryModel : public QAbstractTableModel
{
private:
    struct Entry
    {
        int id = 0;
        QString url;
        http_method method = http_method::GET_HTTP_METHOD;
    };

public:
    enum Column
    {
        ColumnId,
        ColumnMethod,
        ColumnUrl,
        ColumnCount
    };

public:
    HistoryModel();

    void addHistory(int id, const QString &url, http_method method);
    void removeHistory(int id);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role) const;

private:
    QMap<http_method, QString> m_methodNameMap;
    QList<Entry> m_entryList;
};

#endif // HISTORYMODEL_H
