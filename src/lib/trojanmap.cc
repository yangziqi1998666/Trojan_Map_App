#include "trojanmap.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <algorithm>
#include <fstream>
#include <locale>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <sstream>
#include <string>
#include <utility>
#include <cstdlib>
#include<cmath>
#include<ctime>
#include <iostream>
#include<string>
// #include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <cctype>
#include <unordered_set>
#include <stack>
#include <chrono>
#include <ncurses.h>

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"

using namespace std;

//-----------------------------------------------------
// TODO (Students): You do not and should not change the following functions:
//-----------------------------------------------------

/**
 * PrintMenu: Create the menu
 * 
 */
void TrojanMap::PrintMenu() {
    initscr();
    start_color();
    int row,col;
    char str[80];
    char str1[80];
    char str2[80];
    char str3[80];
    char str4[80];
    int y,x;
    init_pair(1, COLOR_RED, COLOR_GREEN); // wrong
    init_pair(2, COLOR_GREEN, COLOR_BLUE); // byebye,hello
    init_pair(3, COLOR_YELLOW, COLOR_BLACK); // normal
    getmaxyx(stdscr,row,col);		/* get the number of rows and columns */


    if (!flag){
        flag = true;
        attron(COLOR_PAIR(2));
        string hello = "Welcome to TrojanMap!";
        mvprintw(row/2-6,(col-strlen(hello.data()))/2,hello.data());
        string tip = "Press any key to Menu";
        mvprintw(row/2,(col-strlen(tip.data()))/2,tip.data());
        string author = "Ziqi Yang";
        mvprintw(LINES-2,(col-strlen(author.data()))/2, author.data());
        string git = "Github:https://github.com/yangziqi1998666/Trojan_Map_App)";
        mvprintw(LINES-1,(col- strlen(git.data()))/2,git.data());
        getch();
        clear();
    }




    attron(COLOR_PAIR(3));


    std::string menu;
    menu ="**************************************************************\n";
    getyx(stdscr,y,x);
    mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
    menu ="* Select the function you want to execute.                    \n";
    getyx(stdscr,y,x);
    mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
    menu ="* 1. Autocomplete                                             \n";
    getyx(stdscr,y,x);
    mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
    menu ="* 2. Find the position                                        \n";
    getyx(stdscr,y,x);
    mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
    menu ="* 3. CalculateShortestPath                                    \n";
    getyx(stdscr,y,x);
    mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
    menu ="* 4. Travelling salesman problem                              \n";
    getyx(stdscr,y,x);
    mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
    menu ="* 5. Cycle Detection                                          \n";
    getyx(stdscr,y,x);
    mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
    menu ="* 6. Topological Sort                                         \n";
    getyx(stdscr,y,x);
    mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
    menu ="* 7. Find K Closest Points                                    \n";
    getyx(stdscr,y,x);
    mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
    menu ="* 8. Exit                                                     \n";
    getyx(stdscr,y,x);
    mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
    menu ="**************************************************************\n";
    getyx(stdscr,y,x);
    mvprintw(y,(col-strlen(menu.data()))/2,menu.data());

    menu = "You enter here:";
    mvprintw(y+4, (col-strlen(menu.data()))/2, menu.data());
    getstr(str);
    //getyx(stdscr,y,x);
    //mvprintw(y, 0, "You Entered: %s", str);

    std::string input;
    char number = str[0];

    switch (number) {
        case '1': {
            clear();
            menu ="**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "* 1. Autocomplete                                             \n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            //std::cout << menu << std::endl;
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "Please input a partial location:";
            //std::cout << menu;
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            //getline(std::cin, input);
            getstr(str);
            auto start = std::chrono::high_resolution_clock::now();
            auto results = Autocomplete(str);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            menu = "*************************Results******************************\n";
            //std::cout << menu;
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            if (results.size() != 0) {
                for (auto item: results) {
                    getyx(stdscr,y,x);
                    mvprintw(y,(col-strlen(item.data()))/2,item.data());
                    printw("\n");
                }
            } else {
                //std::cout << "No matched locations." << std::endl;
                menu = "No matched locations.\n";
                getyx(stdscr,y,x);
                mvprintw(y+1,(col-strlen(menu.data()))/2,menu.data());
                //printw(menu.data());
            }
            menu = "**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());

            menu = "Time taken by function: ";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            printw(to_string(duration.count()).data());
            printw( " microseconds" );
            mvprintw(LINES-1,(col-strlen(menu.data()))/2,"Press any key to continue!\n");
            //std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl << std::endl;
            getch();
            clear();
            PrintMenu();
            break;
        }
        case '2': {
            clear();
            menu ="**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "* 2. Find the position                                       \n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "Please input a location:";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            getstr(str);
            auto start = std::chrono::high_resolution_clock::now();
            auto results = GetPosition(str);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            menu = "*************************Results******************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            if (results.first != -1) {
                getyx(stdscr,y,x);
                mvprintw(y,(col-strlen(menu.data()))/2,"Latitude: %s, Longitude: %s \n",to_string(results.first).data(),to_string(results.second).data());
                PlotPoint(results.first, results.second);
            } else {
                menu = "No matched locations.";
                getyx(stdscr,y,x);
                mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            }
            menu = "**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,"Time taken by function: %s microseconds\n",to_string(duration.count()).data());
            mvprintw(LINES-1,(col-strlen(menu.data()))/2,"Press any key to continue!\n");
            getch();
            clear();
            PrintMenu();

            break;
        }
        case '3': {
            clear();
            menu ="**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "* 3. CalculateShortestPath                                    \n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "Please input the start location:";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            getstr(str1);
            menu = "Please input the destination:";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            getstr(str2);
            menu = "Please wait for calculating!\n";
            getyx(stdscr,y,x);
            mvprintw(y+1,(col-strlen(menu.data()))/2,menu.data());
            refresh();
            auto start = std::chrono::high_resolution_clock::now();
            auto results = CalculateShortestPath_Dijkstra(str1, str2);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            menu = "*************************Results*****************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            if (results.size() != 0) {
                y++;
                int count =0;
                mvprintw(y, (col - strlen(menu.data())) / 2," ");
                for (string item: results){
                    printw(item.data());
                    printw(" -> ");
                    count++;
                    if(count==5){
                        printw("\n");
                        mvprintw(++y,(col-strlen(menu.data()))/2," ");
                        count=0;
                    }
                }
                printw("\n");
                menu = "**************************************************************\n";
                getyx(stdscr,y,x);
                mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
                getyx(stdscr,y,x);
                mvprintw(y,(col-strlen(menu.data()))-15,
                         "The distance of the path is: %s miles\n", to_string(CalculatePathLength(results)).data());
                PlotPath(results);
            } else {
                menu = "No route from the start point to the destination.\n";
                getyx(stdscr,y,x);
                mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            }

            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,"Time taken by function Dijkstra: %s microseconds\n",to_string(duration.count()).data());
            auto start1 = std::chrono::high_resolution_clock::now();
            auto results1 = CalculateShortestPath_Bellman_Ford(str1,str2);
            auto stop1 = std::chrono::high_resolution_clock::now();
            auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);
            menu = "*************************Results of Bellman-Ford****************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            if (results1.size() != 0) {
                //for (auto x: results) std::cout << x << std::endl;
                mvprintw(y,(col-strlen(menu.data())),
                         "The distance of the path is: %s miles\n", to_string(CalculatePathLength(results1)).data());
                mvprintw(y,(col-strlen(menu.data()))/2,"Time taken by function Bellman Ford: %s microseconds\n",to_string(duration1.count()).data());
            }
            menu = "**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());

            mvprintw(LINES-1,(col-strlen(menu.data()))/2,"Press any key to continue!\n");
            getch();
            clear();
            PrintMenu();
            break;
        }
        case '4': {
            clear();
            menu ="**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "* 4. Traveling salesman problem                              \n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "In this task, we will select N random points on the map and you\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = " need to find the path to travel these points and back to the start point.\n";
            printw("\n");
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "Please input the number of the places:";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            getstr(str);
            int num = std::stoi(str);
            std::vector<std::string> keys;
            for (auto x: data) {
                keys.push_back(x.first);
            }
            std::vector<std::string> locations;
            srand(time(NULL));
            for (int i = 0; i < num; i++)
                locations.push_back(keys[rand() % keys.size()]);
            PlotPoints(locations);
            menu = "Calculating ...";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());

            auto start = std::chrono::high_resolution_clock::now();
            auto results = TravellingTrojan(locations);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            CreateAnimation(results.second);
            // 2-opt
            auto start1 = std::chrono::high_resolution_clock::now();
            auto results1 = TravellingTrojan_2opt(locations);
            auto stop1 = std::chrono::high_resolution_clock::now();
            auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);
            // genetic
            //auto start2 = std::chrono::high_resolution_clock::now();
            //auto results2 = TravellingTrojan_genetic(locations);
            //auto stop2 = std::chrono::high_resolution_clock::now();
           //auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);

            menu = "*************************Results Backtrack*************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            if (results.second.size() != 0) {
                y++;
                int count =0;
                mvprintw(y, (col - strlen(menu.data())) / 2," ");
                auto res = results.second[results.second.size() - 1];
                for (auto item: res) {
                    printw(item.data());
                    printw(" -> ");
                    count++;
                    if(count==5){
                        printw("\n");
                        mvprintw(++y,(col-strlen(menu.data()))/2," ");
                        count=0;
                    }
                }
                printw("\n");

                menu = "********************Results 2opt*********************************\n";
                getyx(stdscr,y,x);
                mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
                res = results1.second[results1.second.size() - 1];
                count =0;
                y++;
                mvprintw(y, (col - strlen(menu.data())) / 2," ");
                for (auto item: res){
                    printw(item.data());
                    printw(" -> ");
                    count++;
                    if(count==5){
                        printw("\n");
                        mvprintw(++y,(col-strlen(menu.data()))/2," ");
                        count=0;
                    }
                }
                printw("\n");

