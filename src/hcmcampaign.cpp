#include "hcmcampaign.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
////////////////////////////////////////////////////////////////////////

// 0. Class của em tự tạo thêm
int HN415function::Sceil(double value)
{
    int value1 = round(value);
    double diff = value - value1;
    if (abs(diff) < 1e-7) return value1;
    return ceil(value);
}
void HN415function::checkLFandEXP(int& LF, int& EXP)
{
    if (LF < 0) LF = 0;
    else if (LF > 1000) LF = 1000;

    if (EXP < 0) EXP = 0;
    else if (EXP > 500) EXP = 500;
}
bool HN415function::isBaseNumber(int number, int primeNumber)
{
    while(number > 0){
    if(number % primeNumber != 0 && number % primeNumber != 1)
    {
        return false;
    }
    number /= primeNumber;
    }
    return true;
}
bool HN415function::isSpecailNumber(int number)
{
    if(number < 0) return false;
    if(number == 0 || number == 1) return true;
    int numberPrime[3] = {3, 5, 7};
    for(int i = 0; i < 3; i++){
        if(isBaseNumber(number, numberPrime[i])) 
    return true;
    }
    return false;
}

 bool HN415function::Issquarenumbercheck(int n)
 {
    if (n < 0) return false;
    int r = sqrt(n);
    return r * r == n;
 }
int HN415function::TotalDigits(int n)
{
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
}
int HN415function::ComputeSingleDDigts(int score, int year)
{
    int total = HN415function::TotalDigits(score) + HN415function::TotalDigits(year);
        while (total >= 10) {
            total = HN415function::TotalDigits(total);
        }
    return total;
}
 double HN415function::calculateDistance(const Position& pos1, const Position& pos2) 
{
        int rowDiff = pos1.getRow() - pos2.getRow();
        int colDiff = pos1.getCol() - pos2.getCol();
        return (sqrt(double(rowDiff * rowDiff + colDiff * colDiff)));
}
int HN415function::clampValue(int value, int minVal, int maxVal) 
{
    if (value < minVal) return minVal;
    if (value > maxVal) return maxVal;
    return value;
}
 int HN415function::nearestFibonacci(int value) {
    int n1, n2, n3;
    n1 = 1;
    n2 = 1;
    if(n1 > value)
    return n1;
    n3 = n1 + n2;
    while(value >= n3){
        n1 = n2;
        n2 = n3;
        n3 = n1 + n2;
    }
    return n3;
    }

int HN415function::checknumbername(const std::string &s)
{
    if (s == "ROAD") return 1;
    if (s == "FORTIFICATION") return 2;
    if (s == "FOREST") return 3;
    if (s == "URBAN") return 4;
    if (s == "RIVER") return 5;
    if (s == "SPECIAL_ZONE") return 6;

    if (s == "SNIPER") return 10;
    if (s == "ANTIAIRCRAFTSQUAD") return 11;
    if (s == "MORTARSQUAD") return 12;
    if (s == "ENGINEER") return 13;
    if (s == "SPECIALFORCES") return 14;

    if (s == "TRUCK") return 20;
    if (s == "MORTAR") return 21;
    if (s == "ANTIAIRCRAFT") return 22;
    if (s == "ARMOREDCAR") return 23;
    if (s == "APC") return 24;
    if (s == "ARTILLERY") return 25;

    return -1;
}
TerrainType HN415function::findnameT(const std::string &name)
{
    switch(checknumbername(name)){
        case 1: return ROAD;
        case 2: return FORTIFICATION;
        case 3: return FOREST;
        case 4: return URBAN;
        case 5: return RIVER;
        case 6: return SPECIAL_ZONE;
        default: return ROAD;
    }
}
InfantryType HN415function::findnameI(const std::string &name) {
    switch (checknumbername(name)) {
        case 10: return SNIPER;
        case 11: return ANTIAIRCRAFTSQUAD;
        case 12: return MORTARSQUAD;
        case 13: return ENGINEER;
        case 14: return SPECIALFORCES;
        default: return REGULARINFANTRY; 
    }
}
VehicleType HN415function::findnameV(const std::string &name) {
    switch (checknumbername(name)) {
        case 20: return TRUCK;
        case 21: return MORTAR;
        case 22: return ANTIAIRCRAFT;
        case 23: return ARMOREDCAR;
        case 24: return APC;
        case 25: return ARTILLERY;
        default: return TANK;  
    }
}
// 1. Class Unit
Unit::Unit(int quantity, int weight, Position pos)
        : quantity(quantity), weight(weight), pos(pos)
    {
    }
 Unit::~Unit()
    {
    } 
void Unit::setPosition(const Position& newPos){
        pos = newPos;
    }
Position Unit::getCurrentPosition() const{
        return pos;
    }      
 int Unit::returnAttackcurrent() const{
        return attackcurrent;
    }
void Unit::setAttackcurrent(int score){
        this->attackcurrent = score;
    }
 int Unit::getQuantity() { 
        return quantity;
    }
    int Unit::getWeight(){
        return weight;
    }
    void Unit::setQuantity(int quantity){
        if(quantity < 1) this->quantity = 1;
            else this->quantity = quantity;
    }
    void Unit::setWeight(int weight){
        if(weight < 1) this->weight = 1;
            else this->weight = weight;
    }
    void Unit::setBelong(int b){
        belong = b;
    }
    int Unit::getBelong() const{
        return belong;
    }

// 2.Class infantry
 Infantry::Infantry(int quantity, int weight, const Position& pos, InfantryType infantryType)
            : Unit((quantity < 1 ? 1 : quantity), (weight < 1 ? 1 : weight), pos), infantryType(infantryType) 
    {
    }
  string Infantry::TypetoStringI(InfantryType It) const
    {
        if (It == SNIPER) return "SNIPER";
        else if (It == ANTIAIRCRAFTSQUAD) return "ANTIAIRCRAFTSQUAD";
        else if (It == MORTARSQUAD) return "MORTARSQUAD";
        else if (It == ENGINEER) return "ENGINEER";
        else if (It == SPECIALFORCES) return "SPECIALFORCES";
        else if(It == REGULARINFANTRY) return "REGULARINFANTRY";
            else return "UNKNOWN";
    }   
    int Infantry::getAttackScore() {
    int new_quantity = quantity;
    double score = HN415function::Sceil((int)infantryType*56 + quantity*weight);
    if (infantryType == InfantryType::SPECIALFORCES && HN415function::Issquarenumbercheck(weight))
    {
        score += 75;
    }
    if (HN415function::ComputeSingleDDigts(score, 1975) > 7) 
    {
        quantity = HN415function::Sceil((double)new_quantity*1.2);
    }
    else if (HN415function::ComputeSingleDDigts(score, 1975) < 3) 
    {
        quantity = HN415function::Sceil((double)new_quantity*0.9);
    }
    score = HN415function::Sceil((int)infantryType*56 + quantity*weight);
    this->attackcurrent = score;
    return this->attackcurrent;
    }
    string Infantry::str() const {
        stringstream ss;
            ss << "Infantry[infantryType=" << TypetoStringI(infantryType)
                << ",quantity=" << quantity
                << ",weight=" << weight
                << ",position=" << pos.str() << "]";
            return ss.str();
    }
    int Infantry::returnType() { 
        return infantryType;
    }

