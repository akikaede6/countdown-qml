import QtQuick
import QtQuick.Window

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Countdown")

    Countdown {
        id: mainScreen
        width: parent.width
        height: parent.height
        scale: Math.min(parent.width / 640, parent.height / 480)
        transformOrigin: Item.TopLeft

        showText: countDown.countText
        pauseText: countDown.pausetext
    }
}
