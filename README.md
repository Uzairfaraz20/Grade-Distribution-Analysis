# Grade-Distribution-Analysis
## Overview
- This program takes in a .csv file in the form of the UIC College  of  Engineering, collected  
by  UIC’s  Office  of  Institutional  Research (http://oir.uic.edu/).
- This program performs 3 different analysis:
  1. Computes and outputs the grade distribution for the UIC College of Engineering for a specific year.
  Grade distribution is the percentages of A's, B's, C's, D's, and F's across all the classes in the COE. (S and U type scores)
  are ignored
  2. Computes and outputs grade distributions for each department.
  In  the  Fall  of  2017  there  are  11  such  departments:
  BIOE,  CHE,  CME,  CS,  ECE,  ENER,  ENGR,  IE,  IT,  ME,  and  MENG.
  3. Allow the user to search for specifc professors to view the distributons of classes they taught that semester
  
## Input Files
  - The  program  starts  by  inputting  the  filename  for  a  semester  of  course  data,  such  as  **“fall-2017.csv”**.   
  The  input  file  is  a  CSV  file  that  contains a  header  row  followed  by  1  or  more  rows  of  data. Included 
  in the repository is the **"fall-2017.csv"** and
  **"spring-2018.csv"** files for testing.
