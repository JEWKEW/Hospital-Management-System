# Hospital-Management-Sysytem

## Project Description
 Data Structure Project by 3410, 3446, 3493

## File Setup for This project
1. 📑 main.c
2. 📑 login.h
3. 📑 doctor.h
4. 📑 patient.h
5. 📑 piorqueue.h
6. 📑 tree.h
7. 📁 Empty folder name "File"
8. 💽 C complier (Ex. MinGW)

** Make sure you can complie c files in your device. **

## How to run?
To start the project, Choose the main.c file and press run button.

## Testcases

#### If press 1 first in Main Menu
Sample Input:
~~~
----- Main Menu -----
1. Doctor
2. Patient
3. Exit
Enter choice: 1
~~~

Expected Output
~~~
-----  Doctor Menu  -----
Login as Doctor
Back
Enter choice:
~~~

#### In doctor Menu if press 2
Sample Input
~~~
-----  Doctor Menu  -----
Login as Doctor
Back
Enter choice: 2
~~~

Expected Output
~~~
----- Main Menu -----
1. Doctor
2. Patient
3. Exit
Enter choice: 1
~~~

#### But if you press 1 In doctor Menu
Sample Input
~~~
-----  Doctor Menu  -----
Login as Doctor
Back
Enter choice: 1
~~~

Expected Output
~~~
Doctor Username: 
~~~

#### Write d in username to go to password that doctor need to write next
Sample Input
~~~
Doctor Username: d
~~~

Expected Output
~~~
Doctor Password: 
~~~

#### write 1234 in password to entering doctor account
Sample Input
~~~
Doctor Password: 1234
~~~

Expected Output
~~~
Doctor login successful.
Press Enter to continue:
~~~

#### And press Entter to continue next
Sample Input
~~~
Doctor login successful.
Press Enter to continue: 
~~~

Expected Output
~~~
Hi, Doctor. What can I do for you?

----- Doctor System -----
1. Display all Queue
2. Cure Patient
3. Display Cured Patients
4. Back
Enter choice number:
~~~


#### If you press 1 in Doctor Panel
Sample Input
~~~
Hi, Doctor. What can I do for you?

----- Doctor System -----
1. Display all Queue
2. Cure Patient
3. Display Cured Patients
4. Back
Enter choice number: 1
~~~

Expected Output
~~~
Here are all Patients in the queue:
No  NAME                 AGE   SEX        PRIORITY   PHONE           ALLERGIES            CONDITIONS   
1   Bob                  19    Male       40         1234567980      none                 none
2   Atip                 19    Female     0          1234567890      none                 none

Press Enter to continue:
~~~

#### Press Enter to continue
Sample Input
~~~
Here are all Patients in the queue:
No  NAME                 AGE   SEX        PRIORITY   PHONE           ALLERGIES            CONDITIONS   
1   Bob                  19    Male       40         1234567980      none                 none
2   Atip                 19    Female     0          1234567890      none                 none

Press Enter to continue:
~~~

Expected Output
~~~
----- Doctor System -----
1. Display all Queue
2. Cure Patient
3. Display Cured Patients
4. Back
Enter choice number: 
~~~

#### Press 2 to go Cure Patient Option
Sample Input
~~~
----- Doctor System -----
1. Display all Queue
2. Cure Patient
3. Display Cured Patients
4. Back
Enter choice number: 2
~~~

Expected Output
~~~
Cure Patient: Fullname: Bob, Priority: 40
Press Enter to continue: 
~~~

#### Press Enter to Continue
Sample Input
~~~
Cure Patient: Fullname: Bob, Priority: 40
Press Enter to continue: 
~~~

Expected Output
~~~
----- Doctor System -----
1. Display all Queue
2. Cure Patient
3. Display Cured Patients
4. Back
Enter choice number:
~~~
/////////////////////////////////////////////////////////////////////////////////

#### Press 3 to do Display Cured Patients Option
Sample Input
~~~
----- Doctor System -----
1. Display all Queue
2. Cure Patient
3. Display Cured Patients
4. Back
Enter choice number:
~~~

Expected Output
~~~
1.All Cured Patient
2.Search
3.Back
Enter choice number: 
~~~

#### Press 1 to see All Cured Patient
Sample Input
~~~
1.All Cured Patient
2.Search
3.Back
Enter choice number: 1
~~~

Expected Output
~~~
    NAME                 AGE   SEX       
1   Bob                  19    Male      

Press Enter to continue:
~~~

#### Press Enter to continue
Sample Input
~~~
    NAME                 AGE   SEX       
1   Bob                  19    Male      

Press Enter to continue:
~~~

Expected Output
~~~
1.All Cured Patient
2.Search
3.Back
Enter choice number: 
~~~