// 3. Class Vehicle 
 Vehicle:: Vehicle(int quantity, int weight, const Position& pos, VehicleType vehicleType)
            : Unit((quantity < 1 ? 1 : quantity), (weight < 1 ? 1 : weight), pos), vehicleType(vehicleType) 
    {
    }

 int Vehicle::getAttackScore()
    {
            // setQuantity(getQuantity());
            // setWeight(getWeight());
        double score;
        score = ((int)vehicleType * 304 + quantity * weight) / 30.0;
        
        attackcurrent = HN415function::Sceil(score);
        return attackcurrent;
    }
string Vehicle::TypetoStringV(VehicleType vt) const { 
            if (vt == TRUCK) return "TRUCK";
            else if (vt == MORTAR) return "MORTAR";
            else if (vt == ANTIAIRCRAFT) return "ANTIAIRCRAFT";
            else if (vt == ARMOREDCAR) return "ARMOREDCAR";
            else if (vt == APC) return "APC";
            else if (vt == ARTILLERY) return "ARTILLERY";
            else if (vt == TANK) return "TANK";
            else return "UNKNOWN";
    }
string Vehicle::str() const
    {
        stringstream ss;
        ss << "Vehicle[vehicleType=" << TypetoStringV(vehicleType)
            << ",quantity=" << quantity
            << ",weight=" << weight
            << ",position=" << pos.str() << "]";
        return ss.str();
    }
int Vehicle::returnType() { 
        return vehicleType; 
    }

// 4.Class Unitlist

 UnitList::UnitList(int capacity) : countI(0), countV(0),head(nullptr), tail(nullptr)
    {
        this->capacity = capacity;

    }
UnitList::UnitList(const UnitList& other)
    : countI(0), countV(0), head(nullptr), tail(nullptr), capacity(other.capacity), Sizecurr(0)
{
    for (Node* current = other.head; current != nullptr; current = current->next) {
        this->insert(current->unit);  
    }
}
UnitList& UnitList::operator=(const UnitList& other) {
    if (this == &other) return *this;

    // Xóa danh sách hiện tại
    Node* current = head;
    while (current) {
        Node* hntemp = current;
        current = current->next;
        delete hntemp->unit;
        delete hntemp;
    }

    // Reset dữ liệu
    head = tail = nullptr;
    countI = countV = Sizecurr = 0;
    capacity = other.capacity;

    // Sao chép từ danh sách kia
    for (Node* current = other.head; current != nullptr; current = current->next) {
        this->insert(current->unit);
    }

    return *this;
}


Node* UnitList::getHead() const {
        return head;
    }
int UnitList::getCount() const {
        return countI + countV;
    }
bool UnitList::insert(Unit* unit) {
    if (unit == nullptr) { return false; }
    Vehicle* vCheck = dynamic_cast<Vehicle*>(unit);
    Infantry* iCheck = dynamic_cast<Infantry*>(unit);
    for (Node* p = head; p; p = p->next) {
        if (typeid(*p->unit) == typeid(*unit) && p->unit->returnType() == unit->returnType())
        {
            bool CheckVehicle = dynamic_cast<Vehicle*>(p->unit) && vCheck;
            bool CheckInfantry = dynamic_cast<Infantry*>(p->unit) && iCheck;
            if (CheckVehicle || CheckInfantry)
            {
                p->unit->setQuantity(p->unit->getQuantity() + unit->getQuantity());
                if (p->unit->getWeight() < unit->getWeight())
                {
                    p->unit->setWeight(unit->getWeight());
                }
                p->unit->getAttackScore();
                return false;
            }
        }
    }
    if (countV + countI >= capacity)
    {   
        return false;
    }
    Unit* u = nullptr;
    if (vCheck) {
        u = new Vehicle(unit->getQuantity(), unit->getWeight(), unit->getCurrentPosition(), (VehicleType)unit->returnType());

    }
    else {
        u = new Infantry(unit->getQuantity(), unit->getWeight(), unit->getCurrentPosition(), (InfantryType)unit->returnType());

    }
    u->attackcurrent = unit->attackcurrent;
    Node* newNode = new Node(u);
    if (dynamic_cast<Infantry*>(u))
    {
        newNode->next = head;
        head = newNode;
        if (!tail) tail = newNode;
        countI++;
        
    }
    else {
        if (tail) tail->next = newNode;
        else head = newNode;
        tail = newNode;
        countV++;
    }
    Sizecurr++;
    return true;
}
bool UnitList::isContain(VehicleType vehicleType)
    {
        Node* current = head;
        while(current != nullptr){
            Vehicle* VEHICAL = dynamic_cast<Vehicle*>(current->unit);
            if(VEHICAL && VEHICAL->returnType() == vehicleType){
                return true;
            }
            current = current->next;
        }
        return false;

    }
bool UnitList::isContain(InfantryType infantryType)
    {
        Node* current = head;
        while(current != nullptr){
            Infantry* INFANTRY = dynamic_cast<Infantry*>(current->unit);
            if(INFANTRY && INFANTRY->returnType() == infantryType){
                return true;
            }
            current = current->next;
        }
        return false;
    }
 string UnitList::str() const
    {
        stringstream ss;
        ss << "UnitList[count_vehicle=" << countV
        << ";count_infantry=" << countI;
        Node* current = head;
        if (current != nullptr) ss << ";";  

    
        while (current != nullptr) {
            ss << current->unit->str();
            if (current->next != nullptr) {
                ss << ",";
            }
            current = current->next;
        }

        ss << "]";
        return ss.str();
    }   
 void UnitList::setSizecurr(int val) {
        Sizecurr = val;
    }
int UnitList::getSizecurr() {
        return Sizecurr;
    }
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
void UnitList::remove(Unit *unit) {
    if (!unit or !head) return;
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr) {
        if (current->unit == unit) {
            if (current->unit) {
                if (dynamic_cast<Vehicle*>(current->unit)) {
                    countV--;
                } else if (dynamic_cast<Infantry*>(current->unit)) {
                    countI--;
                }
                delete current->unit;
                current->unit = nullptr;
            }
            if (!prev) {head = current->next;}
            else {prev->next = current->next;}
            if (current == tail) {
                tail = prev;
            }
            delete current;
            return;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}
 int UnitList::getCapacity() const { 
        return capacity; 
    }
    
    
    int UnitList::getCountV() const {
        return countV; 
    }
    int UnitList::getCountI() const { 
        return countI; 
    }
    void UnitList::setCountV(int val) { 
        countV = val; 
    }
    void UnitList::setCountI(int val) { 
        countI = val; 
    }
UnitList::~UnitList() {
    Node* current = head;
    while (current) {
        Node* hntemp = current;
        current = current->next;
        delete hntemp->unit;
        delete hntemp;
    }
}

// CLASS POSITION
 Position::Position(int r, int c) : r(r), c(c) {
        this->r = r;
        this->c = c;
    }
    Position::Position(const string &str_pos) {
        r = 0;
        c = 0;
        string newstr_pos = "";
        for (char ch : str_pos) {
            if (ch != ' ') newstr_pos += ch;
        }

        if (newstr_pos.size() < 5 || newstr_pos.front() != '(' || newstr_pos.back() != ')') return;

        newstr_pos = newstr_pos.substr(1, newstr_pos.size() - 2);

        if (newstr_pos.find(',') == string::npos) return;

        string x_pos = newstr_pos.substr(0, newstr_pos.find(','));
        string y_pos = newstr_pos.substr(newstr_pos.find(',') + 1);

        long long val_x = 0, val_y = 0;

        if (x_pos.find('.') != string::npos) {
            val_x = HN415function::Sceil(stof(x_pos));
        } else {
            val_x = HN415function::Sceil(stoll(x_pos));
        }
    

        if (y_pos.find('.') != string::npos) {
            val_y = HN415function::Sceil(stof(y_pos));
        } else {
            val_y = HN415function::Sceil(stoll(y_pos));
        }
    

        r = HN415function::Sceil(val_x);
        c = HN415function::Sceil(val_y);
    }
    int Position::getRow() const { 
        return r;
    }
    int Position::getCol() const { 
        return c;
    }
    void Position::setRow(int r) { 
       this->r = r;
    }
    void Position::setCol(int c) { 
        this->c = c;
    }

    string Position::str() const {
        stringstream ss;
        ss << "(" << r << "," << c << ")";
        return ss.str();
        return "";
    }
//Class army

Army::Army(Unit **unitArray, int size, string name, BattleField *battleField) : name(name),battleField(battleField)
    {
        this->LF = 0;
        this->EXP = 0;
        this->name = name;
        for (int i = 0; i < size; i++) {
            Vehicle* Vehicle_check = dynamic_cast<Vehicle*>(unitArray[i]);
            if (Vehicle_check) LF = LF + unitArray[i]->getAttackScore();
            Infantry* Infantry_check = dynamic_cast<Infantry*>(unitArray[i]);
            if (Infantry_check) EXP = EXP + unitArray[i]->getAttackScore();
        }
       HN415function::checkLFandEXP(LF, EXP);
        int total = LF + EXP;
        int checkcap;
        if(HN415function::isSpecailNumber(total)) checkcap = 12;
        else checkcap = 8;
        this->unitList = new UnitList(checkcap);
        for (int i = 0; i < size; i++) {
            this->unitList->insert(unitArray[i]);
        }
    }
  UnitList* Army::returnUnitList() { 
        return unitList; 
    }
 Army::~Army() {
        delete unitList;
    }
    void Army::fight(Army* enemy, bool defense) {
    }
    string Army::str() const {
        return "Army[name=" + name + ",LF=" + to_string(LF) + ",EXP=" + to_string(EXP) + "]";
    }
    void Army::updateScore(bool update) {
    if (!update) return;
    LF = 0;
    EXP = 0;
    Node* current = unitList->head;
    while (current != nullptr) {
        Unit* unit = current->unit;      
        if ( Vehicle* Vehicle_check = dynamic_cast<Vehicle*>(unit)) LF += Vehicle_check->getAttackScore();  
        else if (Infantry* Infantry_check = dynamic_cast<Infantry*>(unit)) EXP += Infantry_check->getAttackScore();
        current = current->next;
    }
   HN415function::checkLFandEXP(LF, EXP);
}
 int Army::getLF() const { 
            return LF; 
    }
    int Army::getEXP() const { 
            return EXP; 
    }
    void Army::setLF(int lf){
            this->LF = lf;
    }
    void Army::setEXP(int exp) { 
            this->EXP = exp;
    }
//class Liberation
LiberationArmy::LiberationArmy(Unit **unitArray, int size, string name, BattleField *battleField)
                : Army(unitArray,size,name, battleField) 
    {

        this->unitArray = unitArray;
        for(int i = 0;i < size; i++){
                if(dynamic_cast<Vehicle*>(unitArray[i])){
                   this->size_V++;
                }
        else if(dynamic_cast<Infantry*>(unitArray[i])){
                   this->size_I++;
                }
            }
    }
     LiberationArmy::~LiberationArmy() {
    for (auto u : cloneUnitAddress)
        {
            delete u;
        }
    }
     vector<Unit*> LiberationArmy::knapsackfind(vector<Unit*> units, int minScore) {
            int n = units.size();
            int bestScore = INT_MAX;
            vector<Unit*> bestCombo;
            for (int mask = 1; mask < (1 << n); ++mask) {
                int sum = 0;
                vector<Unit*> currentCombo;
                for (int i = 0; i < n; ++i) {
                    if (mask & (1 << i)) {
                        sum += units[i]->attackcurrent;
                        currentCombo.push_back(units[i]);
                    }
                }
                if (sum > minScore && sum < bestScore) {
                    bestScore = sum;
                    bestCombo = currentCombo;
                }
            }
            return bestCombo;

    }
void LiberationArmy::fight(Army *enemy, bool defense) {
if (enemy == nullptr || unitList == nullptr || enemy->returnUnitList() == nullptr) return;

    if (defense == false)
    {   
        
        LF = HN415function::Sceil(LF * 1.5);
        EXP = HN415function::Sceil(EXP * 1.5);

        if (LF < 0) LF = 0;
        else if (LF > 1000) LF = 1000;
        if (EXP < 0) EXP = 0;
        else if (EXP > 500) EXP = 500;

        vector<Unit*> InfantryUnit;
        vector<Unit*> VehicleUnit;

        for (Node* current = unitList->getHead(); current != nullptr; current = current->next) {
              
            if (dynamic_cast<Infantry*>(current->unit)) {
                InfantryUnit.push_back(current->unit);
            }
             if (dynamic_cast<Vehicle*>(current->unit)) {
                VehicleUnit.push_back(current->unit);
            }
           
        }
        
        vector<Unit*> A = knapsackfind(InfantryUnit, enemy->getEXP());
        vector<Unit*> B = knapsackfind(VehicleUnit, enemy->getLF());

        bool foundA = !A.empty();
        bool foundB = !B.empty();

        vector<Node*> eNode;
        for (Node* ecurrent = enemy->returnUnitList()->getHead(); ecurrent != nullptr; ecurrent = ecurrent->next) {
            eNode.push_back(ecurrent);
        }

        if (foundA && foundB) {
            for (Unit* u : A) unitList->remove(u);
            for (Unit* u : B) unitList->remove(u);

           
            for (int i = (int)eNode.size() - 1; i >= 0; --i) {
                Unit* eUnit = eNode[i]->unit;
                Unit* cloned = cloneUnit(eUnit);

                bool HNcheckofinsert = unitList->insert(cloned);
                bool now = false;

                if (!HNcheckofinsert) {
                    for (Node* current = unitList->getHead(); current != nullptr; current = current->next) {
                        if (typeid(*current->unit) == typeid(*eUnit) && current->unit->returnType() == eUnit->returnType()) {
                            now = true;
                            break;
                        }
                    }
                }

                if (HNcheckofinsert || now) {
                    enemy->returnUnitList()->remove(eUnit);
                }
            
            }

        LF = EXP = 0;
            enemy->setLF(0);
            this->updateScore(true);
            enemy->updateScore(true);
        }
        else if (foundA && !foundB && LF > enemy->getLF()) {
            for (Unit* u : VehicleUnit) unitList->remove(u);
            for (Unit* u : A) unitList->remove(u);

            for (int i = (int)eNode.size() - 1; i >= 0; --i) {
                Unit* eUnit = eNode[i]->unit;
                Unit* cloned = cloneUnit(eUnit);

                bool HNcheckofinsert = unitList->insert(cloned);
                bool now = false;

                if (!HNcheckofinsert) {
                    for (Node* current = unitList->getHead(); current != nullptr; current = current->next) {
                        if (typeid(*current->unit) == typeid(*eUnit) && current->unit->returnType() == eUnit->returnType()) {
                            now = true;
                            break;
                        }
                    }
                }

                if (HNcheckofinsert || now) {
                    enemy->returnUnitList()->remove(eUnit);
                }
            
            }

            LF = 0;
            EXP = 0;
            enemy->setLF(0);
            enemy->setEXP(0);
            this->updateScore(true);
            enemy->updateScore(true);
        }
        else if (!foundA && foundB && EXP > enemy->getEXP()) {
            for (Unit* u : InfantryUnit) unitList->remove(u);
            for (Unit* u : B) unitList->remove(u);

            for (int i = (int)eNode.size() - 1; i >= 0; --i) {
                Unit* eUnit = eNode[i]->unit;
                Unit* cloned = cloneUnit(eUnit);

                bool HNcheckofinsert = unitList->insert(cloned);
                bool now = false;

                if (!HNcheckofinsert) {
                    for (Node* current = unitList->getHead(); current != nullptr; current = current->next) {
                        if (typeid(*current->unit) == typeid(*eUnit) && current->unit->returnType() == eUnit->returnType()) {
                            now = true;
                            break;
                        }
                    }
                }

                if (HNcheckofinsert || now) {
                    enemy->returnUnitList()->remove(eUnit);
                }
            
            }

            LF = 0;
            EXP = 0;
            enemy->setLF(0);
            enemy->setEXP(0);
            this->updateScore(true);
            enemy->updateScore(true);
        }
        else {
            for (Node* current = unitList->getHead(); current != nullptr; current = current->next) {
                double newWeight = current->unit->getWeight() * 0.9;
                current->unit->setWeight(HN415function::Sceil(newWeight));
                current->unit->getAttackScore();
            }
            this->updateScore(true);
        }
    }


else {
    // B1: Tăng chỉ số LF và EXP lên 1.3 lần
    LF = HN415function::Sceil(LF * 1.3);
    EXP = HN415function::Sceil(EXP * 1.3);
    HN415function::checkLFandEXP(LF, EXP);

    // B2: Nếu đã mạnh hơn cả 2 chỉ số thì kết thúc
     if (LF >= enemy->getLF() and EXP >= enemy->getEXP()) {
      this->LF = LF;
      this->EXP = EXP;
      return;
  }

    // B3: Nếu thua cả 2 chỉ số thì cần reinforce
    else if (LF < enemy->getLF() && EXP < enemy->getEXP()) {
    while (!(LF >= enemy->getLF() || EXP >= enemy->getEXP())) {
        for (Node* current = unitList->getHead(); current != nullptr; current = current->next) {
            int newQuantity = HN415function::nearestFibonacci(current->unit->getQuantity());
            current->unit->setQuantity(newQuantity);
            
        }
        this->updateScore(true);
    }
}

    // B4: Nếu sau reinforce vẫn còn yếu hơn 1 trong 2 chỉ số ⇒ giảm 10% quantity mỗi đơn vị
      if (!(LF >= enemy->getLF() and EXP >= enemy->getEXP())) {
        for (Node* current = unitList->getHead(); current != nullptr; current = current->next) {
            int newQuantity = HN415function::Sceil(current->unit->getQuantity()*0.9);
            current->unit->setQuantity(newQuantity);
           
        }
        this->updateScore(true);
    }

    
}


}

  string LiberationArmy::str() const 
  {
        stringstream ss;
        ss << "LiberationArmy[LF=" << LF
            << ",EXP=" << EXP
            << ",unitList=" << unitList->str()
            << ",battleField=";

        if (battleField != nullptr)
            ss << battleField->str();  
        else
            ss << "";

        ss << "]";
        return ss.str();
    }
       Unit* LiberationArmy::cloneUnit(Unit* unit) {
        if (Infantry* Infantry_check = dynamic_cast<Infantry*>(unit)) {
            Infantry* copyI = new Infantry(
                Infantry_check->getQuantity(),
                Infantry_check->getWeight(),
                Infantry_check->getCurrentPosition(),
                static_cast<InfantryType>(Infantry_check->returnType())
            );
            cloneUnitAddress.push_back(copyI);
            return copyI;
        }

    if (Vehicle* Vehicle_check = dynamic_cast<Vehicle*>(unit)) {
        Vehicle* copyV = new Vehicle(
            Vehicle_check->getQuantity(),
            Vehicle_check->getWeight(),
            Vehicle_check->getCurrentPosition(),
            static_cast<VehicleType>(Vehicle_check->returnType())

        );
        cloneUnitAddress.push_back(copyV);
        return copyV;
    }

    return nullptr; 
}
// Class ARVN
ARVN::ARVN(Unit** unitArray, int size, string name, BattleField *battleField) 
            : Army(unitArray, size, name, battleField) {
    }
 void ARVN::fight(Army* enemy, bool defense) {
    if (defense == true) {
       
        double LF = this->LF * 1.5;
        double EXP = this->EXP * 1.5;

        vector<Unit*> eInfantryUnit, eVehicleUnit;
        for (Node* cur = enemy->returnUnitList()->getHead(); cur; cur = cur->next) 
        {
            if (dynamic_cast<Infantry*>(cur->unit)) eInfantryUnit.push_back(cur->unit);
                else if (dynamic_cast<Vehicle*>(cur->unit)) eVehicleUnit.push_back(cur->unit);
        }

        vector<Unit*> InfantryUnit, VehicleUnit;
        for (Node* cur = unitList->getHead(); cur; cur = cur->next) 
        {
            if (dynamic_cast<Infantry*>(cur->unit)) InfantryUnit.push_back(cur->unit);
                else if (dynamic_cast<Vehicle*>(cur->unit)) VehicleUnit.push_back(cur->unit);
        }

 
        vector<Unit*> A = knapsackfind(eInfantryUnit, enemy->getEXP());
        vector<Unit*> B = knapsackfind(eVehicleUnit, enemy->getLF());

        bool foundA = !A.empty();
        bool foundB = !B.empty();

       

        vector<Node*> nodeList;
        for (Node* cur = unitList->getHead(); cur; cur = cur->next) {
            nodeList.push_back(cur);
        }

        bool check = false;

if (foundA && foundB) 
{
    for (int i = nodeList.size() - 1; i >= 0; --i)
    {
        unitList->remove(nodeList[i]->unit);
     
    }
      this->updateScore(true);
}
else if (foundA && !foundB && enemy->getLF() > this->getLF()) {
    for (Unit* u : A) {
        unitList->remove(u);
     
    }
    for (size_t i = 0; i + 1 < VehicleUnit.size(); ++i) {
        int newWeight = HN415function::Sceil(VehicleUnit[i]->getWeight() * 0.8);
        VehicleUnit[i]->setWeight(newWeight);
        
    }
     this->updateScore(true);
}
else if (!foundA && foundB && enemy->getEXP() > this->getEXP()) {
    for (Unit* u : B) {
        unitList->remove(u);
        
    }
    for (size_t i = 0; i + 1 < InfantryUnit.size(); ++i) {
        int newWeight = HN415function::Sceil(InfantryUnit[i]->getWeight() * 0.8);
        VehicleUnit[i]->setWeight(newWeight);
       
    }
    this->updateScore(true);
}





    } 
    else {
        Node* current = unitList->getHead();
        while (current != nullptr) {
            Unit* unit = current->unit;
            int newQuantity = HN415function::Sceil(unit->getQuantity()*0.8);
            unit->setQuantity(newQuantity);
            if (unit->getQuantity() <= 1) {
                unitList->remove(unit);
                current = unitList->getHead();
                continue;
            }
            current = current->next;
        }
        this->updateScore(true);
    }

}


    string ARVN::str() const {
        stringstream ss;
        ss << "ARVN[";
        ss << "LF=" << this->LF << ",";
        ss << "EXP=" << this->EXP << ",";
        ss << "unitList=";
        if (this->unitList) {
            ss << this->unitList->str();
        } else {
            ss << "empty";
        }

        ss << ",battleField=";
        if (this->battleField) {
            ss << this->battleField->str();
        } else {
            ss << "";
        }

        ss << "]";
        return ss.str();
    }
 
vector<Unit*> ARVN::knapsackfind(vector<Unit*> units, int minScore) {
        int n = units.size();
        int bestScore = INT_MAX;
        vector<Unit*> bestCombo;
        for (int mask = 1; mask < (1 << n); ++mask) {
            int sum = 0;
            vector<Unit*> currentCombo;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    sum += units[i]->attackcurrent;
                    currentCombo.push_back(units[i]);
                }
            }
            if (sum > minScore && sum < bestScore) {
                bestScore = sum;
                bestCombo = currentCombo;
            }
        }
        return bestCombo;
    }

    //Class TERRI
    TerrainElement::TerrainElement(Position pos) : pos(pos)
    {}  
    TerrainElement::~TerrainElement() {
        // Giải phóng tài nguyên nếu có
    }
    void Road::getEffect(Army *army) {
        // Không gây ảnh hưởng cho quân đội.
    }
