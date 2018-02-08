import QtQuick 2.0

Rectangle {
    id:idButton
        property int margin: 50
        property alias label: caption.text
        property alias textSize: caption.font.pointSize
        color: "gray"
        width:160
        height:50
        radius:10

        Text {
            id: caption
            text: "Show"
            color: "white"
            anchors.centerIn: parent
            font.bold: true
            font.pointSize: 20

            //font{bold:true; pixelSize: 50}
        }


        states: [
            State {
                name:"highlighted"
                PropertyChanges{
                    target:idButton
                    color: "red"
                }
            }
            //+ default state
        ]


        MouseArea{
            anchors.fill: parent
            hoverEnabled: true

               onEntered: {
                    idButton.state = "highlighted"
               }

               onExited: {
                   idButton.state = ""

               }
        }
    }
