import QtQuick
import QtQuick.Controls

Rectangle {
    color: Constants.backgroundColor

    property string showText: "00:00"
    property string pauseText: "Pause"

    TextField {
        id: textField
        x: 40
        y: 100
        width: 80
        height: 40
        text: qsTr("")
        maximumLength: 2
        font.pixelSize: 25
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        onTextChanged: countDown.onTextFieldChanged(text)
    }

    ComboBox {
        id: bgmCombo
        x: 130
        y: 40
        width: 110
        height: 40
        textRole: "text"
        model: [
            { text: qsTr("BGM1") },
            { text: qsTr("BGM2") },
            { text: qsTr("BGM3") }
        ]
        font.pixelSize: 25
    }

    Text {
        id: bgmText
        x: 40
        y: 40
        width: 70
        height: 40
        text: qsTr("BGM:")
        font.pixelSize: 25
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: minText
        x: 150
        y: 100
        width: 60
        height: 40
        text: qsTr("min")
        font.pixelSize: 25
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Button {
        id: startBtn
        x: 280
        y: 100
        width: 110
        height: 40
        text: qsTr("Start")
        font.pixelSize: 25
        onClicked: countDown.onStartBtnClicked()
    }

    Button {
        id: pauseBtn
        x: 400
        y: 100
        width: 110
        height: 40
        text: pauseText
        font.pixelSize: 25
        onClicked: countDown.onPauseBtnClicked()
    }

    Button {
        id: cancelBtn
        x: 520
        y: 100
        width: 110
        height: 40
        text: qsTr("Cancel")
        font.pixelSize: 25
        onClicked: countDown.onCancelBtnClicked()
    }

    Text {
        id: timeText
        x: 50
        y: 150
        width: 540
        height: 300
        text: showText
        font.pixelSize: 200
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}
