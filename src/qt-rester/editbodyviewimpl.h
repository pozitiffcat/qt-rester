#ifndef EDITBODYVIEWIMPL_H
#define EDITBODYVIEWIMPL_H

#include <qcompilerdetection.h>
#include <edit_body_view.hpp>

class QPlainTextEdit;

class EditBodyViewImpl : public edit_body_view
{
public:
    void setBodyText(QPlainTextEdit *bodyText);

    std::string get_text() const;
    void set_text(const std::string &text);

private:
    QPlainTextEdit *m_bodyText = Q_NULLPTR;
};

#endif // EDITBODYVIEWIMPL_H
