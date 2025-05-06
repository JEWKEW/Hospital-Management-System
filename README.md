# Hospital-Management-Sysytem

Project Description
 Data Structure Project by 3410, 3446, 3493

File Setup for This project
1.📑 main.c
2.📑 login.h
3.📑 doctor.h
4.📑 patient.h
5.📑 piorqueue.h
6.📑 tree.h
7.📁 Empty folder name "File"
8.💽 C complier (Ex. MinGW)

** Make sure you can complie c files in your device. **

How to run?
    To start the project, Choose the main.c file and press run button.

_Testcases_

If press 1 first in Main Menu
Sample Input:
===  Main Menu  ===
[(1) Doctor       ]
[(2) Patient      ]
[(3) Exit         ]
Enter choice: 1

Expected Output
---  Doctor Menu  ---
~~~~~~~~~~~~~~~~~~~~~
[(1) Login as Doctor]
[(2) Back           ]
Enter choice:  

///////////////////////////////////////////////////

In doctor Menu if press 2
Sample Input
---  Doctor Menu  ---
~~~~~~~~~~~~~~~~~~~~~
[(1) Login as Doctor]
[(2) Back           ]
Enter choice: 2

Expected Output
===  Main Menu  ===
[(1) Doctor       ]
[(2) Patient      ]
[(3) Exit         ]
Enter choice: 

////////////////////////////////////////////////////////////////

But if you press 1 In doctor Menu
Sample Input
---  Doctor Menu  ---
~~~~~~~~~~~~~~~~~~~~~
[(1) Login as Doctor]
[(2) Back           ]
Enter choice: 1

Expected Output
Doctor Username: 

/////////////////////////////////////////////////////////////////////////////////

Write d in username to go to password that doctor need to write next
Sample Input
Doctor Username: d

Expected Output
Doctor Password: 

//////////////////////////////////////////////////////

write 1234 in password to entering doctor account
Sample Input
Doctor Password: 1234

Expected Output
Doctor login successful.
Press Enter to continue: 

//////////////////////////////////////////

And press Entter to continue next
Sample Input
Doctor login successful.
Press Enter to continue: 

Expected Output
Doctor Panel!
Hi, Doctor. What can I do for you?
1. Display all Queue
2. Cure Patient
3. Display Cured Patients
4. Back
Enter choice number: 

//////////////////////////////////////////////////

If you press 1 in Doctor Panel
Sample Input
Doctor Panel!
Hi, Doctor. What can I do for you?
1. Display all Queue
2. Cure Patient
3. Display Cured Patients
4. Back
Enter choice number: 1

Expected Output
Here are all Patients in the queue:
No  NAME                 AGE   SEX        PRIORITY   PHONE           ALLERGIES            CONDITIONS   
1   Bob                  19    Male       40         1234567980      none                 none
2   Atip                 19    Female     0          1234567890      none                 none

Press Enter to continue:

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

Press Enter to continue
Sample Input
Here are all Patients in the queue:
No  NAME                 AGE   SEX        PRIORITY   PHONE           ALLERGIES            CONDITIONS   
1   Bob                  19    Male       40         1234567980      none                 none
2   Atip                 19    Female     0          1234567890      none                 none

Press Enter to continue:

Expected Output
Hi, Doctor. What can I do for you?
1. Display all Queue
2. Cure Patient
3. Display Cured Patients
4. Back
Enter choice number: 

////////////////////////////////////////////////////////////////

Press 2 to go Cure Patient Option
Sample Input
Hi, Doctor. What can I do for you?
1. Display all Queue
2. Cure Patient
3. Display Cured Patients
4. Back
Enter choice number: 2

Expected Output
Cure Patient: Fullname: Bob, Priority: 40
Press Enter to continue: 

////////////////////////////////////////////////////////////////////////////////////////////

Press Enter to Continue
Sample Input
Cure Patient: Fullname: Bob, Priority: 40
Press Enter to continue: 

Output Expected
Hi, Doctor. What can I do for you?
1. Display all Queue
2. Cure Patient
3. Display Cured Patients
4. Back
Enter choice number: 

/////////////////////////////////////////////////////////////////////////////////

Press 3 to do Display Cured Patients Option
Sample Input
Hi, Doctor. What can I do for you?
1. Display all Queue
2. Cure Patient
3. Display Cured Patients
4. Back
Enter choice number: 3

Expected Output
1.All Cured Patient
2.Search
3.Back
Enter choice number: 

////////////////////////////////////

Press 1 to see All Cured Patient
Sample Input
1.All Cured Patient
2.Search
3.Back
Enter choice number: 1

Expected Output
    NAME                 AGE   SEX       
1   Bob                  19    Male      

Press Enter to continue:

//////////////////////////////////////////////

Press Enter to continue
Simple Input
    NAME                 AGE   SEX       
1   Bob                  19    Male      

Press Enter to continue:

Expected Output
1.All Cured Patient
2.Search
3.Back
Enter choice number: 

/////////////////////////////////////////

press 2 to Search for Patient that you have cured
Simple Input
1.All Cured Patient
2.Search
3.Back
Enter choice number: 2

Expected Output
Enter Search Name: 

/////////////////////////////////////////////////////////

Write a name of patient that have been cured example: Bob
Simple Input
Enter Search Name: Bob

Expected Output
Patient Information:
Name: Bob
Age: 19
Sex: Male
Phone number: 1234567980
Allergies: none
Condition: none

Press Enter to continue:

///////////////////////////////////////////////////////////////////

Press Enter to continue
Simple Input
Patient Information:
Name: Bob
Age: 19
Sex: Male
Phone number: 1234567980
Allergies: none
Condition: none

Press Enter to continue:

Expected Output
1.All Cured Patient
2.Search
3.Back
Enter choice number: 

//////////////////////////////////////////////////

Press 3 to go Back
Simple Input
1.All Cured Patient
2.Search
3.Back
Enter choice number: 3

Expected Output
Hi, Doctor. What can I do for you?
1. Display all Queue
2. Cure Patient
3. Display Cured Patients
4. Back
Enter choice number: 

//////////////////////////////////////////////////////////////////////

Press 4 to go back
Simple Input
Hi, Doctor. What can I do for you?
1. Display all Queue
2. Cure Patient
3. Display Cured Patients
4. Back
Enter choice number: 4

Expected Output
  Doctor Menu  ---
~~~~~~~~~~~~~~~~~~~~~
[(1) Login as Doctor]
[(2) Back           ]
Enter choice: 

/////////////////////////////////////////////////////////////////////////////////

Press 2 to go to Patient
Simple Input
===  Main Menu  ===
[(1) Doctor       ]
[(2) Patient      ]
[(3) Exit         ]
Enter choice:  2

Expected Output
-----   Patient Menu   -----
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
[(1) Login as Patient       ]
[(2) Create Patient Account ]
[(3) Back                   ]
Enter choice: 

////////////////////////////////////////////////////////////////////

press 2 to create patient account
Simple Input
-----   Patient Menu   -----
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
[(1) Login as Patient       ]
[(2) Create Patient Account ]
[(3) Back                   ]
Enter choice: 2

Expected Output
Name: 

/////////////////////////////////////////////////

Write your name as a patient example : Ben
Simple Input 
Name: Ben

Expected Output
Password (at least 4 characters): 

////////////////////////////////////////////

write your own password example: 1234
Simple Input
Password (at least 4 characters): 1234

Expected Output
Confirm Password: 

////////////////////////////////////////

Simple Input
Confirm Password: 1234

Expected Output
