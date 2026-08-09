#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <string>

const int MAX_FOOD_ITEMS = 25;
// Header file, kept it similar to example, we didn't learn it well, so nothing too new. 
class FoodarrayList {
private:
    double foods[25];
    int count;

public:
    FoodarrayList();

    bool addcalorie(double calorie);
    int getCount() const;
    double getcalorie(int index) const;

    double getTotalcalories() const;
    double getAveragecalories() const;
    int findmeal(double target) const;
    

    static bool isValidcalorie(double calories);
};

class food {
private:
    std::string type;
    std::string name;
    FoodarrayList foodlist;

public:
    food();
    food(std::string foodtype, std::string foodname);

    std::string gettype() const;
    std::string getName() const;
    FoodarrayList& getFoodlist();
    const FoodarrayList& getFoodlist() const;
    std::string getCalorie() const;
    

    static bool isValidtype(std::string type);
};
void sortMeals(food mealArray[], int mealCount);
class Food {
private:
    std::string type;
    std::string name;
    std::string description;
    double calories;
    int mealrating;
    bool eatentoday;

public:
    // Constructors
    Food();
    Food(std::string foodDescription, int taskmealrating);
    Food(std::string foodtype, std::string foodname, double foodcalories, int taskmealrating);

    // Getters
    std::string getType() const;
    std::string getName() const;
    double getCalories() const;
    int getmealrating() const;
    bool iseaten() const;
    void markEaten();
    static bool isValidmealrating(int mealrating);
};

class FoodNode {
public:
    Food data;
    FoodNode* next;

    FoodNode(Food task);
};

class foodList {
private:
    FoodNode* head;

public:
    foodList();
    foodList(const foodList& other) = delete;
    foodList& operator=(const foodList& other) = delete;
    ~foodList();

    void insertFront(Food task);
    int countFoods() const;
    FoodNode* findFood(std::string description);
    const FoodNode* findFood(std::string description) const;
    bool markFoodeaten(std::string description);
    int removeEatenMeals();
    void clear();
    bool isEmpty() const;
    void printlistmeals() const;
};

struct Meals {
    std::string name;
    std::string type;
    int grams;
    double Calories;
};

class FoodReport {
public:
    static bool isValidgrams(int grams);
    static bool isValidCalories(double Calories);
    static double calculatecalorieValue(const Meals& item);

    static int readFoodFile(std::string filename, Meals items[], int MAX_FOOD_ITEMS);
    static bool writeFoodReport(std::string filename, const Meals items[], int count);

    static double calculateTotalcalories(const Meals items[], int count);
    static int findItemByname(const Meals items[], int count, std::string name);
    static int findHighestcalorieIndex(const Meals items[], int count);
};

bool isValidMenuChoice(int choice);
bool isValidMenuarrayChoice(int arraychoice);
bool isValidMenulistChoice(int listchoice);
void printMenu();
void printmeal(const food& meal);


double calculateTotalCalories(const food mealArray[], int mealCount);

#endif
