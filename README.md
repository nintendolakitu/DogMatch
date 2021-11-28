# DogMatch
DogMatch Program created in C++. Used to match potential dog owners with an optimal breed based on their lifestyle.

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