//                menu = "********************Results genetic*******************************\n";
//                getyx(stdscr,y,x);
//                mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
//                res = results2.second[results2.second.size() - 1];
//                count =0;
//                y++;
//                mvprintw(y, (col - strlen(menu.data())) / 2," ");
//                for (auto item: res){
//                    printw(item.data());
//                    printw(" -> ");
//                    count++;
//                    if(count==5){
//                        printw("\n");
//                        mvprintw(++y,(col-strlen(menu.data()))/2," ");
//                        count=0;
//                    }
//                }
//                printw("\n");
                menu = "**************************************************************\n";
                getyx(stdscr,y,x);
                mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
                getyx(stdscr,y,x);
                mvprintw(y,(col-strlen(menu.data()))-40,"The distance of the path by Backtracking is:: %s miles\n", to_string(results.first).data());
                getyx(stdscr,y,x);
                mvprintw(y,(col-strlen(menu.data()))-40,"The distance of the path by 2-opt Heuristic is:: %s miles\n", to_string(results1.first).data());
                //getyx(stdscr,y,x);
                //mvprintw(y,(col-strlen(menu.data()))-40,"The distance of the path by genetic is:: %s miles\n", to_string(results2.first).data());

                PlotPath(results.second[results.second.size() - 1]);
            } else {
                menu = "The size of the path is 0";
                getyx(stdscr,y,x);
                mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            }
            menu = "**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,"Time taken by function Backtracking: %s microseconds\n",to_string(duration.count()).data());
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,"Time taken by function 2-opt Heuristic: %s microseconds\n",to_string(duration1.count()).data());
            //getyx(stdscr,y,x);
            //mvprintw(y,(col-strlen(menu.data()))/2,"Time taken by function genetic: %s microseconds\n",to_string(duration2.count()).data());

            mvprintw(LINES-1,(col-strlen(menu.data()))/2+20,"Press any key to continue!\n");
            getch();
            clear();
            PrintMenu();
            break;
        }
        case '5': {
            clear();
            menu ="**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "* 5. Cycle Detection                                         \n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());

            menu = "Please input the left bound longitude(between -118.299 and -118.264):";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            getstr(str);
            std::vector<double> square;
            square.push_back(atof(str));

            menu = "Please input the right bound longitude(between -118.299 and -118.264):";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            getstr(str);
            square.push_back(atof(str));

            menu = "Please input the upper bound latitude(between 34.011 and 34.032):";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            getstr(str);
            square.push_back(atof(str));

            menu = "Please input the lower bound latitude(between 34.011 and 34.032):";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            getstr(str);
            square.push_back(atof(str));

            auto start = std::chrono::high_resolution_clock::now();
            auto results = CycleDetection(square);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            menu = "*************************Results******************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            if (results == true){
                menu = "there exists cycle in the subgraph \n" ;
                getyx(stdscr,y,x);
                mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            }
            else{
                menu = "there exist no cycle in the subgraph \n";
                getyx(stdscr,y,x);
                mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            }
            menu = "**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,"Time taken by function: %s microseconds\n",to_string(duration.count()).data());
            mvprintw(LINES-1,(col-strlen(menu.data()))/2,"Press any key to continue!\n");
            getch();
            clear();
            PrintMenu();
            break;
        }
        case '6': {
            clear();
            menu ="**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "* 6. Topological Sort                                        \n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "Please input the locations filename:";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            string locations_filename;
            getstr(str);
            locations_filename=str;

            menu = "Please input the dependencies filename:";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            string dependencies_filename;
            getstr(str);
            dependencies_filename = str;

            // Read location names from CSV file
            std::vector<std::string> location_names;
            if (locations_filename == ""){
                location_names = {"Cardinal Gardens", "Coffee Bean1", "CVS"};
                location_names = {"USC Parking", "Sunlife Smoothies", "CVS"};
            }
            else
                location_names = ReadLocationsFromCSVFile(locations_filename);

            // Read dependencies from CSV file
            std::vector<std::vector<std::string>> dependencies;
            if (dependencies_filename == ""){
                dependencies = {{"Coffee Bean1", "Cardinal Gardens"},
                                {"CVS",          "Cardinal Gardens"},
                                {"CVS",          "Coffee Bean1"}};
                //dependencies = {{"USC Parking","Sunlife Smoothies"}, {"USC Parking","CVS"}, {"Sunlife Smoothies","CVS"}};
            }
            else
                dependencies = ReadDependenciesFromCSVFile(dependencies_filename);

            auto start = std::chrono::high_resolution_clock::now();
            auto result = DeliveringTrojan(location_names, dependencies);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            menu = "*************************Results******************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "Topological Sorting Results:\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());

            std::vector<std::string> node_ids;
            for (auto item: result) {
                std::string id = GetID(item);
                node_ids.push_back(id);
            }
            PlotPointsOrder(node_ids);
            menu = "**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,"Time taken by function: %s microseconds\n",to_string(duration.count()).data());
            mvprintw(LINES-1,(col-strlen(menu.data()))/2,"Press any key to continue!\n");
            getch();
            clear();
            PrintMenu();
            break;
        }
        case '7': {
            clear();
            menu ="**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "* 7. Find K Closest Points                                   \n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu = "**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());

            menu = "Please input the locations:";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            std::string origin;
            getstr(str);
            origin = str;
            menu = "Please input k:";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            getstr(str);
            int k = std::stoi(str);

            auto start = std::chrono::high_resolution_clock::now();
            auto result = FindKClosestPoints(origin, k);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            menu = "*************************Results******************************";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            menu =  "Find K Closest Points Results:" ;
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            int cnt = 1;
            for (auto item: result) {
                mvprintw(y,(col-strlen(menu.data()))/2,"%d: %s \n",cnt,data[item].name.data());
                cnt++;
            }
            PlotPointsLabel(result, GetID(origin));
            menu = "**************************************************************\n";
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,menu.data());
            getyx(stdscr,y,x);
            mvprintw(y,(col-strlen(menu.data()))/2,"Time taken by function: %s microseconds\n",to_string(duration.count()).data());
            mvprintw(LINES-1,(col-strlen(menu.data()))/2,"Press any key to continue!\n");
            getch();
            clear();
            PrintMenu();
            break;
        }
        case '8':{
            endwin();
            break;
        }
        default: {
            attron(COLOR_PAIR(1));
            clear();
            mvprintw(0,50,"Please enter 1 - 8 !\n");
            sleep(2);
            PrintMenu();
            break;
        }
    }
}


