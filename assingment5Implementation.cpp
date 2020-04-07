/* 

assingment5Implementation.cpp - implementation file for a program named assingment5
============================================================================

This program is for Assignment No. 5, Course 04-630 Data Structures and Algorithms for Engineers.  
It contains the functions that I had to develop on my own using the guide of the labs and TAs and recitation

Pseudocode
----------

develop a function to read the map from the input file
the function should accept the following parameters FILE *fp_in,   int map[][MAX_M], int map_dimension_x, int map_dimension_y
inside the function have a for loop where as the map is being read values are saved to the 2D array
read the map from the input file using the sscanf function and save store values to the map

develop the print map function which after reading the map allows it to be printed to the output file
to do this follow the order of assingment 5 where it is specified that
- An empty cell is depicted by a space ' ' character
- An obstacle is depicted by '#' character
- The start position of the robot is depicted by a '@' character
- The destination position of the robot is depicted by a '$' character
- The path cells are depicted by a '*' character
this is to be carried out with if statements for checking conditions before printing

develop a mapping function
the function should have 3 parameters that us x coordinate, y coordinate and the size of array then be
able to return the formula base+ i*map_dimension_y+ j; 
this function is to be used for the mapping to graph function

develop a function that maps the map to graph
should take the parameters graph *g, bool directed,int map[][MAX_M], int map_dimension_x, int map_dimension_y
the function maaping_function for creating vertices for any given coordinates and in doing so allows additions of edges 

develop a function that returns the values of start to 2 and destination to 3
the function should accept the parameters int map[][MAX_M], int map_dimension_x, int map_dimension_y, int robot_x, int robot_y,int goal_x, int goal_y



Author
------

Lynet T Svotwa, Carnegie Mellon University Africa
01/02/2020


testing
---------
to test most of the sunction I put a print function which I then removed after checking if there were working well


*/

#include "assingment5.h"
//#include "graph.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>


//function to be called when prompting users to close termiaal
void prompt_and_exit(int status) {
	printf("Press any key to continue and close terminal\n"); // printing to the screen
	getchar();
	exit(status);
}

void print_message_to_file(FILE *fp, char message[]) 
{ 
	fprintf(fp,"The message is: %s\n", message);
}




// function to get the start and destination cordinates
void get_start_and_destination_coordinates(int map[][MAX_M], int map_dimension_x, int map_dimension_y, int *robot_x,int *robot_y,int *goal_x, int *goal_y)
{
	int i,j;
	for (i=0; i<map_dimension_x; i++) 
	{
		for (j=0; j<map_dimension_y; j++) 
		{
			if(map[i][j]==2) // checking if the map coordinates have the value of 2 which depicts the start if soo
			{
				*robot_x = i;    // the value of i should be assigned to the robot_x
				*robot_y = j;    //and the vlaue of j should be assingmend to robot_y
			}
			else if(map[i][j]==3)   // checking if the map coordinates have the value of 2 which depicts the start if so
			{
				*goal_x = i;    //the value of i is assigned to the goal destination goal_x
				*goal_y = j;    //the value of j is assinged to the goal destination goal_y

			}

		}

	}
}

//function that prints the map to the output file
// to do this parameters such as the map and its dimensions are needed
void print_map(FILE *fp_out,   int map[][MAX_M], int map_dimension_x, int map_dimension_y) 
{

	int l, m;   //declare variables for my loops


	for (l=0; l<map_dimension_x; l++) 
	{
		for (m=0; m<map_dimension_y; m++) 
		{
			// fscanf(fp_out, "%d", &(map[l][m])); // pass a pointer to the array element to be changed, i.e. the address of the element
			//first if condition checks for the value of zero
			if(map[l][m]==0)        
			{
				fprintf(fp_out, "  "); //if the condition is satisfied then a blank space should be printed in the output file
			}
			else if(map[l][m]==1)   //second condition checks for the value of 1
			{
				fprintf(fp_out, "# "); //if the condition is met then it that value in the output file should be printed as a #
			}

			else if(map[l][m]==2)  // second condtion checks for the start position of 2
			{
				fprintf(fp_out, "@ "); //if condition is met the 2 should be representended by the @ character in the output file
			}

			else if(map[l][m]==3)  //third condition checks for the goal position of 3
			{
				fprintf(fp_out, "$ ");  //if condition is met the 3 should the represented by a $ in the output file
			}

			else if(map[l][m]==4)  // fourth condition checks for the path
			{
				fprintf(fp_out, "* "); //if a path is to be found then it should be represented by the *
			}
			printf(" %d", map[l][m]);  //printing map to terminal to check how it works


		}
		fprintf(fp_out, "\n"); // ensuring that the the loop prints the next answer to next line
		printf("\n");
	}
	fprintf(fp_out, "\n");// ensuring that when the first loop is closed then the next test case is printed on next lien
}