void Mountain::getEffect(Army *army) {
    if (!army) return;

    Node* current = army->returnUnitList()->getHead();
    bool isLiberArmy = dynamic_cast<LiberationArmy*>(army) != nullptr;

    int newEXP = army->getEXP();
    int newLF = army->getLF();

    while (current != nullptr) {
        Unit* unit = current->unit;
        double dist = HN415function::calculateDistance(pos, unit->getCurrentPosition());

        if (isLiberArmy && dist <= 2.0) {
            if (dynamic_cast<Infantry*>(unit)) {
               
                int deltaEXP = HN415function::Sceil(0.3 * unit->returnAttackcurrent());
                newEXP += deltaEXP;
           
            } else if (dynamic_cast<Vehicle*>(unit)) {
                int deltaLF = HN415function::Sceil(0.1 * unit->returnAttackcurrent());
                newLF -= deltaLF;
              
            }
        } else if (!isLiberArmy && dist <= 4.0) {
            if (dynamic_cast<Infantry*>(unit)) {
                int deltaEXP = HN415function::Sceil(0.2 * unit->returnAttackcurrent());
                newEXP += deltaEXP;
             
            } else if (dynamic_cast<Vehicle*>(unit)) {
                int deltaLF = HN415function::Sceil(0.05 * unit->returnAttackcurrent());
                newLF -= deltaLF;
          
            }
        }

        current = current->next;
    }

    // Giới hạn giá trị EXP và LF theo yêu cầu
    HN415function::checkLFandEXP(newLF, newEXP);

   
    army->setEXP(newEXP);
    army->setLF(newLF);
}