/**
 * CreateGraphFromCSVFile: Read the map data from the csv file
 * 
 */
void TrojanMap::CreateGraphFromCSVFile() {
    std::fstream fin;
    fin.open("src/lib/map.csv", std::ios::in);
    std::string line, word;

    getline(fin, line);
    while (getline(fin, line)) {
        std::stringstream s(line);

        Node n;
        int count = 0;
        while (getline(s, word, ',')) {
            word.erase(std::remove(word.begin(), word.end(), '\''), word.end());
            word.erase(std::remove(word.begin(), word.end(), '"'), word.end());
            word.erase(std::remove(word.begin(), word.end(), '['), word.end());
            word.erase(std::remove(word.begin(), word.end(), ']'), word.end());
            if (count == 0)
                n.id = word;
            else if (count == 1)
                n.lat = stod(word);
            else if (count == 2)
                n.lon = stod(word);
            else if (count == 3)
                n.name = word;
            else {
                word.erase(std::remove(word.begin(), word.end(), ' '), word.end());
                n.neighbors.push_back(word);
            }
            count++;
        }
        data[n.id] = n;
    }
    fin.close();
}

/**
 * PlotPoint: Given a location id, plot the point on the map
 * 
 * @param  {std::string} id : location id
 */
void TrojanMap::PlotPoint(std::string id) {
    std::string image_path = cv::samples::findFile("src/lib/input.jpg");
    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
    auto result = GetPlotLocation(data[id].lat, data[id].lon);
    cv::circle(img, cv::Point(result.first, result.second), DOT_SIZE,
               cv::Scalar(0, 0, 255), cv::FILLED);
    cv::imshow("TrojanMap", img);
    cv::waitKey(1);
}

/**
 * PlotPoint: Given a lat and a lon, plot the point on the map
 * 
 * @param  {double} lat : latitude
 * @param  {double} lon : longitude
 */
void TrojanMap::PlotPoint(double lat, double lon) {
    std::string image_path = cv::samples::findFile("src/lib/input.jpg");
    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
    auto result = GetPlotLocation(lat, lon);
    cv::circle(img, cv::Point(int(result.first), int(result.second)), DOT_SIZE,
               cv::Scalar(0, 0, 255), cv::FILLED);
    cv::startWindowThread();
    cv::imshow("TrojanMap", img);
    cv::waitKey(1);
}

/**
 * PlotPath: Given a vector of location ids draws the path (connects the points)
 * 
 * @param  {std::vector<std::string>} location_ids : path
 */
void TrojanMap::PlotPath(std::vector<std::string> &location_ids) {
    std::string image_path = cv::samples::findFile("src/lib/input.jpg");
    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
    auto start = GetPlotLocation(data[location_ids[0]].lat, data[location_ids[0]].lon);
    cv::circle(img, cv::Point(int(start.first), int(start.second)), DOT_SIZE,
               cv::Scalar(0, 0, 255), cv::FILLED);
    for (auto i = 1; i < location_ids.size(); i++) {
        auto start = GetPlotLocation(data[location_ids[i - 1]].lat, data[location_ids[i - 1]].lon);
        auto end = GetPlotLocation(data[location_ids[i]].lat, data[location_ids[i]].lon);
        cv::circle(img, cv::Point(int(end.first), int(end.second)), DOT_SIZE,
                   cv::Scalar(0, 0, 255), cv::FILLED);
        cv::line(img, cv::Point(int(start.first), int(start.second)),
                 cv::Point(int(end.first), int(end.second)), cv::Scalar(0, 255, 0),
                 LINE_WIDTH);
    }
    cv::startWindowThread();
    cv::imshow("TrojanMap", img);
    cv::waitKey(1);
}

/**
 * PlotPoints: Given a vector of location ids draws the points on the map (no path).
 * 
 * @param  {std::vector<std::string>} location_ids : points
 */
void TrojanMap::PlotPoints(std::vector<std::string> &location_ids) {
    std::string image_path = cv::samples::findFile("src/lib/input.jpg");
    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
    for (auto x: location_ids) {
        auto result = GetPlotLocation(data[x].lat, data[x].lon);
        cv::circle(img, cv::Point(result.first, result.second), DOT_SIZE,
                   cv::Scalar(0, 0, 255), cv::FILLED);
    }
    cv::imshow("TrojanMap", img);
    cv::waitKey(1);
}

