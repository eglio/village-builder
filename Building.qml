import QtQuick 2.0

Rectangle {
    id: bld
    property int tilesize: parent.height / 5

    property int myIndex: 0
    width: tilesize
    height: tilesize
    color: "#8DBD0C"
    border.color: "#8DBD0C"

    property alias picture: coverImage
    property var assetNames: ["blank.png","power1.png","power2.png","power3.png","money1.png","money2.png", "money3.png","obstacle.png"]

    Image {
        id:coverImage
        anchors.centerIn: parent
        source: "blank.png"
        width: parent.width - 20
        height: parent.height - 20

        }

        states: [
    State {
        name:"hover"
        PropertyChanges{
            target:bld
            border.color: "black"
        }
    }
    ]

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true

        onClicked: {
            fieldManager.selectBuilding(myIndex);
        }

        onEntered: {
            bld.state="hover"
        }

        onExited: {
            bld.state=""
        }
    }

    Connections {
        target: window
        onReceivedUpdateGraphics: {
            var assetID = fieldManager.getAssetID(myIndex)
            picture.source= assetNames[assetID]
        }
    }
}
