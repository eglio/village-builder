import QtQuick 2.0

Rectangle {
    width:parent.width
    id:status
    height: 30
    color: "#EEEEEE"
    anchors.bottom: parent.bottom

    Text{
        id: textItem
        text:"Welcome! Please click on a tile and choose an action"
        font.pointSize: 18
    }

    Connections {
        target: window
        onReceivedActionPerformed: {
            textItem.text = fieldManager.getLastMessage()
        }
    }
}