/**
 * PlotPoints: Given a vector of location ids draws the points on the map (no path).
 * 
 * @param  {std::vector<std::string>} location_ids : points inside square
 * @param  {std::vector<double>} square : boundary
 */
void TrojanMap::PlotPointsandEdges(std::vector<std::string> &location_ids, std::vector<double> &square) {
    std::string image_path = cv::samples::findFile("src/lib/input.jpg");
    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
    auto upperleft = GetPlotLocation(square[2], square[0]);
    auto lowerright = GetPlotLocation(square[3], square[1]);
    cv::Point pt1(int(upperleft.first), int(upperleft.second));
    cv::Point pt2(int(lowerright.first), int(lowerright.second));
    cv::rectangle(img, pt2, pt1, cv::Scalar(0, 0, 255));
    for (auto x: location_ids) {
        auto result = GetPlotLocation(data[x].lat, data[x].lon);
        cv::circle(img, cv::Point(result.first, result.second), DOT_SIZE,
                   cv::Scalar(0, 0, 255), cv::FILLED);
        for (auto y: data[x].neighbors) {
            auto start = GetPlotLocation(data[x].lat, data[x].lon);
            auto end = GetPlotLocation(data[y].lat, data[y].lon);
            cv::line(img, cv::Point(int(start.first), int(start.second)),
                     cv::Point(int(end.first), int(end.second)), cv::Scalar(0, 255, 0),
                     LINE_WIDTH);
        }
    }
    cv::imshow("TrojanMap", img);
    cv::waitKey(1);
}

/**
 * PlotPointsOrder: Given a vector of location ids draws the points on the map (no path).
 * 
 * @param  {std::vector<std::string>} location_ids : points
 */
void TrojanMap::PlotPointsOrder(std::vector<std::string> &location_ids) {
    std::string image_path = cv::samples::findFile("src/lib/input.jpg");
    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
    for (auto x: location_ids) {
        auto result = GetPlotLocation(data[x].lat, data[x].lon);
        cv::putText(img, data[x].name, cv::Point(result.first, result.second), cv::FONT_HERSHEY_DUPLEX, 1.0,
                    CV_RGB(255, 0, 0), 2);
    }
    // Plot dots and lines
    auto start = GetPlotLocation(data[location_ids[0]].lat, data[location_ids[0]].lon);
    cv::circle(img, cv::Point(int(start.first), int(start.second)), DOT_SIZE,
               cv::Scalar(0, 0, 255), cv::FILLED);
    for (auto i = 1; i < location_ids.size(); i++) {
        auto start = GetPlotLocation(data[location_ids[i - 1]].lat, data[location_ids[i - 1]].lon);
        auto end = GetPlotLocation(data[location_ids[i]].lat, data[location_ids[i]].lon);
        cv::circle(img, cv::Point(int(end.first), int(end.second)), DOT_SIZE,
                   cv::Scalar(0, 0, 255), cv::FILLED);
        cv::arrowedLine(img, cv::Point(int(start.first), int(start.second)),
                        cv::Point(int(end.first), int(end.second)), cv::Scalar(0, 255, 0),
                        LINE_WIDTH);
    }
    cv::imshow("TrojanMap", img);
    cv::waitKey(1);
}

/**
 * PlotPoints: Given a vector of location ids draws the points on the map (no path).
 * 
 * @param  {std::vector<std::string>} location_ids : points
 */
void TrojanMap::PlotPointsLabel(std::vector<std::string> &location_ids, std::string origin) {
    std::string image_path = cv::samples::findFile("src/lib/input.jpg");
    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
    int cnt = 1;
    auto result = GetPlotLocation(data[origin].lat, data[origin].lon);
    cv::circle(img, cv::Point(result.first, result.second), DOT_SIZE,
               cv::Scalar(0, 255, 0), cv::FILLED);
    for (auto x: location_ids) {
        auto result = GetPlotLocation(data[x].lat, data[x].lon);
        cv::circle(img, cv::Point(result.first, result.second), DOT_SIZE,
                   cv::Scalar(0, 0, 255), cv::FILLED);
        cv::putText(img, std::to_string(cnt), cv::Point(result.first, result.second), cv::FONT_HERSHEY_DUPLEX, 1.0,
                    CV_RGB(255, 0, 0), 2);
        cnt++;
    }
    cv::imshow("TrojanMap", img);
    cv::waitKey(1);
}

/**
 * CreateAnimation: Create the videos of the progress to get the path
 * 
 * @param  {std::vector<std::vector<std::string>>} path_progress : the progress to get the path
 */