void River::getEffect(Army* army) {
    if (!army || !army->returnUnitList()) return;

    Node* cur = army->returnUnitList()->getHead();
    while (cur != nullptr) {
        Unit* unit = cur->unit;
        double distance = HN415function::calculateDistance(pos, unit->getCurrentPosition());
        Infantry* infantry = dynamic_cast<Infantry*>(unit);
        if (infantry) {
            if (distance <= 2.0) {
                int currAttackscore = infantry->attackcurrent;
                int reduce =(currAttackscore * 0.1);
                currAttackscore = (currAttackscore + HN415function::Sceil(-reduce));
                unit->setAttackcurrent(currAttackscore);
            }
        }
        cur = cur->next;
    }
}



// }
void Urban::getEffect(Army* army) {
    if (!army || !army->returnUnitList()) return;

    bool isLiberationArmy = dynamic_cast<LiberationArmy*>(army) != nullptr;
    Node* head = army->returnUnitList()->getHead();
    Node* cur = head;

  
    while (cur != nullptr) {
        Unit* unit = cur->unit;

        // Kiểm tra xem đã áp dụng chưa (tránh lặp)
        bool alreadyAffected = false;
        Node* check = head;
        while (check != cur) {
            if (check->unit == unit) {
                alreadyAffected = true;
                break;
            }
            check = check->next;
        }
        if (alreadyAffected) {
            cur = cur->next;
            continue;
        }

        Position unitPos = unit->getCurrentPosition();
        double D = HN415function::calculateDistance(pos, unitPos);
        if (abs(D) < 1e-6) D = 1.0;  
       

        Infantry* infancheck = dynamic_cast<Infantry*>(unit);

        if (infancheck) {
            InfantryType type = static_cast<InfantryType>(infancheck->returnType());
            int atk = unit->returnAttackcurrent();

            if (isLiberationArmy && (type == SPECIALFORCES || type == REGULARINFANTRY) && D <= 5.0) {
                int bonus = HN415function::Sceil((2.0 * atk) / D);
                 
                unit->setAttackcurrent(atk + bonus);

                
            }
            else if (!isLiberationArmy && type == REGULARINFANTRY && D <= 3.0) {
                int bonus = HN415function::Sceil((3.0 * atk) / (2.0 * D));
                
                unit->setAttackcurrent((atk + bonus));

               
            }
        }
        else {
            Vehicle* vehicheck = dynamic_cast<Vehicle*>(unit);
            if (isLiberationArmy && vehicheck) {
                VehicleType type = static_cast<VehicleType>(vehicheck->returnType());
                int atk = unit->returnAttackcurrent();

                if (type == ARTILLERY && D <= 2.0) {
                    int penalty = HN415function::Sceil(- atk * 0.5);
                    unit->setAttackcurrent(HN415function::Sceil(atk  + penalty));

                   
                }
            }
        }

        cur = cur->next;
    }
    
}


