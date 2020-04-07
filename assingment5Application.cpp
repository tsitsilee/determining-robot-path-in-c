/* 

assingment5Application.cpp - Application file for a program named assingment5
============================================================================

This program is for Assignment No. 5, Course 04-630 Data Structures and Algorithms for Engineers. 


Pseudocode
----------
Create assingment 5 and copy the waveAppication code to the assingment5Application.cpp 
read and understand the given code before proceeding
include the assingment5.h file to be able to use the signatures and declarationd from there
check to see if it initialises all the variables to be used 
edit dvernon to lsvotwa for andrew id
test to see if its working for reading the input file

inside the for loop for scenarios add functionality by calling the functions from assingment5Implementation.cpp

call the read map functions to read the map from the read input file and pass in the required parameters fp_in,  map,  map_dimension_x, map_dimension_y
get the start and destination coordinates by calling the function  get_start_and_destination_coordinates and passing in 
	map, map_dimension_x, map_dimension_y, &robot_x, &robot_y, &goal_x,&goal_y

initiliaze the graph 
when initilized use t when calling the map_tographfunction and pass &g,  directed, map, map_dimension_x, map_dimension_y

to call the find path function 
 first calculate robot_goal_vert and nt robot_start_vert by calling the function mapping_function and passing robot_x, robot_y, map_dimension_y
 once found call the find_path function and pass &g,  robot_start_vert,  robot_goal_vert, map ,map_dimension_y

 add an if condition that will print that no path is founf when the find_path is false

 finally call the put_start_and_destination_coordinates function and pass map, map_dimension_x, map_dimension_y, robot_x, robot_y, goal_x, goal_y

 after testing comment out the part that requires user interaction with the terminal

 explanations for the functions being called is in the assingment5Implmentation.cpp file








Author
------

Lynet T Svotwa, Carnegie Mellon University Africa
01/02/2020
revision date 16/02/2020
version 3 revision date 28/02/2020

acknowledgements
David Vernon Lab 6, textApplication code, binary tree code 
TA's for guidance
Geoffrey Njongu
Khotso Selialia



testing
---------

Test to see if it will print my andrewID to the output file
test to see if it prints the scenario number to the output file
test to see if it prints the graph to the terminal to be removed though
test to see if it prints the first 2 scenarios as expected 
add in a test case to see if there is no path will it print to the output file that there is no path and in the expected format
test to see of different dimensions would still get results 


my sample input is as follows with 10 test cases
10
4 4
2 0 0 0 
0 1 1 0 
0 0 0 0 
0 0 0 3
10 10
0 0 0 0 0 0 0 0 0 0
0 2 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 1 1 1 1 1 1 0
0 0 0 1 1 1 1 0 0 0
0 0 0 1 1 1 1 0 0 0
0 0 0 0 0 1 1 0 0 0
0 1 1 1 0 0 0 0 0 0
0 1 1 1 0 0 0 0 3 0
0 0 0 0 0 0 0 0 0 0 
5 6
2 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 3
5 6
0 2 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 3 0
0 0 0 0 0 0
5 10
0 0 0 0 0 0 0 0 0 0
0 2 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1 1 0
0 0 0 0 0 0 3 0 1 0
2 30
0 2 0 1 0 0 0 0 1 0 0 0 1 0 0 1 0 0 0 0 0 1 0 0 0 1 0 0 3 0
0 1 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1 0
12 3
2 1 0 
0 0 0 
1 1 0 
0 0 0
0 1 1 
0 0 1 
1 0 0 
0 0 1
1 0 0 
0 0 1 
0 0 0 
0 1 3
5 6
1 1 1 1 1 2
1 0 1 1 1 1
1 1 1 1 1 1
1 1 1 0 1 1
1 1 3 1 1 0
4 4
0 0 0 2 
0 1 1 0 
1 0 0 0 
3 0 0 0
12 4
2 1 0 0
0 0 0 1
1 1 0 1
0 0 0 0
0 1 1 1 
0 0 1 0 
1 0 0 0 
0 0 1 1
1 0 0 1
0 0 1 0
0 0 0 1
0 1 1 3



and my sample output is as follows

lsvotwa
Scenario 1
@       
* # #   
*       
* * * $ 

Scenario 2
                    
  @                 
  *                 
  *   # # # # # #   
  *   # # # #       
  *   # # # #       
  * * * * # #       
  # # # *           
  # # # * * * * $   
                    

Scenario 3
No path exists from (0 0) to (4 5)
@ # # # # # 
# # # # # # 
# # # # # # 
# # # # # # 
# # # # # $ 

Scenario 4
  @         
  *         
  *         
  * * * $   
            

Scenario 5
                    
  @                 
* *                 
* # # # # # # # #   
* * * * * * $   #   

Scenario 6
  @ * # * * *   # * * * #     # * * * *   # * * * # * * $   
  # * * * # * * * * # * * * * * *   # * * * * # * * *   #   

Scenario 7
@ #   
* * * 
# # * 
* * * 
* # # 
* * # 
# *   
  * # 
# *   
  * # 
  * * 
  # $ 

Scenario 8
No path exists from (0 5) to (4 2)
# # # # # @ 
#   # # # # 
# # # # # # 
# # #   # # 
# # $ # #   

Scenario 9
      @ 
  # # * 
#     * 
$ * * * 

Scenario 10
No path exists from (0 0) to (11 3)
@ #     
      # 
# #   # 
        
  # # # 
    #   
#       
    # # 
#     # 
    #   
      # 
  # # $ 



*/
// main program for where the program is first executed

