#ifndef RESPONSEBODYVIEWIMPL_H
#define RESPONSEBODYVIEWIMPL_H

#include <qcompilerdetection.h>
#include <response_body_view.hpp>

class QPlainTextEdit;

class ResponseBodyViewImpl : public response_body_view
{
public:
    void setResponseText(QPlainTextEdit *responseText);
    void set_text(const std::string &text);

private:
    QPlainTextEdit *m_responseText = Q_NULLPTR;
};

#endif // RESPONSEBODYVIEWIMPL_H
