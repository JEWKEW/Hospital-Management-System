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
---  Doctor Menu  ---
~~~~~~~~~~~~~~~~~~~~~
[(1) Login as Doctor]
[(2) Back           ]
Enter choice: 1
Doctor Username: 

/////////////////////////////////////////////////////////////////////////////////

Write d in username to go to password that doctor need to write next
Sample Input
---  Doctor Menu  ---
~~~~~~~~~~~~~~~~~~~~~
[(1) Login as Doctor]
[(2) Back           ]
Enter choice: 1
Doctor Username: d

Expected Output
---  Doctor Menu  ---
~~~~~~~~~~~~~~~~~~~~~
[(1) Login as Doctor]
[(2) Back           ]
Enter choice: 1
Doctor Username: d
Doctor Password: 

//////////////////////////////////////////////////////

write 1234 in password to entering doctor account
Sample Input
---  Doctor Menu  ---
~~~~~~~~~~~~~~~~~~~~~
[(1) Login as Doctor]
[(2) Back           ]
Enter choice: 1
Doctor Username: d
Doctor Password: 1234

Expected Output
---  Doctor Menu  ---
~~~~~~~~~~~~~~~~~~~~~
[(1) Login as Doctor]
[(2) Back           ]
Enter choice: 1
Doctor Username: d
Doctor Password: 1234
Doctor login successful.
Press Enter to continue: 

//////////////////////////////////////////

And press Entter to continue next
Sample Input
---  Doctor Menu  ---
~~~~~~~~~~~~~~~~~~~~~
[(1) Login as Doctor]
[(2) Back           ]
Enter choice: 1
Doctor Username: d
Doctor Password: 1234
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

Press Enter to continue:
