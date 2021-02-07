QrwEmoticons
=============
Qt5 (Widgets) Emoticon library and plugins.

Since its pure Qt code you can use it on almost any platform.


![](https://github.com/raven-worx/qrwemoticons/blob/master/demo.gif)


Features
-------------

+ Copy & Paste support
+ Emoticon providers
    + Google Noto-Emoji - [https://github.com/googlei18n/noto-emoji](https://github.com/googlei18n/noto-emoji)
    + OpenMoji - [https://www.openmoji.org](https://www.openmoji.org)
    + JoyPixels - [https://www.joypixels.com](https://www.joypixels.com)
    + Twitter Twemoji - [https://github.com/twitter/twemoji](https://github.com/twitter/twemoji)

How-To Build
-------------

    git clone 
    cd qrwemoticons
    git submodule update --init --recursive
    
Build with QtCreator or manually with qmake and make.

How-To Use
-------------
Link your application against the QrwEmoticons library. For a usage example see the "example-app" project.

The emoticons plugins are loaded from the "emoticons" folder in [Qt's plugin search locations](https://doc.qt.io/qt-5/deployment-plugins.html#the-plugin-directory). For example create a "emoticons" folder next to your application binary or in the Qt installation directory and copy the plugins there. 

Update scripts
-------------

##### Emoticons .qrc files
In case of an update of emoticons of a provider (e.g. submodule update) the qrc files have to be updated accordingly.

To do so run the `generate_emoticon_qrc.py` python script in the plugin source directory.

For example:

    cd plugin-google
    python ../scripts/generate_emoticon_qrc.py --provider google --dir noto-emoji --filename emoticons_google

##### Emoticons unicode data
In case the unicode data table needs to be updated (can be downloaded from https://unicode.org/emoji/charts/full-emoji-list.html) run the `generate_emoticon_data.py` python script (inside the script directory)

    python generate_emoticon_data.py -d data > ..\lib\src\QrwEmoticons_data.cpp

Known issues
-------------

Unfortunately Qt's SVG rendering capabilities are not mature enough to render Google Noto-Emoji icons properly.
Only known workaround is stepping back in the noto submodule to a certain commit when rendering was still working. 

License
-------------
CreativeCommons Attribution 4.0 International (CC BY 4.0)

https://creativecommons.org/licenses/by/4.0/

