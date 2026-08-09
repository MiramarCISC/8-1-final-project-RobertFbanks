#include "project.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

// ===============================
// Arraylist
// ===============================

FoodarrayList::FoodarrayList() {
    count = 0;

    for (int i = 0; i < 25; i++) {
        foods[i] = 0.0;
    }
} // Makes array and sets every i value to 0 until used.

// Checks if the calorie amount is the correct size and if there is enough sopace in the array.
bool FoodarrayList::addcalorie(double calorie) {
    if (!isValidcalorie(calorie) || count >= 25) {
        return false;
    }

    foods[count] = calorie;
    count++;

    return true;
}
// gets the count of which space the program is in the array.
int FoodarrayList::getCount() const {
    return count;
}
// gets the value of calories at an index.
double FoodarrayList::getcalorie(int index) const {
    if (index < 0 || index >= count) {
        return 0.0;
    }

    return foods[index];
}
// Goes through every iteration in the array and adds the calories.
double FoodarrayList::getTotalcalories() const {
    double total = 0.0;

    for (int i = 0; i < count; i++) {
        total += foods[i];
    }

    return total;
}
int FoodarrayList::findmeal(double target) const {
    for (int i = 0; i < count; i++) {
    if (foods[i] == target) {
    return i;
    }
}

return -1;
}
void sortMeals(food mealArray[], int mealCount) {
    for (int i = 0; i < mealCount - 1; i++) {
        int smallest = i;

        for (int j = i + 1; j < mealCount; j++) {
            if (mealArray[j].getFoodlist().getTotalcalories() <
                mealArray[smallest].getFoodlist().getTotalcalories()) {
                smallest = j;
            }
        }

        if (smallest != i) {
            food temp = mealArray[i];
            mealArray[i] = mealArray[smallest];
            mealArray[smallest] = temp;
        }
    }
}

// calculates total calorie value in main
double calculateTotalCalories(const food mealArray[], int mealCount) {
    if (mealArray == nullptr || mealCount <= 0) {
        return 0.0;
    }

    double Total = 0.0;
    for (int i = 0; i < mealCount; i++) {
        Total += mealArray[i].getFoodlist().getTotalcalories();
    }

    return Total;
}
// hecks if calorie input is in a decent range.
bool FoodarrayList::isValidcalorie(double food) {
    
    if (food >= 0.0 && food <= 5000.0){
        return true;
    }
    else {
        return false;
    }
}

// ===============================
// Array
// ===============================
// initializes food object.
food::food() {
    type = "";
    name = "";
}
// Creates food type and name.
food::food(string foodtype, string foodname) {
    type = foodtype;
    name = foodname;
}
// Returns food type
string food::gettype() const {
    return type;
}
// Returns food name
string food::getName() const {
    return name;
}
// Returns food calorie list
FoodarrayList& food::getFoodlist() {
    return foodlist;
}
const FoodarrayList& food::getFoodlist() const {
    return foodlist;
}
// Determines if the food type entered is good.
bool food::isValidtype(string type) {
    if (type == "Protein" || type == "Dairy" || type == "Carbs" || type == "Vegetables" || type == "Fruit" || type == "Beverage" || type == "Dessert" || type == "Other"){
        return true;
    }
    else {
        return false;
    }
    
}

