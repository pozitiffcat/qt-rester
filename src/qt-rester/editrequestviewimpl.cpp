#include "editrequestviewimpl.h"

#include <QLineEdit>
#include <QComboBox>

void EditRequestViewImpl::setUrlEdit(QLineEdit *urlEdit)
{
    m_urlEdit = urlEdit;
}

void EditRequestViewImpl::setMethodCombo(QComboBox *methodCombo)
{
    m_methodCombo = methodCombo;
}

void EditRequestViewImpl::setSendButton(QWidget *widget)
{
    m_sendButton = widget;
}

void EditRequestViewImpl::set_url(const std::string &url)
{
    m_urlEdit->setText(QString::fromStdString(url));
}

std::string EditRequestViewImpl::get_url() const
{
    return m_urlEdit->text().toStdString();
}

void EditRequestViewImpl::set_http_method(http_method method)
{
    switch (method)
    {
    case http_method::GET_HTTP_METHOD:
        m_methodCombo->setCurrentIndex(0);
        break;
    case http_method::POST_HTTP_METHOD:
        m_methodCombo->setCurrentIndex(1);
        break;
    case http_method::PUT_HTTP_METHOD:
        m_methodCombo->setCurrentIndex(2);
        break;
    case http_method::DELETE_HTTP_METHOD:
        m_methodCombo->setCurrentIndex(3);
        break;
    }
}

http_method EditRequestViewImpl::get_http_method() const
{
    switch (m_methodCombo->currentIndex())
    {
    case 0:
        return http_method::GET_HTTP_METHOD;
    case 1:
        return http_method::POST_HTTP_METHOD;
    case 2:
        return http_method::PUT_HTTP_METHOD;
    case 3:
        return http_method::DELETE_HTTP_METHOD;
    default:
        Q_ASSERT_X(false, "get_http_method", "invalid index");
    }
}

void EditRequestViewImpl::set_send_enabled(bool enabled)
{
    m_sendButton->setEnabled(enabled);
}
