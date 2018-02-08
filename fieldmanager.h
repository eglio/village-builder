#ifndef FIELDMANAGER_H
#define FIELDMANAGER_H

#include <QObject>
#include "building.h"
#include<QString>

class FieldManager : public QObject
{
    Q_OBJECT

    std::vector<Building> field;

public:
    explicit FieldManager(QObject *parent = nullptr);
    QString lastMessage;
    std::string collectedResourcesString;

    int energyGain =0, moneyGain = 0; //used in "collected resources string"

    Q_INVOKABLE void selectBuilding(int i);
    Q_INVOKABLE void upgradeSelectedBuilding();
    Q_INVOKABLE void demolishSelectedBuilding();
    Q_INVOKABLE void buidInSelectedTile(int type); //manage new build with popup window
    Q_INVOKABLE void collectResources();
    Q_INVOKABLE void newGame();
    Q_INVOKABLE int getAssetID(int i);
    Q_INVOKABLE QString getAvailableEnergy();
    Q_INVOKABLE QString getAvailableMoney();
    Q_INVOKABLE QString getLastMessage();
    void update();



private:
    //config
    int currentBuildingIndex = 0;
    int availableEnergy = 300;
    int availableMoney = 300;
    int demolitionCost = 100; //energy
    int upgradeFactorCost = 200; // money

signals:
    void updateGraphics();
    void actionPerformed();
public slots:
};

#endif // FIELDMANAGER_H
