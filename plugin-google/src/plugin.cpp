#include "plugin.h"
#include <QrwEmoticonsHelper.h>
#include <QPainter>
#include <QPixmapCache>
#include <QSvgRenderer>

EmoticonGooglePlugin::EmoticonGooglePlugin(QObject* parent)
    : QrwEmoticonsPluginInterface(parent)
{
    //Q_INIT_RESOURCE(emoticons_google_X);
}

EmoticonGooglePlugin::~EmoticonGooglePlugin()
{
    //Q_CLEANUP_RESOURCE(emoticons_google_X);
}

QString EmoticonGooglePlugin::getEmoticonPath(const QrwEmoticons::Emoticon &code) const
{
    // Google-Noto doesn't add variation selectors (0xFE0E and 0xFE0F) to their filenames?!
    QrwEmoticons::Emoticon c = code;
        c.removeAll(0xFE0E);
        c.removeAll(0xFE0F);
    return QStringLiteral(":/QrwEmoticons/google/") % EMOTICON_FILENAME(c) % QStringLiteral(".svg");
}

bool EmoticonGooglePlugin::hasEmoticon(const QrwEmoticons::Emoticon & code)
{
    const QString fileName = this->getEmoticonPath(code);
    return QFile::exists(fileName);
}

QPixmap EmoticonGooglePlugin::getEmoticon(const QrwEmoticons::Emoticon & code, const QSize & size)
{
    const QString fileName = this->getEmoticonPath(code);
    QPixmap pix = QrwEmoticonsHelper::SvgToPixmap(fileName, size);
    return pix;
}
