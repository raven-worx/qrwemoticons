#include "MainWindow.h"
#include <QTextEdit>
#include <QtWidgets>
#include <QrwEmoticons/QrwEmoticons>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QrwEmoticonsTextEdit* textEdit = new QrwEmoticonsTextEdit( this );
        QFont font = textEdit->font();
            font.setPixelSize( 30 );
        textEdit->setFont( font );
    this->setCentralWidget( textEdit );

    QToolBar* toolBar = this->addToolBar("");

    QComboBox* providerComboBox = new QComboBox( toolBar );
        providerComboBox->addItems( QStringList() << "google" << "twitter" << "openmoji" << "emojione" );
        providerComboBox->setCurrentText( textEdit->emoticons()->provider() );
    connect( providerComboBox, &QComboBox::currentTextChanged, this, [textEdit](const QString & text) {
        textEdit->emoticons()->setProvider(text);
        textEdit->relayout();
    });
    toolBar->addWidget( providerComboBox );

    QSpinBox* fontSizeSpinBox = new QSpinBox( toolBar );
        fontSizeSpinBox->setRange(1,300);
        fontSizeSpinBox->setValue(font.pixelSize());
    connect( fontSizeSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, [textEdit](int value) {
        QFont font = textEdit->font();
            font.setPixelSize( value );
        textEdit->setFont( font );
    } );
    toolBar->addWidget( fontSizeSpinBox );
}
