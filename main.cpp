 /* CSCI 261 Final Project - Dog Breed Matching Program
 *
 * Author: Sara Larson
 *
 * In this program, I used File I/O, two classes, vectors, strings, if-else if statements,
 * for and while loops, a function, and cin/cout statements to match potential dog
 * owners with a good dog breed for them. The user enters information about themself
 * and their wishes through a series of questions. This information is then used to
 * populate a class that represents their ideal dog. A file containing dog breeds and
 * information about them is read into a series of two vectors. One vector contains
 * all the file information and the other vector contains information about each
 * specific line. Through the use of a for loop, this second vector gets reset for
 * every line of the first vector. The contents of the second vector are compared
 * to the class created to match a dog breed to the class. If 4/5 or 5/5 attributes
 * match, the breed is outputted to the user. After the user has gotten their list
 * and indicated that they no longer wish to continue, an SFML goodbye graphic is
 * displayed.
 */

#include <iostream>                             // for standard input/output
#include "Dog.h"
#include "Ball.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;                            // using the standard namespace

#include <SFML/Graphics.hpp>                    // include the SFML Graphics Library
using namespace sf;                             // using the sf namespace

// Function prototype for matching breeds
void idealDogBreed(Dog userDog);

int main() {
    // Introductory information printed to user
    cout << "Welcome to Dog-Match, where we find the perfect breed for you!" << endl;
    cout << "Are you interested in finding out which breed best matches your lifestyle?" << endl;
    cout << "1. Yes!" << endl;
    cout << "2. No" << endl;
    // Integer answer that dictates whether the program will run or exit
    int answer = 0;
    cin >> answer;
    // Exiting program if choice is invalid
    if ((answer != 1) && (answer != 2)) {
        cout << "Invalid choice." << endl;
        cout << "Thanks for visiting! Come bark soon!";
        return -1;
    }
    // Exiting program if choice is No
    else if (answer == 2) {
        cout << "Thanks for visiting! Come bark soon!" << endl;
        return -1;
    }
    // Using an int in a while loop for continual program use
    int continueAnswer = 1;
    // While loop that contains the program
    while (continueAnswer == 1) {

        // Using a size variable to continue while loop as long as invalid answers are entered
        // Creating a user string value for size to enter into the user class
        int userSize = 0;
        string userSizeClass;
        while (userSize == 0) {
            cout << "\nPlease enter information about your ideal dog." << endl;
            cout << "What size dog would you prefer?" << endl;
            cout << "1. Large" << endl;
            cout << "2. Medium" << endl;
            cout << "3. Small" << endl;
            // User enters size
            cin >> userSize;

            // If an invalid size is entered, the while loop is re-entered from the top
            if (userSize != 1 && userSize != 2 && userSize != 3) {
                cout << "Please enter a valid option." << endl;
                userSize = 0;
                continue;
            }

            // If a valid size is entered, the user size variable is set appropriately
            if (userSize == 1) {
                userSizeClass = "Large";
            }
            else if (userSize == 2) {
                userSizeClass = "Medium";
            }
            else {
                userSizeClass = "Small";
            }
        }

        // Using a groom variable to continue while loop as long as invalid answers are entered
        // Creating a user string value for grooming to enter into the user class
        int userGrooming = 0;
        string userGroomClass;
        while (userGrooming == 0) {
            cout << "\nPlease enter the level of grooming you would prefer:" << endl;
            cout << "1. High" << endl;
            cout << "2. Medium" << endl;
            cout << "3. Low" << endl;
            // User enters grooming level
            cin >> userGrooming;

            // If an invalid grooming level is entered, the while loop is re-entered from the top
            if (userGrooming != 1 && userGrooming != 2 && userGrooming != 3) {
                cout << "Please enter a valid option." << endl;
                userGrooming = 0;
                continue;
            }

            // If a valid grooming level is entered, the user groom variable is set appropriately
            if (userGrooming == 1) {
                userGroomClass = "High";
            }
            else if (userGrooming == 2) {
                userGroomClass = "Medium";
            }
            else {
                userGroomClass = "Low";
            }
        }

        // Using a fitness variable to continue while loop as long as invalid answers are entered
        // Creating a user string value for fitness to enter into the user class
        int userFitness = 0;
        string userFitnessClass;
        while (userFitness == 0) {
            cout << "\nPlease describe your level of fitness" << endl;
            cout << "1. High" << endl;
            cout << "2. Medium" << endl;
            cout << "3. Low" << endl;
            // User enters fitness level
            cin >> userFitness;

            // If an invalid fitness level is entered, the while loop is re-entered from the top
            if (userFitness != 1 && userFitness != 2 && userFitness != 3) {
                cout << "Please enter a valid value." << endl;
                userFitness = 0;
                continue;
            }

            // If a valid fitness is entered, the user fitness variable is set appropriately
            if (userFitness == 1) {
                userFitnessClass = "High";
            }
            else if (userFitness == 2) {
                userFitnessClass = "Medium";
            }
            else {
                userFitnessClass = "Low";
            }
        }

        // Using a temperature variable to continue while loop as long as invalid answers are entered
        // Creating a user string value for temp to enter into the user class
        int userTemp = 0;
        string userTempClass;
        while (userTemp == 0) {
            cout << "\nPlease describe the temperature you live in for the majority of the year:" << endl;
            cout << "1. Mostly Hot/Warm" << endl;
            cout << "2. Mix of Warm and Cool" << endl;
            cout << "3. Mostly Cold/Cool" << endl;
            // User enters temperature
            cin >> userTemp;

            // If an invalid temperature is entered, the while loop is re-entered from the top
            if (userTemp != 1 && userTemp != 2 && userTemp != 3) {
                cout << "Please enter a valid option." << endl;
                userTemp = 0;
                continue;
            }

            // If a valid temp is entered, the user temp variable is set appropriately
            if (userTemp == 1) {
                userTempClass = "Hot";
            }
            else if (userTemp == 2) {
                userTempClass = "Mid";
            }
            else {
                userTempClass = "Cold";
            }
        }

        // Using a playfulness variable to continue while loop as long as invalid answers are entered
        // Creating a user string value for playfulness to enter into the user class
        int userPlayfulness = 0;
        string userPlayClass;
        while (userPlayfulness == 0) {
            cout << "\nPlease enter the level of playfulness you want in a dog:" << endl;
            cout << "1. Very Playful" << endl;
            cout << "2. Mid-Level Playful" << endl;
            cout << "3. Not Very Playful" << endl;
            // User enters playfulness
            cin >> userPlayfulness;
            // MAYBE make this cin value a constant

            // If an invalid playfulness is entered, the while loop is re-entered from the top
            if (userPlayfulness != 1 && userPlayfulness != 2 && userPlayfulness != 3) {
                cout << "Please enter a valid option." << endl;
                userPlayfulness = 0;
                continue;
            }

            // If a valid playfulness is entered, the user playfulness variable is set appropriately
            if (userPlayfulness == 1) {
                userPlayClass = "High";
            }
            else if (userPlayfulness == 2) {
                userPlayClass = "Medium";
            }
            else {
                userPlayClass = "Low";
            }
        }

        // Creating the user's Dog by calling the Dog parameterized constructor using the class variables created above
        Dog userDog(userSizeClass, userGroomClass, userFitnessClass, userTempClass, userPlayClass);

        // Outputting the breeds to the user
        cout << "Here is a list of breeds that would fit best with you!\n" << endl;
        // Calling the dog-breed-matching function with the userDog as the argument
        idealDogBreed(userDog);
        // Outputting information regarding the program
        cout << left << setw(95) << "*** Please note that these breeds match your criteria by 80%+" << right << "***" << endl;
        cout << left << setw(95) << "*** If the above list is blank, please try again, changing answers slightly as appropriate" << right << "***" << endl;
        cout << "\n" << "- All dog breed information used is from the American Kennel Club -" << endl;

        // Asking the user if they would like to use the program again
        int continuingThisLoop = -1;
        // Using another while loop in order to catch invalid inputs
        while (continuingThisLoop == -1) {
            cout << "\n" << "Would you like to go again?" << endl;
            cout << "1. Yes!" << endl;
            cout << "2. No" << endl;
            cin >> continueAnswer;

            // If an invalid input is entered, then this inner while loop is re-entered
            if (continueAnswer != 1 && continueAnswer != 2) {
                cout << "Please enter a valid option" << endl;
                continuingThisLoop = -1;
            }

            // If the user answers yes, the large while loop encompassing the whole program is re-entered
            else if (continueAnswer == 1) {
                continuingThisLoop = 0;
            }

            // If the user answers no, both loops are exited
            else {
                cout << "Thank you for visiting!" << endl;
                continuingThisLoop = 0;

            }
        }
    }

    // Creating a ball of type Ball to display on the SFML window
    Ball ball;
    // Setting initial x and y speeds as constant values
    ball.setXDir(.3);
    ball.setYDir(.5);

    // create a RenderWindow object
    // specify the size to be 640x640
    // set the title to be "SFML Example Window"
    RenderWindow window( VideoMode(640, 640), "SFML Example Window" );

    //********************************************
    //  PLACE ANY FILE INPUT PROCESSING BELOW HERE
    //********************************************

    //********************************************
    //  PLACE ANY FILE INPUT PROCESSING ABOVE HERE
    //********************************************

    // while our window is open, keep it open
    // this is our draw loop
    while( window.isOpen() ) {
        window.clear( Color::Cyan );           // clear the contents of the old frame
                                                // by setting the window to black

        //****************************************
        //  ADD ALL OF OUR DRAWING BELOW HERE
        //****************************************

        // Creating a circle shape that makes up part of the image of a dog bone
        CircleShape circle1;
        circle1.setRadius(100);
        circle1.setPosition(20, 20);
        circle1.setFillColor(Color::White);
        window.draw(circle1);

        // Creating a circle shape that makes up part of the image of a dog bone
        CircleShape circle2;
        circle2.setRadius(100);
        circle2.setPosition(20, 120);
        circle2.setFillColor(Color::White);
        window.draw(circle2);

        // Creating a rectangle shape that makes up part of the image of a dog bone
        RectangleShape rec;
        rec.setSize(Vector2f(400, 165));
        rec.setFillColor(Color::White);
        rec.setPosition(100, 80);
        window.draw(rec);

        // Creating a circle shape that makes up part of the image of a dog bone
        CircleShape circle3;
        circle3.setRadius(100);
        circle3.setPosition(420, 20);
        circle3.setFillColor(Color::White);
        window.draw(circle3);

        // Creating a circle shape that makes up part of the image of a dog bone
        CircleShape circle4;
        circle4.setRadius(100);
        circle4.setPosition(420, 120);
        circle4.setFillColor(Color::White);
        window.draw(circle4);

        // Writing the font to appear on the SFML window
        Font dogFont;
        if (!dogFont.loadFromFile("data/arial.ttf")) {
            return -1;
        }
        Text goodbye;
        goodbye.setFont(dogFont);
        goodbye.setString("COME BARK SOON!");
        goodbye.setPosition(35, 125);
        goodbye.setCharacterSize(60);
        goodbye.setFillColor(Color::Black);
        window.draw(goodbye);

        // Drawing the ball of type Ball initialized above and updating it's position
        window.draw(ball.getBall());
        ball.updatePosition();

        // Creating a y-axis barrier for the bouncing ball
        // If it gets up to 315 on the y-axis, it will bounce back down
        if (ball.getBall().getPosition().y >= 545 || ball.getBall().getPosition().y <= 315) {
            ball.setYDir(ball.getYDir() * -1);
        }

        //****************************************
        //  ADD ALL OF OUR DRAWING ABOVE HERE
        //****************************************

        window.display();                       // display the window

        //****************************************
        // HANDLE EVENTS BELOW HERE
        //****************************************
        Event event;
        while( window.pollEvent(event) ) {      // ask the window if any events occurred
            if( event.type == Event::Closed ) { // if event type is a closed event
                                                // i.e. they clicked the X on the window
                window.close();                 // then close our window
            }
        }
    }

    return EXIT_SUCCESS;                        // report our program exited successfully
}

