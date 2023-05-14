#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>

using namespace std;


const int width = 9;
const int height = 9;




int print_board(int grid[width][height])
{
  cout << "\n\n\n\n"  << endl;
  int count = 0;
  for(int i = 0; i < height; i++){
    cout << "\n\n"  << endl;
    for(int j = 0; j < width; j++){
      cout << " " << grid[j][i];      
      count++;
    }
  }
  cout << "\n\n\n\n"  << endl;
  return 1;
}

int print_board_with_position(int grid[width][height], int x, int y)
{
  int count = 0;
  for(int i = 0; i < y; i++){
    cout << "\n"  << endl;
    for(int j = 0; j < x; j++){
      if(x==j && y==i){
        cout << "|" << grid[i][j];
      }else{
        cout << " " << grid[i][j];
      }
      
      count++;
    }
  }
  return 1;
}

int complete(int grid[width][height])
{
  for(int i = 0; i < width; i++){
    for(int j = 0; j < height; j++){
      if(grid[i][j]==0){
        cout << "\n Sudoku is not complete"  << endl;
        return -1;
      }
    }
  }
  cout << "\n Sudoku is complete"  << endl;
  print_board(grid);
  return 1;
}


int check(int grid[width][height], int x, int y, int num)
{
  // check column
  for(int m=0; m<width; m++){
    if(grid[m][y]==num){
      cout << "\n Return_#1 \n";
      return -1;
    }
  }
  // check row
  for(int n=0; n<height; n++){
    if(grid[x][n]==num){
      cout << "\n Return_#2 \n";
      return -1;
    }
  }
  // check box
  int x0 = x / 3;
  int y0 = y / 3;
  if(grid[x0+1][y0]==num){
      cout << "\n Return_#3 \n";
      return -1;
  }
  if(grid[x0+2][y0]==num){
      cout << "\n Return_#4 \n";
      return -1;
  }
  if(grid[x0+3][y0]==num){
      cout << "\n Return_#5 \n";
      return -1;
  }
  if(grid[x0][y0+1]==num){
      cout << "\n Return_#6 \n";
      return -1;
  }
  if(grid[x0][y0+2]==num){
      cout << "\n Return_#7 \n";
      return -1;
  }
  if(grid[x0][y0+3]==num){
      cout << "\n Return_#8 \n";
      return -1;
  }
  return 1;
}

int solve (int grid[width][height], int x, int y)
{
  cout << "\n x: \n" << x << endl;
  cout << "\n y: \n" << y << endl;
  if(x >= width)
    return -1;
  if(y >= height)
    return -1;
  int finished = complete(grid);
  if(finished == 1){
    print_board(grid);
    cout << "\n\n COMPLETED \n\n";
    exit(0);
  }
  if(grid[x][y]==0)
  {
    for(int i = 1; i < 10; i++){
      int result = check(grid, x, y, i);
      if(result == 1){
        grid[x][y] = i;
        cout << "\n d[counter] = i \n";
        cout << "\n i : " <<  i << endl;
        solve(grid, x, y+1);
        solve(grid, x+1, y);
      }
    }
  }
  solve(grid, x, y+1);
  solve(grid, x+1, y);
  return 1;
}


int main () {
    list<int> mylist;
    int myint;
    // Create a text string, which is used to output the text file
    string myText;

    int x = 0;
    int y = 0;

    ifstream MyReadFile2("Easy.txt");
    int grid[width][height];
    vector<int> d;
    // Use a while loop together with the getline() function to read the file line by line
    int j = 0;
    while (getline (MyReadFile2, myText)) {
      j++;
      // Output the text from the file
      // Traverse the string
      for (int i = 0; i < myText.length(); i++) {
          int dig = myText[i] - '0';
          d.push_back(dig);
          mylist.push_back(dig);
          grid[i][j] =  dig;
      }
  }
  // Close the file
  MyReadFile2.close();

  solve(grid, x, y);
  print_board(grid);
  
}



