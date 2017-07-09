#include "historymodel.h"


HistoryModel::HistoryModel()
{
    m_methodNameMap[http_method::GET_HTTP_METHOD] = "GET";
    m_methodNameMap[http_method::POST_HTTP_METHOD] = "POST";
    m_methodNameMap[http_method::PUT_HTTP_METHOD] = "PUT";
    m_methodNameMap[http_method::DELETE_HTTP_METHOD] = "DELETE";
}

void HistoryModel::addHistory(int id, const QString &url, http_method method)
{
    const int row = m_entryList.count();
    beginInsertRows(QModelIndex(), row, row);
    m_entryList.append({id, url, method});
    endInsertRows();
}

void HistoryModel::removeHistory(int id)
{
    int idx = -1;

    for (int i = 0; i < m_entryList.count(); ++i)
    {
        if (m_entryList[i].id == id)
        {
            idx = i;
            break;
        }
    }

    if (idx != -1)
    {
        beginRemoveRows(QModelIndex(), idx, idx);
        m_entryList.removeAt(idx);
        endRemoveRows();
    }
}

int HistoryModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_entryList.count();
}

int HistoryModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return ColumnCount;
}

QVariant HistoryModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
        return {};

    switch (section)
    {
    case ColumnId:
        return tr("Id");
    case ColumnMethod:
        return tr("Method");
    case ColumnUrl:
        return tr("Url");
    default:
        break;
    }

    return {};
}

QVariant HistoryModel::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole)
        return {};

    switch (index.column())
    {
    case ColumnId:
        return m_entryList.value(index.row()).id;
    case ColumnMethod:
        return m_methodNameMap.value(m_entryList.value(index.row()).method);
    case ColumnUrl:
        return m_entryList.value(index.row()).url;
    default:
        break;
    }

    return {};
}

