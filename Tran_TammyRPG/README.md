[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `Tammy Tran`  
### **Student ID:** `828404870`  

---

## **1. Project Overview**
This project is a text-based RPG that uses a binary decision tree. At each event in the game, it is a node with two possible choices, left or right. The player progresses through the game by selecting one of the two options shown at each stage. The decision tree is built based off from reading data from the story.txt file that includes event descriptions and the left and right events. Finally, the game officially ends when it reaches a leaf node (nullptr/-1 left and -1 right) with no other choices.

---

## **2. Folder & File Structure**

- **`main.cpp`** → `[This is the main function file where you start the game execution. The file also has logic that helps read and load the story data from the file.]`  
- **`GameDecisionTree.h`** → `[This file contains the declartion of the GameDecisionTree class which is used to manage the decision tree. In this class, I included a method to load the story from the txt file, created the binary decision tree and transversed through the tree based on the players choice.]`  
- **`Node.h`** → `[This file contains the Node class where a node is used to represent an event in the game. Then using the left and right children as the possible choices(paths) you can choose.]`  
- **`Story.h`** → `[This file contains the Story class which stores the informaton of each event.]`  
- **`story.txt`** → `[The game loads story events from the file since each line in the file is an event that includes the eventNumber, description, leftChildEventNumbre and rightChildEventNumber. Using the delimiter declared in the main.cpp we are able to load the events from the file and construct a binary decision tree that parses the lines.]`  

---

## **3. Decision Tree Construction**
The decision tree is built by reading the lines from the story.txt file, which is organized like a binary tree structure. Like a binary tree, each event has a description and is connected to two possible outcomes (left or right). As the file reads the story.txt file, nodes are created for each event and create a tree. Eventually, based on the players choices, a pathway is created when progressing through the story and reaching the end.

- How are `Story` objects created from the text file?  
  - Story objects are created by reading the lines of the story.txt file. As we know, each event description has an event number, left event number and right event number that are separated by a delimiter. So, when it parses using a string stream on lines 36 - lines 47, a story object is created and used to create Node<T> which is added to storyMap. 
- How are nodes linked based on left and right event numbers?  
  - The nodes are linked on left and right event numbers by having the program iterate through the storyMap which link the nodes. 
- What happens if an event has `-1` as left or right children?  
  - If an event has a -1 as left or right children, then it means it is set to nullptr and is a leaf node. This will then cause the story to end.
---

## **4. Game Traversal**
The game moves through the decision tree by starting at the root and moving to the left or right child node based on what the player chooses. The story repeats and continues until a leaf node is reached which will cause the story to end.

- How does user input determine the path taken?  
  - The user input determines the path taken by allowing the player to choose between the two prompted options of the number 1 (left) or number 2 (right).
- What happens when the player reaches a leaf node? 
  - When the player reaches a leaf node, the story will end since there are no other choices to make.
- Explain the special case where multiple events lead to the same outcome.  
  - Depending on the players choices, some events lead to the same outcome in the game. This occurs when a node points to the same node. This means that the story can have multiple paths that can lead to a common ending. For example, in my game, 4 can lead to 8 and 9 but 6 can also lead to 8 and 9. 
  
---

## **5. File Parsing & Data Loading**
The story.txt is read by using an ifstream object that reads each line and divides it to event number, description, left event number and right event number. Nodes are also created and stored into the storyMap and then assigned to the left and right pointers.

- How is the file read and parsed using a delimiter? 
  - The story.txt file is read using an ifstream object and then processes each line using a stringstream to divide left and right using a delimiter. The data is then taken for eventNumber, description, leftEventNumber, and rightEventNumber and used to create Story objects.
- How do you ensure nodes are properly linked?  
  - To ensure all nodes are linked after creating a node, they are stored in the storyMap after created. Once all the nodes are created, the right and left pointers are assigned by checking the rightEventNumber and leftEventNumber from the map.  
- Any challenges faced while handling file input?  
  - A challenge I faced while handling file input was that ifstream file("Story.txt") did not work because the file path was not recognized. In order to fix this, I went into terminal to get ifstream file("/Users/tammytran/programming-assignment-2-ttran3300/story.txt");. I also included an if statement to check whether the file was successfully opened which helped me identify if the file was read properly.

---

## **6. Debugging Process (Errors & Fixes)**
When I was testing my program it kept crashing and showing a SIGSEG error. I realized it was trying to access memory that wasn't properly initialized, so I fixed it by adding an if(p.second) which ensured that the pointer stored is valid (not a nullptr).

---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)

CONGRATULATIONS! You won the lottery and take home 5 million dollars. Do you:
1. You share your wealth with your friends/family. (Go left)
2. You spend the money on yourself. (Go right)

Enter your choice: 1
   You share your wealth with your friends/family. Do you:
1. You quickly book a flight for you and your best friends to travel to Costa Rica for 2 weeks. (Go left)
2. You pay off all your family debts and settle down. (Go right)
   
Enter your choice: 1
   
You quickly book a flight for you and your best friends to travel to Costa Rica for 2 weeks. Do you:
1. You spend your last day at an all-inclusive resort. (Go left)
2. You spend your last day venturing out of the hotel to explore. (Go right)
   
Enter your choice: ejdslk
   
Invalid. Enter your choice: 2
   
You spend your last day venturing out of the hotel to explore. Do you:
1. You go hiking to a beautiful waterfall. (Go left)
2. You try new foods in the local town and enjoy the beach. (Go right)
   
Enter your choice: 1
   
You go hiking to a beautiful waterfall. Do you:
1. Your trip has sadly come to an end and you have a safe flight home. (Go left)
   
Enter your choice: 1
   
Your trip has sadly come to an end and you have a safe flight home.
   
The game has ended. Thanks for playing!

Process finished with exit code 0

---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(n)`  
- **Searching for an event in the tree** → `O(1)`  
- **Game traversal efficiency** → `O(logn)`  

---

## **9. Edge Cases & Testing**
An edge case that I tested was when the player inputs an invalid input such as a letter or number other than 1 or 2, the game will prompt the user again until a valid input is provided.

---

## **10. Justification of Additional Features (If Any)**
A feature I added to the game was to prompt "The game has ended. Thanks for playing!" when the player has reached a leaf node to clarify the game is officially over.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
