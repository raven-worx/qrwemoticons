#ifndef QRWEMOTICONS_P_H
#define QRWEMOTICONS_P_H

#include <QrwEmoticons/QrwEmoticons>
#include <QPluginLoader>
#include <QJsonObject>
#include <QPointer>

typedef QSet<QrwEmoticons::Emoticon> EmoticonsData;

class QrwEmoticonsPrivate : public QObject
{
    Q_OBJECT

    QRWEMOTICONS_DECLARE_PUBLIC(QrwEmoticons)

public:
    ~QrwEmoticonsPrivate();

    enum TextFormatProperty {
        EmoticonUnicode = QTextFormat::UserProperty,
        EmoticonImagePath,
        EmoticonQString
    };
    Q_ENUMS(TextFormatProperty)

    static QString GetEmoticonString( const QrwEmoticons::Emoticon & code );
    static QString GetEmoticonString( uint character );

protected Q_SLOTS:
    void onTextDocumentContentsChanged(int position, int charsRemoved, int charsAdded);

protected:
    QrwEmoticonsPrivate(QrwEmoticons*, QTextDocument*);

    static const EmoticonsData EMOTICONS;
    static const int EmoticonTextFormatObjectType = QTextFormat::UserObject + 0xEEEE;

    QrwEmoticons* RegisterOnTextDocument( QTextDocument* document );
    void UnregisterFromTextDocument( QTextDocument* document );
    QrwEmoticons* GetFromDocument( const QTextDocument* document );

    bool IsEmoticon( uint character );
    bool IsEmoticon( const QrwEmoticons::Emoticon & code );

    QString getDocumentText( bool html = false ) const;
    QString getCursorText( const QTextCursor & cursor, bool html = false ) const;

    QrwEmoticons::Emoticon getEmoticonCode(QTextCursor c, int* selectionLength );

    void applyTextCharFormat(int pos = 0);

    bool loadPlugin(const QString & id = QString());

    int getLineHeight(int posInDocument, const QTextFormat & format) const;

    struct Plugin {
        QPointer<QrwEmoticonsPluginInterface> interface;
        QJsonObject metaData;
        void clear() {
            interface = Q_NULLPTR;
            metaData = QJsonObject();
        }
    } m_Plugin;

    QPluginLoader   m_PluginLoader;
    bool            m_InApply;
    QTextDocument*  m_TextDocument;
    quint8          m_MaxEmoticonCharCodeCount;
};

inline uint qHash(const QrwEmoticons::Emoticon &code, uint seed)
{
    return qHash(QrwEmoticonsPrivate::GetEmoticonString(code), seed);
}

#endif //QRWEMOTICONS_P_H