#### press 2 to Search for Patient that you have cured
Sample Input
~~~
1.All Cured Patient
2.Search
3.Back
Enter choice number: 2
~~~

Expected Output
~~~
Enter Search Name: 
~~~

#### Write a name of patient that have been cured example: Bob
Sample Input
~~~
Enter Search Name: Bob
~~~

Expected Output
~~~
Patient Information:
Name: Bob
Age: 19
Sex: Male
Phone number: 1234567980
Allergies: none
Condition: none

Press Enter to continue:
~~~

#### Press Enter to continue
~~~
Sample Input
Patient Information:
Name: Bob
Age: 19
Sex: Male
Phone number: 1234567980
Allergies: none
Condition: none

Press Enter to continue:
~~~

Expected Output
~~~
1.All Cured Patient
2.Search
3.Back
Enter choice number: 
~~~

#### Press 3 to go Back
Sample Input
~~~
1.All Cured Patient
2.Search
3.Back
Enter choice number: 3
~~~

Expected Output
~~~
----- Doctor System -----
1. Display all Queue
2. Cure Patient
3. Display Cured Patients
4. Back
Enter choice number:
~~~

#### Press 4 to go back
Sample Input
~~~
----- Doctor System -----
1. Display all Queue
2. Cure Patient
3. Display Cured Patients
4. Back
Enter choice number: 4
~~~

Expected Output
~~~
-----  Doctor Menu  -----
1. Login as Doctor
2. Back
Enter choice:
~~~

#### Press 2 to go to Patient
Sample Input
~~~
----- Main Menu -----
1. Doctor
2. Patient
3. Exit
Enter choice: 2
~~~

#### Expected Output
~~~
-----   Patient Menu   -----
1. Login as Patient
2. Create Patient Account
3. Back
Enter choice:
~~~

#### press 2 to create patient account
Sample Input
~~~
-----   Patient Menu   -----
1. Login as Patient
2. Create Patient Account
3. Back
Enter choice:
~~~

Expected Output
~~~
Name: 
~~~

#### Write your name as a patient example : Ben
Sample Input 
~~~
Name: Ben
~~~

Expected Output
~~~
Password (at least 4 characters): 
~~~

#### write your own password example: 1234
Sample Input
~~~
Password (at least 4 characters): 1234
~~~

Expected Output
~~~
Confirm Password: 
~~~

#### Sample Input
~~~
Confirm Password: 1234
~~~

Expected Output
~~~
Patient account created successfully.
Press Enter to continue: 
~~~

#### Press Enter to continue
Sample Input
~~~
Patient account created successfully.
Press Enter to continue: 
~~~

Expected Output
~~~
-----   Patient Menu   -----
1. Login as Patient
2. Create Patient Account
3. Back
Enter choice:
~~~

#### Press 1 to Login as Patient
Sample Input
~~~
-----   Patient Menu   -----
1. Login as Patient
2. Create Patient Account
3. Back
Enter choice: 1
~~~

Expected Output
~~~
Input Name: 
~~~

#### Input name
Sample Input
~~~
Input Name: Ben
~~~

Expected Output
~~~
Input Password: 
~~~

#### Input password
Sample Input
~~~
Input Password: 1234
~~~

Expected Output
~~~
Patient login successful.
Press Enter to continue: 
~~~

#### Press Enter to continue the program
Sample Input
~~~
Patient login successful.
Press Enter to continue: 
~~~

Expected Output
~~~
Jame! You are in Patient Panel.

----- Patient Queue System -----
1. Add Queue
2. Check Queue
3. Cancel Queue
4. Exit
Choose an option:
~~~

#### Press 1 to Add Queue
Sample Input
~~~
Jame! You are in Patient Panel.

----- Patient Queue System -----
1. Add Queue
2. Check Queue
3. Cancel Queue
4. Exit
Choose an option:
~~~

Expected Output
~~~
Enter fullname: 
~~~

#### Input name
Sample Input
~~~
Enter fullname: Ben
~~~

Expected Output
~~~
Enter age:
~~~

#### Input age
Sample Input
~~~
Enter age: 20
~~~

Expected Output
~~~
Enter sex:
~~~

#### Input sex
Sample Input
~~~
Enter sex: Male
~~~

Expected Output
~~~
Enter phone number:
~~~

#### Input sex
Sample Input
~~~
Enter phone number: 1234567890
~~~

Expected Output
~~~
Enter allergies (or 'none'):
~~~

#### Input allergies
Sample Input
~~~
Enter allergies (or 'none'): none
~~~

Expected Output
~~~
Enter underlying conditions (or 'none'): 
~~~

