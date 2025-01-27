# Rock-Paper-Scissors Game  

## Overview  
This project implements a console-based Rock-Paper-Scissors game in C++, where a human player competes against a computer.     
The game also includes test cases to ensure the functionality of different components. 

## Windows configuration  
Build the project  
```  
cd build/  
cmake -G "Unix Makefiles" .  
make  
```  
Fast build rule for target
```
run
```
Build rule for target
```  
rebuild_and_run  
```  
Clean build artifacts 
```  
clean_all  
```  

## Unix/Linux configuration  
Build the project  
```  
cd RPS_GAME/  
make    
```  
Clean up build artifacts
```  
clean  
```  

## How to Play   
- Run the program.  
- Enter the number of victories required to win the game.  
- The computer and the human player alternate making moves. Moves can be:  
	1 for Paper  
	2 for Scissors  
	3 for Stone  
- The game ends when either the human or the computer achieves the required number of victories.  
- The winner is announced at the end.  

## Running Tests  
The GameManager class includes a test() method that invokes various test cases to validate functionality. Modify the main function to call GamePlay.test() to run tests.  
