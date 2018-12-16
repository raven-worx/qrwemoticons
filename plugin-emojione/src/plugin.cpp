#include "plugin.h"

EmoticonEmojionePlugin::EmoticonEmojionePlugin(QObject* parent)
    : QrwEmoticonsPluginInterface(parent)
{
    Q_INIT_RESOURCE(emoticons_emojione_0);
    Q_INIT_RESOURCE(emoticons_emojione_1);
    Q_INIT_RESOURCE(emoticons_emojione_2);
}

EmoticonEmojionePlugin::~EmoticonEmojionePlugin()
{
    //Q_CLEANUP_RESOURCE(emoticons_emojione);
}

QString EmoticonEmojionePlugin::getEmoticonPath(const QrwEmoticons::Emoticon &code) const
{
    return QStringLiteral(":/QrwEmoticons/emojione/") % EMOTICON_FILENAME(code) % QStringLiteral(".png");
}

bool EmoticonEmojionePlugin::hasEmoticon(const QrwEmoticons::Emoticon & code)
{
    const QString fileName = this->getEmoticonPath(code);
    return QFile::exists(fileName);
}

QPixmap EmoticonEmojionePlugin::getEmoticon(const QrwEmoticons::Emoticon & code, const QSize & size)
{
    Q_UNUSED(size);
    const QString fileName = this->getEmoticonPath(code);
    if( QFile::exists(fileName) )
        return QPixmap(fileName);
    return QPixmap();
}
