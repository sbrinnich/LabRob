# LabRob
## GEPR 2 Aufgabe 5 - Roboter Labyrinth
<b> by Alexander Dietrich and Selina Brinnich </b>

### Usage

<code>labrob [filename_for_maze] [optional_parameters]</code>

Possible Parameters:
- -h    print help info
- -p    print maze before robots start search
- -t1   send a <b>Left Hand Robot</b> through the maze
- -t2   send a <b>Tremaux Robot</b> through the maze
- -t3   send a <b>Gaston Tarry Robot</b> through the maze
- -t4   send a <b>Fill Deadend Robot</b> through the maze


### Output

The output of each robot is done after all robots have finished their search through the maze.
For each robot following information gets printed: Number of steps needed to get to the exit as well as
the maze including the path the robot took during search. Following characters are used for displaying
the maze:
- <b>' '</b> A free field not visited by the robot
- <b>'#'</b> A wall
- <b>'.'</b> A free field the robot visited at least once
- <b>'X'</b> Mark which is used by Deadend Filler Robots to fill dead ends


### Notes/Hints

<b>Gaston Tarry Robot</b><br />
The Gaston Tarry Robot is not guaranteed to find an exit to the maze!
The algorithm used to implement this robot is not suitable for so called 'braid'-mazes.

<b>Output type</b><br />
We chose to display the paths the robots took during their search in one maze each 
and not all together in only one maze. This is because we wanted the paths to be easier readable
which (in our opinion) would not be possible when only printing one maze.