#ifndef EMOTICON_EMOJIONE_PLUGIN_H
#define EMOTICON_EMOJIONE_PLUGIN_H

#include <QObject>
#include <QrwEmoticons/QrwEmoticons.h>
#include <QrwEmoticons/QrwEmoticonsPlugin.h>

class EmoticonJoypixelsPlugin : public QrwEmoticonsPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QrwEmoticonsPluginInterface_iid FILE "plugin.json")
    Q_INTERFACES(QrwEmoticonsPluginInterface)

public:
    explicit EmoticonJoypixelsPlugin(QObject *parent = nullptr);
    ~EmoticonJoypixelsPlugin();

    virtual bool hasEmoticon(const QrwEmoticons::Emoticon & code) Q_DECL_OVERRIDE;
    virtual QPixmap getEmoticon(const QrwEmoticons::Emoticon & code, const QSize & size) Q_DECL_OVERRIDE;

private:
    QString getEmoticonPath(const QrwEmoticons::Emoticon &code) const;
};

#endif // EMOTICON_EMOJIONE_PLUGIN_H
