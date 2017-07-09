#ifndef EDITREQUESTVIEWIMPL_H
#define EDITREQUESTVIEWIMPL_H

#include <qcompilerdetection.h>
#include <edit_request_view.hpp>

class QWidget;
class QLineEdit;
class QComboBox;

class EditRequestViewImpl : public edit_request_view
{
public:
    void setUrlEdit(QLineEdit *urlEdit);
    void setMethodCombo(QComboBox *methodCombo);
    void setSendButton(QWidget *widget);

    void set_url(const std::string &url);
    std::string get_url() const;

    void set_http_method(http_method method);
    http_method get_http_method() const;

    void set_send_enabled(bool enabled);

private:
    QLineEdit *m_urlEdit = Q_NULLPTR;
    QComboBox *m_methodCombo = Q_NULLPTR;
    QWidget *m_sendButton = Q_NULLPTR;
};

#endif // EDITREQUESTVIEWIMPL_H
