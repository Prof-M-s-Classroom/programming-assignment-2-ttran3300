#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        ifstream file("/Users/tammytran/programming-assignment-2-ttran3300/story.txt");
        string description;
        string eventNumber;
        string leftEventNumber;
        string rightEventNumber;
        string story;
        unordered_map<int, Node<T>*> storyMap;
        storyMap[-1] = nullptr;

        if (!file) {
            cout << "Error: Unable to open file: " << filename << endl;
            return;
        }

        while (getline(file, story)) {
            stringstream ss(story);
            getline(ss, eventNumber, delimiter);
            getline(ss, description, delimiter);
            getline(ss, leftEventNumber, delimiter);
            getline(ss, rightEventNumber);

            T event(description, stoi(eventNumber), stoi(leftEventNumber), stoi(rightEventNumber));
            Node<T>* current = new Node<T>(event);

            storyMap[stoi(eventNumber)] = current;
        }
        file.close();
        root = storyMap[1];

        for (auto p : storyMap) {
            if (p.second) {

                p.second->left = storyMap[(p.second->data.leftEventNumber)];
                p.second->right = storyMap[(p.second->data.rightEventNumber)];
            }
        }
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        Node<T>* current = root;

        while (current && (current->left || current->right)) {
            cout << current->data.description << "Do you: " <<endl;

            if (current->left) {
                cout << "1." << current->left->data.description << "(Go left)" <<endl;
            }

            if (current->right) {
                cout << "2." << current->right->data.description << "(Go right)" <<endl;
            }

            cout << "Enter your choice: ";

            int num;
            cin >> num;

            while (cin.fail() || num == 1 && current->left == nullptr || num == 2 && current->right == nullptr || num > 2 || num < 1) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid. Enter your choice: ";
                cin >> num;
            }

            if (num == 1) {
                current = current->left;
            } else {
                current = current->right;
            }

            if (current && current->left == nullptr && current->right == nullptr) {
                cout << current->data.description << endl;
                cout << "The game has ended. Thanks for playing!" << endl;
                break;
            }

        }
    }
};

#endif // GAMEDECISIONTREE_H