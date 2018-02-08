#ifndef BUILDING_H
#define BUILDING_H
#include <QString>


class Building
{
public:
    Building();
    bool upgrade();
    bool demolish();
    void collectResources();
    QString getInfo();
    bool build(int type);
    int level = 0;
    int type = 0;
    //bool disabled = false;
    int product = 50;
    int getAssetString();
};

#endif // BUILDING_H