void Fortification::getEffect(Army *army) {
    if (!army) {return;}
    bool isLiberArmy = dynamic_cast<LiberationArmy*>(army) != nullptr;
    Node* current = army->returnUnitList()->getHead();
    while (current != nullptr) {
        Unit*unit = current->unit;
        double distance = HN415function::calculateDistance(this->pos, unit->getCurrentPosition());
        if (isLiberArmy) {
            if (distance<=2) {
                unit->attackcurrent = HN415function::Sceil(0.8*unit->attackcurrent);
                unit->setAttackcurrent(unit->attackcurrent);
            }
        }
        else {
            if (distance <= 2) {
                unit->attackcurrent += HN415function::Sceil(0.2*unit->attackcurrent);
                unit->setAttackcurrent(unit->attackcurrent);
            }
        }
        current = current->next;
    }
}

void SpecialZone::getEffect(Army *army) {
    if (!army) {return;}
    Node* current = army->returnUnitList()->getHead();
    while (current != nullptr) {
        Unit*unit = current->unit;
        double distance = HN415function::calculateDistance(this->pos, unit->getCurrentPosition());
        if (distance<=1) {
            unit->setAttackcurrent(0);
        }
        current = current->next;
    }
}

//Class battle
BattleField::BattleField(int n_rows, int n_cols,
                         const vector<Position*>& arrayForest,
                         const vector<Position*>& arrayRiver,
                         const vector<Position*>& arrayFortification,
                         const vector<Position*>& arrayUrban,
                         const vector<Position*>& arraySpecialZone)
    : n_rows(n_rows), n_cols(n_cols)
{
    // Kiểm tra kích thước hợp lệ
    if (n_rows <= 0 || n_cols <= 0) {
        throw std::invalid_argument("Invalid battlefield size.");
    }

    // Cấp phát mảng 2D
    terrain = new TerrainElement**[n_rows];
    for (int i = 0; i < n_rows; ++i) {
        terrain[i] = new TerrainElement*[n_cols];
        for (int j = 0; j < n_cols; ++j) {
            terrain[i][j] = new Road(Position(i, j));
        }
    }

    // Gán Forest nếu là Road
    for (int i = 0; i < arrayForest.size(); ++i) {
        Position* p = arrayForest[i];
        if (p != NULL) {
            int r = p->getRow();
            int c = p->getCol();
            if (r >= 0 && r < n_rows && c >= 0 && c < n_cols) {
                if (terrain[r][c] != NULL && dynamic_cast<Road*>(terrain[r][c]) != NULL) {
                    delete terrain[r][c];
                    terrain[r][c] = new Mountain(*p);
                }
            }
        }
    }

    // Gán River nếu là Road
    for (int i = 0; i < arrayRiver.size(); ++i) {
        Position* p = arrayRiver[i];
        if (p != NULL) {
            int r = p->getRow();
            int c = p->getCol();
            if (r >= 0 && r < n_rows && c >= 0 && c < n_cols) {
                if (terrain[r][c] != NULL && dynamic_cast<Road*>(terrain[r][c]) != NULL) {
                    delete terrain[r][c];
                    terrain[r][c] = new River(*p);
                }
            }
        }
    }

    // Gán Fortification nếu là Road
    for (int i = 0; i < arrayFortification.size(); ++i) {
        Position* p = arrayFortification[i];
        if (p != NULL) {
            int r = p->getRow();
            int c = p->getCol();
            if (r >= 0 && r < n_rows && c >= 0 && c < n_cols) {
                if (terrain[r][c] != NULL && dynamic_cast<Road*>(terrain[r][c]) != NULL) {
                    delete terrain[r][c];
                    terrain[r][c] = new Fortification(*p);
                }
            }
        }
    }

    // Gán Urban nếu là Road
    for (int i = 0; i < arrayUrban.size(); ++i) {
        Position* p = arrayUrban[i];
        if (p != NULL) {
            int r = p->getRow();
            int c = p->getCol();
            if (r >= 0 && r < n_rows && c >= 0 && c < n_cols) {
                if (terrain[r][c] != NULL && dynamic_cast<Road*>(terrain[r][c]) != NULL) {
                    delete terrain[r][c];
                    terrain[r][c] = new Urban(*p);
                }
            }
        }
    }

    // Gán SpecialZone nếu là Road
    for (int i = 0; i < arraySpecialZone.size(); ++i) {
        Position* p = arraySpecialZone[i];
        if (p != NULL) {
            int r = p->getRow();
            int c = p->getCol();
            if (r >= 0 && r < n_rows && c >= 0 && c < n_cols) {
                if (terrain[r][c] != NULL && dynamic_cast<Road*>(terrain[r][c]) != NULL) {
                    delete terrain[r][c];
                    terrain[r][c] = new SpecialZone(*p);
                }
            }
        }
    }
}

