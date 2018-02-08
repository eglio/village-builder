import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    id:window
    visible: true
    width: 740
    height: 600
    title: qsTr("Village builder")
    signal receivedUpdateGraphics();
    signal receivedActionPerformed();

    Statusbar{}

    Sidebar{}

    VillageGrid{}

    function onUpdateGraphics(){
        receivedUpdateGraphics();
    }


    function onActionPerformed(){
        receivedActionPerformed()
    }
}
