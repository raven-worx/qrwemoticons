#ifndef QRWEMOTICONS_TEXTEDIT_H
#define QRWEMOTICONS_TEXTEDIT_H

#include <QrwEmoticons/Global.h>
#include <QTextEdit>

// TODO: add private class

class QrwEmoticons;

class QRWEMOTICONS_EXPORT QrwEmoticonsTextEdit : public QTextEdit
{
    Q_OBJECT

public:
    explicit QrwEmoticonsTextEdit(QWidget* parent = Q_NULLPTR);

    QString	toHtml() const;
    QString	toPlainText() const;

protected:
    virtual QMimeData* createMimeDataFromSelection() const;

private:
    QrwEmoticons*   m_Emoticons;
};

#endif // QRWEMOTICONS_TEXTEDIT_H