#### Input underlying conditions
Sample Input
~~~
Enter underlying conditions (or 'none'): none
~~~

Expected Output
~~~
Now, please answer a few health questions to assess priority:

How would you rate your pain right now?
1. No symptoms at all
2. Mild
3. Moderate
4. Severe
5. Worst imaginable
Enter choice (1-5):
~~~
//////////////////////////////////////////////////////

#### rating your pain example: 3
Sample Input
~~~
How would you rate your pain right now?
1. No symptoms at all
2. Mild
3. Moderate
4. Severe
5. Worst imaginable
Enter choice (1-5): 3
~~~

Expected Output
~~~
How would you rate your fatigue level?
1. No symptoms at all
2. Mild
3. Moderate
4. Severe
5. Worst imaginable
Enter choice (1-5):
~~~

#### rating your fatigue level example: 2
Sample Input
~~~
How would you rate your fatigue level?
1. No symptoms at all
2. Mild
3. Moderate
4. Severe
5. Worst imaginable
Enter choice (1-5): 2
~~~

Expected Output
~~~
Do you feel chest tightness or difficulty breathing?
1. No symptoms at all
2. Mild
3. Moderate
4. Severe
5. Worst imaginable
Enter choice (1-5):
~~~

#### rating your chest tightness or difficulty breathing example : 4
Sample Input
~~~
Do you feel chest tightness or difficulty breathing?
1. No symptoms at all
2. Mild
3. Moderate
4. Severe
5. Worst imaginable
Enter choice (1-5): 4
~~~

Expected Output
~~~
What is your level of consciousness?
1. No symptoms at all
2. Mild
3. Moderate
4. Severe
5. Worst imaginable
Enter choice (1-5):
~~~


#### rating your level of consciousness example: 1
Sample Input
~~~
What is your level of consciousness?
1. No symptoms at all
2. Mild
3. Moderate
4. Severe
5. Worst imaginable
Enter choice (1-5): 1
~~~

Expected Output
~~~
Status: URGENT
Patient added and saved.
Press Enter to continue:
~~~

#### Press Enter to continue
~~~
Sample Input
Status: URGENT
Patient added and saved.
Press Enter to continue:
~~~

Expected Output
~~~
----- Patient Queue System -----
1. Add Queue
2. Check Queue
3. Cancel Queue
4. Exit
Choose an option: 
~~~

#### Press 2 to check your queue
Sample Input
~~~
----- Patient Queue System -----
1. Add Queue
2. Check Queue
3. Cancel Queue
4. Exit
Choose an option: 2
~~~

Expected Output
~~~
What is your name: 
~~~

#### Example if your name is Ben
Sample Input
~~~
What is your name: Ben
~~~

Expected Output
~~~
Next is your queue
Press Enter to continue: 
~~~

#### Example if your name is Ben
Sample Input
~~~
Next is your queue
Press Enter to continue: 
~~~

Expected Output
~~~
----- Patient Queue System -----
1. Add Queue
2. Check Queue
3. Cancel Queue
4. Exit
Choose an option: 
~~~

#### Press 3 to Cancel Queue
Sample Input
~~~
----- Patient Queue System -----
1. Add Queue
2. Check Queue
3. Cancel Queue
4. Exit
Choose an option: 3
~~~

Expected Output
~~~
Enter name to delete from queue: 
~~~

#### Example if your name is Ben
Sample Input
~~~
Enter name to delete from queue: Ben
~~~

Expected Output
~~~
Patient 'Ben' removed from queue.
Press Enter to continue: 
~~~

#### Press enter to continue
Sample Input
~~~
Patient 'Ben' removed from queue.
Press Enter to continue: 
~~~

Expected Output
~~~
----- Patient Queue System -----
1. Add Queue
2. Check Queue
3. Cancel Queue
4. Exit
Choose an option: 
~~~

#### Press 4 to exit from Patient Queue System
Sample Input
~~~
----- Patient Queue System -----
1. Add Queue
2. Check Queue
3. Cancel Queue
4. Exit
Choose an option: 4
~~~

Expected Output
~~~
-----   Patient Menu   -----
1. Login as Patient
2. Create Patient Account
3. Back
Enter choice:
~~~

#### press 3 to go back
Sample Input
~~~
-----   Patient Menu   -----
1. Login as Patient
2. Create Patient Account
3. Back
Enter choice: 3
~~~

Expected Output
~~~
----- Main Menu -----
1. Doctor
2. Patient
3. Exit
Enter choice: 
~~~

Press 3 to Exit
Sample Input
~~~
----- Main Menu -----
1. Doctor
2. Patient
3. Exit
Enter choice: 3
~~~

Expected Output
~~~
see you again next time
~~~