void TrojanMap::CreateAnimation(std::vector<std::vector<std::string>> path_progress) {
    cv::VideoWriter video("src/lib/001.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 10, cv::Size(1248, 992));
    for (auto location_ids: path_progress) {
        std::string image_path = cv::samples::findFile("src/lib/input.jpg");
        cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
        auto start = GetPlotLocation(data[location_ids[0]].lat, data[location_ids[0]].lon);
        cv::circle(img, cv::Point(int(start.first), int(start.second)), DOT_SIZE,
                   cv::Scalar(0, 0, 255), cv::FILLED);
        for (auto i = 1; i < location_ids.size(); i++) {
            auto start = GetPlotLocation(data[location_ids[i - 1]].lat, data[location_ids[i - 1]].lon);
            auto end = GetPlotLocation(data[location_ids[i]].lat, data[location_ids[i]].lon);
            cv::circle(img, cv::Point(int(end.first), int(end.second)), DOT_SIZE,
                       cv::Scalar(0, 0, 255), cv::FILLED);
            cv::line(img, cv::Point(int(start.first), int(start.second)),
                     cv::Point(int(end.first), int(end.second)), cv::Scalar(0, 255, 0),
                     LINE_WIDTH);
        }
        video.write(img);
        cv::imshow("TrojanMap", img);
        cv::waitKey(1);
    }
    video.release();
}

/**
 * GetPlotLocation: Transform the location to the position on the map
 * 
 * @param  {double} lat         : latitude 
 * @param  {double} lon         : longitude
 * @return {std::pair<double, double>}  : position on the map
 */
std::pair<double, double> TrojanMap::GetPlotLocation(double lat, double lon) {
    std::pair<double, double> bottomLeft(34.01001, -118.30000);
    std::pair<double, double> upperRight(34.03302, -118.26502);
    double h = upperRight.first - bottomLeft.first;
    double w = upperRight.second - bottomLeft.second;
    std::pair<double, double> result((lon - bottomLeft.second) / w * 1248,
                                     (1 - (lat - bottomLeft.first) / h) * 992);
    return result;
}

//-----------------------------------------------------
// TODO: Student should implement the following:
//-----------------------------------------------------
/**
 * GetLat: Get the latitude of a Node given its id.
 * 
 * @param  {std::string} id : location id
 * @return {double}         : latitude
 */
double TrojanMap::GetLat(std::string id) {
    return data.count(id) ? data[id].lat : -1;
}


/**
 * GetLon: Get the longitude of a Node given its id. 
 * 
 * @param  {std::string} id : location id
 * @return {double}         : longitude
 */
double TrojanMap::GetLon(std::string id) {
    return data.count(id) ? data[id].lon : -1;
}

/**
 * GetName: Get the name of a Node given its id.
 * 
 * @param  {std::string} id : location id
 * @return {std::string}    : name
 */
std::string TrojanMap::GetName(std::string id) {
    return data[id].name;
}

/**
 * GetNeighborIDs: Get the neighbor ids of a Node.
 * 
 * @param  {std::string} id            : location id
 * @return {std::vector<std::string>}  : neighbor ids
 */
std::vector<std::string> TrojanMap::GetNeighborIDs(std::string id) {
    return data[id].neighbors;
}

/**
 * CalculateDistance: Get the distance between 2 nodes. 
 * 
 * @param  {std::string} a  : a_id
 * @param  {std::string} b  : b_id
 * @return {double}  : distance in mile
 */
double TrojanMap::CalculateDistance(const std::string &a_id, const std::string &b_id) {
    // Do not change this function
    // TODO: Use Haversine Formula:
    // dlon = lon2 - lon1;
    // dlat = lat2 - lat1;
    // a = (sin(dlat / 2)) ^ 2 + cos(lat1) * cos(lat2) * (sin(dlon / 2)) ^ 2;
    // c = 2 * arcsin(min(1, sqrt(a)));
    // distances = 3961 * c;

    // where 3961 is the approximate radius of the earth at the latitude of
    // Washington, D.C., in miles
    Node a = data[a_id];
    Node b = data[b_id];
    double dlon = (b.lon - a.lon) * M_PI / 180.0;
    double dlat = (b.lat - a.lat) * M_PI / 180.0;
    double p =
            pow(sin(dlat / 2), 2.0) + cos(a.lat * M_PI / 180.0) * cos(b.lat * M_PI / 180.0) * pow(sin(dlon / 2), 2.0);
    double c = 2 * asin(std::min(1.0, sqrt(p)));
    return c * 3961;
}

/**
 * CalculatePathLength: Calculates the total path length for the locations inside the vector.
 * 
 * @param  {std::vector<std::string>} path : path
 * @return {double}                        : path length
 */
double TrojanMap::CalculatePathLength(const std::vector<std::string> &path) {
    // Do not change this function
    double sum = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        sum += CalculateDistance(path[i], path[i + 1]);
    }
    return sum;
}

/**
 * Autocomplete: Given a parital name return all the possible locations with
 * partial name as the prefix.
 *
 * @param  {std::string} name          : partial name
 * @return {std::vector<std::string>}  : a vector of full names
 */
std::vector<std::string> TrojanMap::Autocomplete(std::string name) {
    vector<std::string> results;
    // transform input name into lowercase
    // https://www.cplusplus.com/reference/cctype/tolower/?kw=tolower
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    for (auto it = data.begin(); it != data.end(); ++it) {
        string cur = it->second.name;
        // transform name in data into lower case
        transform(cur.begin(), cur.end(), cur.begin(), ::tolower);
        char *buf1 = new char[name.size()+1];
        char *buf2 = new char[cur.size()+1];
        strcpy(buf1, name.c_str());
        strcpy(buf2, cur.c_str());
        bool flag = true;
        // check if the input name match with the data name
        for(int i=0; i<name.size();i++){
            if(buf1[i]!=buf2[i])
                flag = false;
        }
        // add original name into results
        if(flag){
            results.push_back(it->second.name);
        }
    }
    return results;
}

/**
 * GetPosition: Given a location name, return the position.
 *
 * @param  {std::string} name          : location name
 * @return {std::pair<double,double>}  : (lat, lon)
 */
std::pair<double, double> TrojanMap::GetPosition(std::string name) {
    // acquire id by given name
    std::string id = GetID(name);
    // if id does not exist, the return of lan and lon will be -1
    double lan = GetLat(id);
    double lon = GetLon(id);
    std::pair<double, double> results(lan, lon);
    return results;
}

/**
 * GetID: Given a location name, return the id. 
 * If the node does not exist, return an empty string. 
 *
 * @param  {std::string} name          : location name
 * @return {int}  : id
 */
std::string TrojanMap::GetID(std::string name) {
    std::string res = "";
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (name == it->second.name) {
            res = it->second.id;
        }
    }
    return res;
}

/**
 * CalculateShortestPath_Dijkstra: Given 2 locations, return the shortest path which is a
 * list of id.
 *
 * @param  {std::string} location1_name     : start
 * @param  {std::string} location2_name     : goal
 * @return {std::vector<std::string>}       : path
 */
std::vector<std::string> TrojanMap::CalculateShortestPath_Dijkstra(
        std::string location1_name, std::string location2_name) {
    std::vector<std::string> path;

    std::string location1_id = GetID(location1_name);
    std::string location2_id = GetID(location2_name);

    std::unordered_map<std::string, std::string> records;   // id,id for retrieve
    std::unordered_set<std::string> founds;     // id (location already found path)
    std::unordered_map<std::string, double> dists;  // id, distance to location1

    // init dists
    for (auto item: data) {
        dists[item.first] = item.first == location1_id ? 0 : DBL_MAX;
    }
    //lambda can be used in C++14
    //std::for_each(data.begin(), data.end(), [&](auto item){ dists[item.first] = item.first == location1_id ? 0 : DBL_MAX;});

    while (!founds.count(location2_id)) {
        std::string minId;
        auto minVal = DBL_MAX;

        // Find the min node witch is not in the founds
        for (auto &dist: dists) {
            if (founds.count(dist.first)) continue;
            if (dist.second < minVal) {
                minVal = dist.second;
                minId = dist.first;
            }
        }

        // Update the min value
        std::vector<std::string> neighbors = GetNeighborIDs(minId);
        for (auto &id: neighbors) {
            if (founds.count(id)) continue;
            double dist = minVal + CalculateDistance(minId, id);
            if (dist < dists[id]) {
                dists[id] = dist;
                records[id] = minId;
            }
        }

        founds.insert(minId);
    }

    // Retrieve the path
    std::string p = location2_id;
    while (!p.empty()) {
        path.push_back(p);
        p = records[p];
    }
    std::reverse(path.begin(), path.end());

    return path;
}

/**
 * CalculateShortestPath_Bellman_Ford: Given 2 locations, return the shortest path which is a
 * list of id.
 *
 * @param  {std::string} location1_name     : start
 * @param  {std::string} location2_name     : goal
 * @return {std::vector<std::string>}       : path
 */
