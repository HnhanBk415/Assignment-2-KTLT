#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task428()
{
    string name = "Task428";
    
    //! data ------------------------------------
    Vehicle tankOfLiber1(20, 20, Position(1, 2), MORTAR);
    Vehicle tankOfLiber2(5, 20, Position(3, 2), MORTAR);
    Infantry sniperOfLiber1(10, 20, Position(1, 0), SNIPER);
    Infantry sniperOfLiber2(10, 20, Position(1, 1), SNIPER);
    Unit** unitArrayOfLiber8 = new Unit*[4];
    unitArrayOfLiber8[0] = &tankOfLiber1;
    unitArrayOfLiber8[1] = &tankOfLiber2;
    unitArrayOfLiber8[2] = &sniperOfLiber1;
    unitArrayOfLiber8[3] = &sniperOfLiber2;
    LiberationArmy* liberationArmy8 = new LiberationArmy(unitArrayOfLiber8, 4, "LiberationArmy",0);
    
    //! process ---------------------------------
    
    //! expect ----------------------------------
    string expect = "LiberationArmy[LF=38,EXP=400,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SNIPER,quantity=24,weight=20,position=(1,0)],Vehicle[vehicleType=MORTAR,quantity=25,weight=20,position=(1,2)]],battleField=]\n"; // True (1) if all 12 insertions succeeded and 13th failed\n"
    
    //! output ----------------------------------
    stringstream output;
    output << liberationArmy8->str() << endl;
    
    //! remove data -----------------------------
    delete liberationArmy8;
    
    //! result ----------------------------------
    
    return printResult(output.str(), expect, name);
}
