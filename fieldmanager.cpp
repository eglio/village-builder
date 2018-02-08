#include "FieldManager.h"
#include <stdlib.h>
#include <iostream>

//#include "xmlparser.h"

FieldManager::FieldManager(QObject *parent) : QObject(parent)
{
}

void FieldManager::newGame() {
    field.clear();
    for (int i = 0; i < 25; i++)
    {
        Building* b = new Building();
        field.push_back(*b);
    }
}

void FieldManager::upgradeSelectedBuilding(){
    //upgrading only costs money, level acts as price multiplier
    int price = (field.at(currentBuildingIndex).level);
    price*= upgradeFactorCost;
    if(price>=availableMoney) {
        this->lastMessage = "Not enough money\n";
        emit actionPerformed();} //unaffordable
    else{ //affordable
        if(field.at(currentBuildingIndex).upgrade()) {
            availableMoney -= price;
            this->collectResources();
            emit updateGraphics();
            this->lastMessage = QString::fromStdString("Building upgraded"+this->collectedResourcesString);
            emit actionPerformed();
        }
        else {this->lastMessage = "Can't upgrade this";
                emit actionPerformed();}
    }
}

void FieldManager::demolishSelectedBuilding(){
    //demolishing only costs energy
    if (availableEnergy >= demolitionCost){ //affordable
        if(field.at(currentBuildingIndex).demolish()){
            //demolished
            availableEnergy -= demolitionCost;
            this->collectResources();
            emit updateGraphics();
            this->lastMessage = QString::fromStdString("Demolished"+this->collectedResourcesString);
            emit actionPerformed();
        }
        else { this->lastMessage ="nothing to demolish";
            emit actionPerformed();}
    } else{
    this->lastMessage = "Not enough energy";
    emit actionPerformed();} //not affordable
}

void FieldManager::buidInSelectedTile(int type){
    //building only costs energy
    if(availableEnergy >= demolitionCost){ //affordable
        if(field.at(currentBuildingIndex).build(type)){
            availableEnergy -= demolitionCost;
            this->collectResources();
            emit updateGraphics();
            this->lastMessage =  QString::fromStdString("Built new building"+this->collectedResourcesString);
            emit actionPerformed();
        }else{
            this->lastMessage = "Can't build here!";
            emit actionPerformed();
        }
    }
    else{this->lastMessage = "Not enough energy!";
        emit actionPerformed();}

}

void FieldManager::collectResources(){
    //reset gain values
    this->energyGain = 0;
    this->moneyGain = 0;
    for_each(field.begin(), field.end(),[this](Building b)mutable{
        //get resurces based on type and lelvel. level acts as multiplier
        int gain = b.product * b.level;
        if (b.level>0 && b.level <4){ //active building
                if (b.type == 1){ availableEnergy += gain; this->energyGain +=gain;} //energy source
                if (b.type == 2){ availableMoney += gain; this->moneyGain +=gain;} //money source
            }
    }); //should use getters/setters instead of having public attributes
    //total gain
    this->collectedResourcesString = ", collected "+ std::to_string(energyGain) + " ⚡ and " + std::to_string(moneyGain) +"💲";
}

void FieldManager::selectBuilding(int index){
   currentBuildingIndex = index;
   this->lastMessage = field.at(index).getInfo();
   emit actionPerformed();
}

int FieldManager::getAssetID(int i){
    return field.at(i).getAssetString();
}

QString FieldManager::getAvailableMoney(){
    std::string temp = std::to_string(this->availableMoney);
    return QString::fromStdString(temp);
}

QString FieldManager::getAvailableEnergy(){
    std::string temp = std::to_string(this->availableEnergy);
    return QString::fromStdString(temp);
}

QString FieldManager::getLastMessage(){
    return this->lastMessage;
}

void FieldManager::update(){
    emit updateGraphics();
}
