#include <QrwEmoticons/QrwEmoticons.h>
#include "QrwEmoticons_p.h"
#include <QPainter>

QrwEmoticons::QrwEmoticons(QTextDocument* document, QObject* parent)
    : QObject(parent)
{
    p_ptr = new QrwEmoticonsPrivate(this, document);
}

QrwEmoticons::~QrwEmoticons()
{
}

QString QrwEmoticons::getPlainText() const
{
    Q_D(const QrwEmoticons);
    return d->getDocumentText( false );
}

QString QrwEmoticons::getPlainText(const QTextCursor & cursor) const
{
    Q_D(const QrwEmoticons);
    return d->getCursorText( cursor, false );
}

QString QrwEmoticons::getHtml() const
{
    Q_D(const QrwEmoticons);
    return d->getDocumentText( true );
}

QString QrwEmoticons::getHtml(const QTextCursor & cursor) const
{
    Q_D(const QrwEmoticons);
    return d->getCursorText( cursor, true );
}

void QrwEmoticons::drawObject(QPainter* painter, const QRectF & rect, QTextDocument* doc, int posInDocument, const QTextFormat & format)
{
    Q_D(QrwEmoticons);

    Q_UNUSED(doc);
    Q_UNUSED(posInDocument);

    const QrwEmoticons::Emoticon code = format.property( QrwEmoticonsPrivate::EmoticonUnicode ).value<QrwEmoticons::Emoticon>();
    //const QString emoticonImagePath = format.stringProperty( QrwEmoticonsPrivate::EmoticonImagePath );
    //const QPixmap pix( emoticonImagePath );

    // TODO: check if plugin is loaded

    const QRectF drawRect = rect.adjusted(2,0,-2,0);
    painter->save();
        if( !d->m_Plugin.interface->hasEmoticon(code) )
        {
            painter->setPen( QPen(Qt::darkGray, 1, Qt::SolidLine) );
            painter->setBrush( QColor(240,240,240) );
            painter->drawRect( drawRect );
            painter->setFont( QFont("typewriter", 6) );

            //QString codeStr = QString::number(emoticonCode,16).toUpper();
            //while( codeStr.length() < 6 )
            //    codeStr.prepend(QLatin1Char('0'));
            //painter->drawText( drawRect, Qt::AlignCenter, QString("%1\n%2").arg(codeStr.left(3)).arg(codeStr.right(3)) );
            painter->drawText( drawRect, Qt::AlignCenter, QString("?") );
        }
        else
        {
            const QPixmap pix = d->m_Plugin.interface->getEmoticon(code, drawRect.size().toSize());

            painter->setPen( Qt::NoPen );
            painter->setBrush( Qt::NoBrush );
            painter->drawPixmap( rect.adjusted(1,0,-1,0), pix, QRectF(QPointF(0,0),pix.size()) );
        }
    painter->restore();
}

QSizeF QrwEmoticons::intrinsicSize(QTextDocument* doc, int posInDocument, const QTextFormat & format)
{
    Q_D(QrwEmoticons);
    int height = d->getLineHeight(posInDocument, format);
    return QSize(height+2, height);
}

QString QrwEmoticons::plugin() const
{
    Q_D(const QrwEmoticons);
    return d->m_Plugin.metaData.value(QStringLiteral("id")).toString();
}

void QrwEmoticons::setPlugin(const QString & plugin)
{
    Q_D(QrwEmoticons);
    d->loadPlugin(plugin);
}
