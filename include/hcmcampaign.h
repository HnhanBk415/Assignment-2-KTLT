/*
 * Ho Chi Minh City University of Technology
 * Faculty of Computer Science and Engineering
 * Initial code for Assignment 2
 * Programming Fundamentals Spring 2025
 * Date: 02.02.2025
 */

// The library here is concretely set, students are not allowed to include any other libraries.
#ifndef _H_HCM_CAMPAIGN_H_
#define _H_HCM_CAMPAIGN_H_

#include "main.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Forward declaration
class Unit;
class UnitList;
class Army;
class TerrainElement;

class Vehicle;
class Infantry;

class LiberationArmy;
class ARVN;

class Position;

class Road;
class Mountain;
class River;
class Urban;
class Fortification;
class SpecialZone;

class BattleField;

class HCMCampaign;
class Configuration;

enum VehicleType
{
    TRUCK,
    MORTAR,
    ANTIAIRCRAFT,
    ARMOREDCAR,
    APC,
    ARTILLERY,
    TANK
};
enum InfantryType
{
    SNIPER,
    ANTIAIRCRAFTSQUAD,
    MORTARSQUAD,
    ENGINEER,
    SPECIALFORCES,
    REGULARINFANTRY
};
enum TerrainType
    {
        ROAD,
        FOREST,
        RIVER,
        FORTIFICATION,
        URBAN,
        SPECIAL_ZONE
    };
//Hàm phục vụ cho các hàm tự tạo của em
class HN415function{
    public:
    static string trimbyhn(const string &s); 
    static void checkLFandEXP(int& LF, int& EXP);
    static int Sceil(double value);
    static bool isBaseNumber(int number, int primeNumber);
    static bool isSpecailNumber(int number);
    static bool Issquarenumbercheck(int n);
    static int TotalDigits(int n);
    static int ComputeSingleDDigts(int score, int year);
    static  double calculateDistance(const Position& pos1, const Position& pos2);
    static int clampValue(int value, int minVal, int maxVal);
    static  int nearestFibonacci(int value);
    static TerrainType findnameT(const std::string &name);
    static InfantryType findnameI(const std::string &name);
    static VehicleType findnameV(const std::string &name);
    static int checknumbername(const std::string &s);
};
class Army
{
protected:
    int LF, EXP;
    string name;

    BattleField *battleField;

public:
    Army(Unit **unitArray, int size, string name, BattleField *battleField);
    virtual ~Army();
    virtual void fight(Army *enemy, bool defense = false) = 0;
    virtual string str() const = 0;
    UnitList *unitList; 
    UnitList* returnUnitList();
    void updateScore(bool update);
    int getLF() const;
    int getEXP() const;
    void setLF(int lf);
    void setEXP(int exp);
    

};
   class LiberationArmy : public Army
    {
    private:
        Unit **unitArray;   
        vector<Unit*> knapsackfind(vector<Unit*> units, int maxScore);
        Unit* cloneUnit(Unit* unit);
        int size_V = 0;
        int size_I = 0;
        vector<Unit*> cloneUnitAddress;
    public:
        LiberationArmy(Unit **unitArray, int size, string name, BattleField *battleField);
        ~LiberationArmy();
        void fight(Army *enemy, bool defense) override;
        string str() const override;
    };
    class ARVN : public Army
    { 
    public:
        ARVN(Unit** unitArray, int size, string name, BattleField *battleField);
        void fight(Army* enemy, bool defense=false) override;
        string str() const;
        
        vector<Unit*> knapsackfind(vector<Unit*> units, int maxScore);
    };

class Position
{
private:
    int r, c;

public:
    Position(int r = 0, int c = 0);
    Position(const string &str_pos); // Example: str_pos = "(1,15)"
    int getRow() const;
    int getCol() const;
    void setRow(int r);
    void setCol(int c);
    string str() const; // Example: returns "(1,15)"
};

class Unit
{
protected:
    int quantity, weight;
    Position pos;
    int belong;
public:
    int attackcurrent;
    int returnAttackcurrent() const;
    void setAttackcurrent(int score);

    Unit(int quantity, int weight, Position pos);
    virtual ~Unit();
    virtual int getAttackScore() = 0;
    Position getCurrentPosition() const;
    virtual string str() const = 0;
    
    int getQuantity();
    int getWeight();
    void setQuantity(int quantity);
    void setWeight(int weight);
    void setBelong(int b);
    int getBelong() const;
    virtual int returnType() = 0;
    void setPosition(const Position& newPos);
};
class Infantry : public Unit{
 protected:
        InfantryType infantryType;
 public:
    Infantry(int quantity, int weight, const Position& pos, InfantryType infantryType);
        int getAttackScore() override;
       
