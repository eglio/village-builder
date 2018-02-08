import QtQuick 2.0

Rectangle {
    color:"#DDDDDD"
    height: parent.height-30
    width: parent.height-30

    Grid{
        anchors.fill: parent
        columns: 5
        rows: 5

        Repeater{
            model:25
            Building{
                myIndex: index
                tilesize: parent.height / 5
            }

        }
    }
}
