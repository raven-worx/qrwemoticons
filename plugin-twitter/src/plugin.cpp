#include "plugin.h"
#include <QrwEmoticonsHelper.h>

EmoticonTwitterPlugin::EmoticonTwitterPlugin(QObject* parent)
    : QrwEmoticonsPluginInterface(parent)
{
    Q_INIT_RESOURCE(emoticons_twitter_0);
    Q_INIT_RESOURCE(emoticons_twitter_1);
    Q_INIT_RESOURCE(emoticons_twitter_2);
}

EmoticonTwitterPlugin::~EmoticonTwitterPlugin()
{
    //Q_CLEANUP_RESOURCE(emoticons_twitter);
}

QString EmoticonTwitterPlugin::getEmoticonPath(const QrwEmoticons::Emoticon &code) const
{
    return QStringLiteral(":/QrwEmoticons/twitter/") % EMOTICON_FILENAME(code) % QStringLiteral(".svg");
}

bool EmoticonTwitterPlugin::hasEmoticon(const QrwEmoticons::Emoticon & code)
{
    const QString fileName = this->getEmoticonPath(code);
    return QFile::exists(fileName);
}

QPixmap EmoticonTwitterPlugin::getEmoticon(const QrwEmoticons::Emoticon & code, const QSize & size)
{
    const QString fileName = this->getEmoticonPath(code);
    QPixmap pix = QrwEmoticonsHelper::SvgToPixmap(fileName, size);
    return pix;
}
