#include "project.hpp"
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool nearlyEqual(double actual, double expected, double tolerance = 0.0001) {
    return fabs(actual - expected) <= tolerance;
}
// Some functions I didn't use, so I added some I did, or changed assertvalues and function names.
void createTestDailyFoodFile(const string& filename) {
    ofstream out(filename);

    out << "Protein 100 400.00" << endl;
    out << "Carbs 250 1000.00" << endl;
    out << "Vegetables 300 150.00" << endl;
    out << "Fruit 200 150.00" << endl;
    out << "Other 100 400.00" << endl;

    out.close();
}

// Week 1: Program Basics
void testWeek1ProgramBasics() {
    FoodarrayList calories;
    calories.addcalorie(80.0);
    calories.addcalorie(90.0);

    double total = calories.getTotalcalories();

    assert(nearlyEqual(total, 170.0));
}

// Week 2: Decisions and Loops
void testWeek2DecisionsAndLoops() {
    assert(FoodarrayList::isValidcalorie(0.0));
    assert(FoodarrayList::isValidcalorie(5000.0));
    assert(!FoodarrayList::isValidcalorie(-1.0));
    assert(!FoodarrayList::isValidcalorie(5001.0));

    assert(food::isValidtype("Protein"));
    assert(food::isValidtype("Fruit"));
    assert(!food::isValidtype("Pizza"));
    assert(!food::isValidtype("Cookies"));

    assert(isValidMenuChoice(0));
    assert(isValidMenuChoice(2));
    assert(!isValidMenuChoice(4));
}

// Week 3: Functions and Program Design
void testWeek3FunctionsAndProgramDesign() {
    FoodarrayList calories;
    calories.addcalorie(200.0);
    calories.addcalorie(80.0);
    calories.addcalorie(900.0);

    assert(nearlyEqual(calories.getTotalcalories(), 1180.0));

    food meal("Protein", "Chicken");
    assert(meal.gettype() == "Protein");
    assert(meal.getName() == "Chicken");
}

// Week 4: Arrays, Searching, and Sorting
void testWeek4ArraysSearchingSorting() {
    // This section was a pain in the A**. Sorry if the test isn't great here im sorry, I tried.
    // I've probaly spend the good part of an hour on this one section just to get it to work. 
    FoodarrayList calories;
    calories.addcalorie(89.0);
    calories.addcalorie(73.0);
    calories.addcalorie(100.0);
    calories.addcalorie(94.0);

    assert(nearlyEqual(calories.getcalorie(0), 89.0));
    assert(nearlyEqual(calories.getcalorie(1), 73.0));
    assert(nearlyEqual(calories.getcalorie(2), 100.0));
    assert(nearlyEqual(calories.getcalorie(3), 94.0));

    assert(nearlyEqual(calories.getTotalcalories(), 356.0));
}

// Week 5: Strings and Structures
void testWeek5StringsAndStructures() {
    food meal("Protein", "Chicken");

    assert(food::isValidtype("Protein"));
    assert(!food::isValidtype("Pizza"));
    assert(meal.gettype() == "Protein");
    assert(meal.getName() == "Chicken");

    Meals item = {"bread", "Carbs", 250, 1000.00};
    assert(item.name == "bread");
    assert(item.type == "Carbs");
    assert(item.grams == 250);
    assert(item.Calories == 1000.00);
}

// Week 6: Simple Linked Task List
void testWeek6SimpleLinkedTaskList() {
    foodList foods;

    foods.insertFront(Food("Protein", "Chicken", 400.0, 5));
    foods.insertFront(Food("Carbs", "mac and cheese", 300.0, 4));
    foods.insertFront(Food("Fruit", "strawberries", 150.0, 3));


    assert(foods.findFood("mac and cheese") != nullptr);
    assert(foods.findFood("pizza") == nullptr);

    assert(foods.markFoodeaten("Chicken"));
    assert(foods.markFoodeaten("strawberries"));

    int removed = foods.removeEatenMeals();

    assert(removed == 2);
    assert(foods.findFood("mac and cheese") != nullptr);
    assert(foods.findFood("Chicken") == nullptr);

    foods.clear();
    assert(foods.isEmpty());
}

// Week 7: File-Based Inventory Report
void testWeek7FileBasedInventoryReport() {
    string inputFilename = "tests/resources/test_food_input.txt";
    string outputFilename = "tests/resources/test_food_report_output.txt";

    createTestDailyFoodFile(inputFilename);

    Meals items[10];
    int count = FoodReport::readFoodFile(inputFilename, items, 10);

    assert(count == 5);
    assert(items[0].type == "Protein");
    assert(items[1].type == "Carbs");
    assert(items[2].type == "Vegetables");

    assert(nearlyEqual(FoodReport::calculatecalorieValue(items[0]), 4.0));
    assert(nearlyEqual(FoodReport::calculateTotalcalories(items, count), 2100.0));

    bool wroteReport = FoodReport::writeFoodReport(outputFilename, items, count);
    assert(wroteReport);

    ifstream in(outputFilename);
    assert(in.is_open());

    string contents;
    string line;

    while (getline(in, line)) {
        contents += line + "\n";
    }

    assert(contents.find("Food Report") != string::npos);
    assert(contents.find("Protein") != string::npos);
    assert(contents.find("Total calories consumed") != string::npos);
}

int main() {
    testWeek1ProgramBasics();
    testWeek2DecisionsAndLoops();
    testWeek3FunctionsAndProgramDesign();
    testWeek4ArraysSearchingSorting();
    testWeek5StringsAndStructures();
    testWeek6SimpleLinkedTaskList();
    testWeek7FileBasedInventoryReport();

    cout << "All corrected final project tests passed!" << endl;
    return 0;
}
