import QtQuick 2.0
import QtQuick.Dialogs 1.2

Rectangle {
    width:170
    height: parent.height -30
    color: "#EEEEEE"
    anchors.right: parent.right
    anchors.top:parent.top

    Column{
        spacing:10

        Text{
            anchors.horizontalCenter: parent.horizontalCenter
            text:"Village\nbuilder"
            font.bold: true
            font.pointSize: 30
        }

        Text{
            anchors.horizontalCenter: parent.horizontalCenter

            id: energy
            text:"⚡ "
            font.pointSize: 20
        }

        Text{
            anchors.horizontalCenter: parent.horizontalCenter

            id:money
            text:"💲 "
            font.pointSize: 20
        }

        MyButton{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.margins: 10
            label: "Quit"
            MouseArea{
                anchors.fill: parent
                onClicked: {Qt.quit()}
            }
        }

        MyButton{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.margins: 10
            label: "Build"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    typeDialog.open();
                }
            }
        }

        MyButton{
            anchors.margins: 10
            anchors.horizontalCenter: parent.horizontalCenter

            label: "Demolish"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    fieldManager.demolishSelectedBuilding();
                }
            }
        }

        MyButton{
            anchors.margins: 10
            anchors.horizontalCenter: parent.horizontalCenter

            label: "Upgrade"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    fieldManager.upgradeSelectedBuilding();
                }
            }
        }
    }

    Connections {
        target: window
        onReceivedUpdateGraphics: {
            money.text = "💲 " + fieldManager.getAvailableMoney()
            energy.text = "⚡ " + fieldManager.getAvailableEnergy()

        }
    }

    Dialog{
        id:typeDialog
        title: "Select building type"
        //accepted: build power source
        onAccepted: {
            fieldManager.buidInSelectedTile(1);
            this.close()
        }

        //rejected: build money source
        onRejected: {
            fieldManager.buidInSelectedTile(2);
            this.close()
        }

        contentItem: Column{
            spacing:10
            anchors.fill: parent
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 16
                text: "Which kind of building do you want to build?"
            }

            MyButton{
                anchors.horizontalCenter: parent.horizontalCenter
                label: "Power plant"
                textSize: 18
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        typeDialog.accepted()
                    }
                }
            }

            MyButton{
                anchors.horizontalCenter: parent.horizontalCenter
                textSize: 18
                label: "House"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        typeDialog.rejected()
                    }
                }
            }
        }

    }
}