//bool mark_path_on_map(graph *g, int robot, int goal,int map[][MAX_M], int map_dimension_x, int map_dimension_y){
//	//mapping_function(vertx[end], goal_y, map_dimension_y);
//
//}


//function to read the map from the input file
void read_map(FILE *fp_in,   int map[][MAX_M], int map_dimension_x, int map_dimension_y) 
{

	int i, j; //initialize variables to be used in the for loops

	for (i=0; i<map_dimension_x; i++) 
	{
		for (j=0; j<map_dimension_y; j++) 
		{
			fscanf(fp_in, "%d", &(map[i][j])); // pass a pointer to the array element to be changed, i.e. the address of the element
		}
	}
}

//function to map the map to graph
//acknowledgements used the formula from the Vernon's storage mapping functions writeup 
int mapping_function(int i,int j,int map_dimension_y){
	int base = 1;
	int map_funct;

	map_funct= base+ i*map_dimension_y+ j; //the formula that maps the map to graph
	return map_funct; //returning the value so that I can use it later

	//(i, j)->(j  ?n + i);
}


//function to map the map to a graph
//following instructions from step 3
//the fucntion usues the above maaping_function for creating vertices for any given coordinates
void map_tograph(graph *g, bool directed,int map[][MAX_M], int map_dimension_x, int map_dimension_y)
{
	g->nvertices = map_dimension_x * map_dimension_y;
	int i, j;
	for( i = 0; i<map_dimension_x; i++)
	{
		for (j=0; j<map_dimension_y; j++) 
		{
			//printf("%d\n", mapping_function(i,j,map_dimension_y));
			if(j < map_dimension_y-1)
			{
				if(map[i][j] != 1 && map[i][j+1] !=1)
					/*as per instructions
					eachvertex will have up to four edges joining the current vertex 
					to the cells that are connected to it.
					This means I need to insert the edges as I did below*/ 
				{
					insert_edge(g,mapping_function(i,j,map_dimension_y), mapping_function(i,j+1,map_dimension_y),directed,1);
				}
				else if (map[i][j] == 1 && map[i][j+1] ==1)
				{
					insert_edge(g,mapping_function(i,j,map_dimension_y), mapping_function(i,j+1,map_dimension_y),directed,1);
				}

			}

		}
	}
	for( j = 0; j<map_dimension_y; j++)
	{

		for (i=0; i<map_dimension_x; i++) 
		{
			if(i < map_dimension_x-1)
			{
				if(map[i][j] != 1 && map[i+1][j] !=1){
					insert_edge(g,mapping_function(i,j,map_dimension_y), mapping_function(i+1,j,map_dimension_y),directed,1);
				}
				else if (map[i][j] == 1 && map[i+1][j] ==1){
					insert_edge(g,mapping_function(i,j,map_dimension_y), mapping_function(i+1,j,map_dimension_y),directed,1);
				}

			}

		}

	}
}

//since I have made the values 0 I needed to return the values 2 and 3 to ensure it prints well to the output file
//to do this I made the fucntion below
void put_start_and_destination_coordinates(int map[][MAX_M], int map_dimension_x, int map_dimension_y, int robot_x, int robot_y,int goal_x, int goal_y)
{
	map[robot_x][robot_y] = 2; //setting back the start to 2
	map[goal_x][goal_y] = 3; //setting back the goal position ot 3
}