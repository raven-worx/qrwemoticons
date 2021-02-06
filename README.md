QrwEmoticons
=============
Qt5 (Widgets) Emoticon library and plugins

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
    git submodule update --init --recursice
    qmake QrwEmoticons.pro
    make
    make install # install to Qt directory

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

License
-------------
CreativeCommons Attribution 4.0 International (CC BY 4.0)

https://creativecommons.org/licenses/by/4.0/