std::vector<std::string> TrojanMap::CalculateShortestPath_Bellman_Ford(
        std::string location1_name, std::string location2_name) {
    std::vector<std::string> path;
    std::string location1_id = GetID(location1_name);
    std::string location2_id = GetID(location2_name);

    std::unordered_map<std::string, double> costs;
    std::unordered_map<std::string, std::string> records;

    for (auto item: data) {
        costs[item.first] = DBL_MAX;
    }
    costs[location1_id] = 0;

    for (int i = 0; i < data.size() - 1; i++) {
        for (auto &it: data) {
            std::string id = it.first;
            std::vector<std::string> neighbors = GetNeighborIDs(id);
            double dist = costs[id];
            for (auto &neighbor: neighbors) {
                double newDist = dist + CalculateDistance(id, neighbor);
                if (newDist < costs[neighbor]) {
                    costs[neighbor] = newDist;
                    records[neighbor] = id;
                }
            }
        }
    }
    std::string p = location2_id;
    while (!p.empty()) {
        path.push_back(p);
        p = records[p];
    }
    std::reverse(path.begin(), path.end());
    return path;
}

/**
 * backtracking
 * Travelling salesman problem: Given a list of locations, return the shortest
 * path which visit all the places and back to the start point.
 *
 * @param  {std::vector<std::string>} input : a list of locations needs to visit
 * @return {std::pair<double, std::vector<std::vector<std::string>>} : a pair of total distance and the all the progress to get final path
 */
std::pair<double, std::vector<std::vector<std::string>>> TrojanMap::TravellingTrojan(
        std::vector<std::string> &location_ids) {
    std::pair<double, std::vector<std::vector<std::string>>> results;
    //Refer to: https://www.geeksforgeeks.org/travelling-salesman-problem-implementation-using-backtracking/
    std::vector<std::string> path;//the path of visited places
    double INF = DBL_MAX/2;
    bool *visited = new bool[location_ids.size()];//array of true/false
    //We assume all places are connected, so it's best to calculate their distance directly
    for (size_t i = 0; i < location_ids.size(); i++) {
        visited[i] = false;//Assume i-th location is unvisted by default
    }
    visited[0] = true; //Inital location is visited by default
    path.push_back(location_ids[0]);
    TravellingTrojan_helper(location_ids, results, visited, path, INF, 0);//Recursively call dfs when curr_locations are visited

    delete[] visited; //delete vistied bool value & save the space complexity
    return results;
}

void TrojanMap::TravellingTrojan_helper(std::vector<std::string> &ids, std::pair<double, std::vector<std::vector<std::string>>> &results,
                                        bool visited[], std::vector<std::string> &path, double &min_dist, double dist) {
    //Check if all locations in the input list "ids" has been added to the path
    if (path.size() == ids.size()) {
        double last_dist = CalculateDistance(path[path.size()-1], ids[0]);
        //Calculate the distance between the last location and the penultimate(last but one) location
        dist += last_dist; //Total distance
        path.push_back(ids[0]);//Record location id into the path
        if (dist < min_dist) { //Begin with the dist < INF
            //check if total distance is shorter than minimum distance
            results.first = dist; //Current Maximum distance
            results.second.push_back(path);//Recored current location id
            min_dist = dist; //Update current minimum distance
        } //Check if there any other shorter dist between locations
        path.erase(path.end() - 1); //Exit the last location
        dist -= last_dist; //Also, substract the dist that are added previously
        return;
    }
    for (size_t i = 1; i < ids.size(); i++) { //Traverased all elements of location id list
        if (!visited[i]) { //Check if current location is in the path or not
            double last_dist = CalculateDistance(path[path.size()-1], ids[i]);
            if (dist + last_dist < min_dist) {
                path.push_back(ids[i]);
                dist += last_dist;
                visited[i] = true;
                TravellingTrojan_helper(ids, results, visited, path, min_dist, dist);
                visited[i] = false;
                path.erase(path.end() - 1);
                dist -= last_dist;
            }
        }
    }
}



/**
 * 2-opt Heuristic
 * Travelling salesman problem: Given a list of locations, return the shortest
 * path which visit all the places and back to the start point.
 *
 * @param  {std::vector<std::string>} input : a list of locations needs to visit
 * @return {std::pair<double, std::vector<std::vector<std::string>>} : a pair of total distance and the all the progress to get final path
 */
std::pair<double, std::vector<std::vector<std::string>>>
TrojanMap::TravellingTrojan_2opt(std::vector<std::string> &location_ids) {
    std::pair<double, std::vector<std::vector<std::string>>> results;
    std::vector<std::string> path;

    for (auto id: location_ids) {
        path.push_back(id);
    }
    path.push_back(location_ids[0]);
    results.second.push_back(path);
    results.first = CalculatePathLength(path);
    int noimprovement = 0;
    while (noimprovement < 10000) {
        int a = rand() % (location_ids.size() - 1) + 1;
        int b = rand() % (location_ids.size() - 1) + 1;
        noimprovement++;
        if (a == b) {
            continue;
        }

        std::string temp = path[a];
        path[a] = path[b];
        path[b] = temp;
        double dist = CalculatePathLength(path);
        if (dist < results.first) {
            results.first = dist;
            results.second.push_back(path);
            noimprovement = 0;
        }
    }
    return results;
}

void TrojanMap::TravellingTrojan_2opt_helper(vector<std::string> &path, int start, int end) {
    int n = (int) path.size();
    while (start < end) {
        std::string temp = path[start];
        path[start % n] = path[end % n];
        path[end % n] = temp;
        start++;
        end--;
    }
}

/**
 * Given CSV filename, it read and parse locations data from CSV file,
 * and return locations vector for topological sort problem.
 *
 * @param  {std::string} locations_filename     : locations_filename
 * @return {std::vector<std::string>}           : locations 
 */
std::vector<std::string> TrojanMap::ReadLocationsFromCSVFile(std::string locations_filename) {
    std::vector<std::string> location_names_from_csv;

    std::fstream fin;
    fin.open(locations_filename, std::ios::in);
    std::string line, word;
    getline(fin, line);
    while (getline(fin, line)) {
        std::stringstream s(line);
        getline(s, word, ',');
        location_names_from_csv.push_back(word);
    }

    return location_names_from_csv;
}

/**
 * Given CSV filenames, it read and parse dependencise data from CSV file,
 * and return dependencies vector for topological sort problem.
 *
 * @param  {std::string} dependencies_filename     : dependencies_filename
 * @return {std::vector<std::vector<std::string>>} : dependencies
 */
std::vector<std::vector<std::string>> TrojanMap::ReadDependenciesFromCSVFile(std::string dependencies_filename) {
    std::vector<std::vector<std::string>> dependencies_from_csv;

    std::fstream fin;
    fin.open(dependencies_filename, std::ios::in);
    std::string line, word;
    getline(fin, line);
    while (getline(fin, line)) {
        std::stringstream s(line);
        std::vector<std::string> dependency;
        while (getline(s, word, ',')) {
            dependency.push_back(word);
        }
        dependencies_from_csv.push_back(dependency);
    }

    return dependencies_from_csv;
}

