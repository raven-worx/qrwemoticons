#include "plugin.h"

EmoticonJoypixelsPlugin::EmoticonJoypixelsPlugin(QObject* parent)
    : QrwEmoticonsPluginInterface(parent)
{
    //Q_INIT_RESOURCE(emoticons_joypixels_X);
}

EmoticonJoypixelsPlugin::~EmoticonJoypixelsPlugin()
{
    //Q_CLEANUP_RESOURCE(emoticons_joypixels_X);
}

QString EmoticonJoypixelsPlugin::getEmoticonPath(const QrwEmoticons::Emoticon &code) const
{
    return QStringLiteral(":/QrwEmoticons/joypixels/") % EMOTICON_FILENAME(code) % QStringLiteral(".png");
}

bool EmoticonJoypixelsPlugin::hasEmoticon(const QrwEmoticons::Emoticon & code)
{
    const QString fileName = this->getEmoticonPath(code);
    return QFile::exists(fileName);
}

QPixmap EmoticonJoypixelsPlugin::getEmoticon(const QrwEmoticons::Emoticon & code, const QSize & size)
{
    Q_UNUSED(size);
    const QString fileName = this->getEmoticonPath(code);
    if( QFile::exists(fileName) )
        return QPixmap(fileName);
    return QPixmap();
}
