
# Java Lab Questions

## Lab2

>1. Write a Java program to convert minutes into a number of years and days

>2. Write a Java program to find the duplicate values of an array of integer values

>3. Write a Java program to find the kth smallest and largest element in a given array. Elements in the array can be in any order.

>4. Write a Java program to find the numbers greater than the average of the numbers of a given array.

>5. Write a Java program to move every positive number to the right and every negative number to the left of a given array of integers.

>6. Display a question to user allow the user to answer the question. Allow 3 chances to user. If correct answer display "Good" else display correct answer after 3 attempts.

>7. Shown below is a Floyd's triangle. 1 2 3 4 5 6 7 8 9 10 11 ... ... ... 15 . . 79 .. .. .. .. .. .. .. .. 91
a. Write a program to print this triangle
b. Modify the program to produce the following form of Floyd's triangle 1 0 1 1 0 1 0 1 0 1 1 0 1 0 1

## Lab3

> 1. Design and implement Employee Information System(EIS), comprising of a class called Employee which include details such as Employee ID, Name, Designation, Salary. The class also provides functionalities such as displaying employee details, searching an employee based on employee ID, provision for salary increment (10%), etc. The main class of EIS initially collect all employee details and later it provides menu items such as search, salary increment, and display.

> 2. A book shop maintains the inventory of books that are being sold at the shop. The list includes details such as author, title, price, publisher and stock position. Whenever a customer wants a book, the sales person inputs the title and author and the system searches the list and displays whether it is available or not. If it is not, an appropriate message is displayed. If it is, then the system displays the book details and requests for the number of copies required. If the requested copies are available, the total cost of the requested copies is displayed; otherwise the message "required copies not in stock" is displayed. Design a system using a class called books with suitable member functions and constructors

> 3. Develop Stack with following operations i) createNew( ) ii) push( ) iii) pop( ) iv) display( ) v) empty( )

## Lab4

> A class called Book is designed (as shown in the class diagram) to model a book written by one author. It contains:
· Four private instance variables: name (String), author (of the class Author you have just created, assume that a book has one and only one author), price (double), and qty (int);
· Two constructors:
```javascript I'm A tab
public Book (String name, Author author, double price) { ...... }
```
```javascript I'm B tab
public Book (String name, Author author, double price, int qty) { ...... }
```
· public methods getName(), getAuthor(), getPrice(), setPrice(), getQty(), setQty().
· A toString() that returns "Book[name=?,Author[name=?,email=?,gender=?],price=?,qty=?". You should reuse Author’s toString().
Write the Book class (which uses the Author class). Also write a test driver called TestBook to test all the public methods in the class Book. Take Note that you have to construct an instance of Author before you can construct an instance of Book.