// project3Grocer.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Meixin Zhang 4/16/2023

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Grocery {
public:
    string word1;

    //print menu
    void printMenu() {
        cout << "Menu options:\n"
            << "Press 1: Item you wish to look for\n"
            << "Press 2: Print how many item pops up on list\n"
            << "Press 3: Print how many items pops up in histogram\n"
            << "Press 4: Quit" << endl;
    }

    //prints list
    void printList() {
        for (unsigned int i = 0; i < name.size(); i++) {
            cout << name.at(i) << " " << numItem.at(i) << endl;
        }
        cout << endl;
    }

    //prints out list in histogram
    void printHistogram() {
        //int i;
        //int j;
        for (unsigned int i = 0; i < name.size(); i++) {
            cout << name.at(i) << " ";
            for (size_t j = 0; j < numItem.at(i); j++) {
                cout << "*";
            }
            cout << endl;
        }
        cout << endl;
    }

    //find name reutrn value
    int itemAppearence() {
        string temp;
        //char firstLetter;
        cout << "Input the item you are search for: " << endl;
        cin >> temp;
        temp[0] = toupper(temp.at(0));
        //firstLetter = toupper(temp.at(0));
        //temp.replace(0, 1, firstLetter);
        
        setWord(temp);
        //int i;
        for (unsigned i = 0; i < name.size(); i++) {
            if (name.at(i) == word1) {
                return numItem.at(i);
            }
        }
        return 0;
    }

    //get user word
    string getWord() {
        return word1;
    }

    //set user word
    void setWord(string userWord) {
        word1 = userWord;
    }

    //set vec string name
    void setNameVec(vector<string> nameList) {
        name = nameList;
    }

    //set vec int numItem
    void setNumItemsVec(vector<int> numItemsList) {
        numItem = numItemsList;
    }

private:
    vector<string> name;
    vector<int> numItem;
};


int main()
{
    Grocery itemsList;
    string tempWord;
    string line;
    //int i;
    vector<string> itemNameVec;
    vector<int> numItem;

    // This is the original file to read
    ifstream ini_file{
        "CS210_Project_Three_Input_File.txt"
    };

    ofstream out_file{ "frequency.dat" }; //create new file to write
    ini_file >> tempWord; //get word from file
    itemNameVec.push_back(tempWord); // first word in vector
    numItem.push_back(0); //first value in vector


    //when not reach end of file; writing to file copy
    while (!ini_file.eof()) {
        ini_file >> tempWord; //get word from file
        bool found = false;
        //going through the vector name
        for (int i = 0; i < itemNameVec.size(); i++) {
            //if word is there increase numItem else add item to vector & w/ 1 in 
            if (itemNameVec.at(i) == tempWord) {
                numItem.at(i) += 1;
                found = true;
            }
        }
        if (found == false) {
            itemNameVec.push_back(tempWord);
            numItem.push_back(1);
        }
    }

    //writing to file frequency
    for (int i = 0; i < itemNameVec.size(); i++) {
        out_file << itemNameVec.at(i) << " " << numItem.at(i) << endl;
    }

    // Closing file
    ini_file.close();
    out_file.close();

    itemsList.setNameVec(itemNameVec); // copy item over list names
    itemsList.setNumItemsVec(numItem); // copy item num over 

    //user interface
    int userInput;
    while (true) {
        itemsList.printMenu();
        cin >> userInput;
        if (userInput == 1 || userInput == 2 || userInput == 3) {
            //enter results
            if (userInput == 1) {
                
                cout << itemsList.getWord();

                cout << itemsList.getWord() << " appears " << itemsList.itemAppearence() << " times." << endl;

            }
            else if (userInput == 2) {
                itemsList.printList();
            }
            else if (userInput == 3) {
                itemsList.printHistogram();
            }
        }
        //Quit
        else if (userInput == 4) {
            return 1;
        }
        else {
            cout << "\nInvalid entry. Try again.\n";
            cin.clear();
            cin.ignore();
            //itemsList.printMenu();

            //cin >> userInput;
            cout << endl;
        }

    }

    return 0;
}
