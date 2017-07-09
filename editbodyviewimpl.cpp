#include "editbodyviewimpl.h"

#include <QPlainTextEdit>

void EditBodyViewImpl::setBodyText(QPlainTextEdit *bodyText)
{
    m_bodyText = bodyText;
}

std::string EditBodyViewImpl::get_text() const
{
    return m_bodyText->toPlainText().toStdString();
}

void EditBodyViewImpl::set_text(const std::string &text)
{
    m_bodyText->setPlainText(QString::fromStdString(text));
}
