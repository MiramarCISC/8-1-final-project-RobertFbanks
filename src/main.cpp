#include "project.hpp"
#include <iostream>

using namespace std;

// This lab has taken me so long ive been forgetting to commit at all. I'm so sorry. I missed that instruction on the canvus page. 

int main() {
    cout << "This is my final project for CISC 192, a meal tracker." << endl;
    cout << "There are 2 versions, one with a normal array and one with a linked list." << endl;
    cout << "Meals can be split into separete parts depending on food category." << endl;
    cout << endl;

    // Set all choices and variables only used in main.
    food mealArray[MAX_FOOD_ITEMS];
    foodList LinkedList;
    int arraychoice = -1;
    int choice = -1;
    int mealCount = 0;
    int listchoice = -1;

    do {
        cout << "Enter 1 for array based tracker" << endl;
        cout << "Enter 2 for linked list based tracker" << endl;
        cout << "Enter 3 to read reccomended meal input file and write report" << endl;
        cout << "Enter 0 to exit program" << endl;
        cout << endl;
        cout << "Please enter choice: ";

        cin >> choice;
        cout << endl;

        while (!isValidMenuChoice(choice)) {
            cout << "Invalid choice. Enter 0-3: ";
            cin >> choice;
        }

        switch (choice) { // Array based tracker
            case 1: {
                do {
                    cout << "Array meal tracker selected" << endl;
                    cout << endl;
                    cout << "Enter 1 to add a meal" << endl;
                    cout << "Enter 2 to display all meals" << endl;
                    cout << "Enter 3 to show total calories" << endl;
                    cout << "Enter 4 to search for meal: " << endl;
                    cout << "Enter 5 to sort meals by calories" << endl;
                    cout << "Enter 0 to exit to main menu" << endl;
                    cout << endl;
                    cout << "Please enter choice: ";

                    cin >> arraychoice;

                    // Checks if the choice is valid
                    while (!isValidMenuarrayChoice(arraychoice)) {
                        cout << "Invalid choice. Enter 0-5: ";
                        cin >> arraychoice;
                    }
                
                    switch (arraychoice) {
                        case 1: { // Used a bit of help in case 1, wanted to make it user inputable. I belive we didn't learn array imput but wanted it to make the program better.
                            if (mealCount >= MAX_FOOD_ITEMS) { // Checks if full
                                cout << "Array is full! Cannot add more items." << endl;
                            }
                            else {
                                string foodType;
                                string foodName;
                                double calories = -1;
                                
                                cout << "Food types: Protein, Carbs, Dairy, Vegetables, Fruit, Dessert, Beverage, or other." << endl;
                                cout << "Enter food type: ";
                                cin >> foodType;
                                // Checks if valid food type
                                while (!food::isValidtype(foodType)) {
                                    cout << "Invalid food type. Please try again: " << endl;
                                    cin >> foodType;
                                }

                                cout << "Enter food name: ";
                                cin.ignore();
                                getline(cin, foodName);

                                cout << "Enter the amount of calories: ";
                                cin >> calories;

                                while (!FoodarrayList::isValidcalorie(calories)) {
                                    cout << "Invalid amount of calories or stop eating so much! Please enter 0-5000: ";
                                    cin >> calories;
                                }
                                // After getting variables, enters it into array
                                food tempFood(foodType, foodName);
                                tempFood.getFoodlist().addcalorie(calories);

                                mealArray[mealCount] = tempFood;
                                mealCount++;

                                cout << "Food added to array" << endl;
                            }
                            break;
                        }
                        case 2: {
                            if (mealCount == 0){
                                cout << "Please add a meal" << endl;
                            }
                            else{ // Used already declared print function to print
                                for (int i = 0; i < mealCount; i++) {
                                    printmeal(mealArray[i]);
                                }
                            }                            
                            break;
                        }
                        case 3: { // Shows total calories of all items enetred on array
                            double Total = calculateTotalCalories(mealArray, mealCount);
                            cout << "Total Calories: " << Total << endl;
                            break;
                        }   
                        case 4: {
                            if (mealCount == 0) {
                                cout << "Please add a meal" << endl;
                            } 
                            else { // Also used week 4 main file to help with this main section
                                string target;
                                cout << "Enter meal name to search for: ";
                                cin.ignore();
                                getline(cin, target);

                                int found = -1;
                                for (int i = 0; i < mealCount; i++) {
                                    if (mealArray[i].getName() == target) {
                                        found = i;
                                        break;
                                    }
                                }

                                if (found == -1) {
                                    cout << "Meal not found." << endl;
                                } 
                                else {
                                    cout << "Found meal at index " << found << ": "
                                        << mealArray[found].getName() << endl;
                                }
                            }
                            break;
                      }
                        case 5: {
                            if (mealCount == 0) {
                                cout << "Please add a meal" << endl;
                            } else { // Automatically sorts the meals by their amount of calories using selection sort form week 4 lab
                                sortMeals(mealArray, mealCount);
                                cout << "Meals sorted by calories." << endl;
                            }
                            break;
                        }
                    }

                } 
                while (arraychoice != 0);

                break;
            }
            case 2: {
                do {
                    cout << "Linked list meal tracker selected" << endl;
                    cout << endl;
                    cout << "Enter 1 to add a meal" << endl;
                    cout << "Enter 2 to display all meals" << endl;
                    cout << "Enter 3 to mark a meal eaten" << endl;
                    cout << "Enter 4 to remove eaton meals" << endl;
                    cout << "Enter 5 to clear all meals" << endl;
                    cout << "Enter 0 to exit to main menu" << endl;
                    cout << endl;
                    cout << "Please enter choice: ";

                    cin >> listchoice;

                    while (!isValidMenulistChoice(listchoice)) {
                        cout << "Invalid choice. Enter 0-5: ";
                        cin >> listchoice;
                    }
                    switch (listchoice) {
                        case 1: { // This section was mostly used from week 6 main file.
                            string foodType;
                            string foodName;
                            double calories;
                            int foodrating;

                            cout << "Food types: Protein, Carbs, Dairy, Vegetables, Fruit, Dessert, Beverage, or other." << endl;
                            cout << "Enter food type: ";
                            cin >> foodType;

                            while (!food::isValidtype(foodType)) {
                            cout << "Invalid type. Try again: ";
                            cin >> foodType;
                            }

                            cout << "Enter food name: ";
                            cin.ignore();
                            getline(cin, foodName);

                            cout << "Enter calories: ";
                            cin >> calories;

                            while (!FoodarrayList::isValidcalorie(calories)) {
                                cout << "Invalid calories, or stop eating so much! Enter 0-5000: ";
                                cin >> calories;
                            }
                            cout << "Enter meal rating (1-5): ";
                            cin >> foodrating;

                            while (!Food::isValidmealrating(foodrating)) {
                                cout << "Invalid rating. Enter 1-5: ";
                                cin >> foodrating;
                            }
                            // Insterts new node with all the information.
                            LinkedList.insertFront(Food(foodType, foodName, calories, foodrating));

                            cout << "Meal added." << endl;

                            break;
                        }
                        case 2: { // Checks if list is empty
                            if (LinkedList.isEmpty()) {
                                cout << "Please add a meal" << endl;
                            }
                            else { // If not empty it prints all info in linked list
                                LinkedList.printlistmeals();
                            }
                            break;
                        }
                        case 3: {
                            string mealname;

                            cout << "Enter name of meal to mark eaten: ";
                            cin.ignore();
                            getline(cin, mealname);
                            // Section to mark a meal eaten
                            if (LinkedList.markFoodeaten(mealname)) {
                                cout << "Food marked as eaten." << endl;
                            }
                            else {
                                cout << "Food not found." << endl;
                            }
                            break;
                        }
                        case 4: {
                            LinkedList.removeEatenMeals(); // Removes all meals marked as eaten
                            cout << "All eaten meals removed" << endl;

                            break;
                        }
                        case 5: {
                            LinkedList.clear();
                            cout << "All meals cleared" << endl;
                            // Clears everything
                            break;
                        }
                    }
                }
                while (listchoice != 0);
                break;
            }
            case 3: {
                cout << "Read reccomended meal file selected" << endl;

                Meals items[MAX_FOOD_ITEMS]; // Influences from example from this project, and week 7 main.
                int count = FoodReport::readFoodFile("data/DailyFood.txt", items, MAX_FOOD_ITEMS);
                cout << "Read " << count << " items from DailyFood.txt" << endl;
                cout << "Total calories reccomened per day: ";
                cout << FoodReport::calculateTotalcalories(items, count) << endl;
                cout << endl; // Reads file and gives reccomended calories
                

                if (FoodReport::writeFoodReport("DailyFood.txt", items, count)) {
                    cout << "Report written to DailyFood.txt" << endl;
                } // Writes a report file

                break;
            }
        }

    } 
    while (choice != 0);

    cout << "Goodbye, thanks for looking!" << endl;
}    
    // End of project            