        string str() const override; 
        int returnType() override;
        string TypetoStringI(InfantryType It) const;
        
};
class Vehicle : public Unit
    {
    protected:
        VehicleType vehicleType;  

    public:
        
        Vehicle(int quantity, int weight, const Position& pos, VehicleType vehicleType);
        int getAttackScore() override;
        string str() const override;
        int returnType() override;
        string TypetoStringV(VehicleType vt) const;
    };
//unitlist
class Node{
        public:
            Unit* unit;
            Node* next;
            Node(Unit* u) : unit(u), next(nullptr){}
};
class UnitList
{
private:
    int capacity;
    int countV, countI;
    int Sizecurr;
public:
    Node* head;
    Node* tail;
    int getCount() const;
    Node* getHead() const;
    UnitList(int capacity);
     UnitList(const UnitList& other); 
     UnitList& operator=(const UnitList& other);
    ~UnitList();
    bool insert(Unit *unit);                   // return true if insert successfully
    bool isContain(VehicleType vehicleType);   // return true if it exists
    bool isContain(InfantryType infantryType); // return true if it exists
    string str() const;
    string toString() const;
    void remove(Unit *unit);
    int getCapacity() const;
    int getCountV() const;
    int getCountI() const;
    void setCountV(int val);
    void setCountI(int val);
    void setSizecurr(int);
    int getSizecurr();
};

class TerrainElement
{
protected:
    Position pos; 
   
public:
    TerrainElement(Position);
    virtual ~TerrainElement();
    virtual void getEffect(Army *army) = 0;
};
 class Road : public TerrainElement {
    public:
        Road(Position pos) : TerrainElement(pos) {}
        // Đường mòn không có hiệu ứng
        void getEffect(Army *army);
    };
class Mountain : public TerrainElement {
    public:
        Mountain(Position pos) : TerrainElement(pos) {}
        // Rừng núi: hiệu ứng áp dụng (stub) 
        void getEffect(Army *army);
    };

    class River : public TerrainElement {
    public:
        River(Position pos) : TerrainElement(pos) {}
        
        void getEffect(Army *army);
    };

    class Urban : public TerrainElement {
    public:
        Urban(Position pos) : TerrainElement(pos) {}
        
        void getEffect(Army *army);
    };

    class Fortification : public TerrainElement {
    public:
        Fortification(Position pos) : TerrainElement(pos) {} 
    
        void getEffect(Army *army);
    };

    class SpecialZone : public TerrainElement {
    public:
        SpecialZone(Position pos) : TerrainElement(pos) {}

        void getEffect(Army *army);
    };
 class BattleField {
    private:
        int n_rows, n_cols;
        TerrainElement ***terrain;
    public:
        
        BattleField(int n_rows, int n_cols, const vector<Position*>& arrayForest,
                    const vector<Position*>& arrayRiver, const vector<Position*>& arrayFortification,
                    const vector<Position*>& arrayUrban, const vector<Position*>& arraySpecialZone);
        ~BattleField();
        

        TerrainElement* getElement(int r, int c) const;
        
        string str() const;
    };
 class Configuration {
    private:
        class TerrainInfo{
            string key;
            string value;
        };
       
        int terrainInfoCount = 0;
        int num_rows;
        int num_cols;
        vector<Position*> arrayForest;
        vector<Position*> arrayRiver;
        vector<Position*> arrayFortification;
        vector<Position*> arrayUrban;
        vector<Position*> arraySpecialZone;
        Unit** liberationUnits = nullptr;
        Unit** ARVNUnits = nullptr;
        int liberationSize = 0;
        int ARVNSize = 0;
        int eventCode;
    public:
        Configuration(const string & filepath);
        ~Configuration();
        string str() const;
        string trimbyhn(const string &s);
        bool isVehicle(const string &name);
        int getNumRows() const { return num_rows; }
        int getNumCols() const { return num_cols; }
        const vector<Position*>& getForestPositions() const { return arrayForest; }
        const vector<Position*>& getRiverPositions() const { return arrayRiver; }
        const vector<Position*>& getFortificationPositions() const { return arrayFortification; }
        const vector<Position*>& getUrbanPositions() const { return arrayUrban; }
        const vector<Position*>& getSpecialZonePositions() const { return arraySpecialZone; }
        int getEventCode() const { return eventCode; }
        Unit** getLiberationUnits() const { return liberationUnits; }
        int getLiberationSize() const { return liberationSize; }

        Unit** getARVNUnits() const { return ARVNUnits; }
        int getARVNSize() const { return ARVNSize; }
        void analysisUnit(const string &content);
        void locationArray(const string &val, vector<Position*> &arrayTarget);
        
    };
class HCMCampaign
{
private:
   Configuration* config;
        BattleField* battleField;
        LiberationArmy* liberationArmy;
        ARVN* arvnArmy;

public:
    HCMCampaign(const string &config_file_path);
     ~HCMCampaign();
    void run();
    string printResult();
};
//class HCM

#endif