// ===============================
// Linked list
// ===============================
// Stats Food for linked list
Food::Food() {
    type = "";
    name = "";
    calories = 0.0;
    mealrating = 0;
    eatentoday = false;
}
// Defines everything used in the linked list.
Food::Food(std::string foodtype, std::string foodname, double foodcalories, int taskmealrating) {
    type = foodtype;
    name = foodname;
    calories = foodcalories;
    mealrating = taskmealrating;
    eatentoday = false;
}
// gets the linked list name
string Food::getName() const {
    return name;
}
// Gets the mealrating.
int Food::getmealrating() const {
    return mealrating;
}
// Returns if eaten.
bool Food::iseaten() const {
    return eatentoday;
}
// used by mark food eaten to mark trur.
void Food::markEaten() {
    eatentoday = true;
}
// Determines if the inputed rating is valid.
bool Food::isValidmealrating(int mealrating) {
    if (mealrating >= 1 && mealrating <= 5){
        return true;
    }
    else {
        return false;
    }
}
// Creates linked list node
FoodNode::FoodNode(Food food) {
    data = food;
    next = nullptr;
}
// Used to set head to nullptr
foodList::foodList() {
    head = nullptr;
}
// Clears linked list
foodList::~foodList() {
    clear();
}
// Adds new node
void foodList::insertFront(Food food) {
    FoodNode* newNode = new FoodNode(food);
    newNode->next = head;
    head = newNode;
}
// Returns a pointer to the node with the searched for name.
const FoodNode* foodList::findFood(string name) const {
    const FoodNode* current = head;

    while (current != nullptr) {
        if (current->data.getName() == name) {
            return current;
        }

        current = current->next;
    }

    return nullptr;
}
// Non constant version of findFood.
FoodNode* foodList::findFood(string name) {
    FoodNode* current = head;
    while (current != nullptr) {
        if (current->data.getName() == name) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}
// Gets type.
string Food::getType() const {
    return type;
}
// Gets calories
double Food::getCalories() const {
    return calories;
}
// Marks the food eaten if it was found.
bool foodList::markFoodeaten(string name) {
    FoodNode* found = findFood(name);

    if (found == nullptr) {
        return false;
    }
    else{
        found->data.markEaten();
        return true;
    }
}
// Safely removes all meals that are marked eaten.
int foodList::removeEatenMeals() {
    int removed = 0;
    FoodNode* current = head;
    FoodNode* previous = nullptr;

    while (current != nullptr) {
        if (current->data.iseaten()) {
            if (previous == nullptr) {
                head = current->next;
            } 
            else {
                previous->next = current->next;
            }

            FoodNode* temp = current;
            current = current->next;
            delete temp;
            removed++;
        } 
        else {
            previous = current;
            current = current->next;
        }
    }

    return removed;
}
// Deletes every dynamically allocated node.
void foodList::clear() {
    FoodNode* current = head;

    while (current != nullptr) {
        FoodNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = nullptr;
}
// Checks weather the linked list is empty.
bool foodList::isEmpty() const {
    if (head == nullptr){
        return true;
    }
    else {
        return false;
    }
}

// ===============================
// FoodReport
// ===============================
// Checks if grams is greater or equal to zero.
bool FoodReport::isValidgrams(int grams) {
    if (grams >= 0){
        return true;
    }
    else {
        return false;
    }
}
// Checks if calories is greater or equal to zero.
bool FoodReport::isValidCalories(double calories) {
    if (calories >= 0.0){
        return true;
    }
    else {
        return false;
    }
}
// Calculates calories / gram.
double FoodReport::calculatecalorieValue(const Meals& item) {
    if (!isValidgrams(item.grams) || !isValidCalories(item.Calories)) {
        return 0.0;
    }

    return item.Calories / item.grams;
}
// Reads the file and checks if it opens and if the values are valid.
int FoodReport::readFoodFile(string filename, Meals items[], int MAX_FOOD_ITEMS) {
    if (items == nullptr || MAX_FOOD_ITEMS <= 0) {
        return 0;
    }

    ifstream in(filename);

    if (!in.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return 0;
    }

    int count = 0;
    Meals item;

    while (count < MAX_FOOD_ITEMS &&
           in >> item.type >> item.grams >> item.Calories) {
        if (isValidgrams(item.grams) && isValidCalories(item.Calories)) {
            items[count] = item;
            count++;
        }
    }
    in.close();
    return count;
}
// Writes the report to a file.
bool FoodReport::writeFoodReport(string filename, const Meals items[], int count) {
    if (items == nullptr || count < 0) {
        return false;
    }

    ofstream out(filename);

    if (!out.is_open()) {
        return false;
    }

    out << fixed << setprecision(2);
    out << "Food Report" << endl;
    out << "Type, Grams, Calories, Calories per Gram" << endl;

    for (int i = 0; i < count; i++) {
        out << items[i].type << " "
            << items[i].grams << " "
            << items[i].Calories << " "
            << calculatecalorieValue(items[i]) << endl;
    }

    out << "Total calories consumed: "
        << calculateTotalcalories(items, count)
        << endl;

    out.close();
    return true;
}
// Calculates the total calories in the file.
double FoodReport::calculateTotalcalories(const Meals items[], int count) {
    if (items == nullptr || count <= 0) {
        return 0.0;
    }

    double total = 0.0;

    for (int i = 0; i < count; i++) {
        total += items[i].Calories;
    }

    return total;
}

// ===============================
// Menu helpers
// ===============================
// Determines if the menu choice is valid.
bool isValidMenuChoice(int choice) {
    if (choice >= 0 && choice <= 3) {
        return true;
    }
    else {
        return false;
    }
}
// Determines if the array choice is valid.
bool isValidMenuarrayChoice(int arraychoice) {
    if (arraychoice >= 0 && arraychoice <= 5) {
        return true;
    }
    else {
        return false;
    }
}
// Determines if the linked list choice is valid.
bool isValidMenulistChoice(int listchoice) {
    if (listchoice >= 0 && listchoice <= 5) {
        return true;
    }
    else {
        return false;
    }
}
// Used to print the info on the array.
void printmeal(const food& meal) {
    cout << "Type: " << meal.gettype() 
         << ", Name: " << meal.getName() 
         << ", Calories: " << meal.getFoodlist().getcalorie(0) 
         << endl;
}
// Prints food list meals.
void foodList::printlistmeals() const {
    const FoodNode* current = head;

    while (current != nullptr) {
        cout << "Type: " << current->data.getType()
             << ", Name: " << current->data.getName()
             << ", Calories: " << current->data.getCalories()
             << ", Rating: " << current->data.getmealrating()
             << ", Eaten Today: " << (current->data.iseaten() ? "Yes" : "No")
             << endl;

        current = current->next;
    }
}