// Kept for reference below to help with final project

/*
int m() {
    int choice = -1;

    cout << "CISC 192 Final Project Sample" << endl;
    cout << "Sample code is provided only as an example." << endl;
    cout << "Delete or replace the sample code before final submission." << endl;

    do {
        printMenu();
        cin >> choice;

        while (!isValidMenuChoice(choice)) {
            cout << "Invalid choice. Enter 0-4: ";
            cin >> choice;
        }

        switch (choice) {
            case 1: {
                Student student("A123", "Alex");
                student.getScoreList().addScore(90.0);
                student.getScoreList().addScore(80.0);
                student.getScoreList().addScore(100.0);
                student.getScoreList().sortAscending();

                printStudent(student);
                cout << "Score 100 found at index "
                     << student.getScoreList().findScore(100.0)
                     << endl;

                break;
            }

            case 2: {
                TaskList tasks;
                tasks.insertFront(Task("study", 5));
                tasks.insertFront(Task("project", 4));
                tasks.markTaskComplete("study");

                cout << "Task count: " << tasks.countTasks() << endl;
                cout << "Removed completed tasks: "
                     << tasks.removeCompletedTasks()
                     << endl;
                cout << "Remaining task count: " << tasks.countTasks() << endl;

                break;
            }

            case 3: {
                InventoryItem items[MAX_INVENTORY_ITEMS];
                int count = InventoryReport::readInventoryFile(
                    "data/inventory.txt",
                    items,
                    MAX_INVENTORY_ITEMS
                );

                cout << "Read " << count << " inventory item(s)." << endl;
                cout << "Total inventory value: "
                     << InventoryReport::calculateTotalInventoryValue(items, count)
                     << endl;

                if (InventoryReport::writeInventoryReport(
                        "inventory_report.txt",
                        items,
                        count
                    )) {
                    cout << "Report written to inventory_report.txt" << endl;
                }

                break;
            }

            case 4:
                cout << "Use this sample only as an example. "
                     << "Delete or replace sample code before submission."
                     << endl;
                break;

            case 0:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Unexpected choice." << endl;
                break;
        }

    } 
    while (choice != 0);

    return 0;
}

*/