#include "assingment5.h" // to ensure that I make use of the signatures in the header file.
//#include "binaryTree.h"
//#include "graph.h"
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

	bool debug = true;
	FILE *fp_in, *fp_out;
	int i;

	graph g;
	bool directed = false;
	int robot_x, robot_y;
	int goal_x,  goal_y;
	int robot;
	int goal;
	int map_dimension_x, map_dimension_y;
	int scenario; 
	int number_of_scenarios;
	int map[MAX_N][MAX_M];
	int findpath[1000];

	if ((fp_in = fopen("../data/input.txt","r")) == 0) {
		printf("Error can't open input input.txt\n");
		getchar();
		exit(0);
	}

	if ((fp_out = fopen("../data/output.txt","w")) == 0) {
		printf("Error can't open output output.txt\n");
		getchar();
		exit(0);
	}

	if (debug) printf("Wavefront Breadth First Search Path Planning\n");

	fprintf(fp_out, "lsvotwa\n");

	scenario = 0;

	fscanf(fp_in, "%d",&number_of_scenarios);


	for (i=0; i<number_of_scenarios; i++) {

		fprintf(fp_out, "Scenario %d\n",i+1);

		fscanf(fp_in, "%d %d",&map_dimension_x, &map_dimension_y); // read the dimensions of the map

		//read_map(fp_in,   map, map_dimension_x, map_dimension_y);  // read the input file and initialize the map array

		/* get the robot and goal coordinates from the map, indicated by values 2 and 3. respectively. 
		HINT: reset the values to 0, i.e. an unoccupied cell, to allow the graph to be constructed correctly

		get_start_and_destination_coordinates(map, map_dimension_x, map_dimension_y, &robot_x, &robot_y, &goal_x, &goal_y); 
		*/

		read_map(fp_in,  map,  map_dimension_x, map_dimension_y); //calling the read mad function
		get_start_and_destination_coordinates(map, map_dimension_x, map_dimension_y, &robot_x, &robot_y, &goal_x,&goal_y); //function to get the start and goal
		                                                                                                                   //cordinates
		if (debug) {
			printf("Scenario %d\n",i+1);
			printf("Map dimensions: %d %d\n", map_dimension_x, map_dimension_y);
			printf("Robot and goal positions: (%d %d), (%d %d)\n", robot_x, robot_y, goal_x, goal_y);
		}



		initialize_graph(&g, directed);  //initilaizing the graph
		map_tograph(&g,  directed, map, map_dimension_x, map_dimension_y); //calling the function that maps the map to graph
		print_graph(&g);  //printing the graph to temrinal
		//int mapping_function(int i,int j,int map_dimension_y);
		//bool find_path(&g, int start, int end);
		int robot_start_vert = mapping_function(robot_x, robot_y, map_dimension_y); // should return 1
		int robot_goal_vert = mapping_function(goal_x, goal_y, map_dimension_y); // should return 1


		//bool find_path(graph *g, int start, int end,int map[][Max_M],int map_dimension_y)
		find_path(&g,  robot_start_vert,  robot_goal_vert, map ,map_dimension_y); //calling function to find the path for the robot

		if(find_path(&g,  robot_start_vert,  robot_goal_vert, map ,map_dimension_y)==false) // condition to be executed if path not found
		{
			fprintf(fp_out, "No path exists from (%d %d) to (%d %d)\n", robot_x, robot_y, goal_x, goal_y);

		}



		put_start_and_destination_coordinates(map, map_dimension_x, map_dimension_y, robot_x, robot_y, goal_x, goal_y); // update the map with the robot and goal code

		print_map(fp_out,  map, map_dimension_x, map_dimension_y); //printing the map 
	}

	fclose(fp_in);
	fclose(fp_out);

	// keep the terminal open until the user hits return
	/*if (debug) 
	{
		printf("Press <return> to finish"); 
		getchar();
	}*/

}


/* function to read the map            */
/* put this in the implementation file */





