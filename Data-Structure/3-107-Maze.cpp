#define elif else if



#include<iostream>
#include<vector>



struct state{
    int x=0,y=0,d=0;
};



int main(){
    // input m,n,start,end
    int m,n;
    state start,end;
    std::cin>>m>>n>>start.x>>start.y>>end.x>>end.y;
    std::cin.clear();

    // create maze
    std::vector<std::vector<int>> maze;
    std::vector<int> barrierline(n+2,1);
    maze.push_back(barrierline); // push top barrier
    for(int i=0;i<m;++i){ // input maze, 0:available, 1:barrier, 2:in path
        std::vector<int> line; // create line
        line.push_back(1); // push left barrier
        // input the given maze line
        int tmpint=0;
        for(int j=0;j<n;++j){
            std::cin>>tmpint;
            line.push_back(tmpint);
        }
        line.push_back(1); // push right barrier
        maze.push_back(line); // push this line
    }
    maze.push_back(barrierline); // push bottom barrier

    state current=start; // start from given start, pointing its right by default
    std::vector<state> path; // store the path
    path.push_back(current); // push the start in path
    while((current.x!=end.x)||(current.y!=end.y)){ // if not reaching end
        if(path.empty()){ // if no possible path
            std::cout<<"no"<<std::endl; // output "no"
            return 0; // exit
        }
        // try in the order of 1:right, 2:down, 3:left, 4:up
        if(!maze[current.x][current.y+1]){ // if the right direction is available
            maze[current.x][current.y]=2; // mark this location in maze
            path.back().d=1; // set its direction to right
            ++current.y; // move right
            path.push_back(current); // push the next location in path
        }
        elif(!maze[current.x+1][current.y]){ // if the down direction is available
            maze[current.x][current.y]=2; // mark this location in maze
            path.back().d=2; // set its direction to down
            ++current.x; // move down
            path.push_back(current); // push the next location in path
        }
        elif(!maze[current.x][current.y-1]){ // if the left direction is available
            maze[current.x][current.y]=2; // mark this location in maze
            path.back().d=3; // set its direction to left
            --current.y; // move left
            path.push_back(current); // push the next location in path
        }
        elif(!maze[current.x-1][current.y]){ // if the up direction is available
            maze[current.x][current.y]=2; // mark this location in maze
            path.back().d=4; // set its direction to up
            --current.x; // move up
            path.push_back(current); // push the next location in path
        }
        else{ // If no direction available
            maze[current.x][current.y]=1; // mark this location unavailable
            path.pop_back(); // remove this location from path
            current=path.back(); // go back;
        }
    }

    maze[current.x][current.y]=2; // mark this location in maze for not being marked after while loop end
    path.back().d=1; // direction at the end is right by default

    // output final path
    for(auto i:path){
        std::cout<<'('<<i.x<<','<<i.y<<','<<i.d<<')';
        if(i.x!=current.x||i.y!=current.y){
            std::cout<<',';
        }
    }
    std::cout<<std::endl;

    return 0;
}


/*

8 8
1 1
8 8
0 0 1 0 0 0 1 0
0 0 1 1 0 0 1 0
0 0 0 0 1 1 0 0
0 1 1 1 0 0 0 0
0 0 0 1 1 0 0 0
0 1 0 0 0 1 0 0
0 1 1 1 0 1 1 0
1 1 0 0 0 0 0 0
(1,1,1),(1,2,2),(2,2,2),(3,2,3),(3,1,2),(4,1,2),(5,1,1),(5,2,1),(5,3,2),(6,3,1),(6,4,1),(6,5,2),(7,5,2),(8,5,1),(8,6,1),(8,7,1),(8,8,1)

8 8
8 8
1 1
0 0 1 0 0 0 1 0
0 0 1 1 0 0 1 0
0 0 0 0 1 1 0 0
0 1 1 1 0 0 0 0
0 0 0 1 1 0 0 0
0 1 0 0 0 1 0 0
0 1 1 1 0 1 1 0
1 1 0 0 0 0 0 0
(8,8,3),(8,7,3),(8,6,3),(8,5,4),(7,5,4),(6,5,3),(6,4,3),(6,3,4),(5,3,3),(5,2,3),(5,1,4),(4,1,4),(3,1,1),(3,2,4),(2,2,3),(2,1,4),(1,1,1)

8 8
1 1
8 8
0 0 1 0 0 0 1 0
0 0 1 1 0 0 1 0
0 0 0 0 1 1 0 0
0 1 1 1 0 0 0 0
0 0 0 1 1 0 0 0
0 1 1 0 0 1 0 0
0 1 1 1 0 1 1 0
1 1 0 0 0 0 0 0
no

4 4
1 1
4 4
0 0 0 1
0 0 1 0
0 1 0 0
1 0 0 0
no

8 8
1 1
4 5
0 0 1 0 0 0 1 0
0 0 1 0 0 0 1 0
0 0 0 0 1 1 0 0
0 1 1 1 0 0 0 0
0 0 0 1 0 0 0 0
0 1 0 0 0 1 0 0
0 1 1 1 0 1 1 0
1 0 0 0 0 0 0 0
(1,1,1),(1,2,2),(2,2,2),(3,2,3),(3,1,2),(4,1,2),(5,1,1),(5,2,1),(5,3,2),(6,3,1),(6,4,1),(6,5,2),(7,5,2),(8,5,1),(8,6,1),(8,7,1),(8,8,4),(7,8,4),(6,8,3),(6,7,4),(5,7,1),(5,8,4),(4,8,3),(4,7,3),(4,6,2),(5,6,3),(5,5,4),(4,5,1)

1 1
1 1
1 1
0
(1,1,1)

9 8
1 1
9 8
0 0 1 0 0 0 1 0
0 0 1 0 0 0 1 0
0 0 0 0 1 1 0 1
0 1 1 1 0 0 1 0
0 0 0 1 0 0 0 0
0 1 0 0 0 1 0 1
0 1 1 1 1 0 0 1
1 1 0 0 0 1 0 1
1 1 0 0 0 0 0 0
(1,1,1),(1,2,2),(2,2,2),(3,2,3),(3,1,2),(4,1,2),(5,1,1),(5,2,1),(5,3,2),(6,3,1),(6,4,1),(6,5,4),(5,5,1),(5,6,1),(5,7,2),(6,7,2),(7,7,2),(8,7,2),(9,7,1),(9,8,1)

*/