BattleField::~BattleField() {
    if (!terrain) return;

    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            delete terrain[i][j];  // elete từng TerrainElement*
        }
        delete[] terrain[i];  // Sau đó mới delete[] hàng i
    }

    delete[] terrain;  // Cuối cùng là delete[] mảng hàng
    terrain = nullptr;
}


 TerrainElement* BattleField::getElement(int r, int c) const {
            if (r < 0 || r >= n_rows || c < 0 || c >= n_cols) return nullptr;
            return terrain[r][c];
        }
        string BattleField::str() const {
        return "BattleField[n_rows=" + to_string(n_rows) + ",n_cols=" + to_string(n_cols) + "]";
    }

    //CLASS CONFI
 string Configuration::trimbyhn(const string &s) {
        size_t start = s.find_first_not_of(" \t\r\n");
        size_t end = s.find_last_not_of(" \t\r\n");
        return (start == string::npos) ? "" : s.substr(start, end - start + 1);
    }
bool Configuration::isVehicle(const string &name)
{
    if (name == "TRUCK" || name == "MORTAR" || name == "ANTIAIRCRAFT" || 
            name == "ARMOREDCAR" || name == "APC" || name == "ARTILLERY" || name == "TANK")
    {
        return true;
    }
        return false;
}
 void Configuration::locationArray(const string &val, vector<Position*> &arrayTarget) {
        arrayTarget.clear();
        size_t start = val.find('[');
        size_t end = val.find(']');
        if (start == string::npos || end == string::npos || start >= end) return;

        string content = val.substr(start + 1, end - start - 1);
        stringstream ss(content);
        string token;
        while (getline(ss, token, ')')) {
            size_t open = token.find('(');
            if (open != string::npos) {
                string coord = token.substr(open + 1);
                size_t comma = coord.find(',');
                if (comma != string::npos) {
                    int x = stoi(trimbyhn(coord.substr(0, comma)));
                    int y = stoi(trimbyhn(coord.substr(comma + 1)));
                    arrayTarget.push_back(new Position(x, y));
                }
            }
        }
    }
    void Configuration::analysisUnit(const string &content) {
        size_t StartBrac = content.find('[');
        size_t EndBrac = content.find(']');
        if (StartBrac == string::npos || EndBrac == string::npos || StartBrac>=EndBrac) {
            return;
        }
        string ListString = content.substr(StartBrac+1, EndBrac-StartBrac-1);
       
        size_t Pos = 0;
        while (Pos < ListString.size()) {
            while (Pos < ListString.size() && (isspace(ListString[Pos]) || ListString[Pos]==',')) {
                Pos++; //todo Pos = 1
            }
            if (Pos >= ListString.size()) {
                break;
            }
            size_t firstParenth = ListString.find('(', Pos); //todo firstParenth = 7
            if (firstParenth == string::npos) {
                break;
            }
            string Name = trimbyhn(ListString.substr(Pos, firstParenth-Pos)); //todo Name = SNIPER
            size_t StrStart = firstParenth + 1; //todo StrStart
            size_t finalParenth = string::npos;
            int ParenthLevel = 0;
            for (size_t i=firstParenth; i<ListString.size(); ++i) {
                if (ListString[i] == '(') {
                    ParenthLevel++;
                }
                else if (ListString[i] == ')') {
                    ParenthLevel--;
                    if (ParenthLevel == 0) {
                        finalParenth = i;
                        break;
                    }
                }
            }
            if (finalParenth == string::npos) {
                break;
            }
            string StrInside = ListString.substr(StrStart, finalParenth-StrStart);
            size_t firstComma = StrInside.find(',');
            size_t secComma = StrInside.find(',', firstComma+1);
            size_t OpenParenth = StrInside.find('(', secComma+1);
            size_t CloseParenth = StrInside.find(')', OpenParenth+1);
            size_t thirdComma = StrInside.find(',', CloseParenth+1);
            if (firstComma == string::npos ||  secComma == string::npos || thirdComma == string::npos
                || OpenParenth == string::npos || CloseParenth == string::npos) {
                Pos = finalParenth+1;
                continue;
            }
            //todo thêm số liệu vào
            int num_quantity = stoi(trimbyhn(StrInside.substr(0, firstComma)));
            int num_weight = stoi(trimbyhn(StrInside.substr(firstComma+1, secComma-firstComma-1)));
            
            string coordStr = trimbyhn(StrInside.substr(OpenParenth + 1, CloseParenth - OpenParenth - 1));
            size_t CommaInside = coordStr.find(',');
            if (CommaInside == string::npos) {
            Pos = finalParenth+1;
            continue;
            }
            
            int x_pos = stoi(trimbyhn(coordStr.substr(0,CommaInside)));
            int y_pos = stoi(trimbyhn(coordStr.substr(CommaInside+1)));
            int num_army = stoi(trimbyhn(StrInside.substr(thirdComma+1)));
            Position num_pos(x_pos, y_pos);
            Unit* unit = nullptr;
            if (isVehicle(Name)) {
                VehicleType type = HN415function::findnameV(Name);
                unit = new Vehicle(num_quantity, num_weight, num_pos, type);
            }
            else {
                InfantryType type = HN415function::findnameI(Name);
                unit = new Infantry(num_quantity, num_weight, num_pos, type);
            }
            if (num_army == 0) {
        Unit** temp = new Unit*[liberationSize + 1];
        for (int i = 0; i < liberationSize; ++i)
            temp[i] = liberationUnits[i];
        temp[liberationSize] = unit;
        delete[] liberationUnits;
        liberationUnits = temp;
        ++liberationSize;
    } else {
        Unit** temp = new Unit*[ARVNSize + 1];
        for (int i = 0; i < ARVNSize; ++i)
            temp[i] = ARVNUnits[i];
        temp[ARVNSize] = unit;
        delete[] ARVNUnits;
        ARVNUnits = temp;
        ++ARVNSize;
    }
            Pos = finalParenth+1;
        }
        
    }
     Configuration::Configuration(const string &filepath) {
        num_rows = num_cols = -1;
        eventCode = 0;
        ifstream ifs(filepath);
        string line;
        
        while (getline(ifs, line)) {
            line = trimbyhn(line);
            if (line.empty() || line[0] == '#') {continue;}
            size_t equalPos = line.find('=');
            if (equalPos == string::npos) {continue;}
            string checkNamefile = trimbyhn(line.substr(0, equalPos));
            string val = trimbyhn(line.substr(equalPos+1));
            if (checkNamefile == "NUM_ROWS") {num_rows = stoi(val);}
            else if (checkNamefile == "NUM_COLS") {num_cols = stoi(val);}
            else if (checkNamefile == "EVENT_CODE") {
                eventCode = max(0, stoi(val));
                if (eventCode > 99) {
                    eventCode = eventCode % 100;
                }
            }
            else if (checkNamefile == "ARRAY_FOREST") {locationArray(val, arrayForest);}
            else if (checkNamefile == "ARRAY_RIVER") {locationArray(val, arrayRiver);}
            else if (checkNamefile == "ARRAY_FORTIFICATION") {locationArray(val, arrayFortification);}
            else if (checkNamefile == "ARRAY_URBAN") {locationArray(val, arrayUrban);}
            else if (checkNamefile == "ARRAY_SPECIAL_ZONE") {locationArray(val, arraySpecialZone);}
            else if (checkNamefile == "UNIT_LIST") {analysisUnit(val);}

        }
        ifs.close();
        
    }
    string Configuration::str() const {
        stringstream ss;
        ss << "[" << "num_rows=" << num_rows << ","
        << "num_cols=" << num_cols << ","
        << "arrayForest=[";
        for (size_t i=0; i<arrayForest.size(); i++) {
            ss << arrayForest[i]->str();
            if (i != arrayForest.size() -1) {ss << ",";}
        }
        ss << "]," << "arrayRiver=[";
        for (size_t i=0; i<arrayRiver.size(); i++) {
            ss << arrayRiver[i]->str();
            if (i != arrayRiver.size() -1) {ss << ",";}
        }
        ss << "]," << "arrayFortification=[";
        for (size_t i=0; i<arrayFortification.size(); i++) {
            ss << arrayFortification[i]->str();
            if (i != arrayFortification.size() -1) {ss << ",";}
        }
        ss << "]," << "arrayUrban=[";
        for (size_t i=0; i<arrayUrban.size(); i++) {
            ss << arrayUrban[i]->str();
            if (i != arrayUrban.size() -1) {ss << ",";}
        }
        ss << "]," << "arraySpecialZone=[";
        for (size_t i=0; i<arraySpecialZone.size(); i++) {
            ss << arraySpecialZone[i]->str();
            if (i != arraySpecialZone.size() -1) {ss << ",";}
        }
        
        
        ss <<"]"<< ",liberationUnits=[";
    for (int i = 0; i < liberationSize; ++i) {
        ss << liberationUnits[i]->str();  // Giả sử mỗi Unit có hàm str()
        if (i != liberationSize - 1) ss << ",";
    }
    ss << "],";

    // ARVNUnits
    ss << "ARVNUnits=[";
    for (int i = 0; i < ARVNSize; ++i) {
        ss << ARVNUnits[i]->str();
        if (i != ARVNSize - 1) ss << ",";
    }
    ss << "],";
        // eventCode
        ss << "eventCode=" << eventCode << "]";
        return ss.str();
    }
    Configuration::~Configuration() {
        // Giải phóng các đối tượng Position đã được cấp phát
    
        for (auto p : arrayForest) delete p;
        for (auto p : arrayRiver) delete p;
        for (auto p : arrayFortification) delete p;
        for (auto p : arrayUrban) delete p;
        for (auto p : arraySpecialZone) delete p;
    
        if(liberationUnits){
            for(int i = 0; i < liberationSize; i++){
                delete liberationUnits[i];
            }
            delete[] liberationUnits;
        }
        if(ARVNUnits){
            for(int i = 0; i < ARVNSize; i++){
                delete ARVNUnits[i];
            }
            delete[] ARVNUnits;
        }

    }
    //class hcm
     HCMCampaign::HCMCampaign(const string & config_file_path) {
        config = new Configuration(config_file_path);

        battleField = new BattleField(
            config->getNumRows(),
            config->getNumCols(),
            config->getForestPositions(),
            config->getRiverPositions(),
            config->getFortificationPositions(),
            config->getUrbanPositions(),
            config->getSpecialZonePositions()
        );

        liberationArmy = new LiberationArmy(
            config->getLiberationUnits(),
            config->getLiberationSize(),
            "LIBERATIONARMY",
            battleField
        );

        arvnArmy = new ARVN(
            config->getARVNUnits(),
            config->getARVNSize(),
            "ARVN",
            battleField
        );
    }
    HCMCampaign::~HCMCampaign() {
        delete config;
        delete battleField;
        delete liberationArmy;
        delete arvnArmy;
    }
   void HCMCampaign::run() {
    int code = config->getEventCode();
    for (int i=0; i<config->getNumRows(); i++) {
        for (int j=0; j<config->getNumCols(); j++) {
            auto element = battleField->getElement(i, j);
            if (element != nullptr) {
                element->getEffect(liberationArmy);
                element->getEffect(arvnArmy);
            }
        }
    }
    if (code < 75) {
        Army* eLib = arvnArmy;
        liberationArmy->fight(eLib, false);
    }
    else {
       arvnArmy->fight(liberationArmy, false);
liberationArmy->fight(arvnArmy, true);
liberationArmy->fight(arvnArmy, false);
arvnArmy->fight(liberationArmy, true);
    }
    Node* current = liberationArmy->returnUnitList()->getHead();
    while (current != nullptr) {
        Node* next = current->next;
        if (current->unit->returnAttackcurrent() <= 5) {
            liberationArmy->returnUnitList()->remove(current->unit);
        }
        current = next;
    }
    current = arvnArmy->returnUnitList()->getHead();
    while (current != nullptr) {
        Node* next = current->next;
        if (current->unit->returnAttackcurrent() <= 5) {
            arvnArmy->returnUnitList()->remove(current->unit);
        }
        current = next;
    }
    liberationArmy->updateScore(true);
    arvnArmy->updateScore(true);
}

        string HCMCampaign::printResult() {
        stringstream ss;
        ss << "LIBERATIONARMY[LF=" << liberationArmy->getLF()
        << ",EXP=" << liberationArmy->getEXP() << "]"
        << "-ARVN[LF=" << arvnArmy->getLF()
        << ",EXP=" << arvnArmy->getEXP() << "]";
        return ss.str();
    }

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////