/**
 * DeliveringTrojan: Given a vector of location names, it should return a sorting of nodes
 * that satisfies the given dependencies.
 *
 * @param  {std::vector<std::string>} locations                     : locations
 * @param  {std::vector<std::vector<std::string>>} dependencies     : prerequisites
 * @return {std::vector<std::string>} results                       : results
 */
std::vector<std::string> TrojanMap::DeliveringTrojan(std::vector<std::string> &locations,
                                                     std::vector<std::vector<std::string>> &dependencies) {
    std::vector<std::string> result;

    std::unordered_map<std::string, vector<std::string>> deps;
    std::unordered_map<std::string, int> inDegree;

    for (auto dep: dependencies){
        deps[dep[0]].push_back(dep[1]);
        inDegree[dep[1]]++;
    }
    int count = 0;
    queue<string> q;
    for (int i=0;i<locations.size(); i++){
        if (inDegree[locations[i]]==0)
            q.push(locations[i]);
    }

    while(!q.empty()){
        string v = q.front();
        q.pop();
        result.push_back(v);
        count++;
        for ( auto item : deps[v]){
            inDegree[item]--;
            if(inDegree[item]==0)
                q.push(item);
        }
    }
    //reverse(result.begin(),result.end());
    return result;
}

/**
 * Cycle Detection: Given four points of the square-shape subgraph, return true if there
 * is a cycle path inside the square, false otherwise.
 * 
 * @param {std::vector<double>} square: four vertexes of the square area
 * @return {bool}: whether there is a cycle or not
 */
bool TrojanMap::CycleDetection(std::vector<double> &square) {
    std::vector<std::string> ids, ids_;
    std::vector<std::vector<std::string>> vv;
    for (auto it : data) {
        if (it.second.lon > square[0] && it.second.lon < square[1]
            && it.second.lat > square[3] && it.second.lat < square[2])
            ids.push_back(it.first);
    }
    std::unordered_map<std::string, bool> visited;
    for (auto id : ids) {
        visited[id] = false;
    }
    for (auto id : ids) {
        std::string str;
        if (!visited[id]) {
            ids_.clear();
            ids_.push_back(id);
            if (CycleDetection_helper(id, str, visited, ids_,  vv))
                return true;
            else
                ids_.clear();
        }
    }
    return false;
}

bool TrojanMap::CycleDetection_helper(string &id, string &parent, unordered_map<string, bool> &visited, vector<string> &ids,
                                       vector<vector<string>> &vv) {
    visited[id] = true;
    for (auto id_ : data[id].neighbors) {
        if (!visited[id_]) {
            ids.push_back(id_);
            if (CycleDetection_helper(id_, id, visited, ids,  vv)) return true;
            ids.pop_back();
        } else if (visited[id_] && id_ != parent) {
            ids.push_back(id_);
            vv.push_back(ids);
            CreateAnimation(vv);
            return true;
        }
    }
    return false;
}



/**
 * FindKClosetPoints: Given a location id and k, find the k closest points on the map
 * 
 * @param {std::string} name: the name of the location
 * @param {int} k: number of closest points
 * @return {std::vector<std::string>}: k closest points
 */
std::vector<std::string> TrojanMap::FindKClosestPoints(std::string name, int k) {
    std::vector<std::string> res;
    std::string sourceId = GetID(name);
    // build a map to store the points which have names
    std::vector<Node> nameData;
    for (auto item : data){
        if ( item.first!=sourceId && !item.second.name.empty())
            nameData.push_back(item.second);
    }

    int num = nameData.size();
    // quick sort
    FindKClosestPoints_(nameData, 0, num - 1, k, sourceId);
    std::map<double, std::string> orderedMap;
    for (int i=0;i<k;i++){
        orderedMap[CalculateDistance(sourceId,nameData[i].id)] = nameData[i].id;
    }
    for (auto item: orderedMap){
        res.push_back(item.second);
    }
    return res;
}

void TrojanMap::FindKClosestPoints_(std::vector<Node>& nameData, int left, int right, int k, std::string souceId){
    //int pivot_id = left + rand()%(right-left);
    int pivot_id = left;
    double pivot_dis = CalculateDistance(nameData[pivot_id].id, souceId);
    swap(nameData[right],nameData[pivot_id]);
    int i = left -1;
    for (int j = left; j < right; ++j) {
        double dist = CalculateDistance(nameData[j].id, souceId);
        if (dist <= pivot_dis) {
            ++i;
            swap(nameData[i],nameData[j]);
        }
    }
    ++i;
    swap(nameData[i],nameData[right]);
    // [left,i-1] smaller than pivot_dis, [i+1,right] bigger than pivot_dis
    if (k < i - left + 1)
        FindKClosestPoints_(nameData, left, i-1, k, souceId);
    else if(k > i - left + 1)
        FindKClosestPoints_(nameData, i+1, right, k - (i - left + 1), souceId);
}




/**
 * Genetic Algorithm
 * Travelling salesman problem: Given a list of locations, return the shortest
 * path which visit all the places and back to the start point.
 *
 * @param  {std::vector<std::string>} input : a list of locations needs to visit
 * @return {std::pair<double, std::vector<std::vector<std::string>>} : a pair of total distance and the all the progress to get final path
 */
double dis[10][11];
int generation, die;
double places[2][10];
int groupbest[11];
double groupbestp;
double groupbestfit;
int changebest;

void calculation(int placenum);
void savebest(int placenum);
void change_bestgroup(int placenum);
void select(int placenum);
void crossover(int placenum);
void mutation(int placenum);

struct group {
    int place[11];
    double p;
    double fit;
    double sum_p;

} group[100];


std::pair<double, std::vector<std::vector<std::string>>> TrojanMap::TravellingTrojan_genetic(std::vector<std::string> &location_ids) {
    int j;
    int placenum = location_ids.size();
    init_group(location_ids,placenum);
    die = 1000;
    while (die--) {
        select(placenum);
        crossover(placenum);
        mutation(placenum);
    }

    vector<string> tt;
    for (j =0; j < placenum +1; j++) {
        tt.push_back(location_ids[groupbest[j]]);
    }
    std::vector<std::vector<std::string>> res;
    res.push_back(tt);
    return {CalculatePathLength(tt),res};
}

void TrojanMap::init_group(std::vector<std::string> &location_ids,int placenum)
{
    int i, j, random, flag, k;
    for (int m =0;m<placenum;m++){
        places[0][m] = GetLat(location_ids[m]);
        places[1][m] = GetLon(location_ids[m]);
    }
    memset(groupbest, -1, sizeof(groupbest));
    groupbestp =0.0;
    groupbestfit =0.0;
    changebest =0;
    for (i =0; i < placenum; i++)
        for (j =0; j <= i; j++) {
            if (j == i)
                dis[i][j] =0.0;
            else {
                dis[i][j] = sqrt(pow(places[0][i] - places[0][j],2.0) + pow(places[1][i] - places[1][j],2.0));   //欧氏距离，sqrt平方根
                dis[j][i] = dis[i][j];
            }
        }


    srand((unsigned) time(NULL));

    for (k =0; k <placenum; k++)
    {
        for (i =0; i < placenum; i++) {
            flag =1;
            while (flag) {
                random = rand() % placenum;
                for (j =0; j < i; j++) {
                    if (group[k].place[j] == random) {
                        break;
                    }
                }
                if (j == i) {
                    group[k].place[i] = random;
                    flag =0;
                }
            }
        }
        group[k].place[placenum] = group[k].place[0];

    }

    calculation(placenum);
    savebest(placenum);
}

