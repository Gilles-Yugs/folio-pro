# title Rock-Paper-Scissors Game Use Case Diagram
actor Player
actor Computer
actor Tester

Player --> (Play Game)
Computer --> (Play Game)
Tester --> (Run Tests)
(Play Game) --> (Choose Move)
(Play Game) --> (Determine Winner)
(Play Game) --> (Display Score)