// Writing the definition of the dog matching function
void idealDogBreed(Dog userDog) {

    // Opening the file with the dogs breeds and information on it
    ifstream dogFile("dogs.txt");
    if (dogFile.fail()) {
        cout << "Error";
    }

    // Declaring a string and vector to read in the file info
    string value;
    vector<string> dogAttributes;

    // Using a while loop to gather all of the information in the file and save it to a vector
    while (getline(dogFile, value)) {
        dogAttributes.push_back(value);
    }

    // Reading through the vector with all the dog info
    for(int j = 0; j < dogAttributes.size(); j++){
        // Creating a new vector for each line
        vector<string> currentLine;
        // Creating a variable to keep track of how well a breed matches to the userDog
        int matchingBreed = 0;
        // Creating an empty string to construct each word on the line and append it to the second vector
        string word = "";
        // Reading through each line of the dog info vector
        for(int k = 0; k < dogAttributes.at(j).size(); k++) {
            // Adding each letter to the word
            word += dogAttributes.at(j).at(k);
            // If the letter is a comma or a period, it is removed from the word
            if(dogAttributes.at(j).at(k) == ',' || dogAttributes.at(j).at(k) == '.') {
                word.pop_back();
                // The word is now added to the second vector
                currentLine.push_back(word);
                // The word variable is reset to blank
                word = "";
            }
        }
        // Comparing the elements of this new vector for each line to the elements in userDog
        // If there is a match, the matchingBreed variable is incremented by 1

        // Comparing size values
        if (currentLine.at(1) == userDog.getSize()) {
            matchingBreed += 1;
        }
        // Comparing the grooming values
        if (currentLine.at(2) == userDog.getGroom()) {
            matchingBreed += 1;
        }
        // Comparing the fitness values
        if (currentLine.at(3) == userDog.getFit()) {
            matchingBreed += 1;
        }
        // Comparing the temperature values
        if (currentLine.at(4) == userDog.getTemp()) {
            matchingBreed += 1;
        }
        // Comparing the playfulness values
        if (currentLine.at(5) == userDog.getPlay()) {
            matchingBreed += 1;
        }
        // If the matching breed integer is equal to 5 matches, the breed name and great match strings are printed
        if (matchingBreed == 5) {
            cout << left << setw(30) << currentLine.at(0);
            cout << setw(10) << "--- GREAT match" << endl;
            cout << "\n";
        }
            // If the matching breed integer is equal to 4 matches, the breed name and good match strings are printed
        else if (matchingBreed == 4) {
            cout << left << setw(30) << currentLine.at(0);
            cout << setw(10) << "--- GOOD match" << endl;
            cout << "\n";
        }
    }
}