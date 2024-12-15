# CS-101-PROJECT
<br>
Author : Zeeshan Ali
It is the project I am going to make in C++ language for my first semester.
<br>
i has three tasks which are : 

Task 1: In this task you will simulate a robot wandering around and trying to avoid bumping into anything. This is a typical robot behavior called obstacle avoidance. The robot has 4 distance sensors that point in 4 directions:
CS101 PAGE 2
Each sensor returns a value between 0 and 100. The smaller the value, the closer the robot is to an object. The bigger the value, the further the robot is from an object. In order to avoid obstacles, the robot should always move in the direction of the sensor with the largest value.
Below is part of an obstacle avoiding robot simulation program. Your job is to fill in the missing pieces.
    1. Create a file called avoid_<your_and_second_member_regno>.cpp and type in the code above. You need to type in all the comments :-). Further create your own library named mylib.h and put all the function prototypes there such that you just have to use the library inside this main file and all the definitions should be in some other file which is loaded when required. (CLO3, PLO1) (5 marks)
    2. Complete the function senseDistance(), which should return a random integer between 0 and 100. (CLO3, PLO1) (5 marks)
    3. Complete the function getSensors(), which should assign a distance value to each element in the sensors[] array, by calling senseDistance() to get the distance value for each sensor. (CLO3, PLO1) (15 marks)
CS101 PAGE 3
    4. Complete the function printSensors(), which should print out the value of each sensor, preceded by its label. For example, if sensors[0] = 93, sensors[1] = 80 sensors[2] = 73 and sensors[3] = 28, then the output might look like this: (CLO3, PLO1) (10 marks)
sensors = [north=93][west=80][south=73][east=28]
Make sure that you use the labels array and don’t hardcode any labels when printing out the sensor values (i.e., output “north” by using labels[0]).
    5.Complete the function furthest(), which should return the index of the entry in the sensors array that has the largest value. For example, given the value of sensors[] shown above, the output from furthest() should be 0 because sensors[0] is 93, which is larger than the other elements in the sensors[] array. (CLO3, PLO1) (10 marks)




Task 2: In this task you have to develop the game "Hang the Man". The concept of the game is, the computer will think of any country/city, it will display underscores which will be equivalent to the length of the country/city name the computer has thought of. For example, in case computer thinks China then it will display ----- . The user may enter any character as his option. If the chosen character is not in the name of city/country user loses 1 chance out of 8 possible chances of mistake and one component of human body is displayed per mistake (see the snap below). Otherwise, the chosen character is replaced in the underscore. (CLO2, PLO1) (30 marks)
Constraints:
• Once a character is chosen, it cannot be chosen again.
• The maximum number of mistakes is 11 {i.e., when the body is completed).
• Display the number of chances left for the user.
• Clear the screen and display the latest data on each iteration of user input.
• At the end, show the result, i.e., win/loose with the correct answer that will be the name of the city/country.
Note: You must NOT use any built-in function for string processing.


Task 3: The goal is to build a C++ program that simulates the basic functionality of an expense-sharing app, similar to Splitwise, with the following features. You will implement a console-based program that tracks shared expenses within multiple groups, allowing users to add expenses, view how much each member owes or is owed, and settle up accordingly.
(CLO2, PLO1) (60 marks)
Features to Implement:
    1.User Accounts:
o Each user should have a unique identifier (either an email address or a phone number).
o When creating an account, the user will need to provide a unique email or phone number, a name, and a password (though for simplicity, you can use just the email/phone and name for identification).
o The program should allow users to sign in and maintain their session once logged in.
    2.Create Groups:
o Allow the user to create multiple groups (e.g., "vacation trip", "roommates").
o Each group should have a name and a list of members.
    3. Add Friends to Groups:
o
Implement a simple way to add members to a group by name.
o
Each member in a group can have an associated name.
4.
Add Expenses:
o
Allow users to add expenses for a group. For each expense, the user should specify:
▪
The total amount of the expense.
▪
The person who paid for the expense.
▪
The group members are involved in the expense.
▪
Optionally, the user can specify an unequal split where some members pay more or less.
CS101 PAGE 4
5.
Expense Splitting:
o
If the split is equal, the total amount should be divided equally among all members of the group.
o
If the split is unequal, the program should allow the user to specify how much each member contributes (ensuring the total expense matches the sum of individual contributions).
6.
Settling Up:
o
After all expenses have been entered, display how much each group member owes or is owed.
o
The program should compute the simplest way to settle the debts (i.e., determine who needs to pay whom and how much).
7.
Display Expense Details:
o
Show a summary of each group, including:
▪
The list of members.
▪
The individual contributions for each expense.
▪
The total amount each member owes or is owed.
8.
Permanent Storage:
o
Use file handling (e.g., text files) to store group data and expenses permanently. The data should be saved so that when the program is restarted, previous data is available for review or further action.
o
You can store the following in files:
▪
Groups and members.
▪
Expenses for each group (with details like amounts, contributors, and splits).
▪
Member balances and debts.

