# Calculator Application - CIS 3250 Project
Andrew Barsoum, Chigozie Davis, Maddie Gabriel, Kevin Glover-Netherton, Jovana Kusic, Nicholas Skoretz

This repository contains the refactored and unified Calculator application codebase.  The code has gone through 2 separate refactoring and review sessions, and been continuously tested throughout the process.

The emphasis was largely on code refactoring and applying coding conventions.  As such, only super obvious bugs such as incorrect menu logic was corrected.  The math functions were left as-is - if they were originally programmed incorrectly, they are still incorrect.

As much as possible, menu prompts were changed to be consistent across the application to present a consistent user experience.

The application has several different calculator packages, such as regular, scientific, and accountant, all with differing functionality.  How well each of them works is up to the user.  


**NB:** Due to withdrawal from the course, Marks section was not completed.  It remains in the original state it was given to us in.  Please excuse the mess.

# User Guide

To compile:  Run "make" will generate a binary file named "calculator" in the "bin/" directory.

To run:  Run './bin/calculator' from within the project directory after compiling.

Selecting a calculator package from the main menu will display the associated functionality.  All menu prompts assume integer input, where functionality prompts can be doubles.

# Known bugs/Limitations
- No bug fixing was done on the mathematical functions - if it was originall programmed incorrectly, it wasn't fixed
- Menu prompts were fixed
- Little to no validation is done on user input.  The assumption is that the user is always going to input the correct expected value, and any issues that result from them not doing that are unknown.

# Original code sections as decided by committee

Kevin Glover-Netherton
- 151 - 308 

Mark Ciobotaru
- Factorial.h, Main ( 436 - 512 )

Andrew Barsoum
- Main ( 310 - 434 )

Jovana Kusic
- Conversions.h ( 1 - 145 )

Chigozie Davis
- Powerfunction.h, conversions.h  (147 - 204 )
- Also any documentation

Nicholas Skoretz
- Matrices.h (entire)

Maddie Gabriel
- Main (1 - 147)