void calculation(int placenum)
{
    int i, k;
    double ss, s;
    s =0.0;
    ss =0.0;
    for (k =0; k <placenum; k++) {
        for (i =0; i < placenum; i++) {
            s += dis[group[k].place[i]][group[k].place[i +1]];
        }
        group[k].fit =1.0/ s;
        ss += group[k].fit;
        s =0.0;
    }
    s =0.0;
    for (i =0; i <placenum; i++) {
        group[i].p = group[i].fit / ss;
        s += group[i].p;
        group[i].sum_p = s;

    }
}

void savebest(int placenum)
{
    int i, j, flag =0;
    double fit = groupbestfit;
    j =0;
    for (i =0; i <placenum; i++) {
        if (group[i].fit > fit) {
            j = i;
            fit = group[i].fit;
            flag =1;
        }
    }

    if (flag) {
        generation = die;
        for (i =0; i < placenum +1; i++)
        {
            groupbest[i] = group[j].place[i];
        }
        groupbestp = group[j].p;
        changebest =0;
        groupbestfit = group[j].fit;
    } else
        changebest =1;
}

void change_bestgroup(int placenum)
{

    int i, j;
    double fit = group[0].fit;
    j =0;
    if (changebest) {
        for (i =1; i <placenum; i++) {
            if (group[i].fit < fit) {
                fit = group[i].fit;
                j = i;

            }
        }
        for (i =0; i < placenum +1; i++) {
            group[j].place[i] = groupbest[i];
        }
        calculation(placenum);
    }
}

void select(int placenum)
{
    int i, j, temp[placenum][placenum+1], k;
    double t;
    srand((unsigned) time(NULL));
    for (i =0; i <placenum; i++)
    {
        t = rand() %10000*1.0/10000;
        for (j =0; j <placenum; j++) {
            if (t < group[j].sum_p) {
                for (k =0; k < placenum +1; k++)
                    temp[i][k] = group[j].place[k];
                break;
            }
        }
    }

    for (i =0; i <placenum; i++)
        for (j =0; j < placenum +1; j++) {
            group[i].place[j] = temp[i][j];
        }
    calculation(placenum);
    savebest(placenum);
    change_bestgroup(placenum);

}

void crossover(int placenum)
{
    int point1, point2;
    int temp, i, j, k, temp2[2][placenum], temp3[2][placenum], num, write;
    srand((unsigned) time(NULL));
    point1 = rand() %placenum;
    point2 = rand() %placenum;
    if (point1 > point2)
    {
        temp = point1;
        point1 = point2;
        point2 = temp;

    }


    if (point1 != point2) {
        for (j =1; j <placenum; j = j +2) {
            memset(temp3, -1, sizeof(temp3));
            memset(temp2, -1, sizeof(temp2));
            k =0;

            for (i = point1; i <= point2; i++) {
                temp2[0][k] = group[j].place[i];
                temp2[1][k] = group[j -1].place[i];

                temp3[0][temp2[0][k]] =1;
                temp3[1][temp2[1][k]] =1;
                k++;

                group[j].place[i] = -1;
                group[j -1].place[i] = -1;

            }

            num = point2 - point1 +1;


            for (k =0; k < point1; k++) {
                if (temp3[0][group[j -1].place[k]] ==1)
                    group[j -1].place[k] = -1;
                else
                    temp3[0][group[j -1].place[k]] =1;

            }

            for (k = point2 +1; k < placenum; k++) {
                if (temp3[0][group[j -1].place[k]] ==1)
                    group[j -1].place[k] = -1;
                else
                    temp3[0][group[j -1].place[k]] =1;

            }


            for (k =0; k < point1; k++) {
                if (temp3[1][group[j].place[k]] ==1)
                    group[j].place[k] = -1;
                else
                    temp3[1][group[j].place[k]] =1;

            }

            for (k = point2 +1; k < placenum; k++) {
                if (temp3[1][group[j].place[k]] ==1)
                    group[j].place[k] = -1;
                else
                    temp3[1][group[j].place[k]] =1;

            }
            write =0;

            for (i =0; i <placenum; i++) {
                while (write <placenum && group[j -1].place[write] == -1) {
                    write++;
                }
                if (write <placenum) {
                    temp = group[j -1].place[i];
                    group[j -1].place[i] = group[j -1].place[write];
                    group[j -1].place[write] = temp;
                    write++;
                } else {
                    write =0;
                    for (k = i; k <placenum; k++) {
                        group[j -1].place[k] = temp2[0][write++];
                        if (write == num)
                            break;
                    }
                    break;
                }
            }

            write =0;
            for (i =0; i <placenum; i++) {
                while (write <placenum&& group[j].place[write] == -1) {
                    write++;
                }
                if (write <placenum) {
                    temp = group[j].place[i];
                    group[j].place[i] = group[j].place[write];
                    group[j].place[write] = temp;
                    write++;
                } else {
                    write =0;
                    for (k = i; k <placenum; k++) {
                        group[j].place[k] = temp2[1][write++];
                        if (write == num)
                            break;
                    }
                    break;
                }
            }
            k =0;
            for (i =0; i < placenum; i++) {
                if (group[j -1].place[i] == -1) {
                    while (temp3[0][k] ==1 && k <placenum) {
                        k++;
                    }
                    group[j -1].place[i] = k++;

                }
            }
            k =0;
            for (i =0; i < placenum; i++) {
                if (group[j].place[i] == -1) {
                    while (temp3[1][k] ==1&& k <placenum) {
                        k++;
                    }
                    group[j].place[i] = k;
                    k++;

                }
            }
            group[j].place[placenum] = group[j].place[0];
            group[j -1].place[placenum] = group[j -1].place[0];

        }//end of j

        calculation(placenum);
        savebest(placenum);
        change_bestgroup(placenum);

    }//end of if (!)

}

void mutation(int placenum)
{
    int t1, t2, temp, t;
    srand((unsigned) time(NULL));
    t = rand() %placenum;
    if (t >2)
    {
        t1 = rand() %placenum;
        t2 = rand() %placenum;

        temp = group[t1].place[t2];
        group[t1].place[t2] = group[t1].place[placenum-1- t2];
        group[t1].place[placenum-1- t2] = temp;
        group[t1].place[placenum] = group[t1].place[0];
    }
    calculation(placenum);
    savebest(placenum);
    change_bestgroup(placenum);


}
