#include <stdlib.h>
#include <stdio.h>
#define SIZE 10

typedef struct {
    int x; 
    int y;
} Point;

Point pt(int x,int y){
    Point p={x,y};
    return p;
}

int visit(int maze[][SIZE],Point start,Point end){
    if(!maze[start.x][start.y]){
         maze[start.x][start.y]=0;
         if(!maze[end.x][end.y] && 
            !(visit(maze,pt(start.x ,start.y+1),end)|| 
              visit(maze,pt(start.x+1, start.y),end)||
              visit(maze,pt(start.x, start.y-1),end)|| 
              visit(maze,pt(start.x-1, start.y),end)))
              {maze[start.x][start.y]=0;}
    }
    return maze[start.x][start.y];
}

void print(int maze[][SIZE]){
    for(int i =0;i<SIZE;i++){ 
        for(int j=0;j<SIZE;j++) switch(maze[i][j]){
            case 0 : printf("x"); break;
            case 1 : printf("█"); break;
        }
        printf("\n"); 
    }     
}
int main(void){ 
    int maze[SIZE][SIZE]={
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 0, 0, 1, 1, 0, 1, 1, 0, 1 },
        { 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 0, 0, 1, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
        { 1, 0, 1, 1, 1, 1, 1, 0, 0, 1 },
        { 1, 0, 0, 0, 1, 0, 0, 0, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
    }; 

    Point start=pt(1,1);
    Point end=pt(8,8);

    print(maze);

    return 0; 
}




