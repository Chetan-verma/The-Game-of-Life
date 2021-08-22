#define MAXROW 3  //maximum row range
#define MAXCOL 6 //maximum column range
typedef enum state {DEAD, ALIVE}State;
typedef State Grid[MAXROW +2][MAXCOL +2];

void CopyMap(Grid map, Grid newmap);//It will copy the updated grid, newmap, into map.
Boolean UserSaysYes(void);// It will ask th user whether or not to go onthe next generation.
void Initialize(Grid map);// It will intialize the grid and input the initial configuration.
int NeighborCount(Grid map, int row, int column);//It will count the number of cells neighboring the one in row, col tha are occupied in the rectangular array map.
void Writemap(Grid map);//It will do the output.
void Initialize(Grid map){
    int row, col;//coordnates of a cell.
    printf("The program is a simulation of the game of life.\n"
        "The grid has a size of %d rows and"
        "%d columns.\n", MAXROW, MAXCOL);
    for(row=0; row<=MAXROW+1; row ++){
        for(col=0; col<=MAXCOL+1; col++){
            map[row][col]=DEAD;//Set all cells empty, including the hedge.
        }
    }
    printf("On each line give a pair of coordinates for a living cell.\n"
            "Terminate the list with the special pair 0 0.\n");
    scanf("%d%d", &row, &col);
    while(row!=0||col!=0){//check termination condition.
        if(row>=1 && row<=MAXROW && col>=1 && col<=MAXCOL){
            map[row][col]=ALIVE;
        }
        else{
            printf("values are not within range.\n");
        }
        scanf("%d%d", &row, &col);
    }
    while (getchar()!='\n')//Discard remaining characters.
        ;
    }

void Writemap(Grid map){
    int row; int col;
    putchar('\n');
    putchar('\n');
    for(row=1; row<= MAXROW; row++){
        for(col=1; col<=MAXCOL; col++){
            if(map[row][col]==ALIVE){
                putchar('*');
            }
            else{
                putchar('-');
            }
        putchar('\n');
        }
    }
}
int NeighborCount(Grid map, int row, int col){
    int i;//row of neighbor of the cel (row, col)
    int j;//column of a neighbor of the cell (row, col)
    int count=0;//counter of living neighbors.
    for(i=row-1; i<=row+1; i++){
        for(j=col-1; j<=col+1; j++){
            if (map[i][j]== ALIVE){
            count ++;
                    }
        }
    }
    if(map[row][col]==ALIVE){
            count--;
        }
        return count;
    }
Boolean UserSaysYes(void){
    int c;
    printf("(y,n)?");
    do{
        while((c=getchar())=='\n')
        ;
        if(c=='y'||c=='Y'||c=='n'||c=='N'){
            return(c=='y'||c=='Y');
        }
        printf("Please respond by typing one of the letters y or n\n");
    }while(1);
}
void CopyMap(Grid map, Grid newmap){
int row, col;
for(row=0; row<= MAXROW+1; row ++){
    for(col=0; col<=MAXCOL+1; col++){
        map[row][col]=newmap[row][col];
    }
}
}