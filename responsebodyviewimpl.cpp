#include "responsebodyviewimpl.h"

#include <QPlainTextEdit>

void ResponseBodyViewImpl::setResponseText(QPlainTextEdit *responseText)
{
    m_responseText = responseText;
}

void ResponseBodyViewImpl::set_text(const std::string &text)
{
    m_responseText->setPlainText(QString::fromStdString(text));
}
