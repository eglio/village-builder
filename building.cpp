    #include "building.h"
#include <QString>
#include <iostream>

/* level values: should use enum?
 * 0 = empty slot
 * 1 = starter building
 * 2-3 = upgrades
 * 4 = obstacle
 */

 /*
  * type values:
  * 0: undefined
  * 1: energy maker
  * 2: money maker
  */

Building::Building()
{
   int temp = rand() % 100 + 1;
   if (temp<=30) this->level = 4; //30% chance of being an obstacle
   else this->level = 0;
}

    bool Building::upgrade(){
        //FieldManager checks for resource
            if (this->level < 3 && this->level >0){
                level++;
                return true;
            }
            return false; //maxed or obstacle
        }

    bool Building::demolish(){
            //FieldManager manages payment, don't pay if nothing present in slot
            if(this->level != 0){
                this->level = 0;
                return true;
            } else {
                return false;
            }
        }

    QString Building::getInfo(){
        switch (level) {
        case 4:
            return "Obstacle, demolish it to build here \n";
            break;
        case 0:
            return "You can build here\n";
            break;
        default: //active building
            if(type == 1) {return "Power plant, produces "+QString::number(product*level)+"⚡, level "+QString::number(level);}
            return "House, produces "+QString::number(product*level)+"💲, level "+QString::number(level);
            break;
        }
    }

    bool Building::build(int type){
        if (level == 0){
            this->type = type;
            this->level = 1;
            return true;
        } //else
        return false;
}

    int Building::getAssetString(){
        /*switch (level) {
        case -1:
            return "obstacle.png";
            break;
        case 0:
            return "blank.png";
            break;
        case 1:
            if(type == 1)return "power"+QString::number(level) + ".png"; //energy
            else return "money"+QString::number(level) + ".png"; //money
            break;
        case 2:
            if(type == 1)return "power"+QString::number(level) + ".png"; //energy
            else return "money"+QString::number(level) + ".png"; //money
        case 3:
            if(type == 1)return "power"+QString::number(level) + ".png"; //energy
            else return "money"+QString::number(level) + ".png"; //money
            break;
        default:
            return "blank.png";
            break;*/

        switch (level) {
        case 4:
            return 7;
            break;
        case 0:
            return 0;
            break;
        default:
            if (type==1) return level;
            else return level + 3;
            break;
        }
    }
