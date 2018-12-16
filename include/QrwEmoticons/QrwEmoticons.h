#ifndef QRWEMOTICONS_H
#define QRWEMOTICONS_H

#include <QrwEmoticons/Global.h>
#include <QtGui/QTextDocument>
#include <QtGui/QTextObjectInterface>

class QrwEmoticonsPrivate;

class QRWEMOTICONS_EXPORT QrwEmoticons : public QObject, public QTextObjectInterface
{
    Q_OBJECT
    Q_INTERFACES(QTextObjectInterface)

    Q_PROPERTY( QString plugin READ plugin WRITE setPlugin NOTIFY pluginChanged )
    //Q_PROPERTY( int maxCharCount READ maxCharCount WRITE setMaxCharCount NOTIFY maxCharCountChanged )
    //Q_PROPERTY( QSize minimumSize READ minimumSize WRITE setMinimumSize NOTIFY minimumSizeChanged )
    //Q_PROPERTY( bool svgEnabled READ svgEnabled WRITE setSvgEnabled NOTIFY svgEnabledChanged )

    QRWEMOTICONS_DECLARE_PRIVATE(QrwEmoticons)

public:
    explicit QrwEmoticons(QTextDocument* document, QObject* parent = Q_NULLPTR);
    virtual ~QrwEmoticons() Q_DECL_OVERRIDE;

    typedef QVector<uint> Emoticon;

    QString getPlainText() const;
    QString getPlainText(const QTextCursor & cursor) const;
    QString getHtml() const;
    QString getHtml(const QTextCursor & cursor) const;

    // QTextObjectInterface interface
    virtual void drawObject(QPainter* painter, const QRectF & rect, QTextDocument* doc, int posInDocument, const QTextFormat & format) Q_DECL_OVERRIDE;
    virtual QSizeF intrinsicSize(QTextDocument* doc, int posInDocument, const QTextFormat & format) Q_DECL_OVERRIDE;

    QString plugin() const;
    void setPlugin(const QString & plugin);

Q_SIGNALS:
    void pluginChanged(const QString & plugin);
};

Q_DECLARE_METATYPE(QrwEmoticons::Emoticon)

#endif // QRWEMOTICONS_H
