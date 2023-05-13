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
  int count = 0;
  for(int i = 0; i < height; i++){
    cout << "\n"  << endl;
    for(int j = 0; j < width; j++){
      cout << " " << grid[j][i];      
      count++;
    }
  }
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

int complete(int grid[width][height], int x, int y)
{
  for(int i = 0; i < y; i++){
    for(int j = 0; j < x; j++){
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
  cout << "\n x:" << x << endl;
  cout << "\n y:" << y << endl;
  cout << "\n num:" << num << endl;
  print_board(grid);
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
  if(x > 8 || y > 8){
    return 1;
  }
  // print_board(d, x, y);
  int finished = complete(grid, x, y);
  if(finished == 1){
    return 1;
  }
  if(grid[x][y]==0)
  {
    for(int i = 1; i < 10; i++){
      int result = check(grid, x, y, i);
      if(result == 1){
        grid[x][y] = i;
        cout << "\n \n d[counter] = i \n";
        cout << "\n \n i : " <<  i << endl;
        if(x>7){
          solve(grid, 0, y+1);
        }else{
          solve(grid, x+1, y);
        }
      }else{
          cout << "\n Number already found: " << i << endl;
      }
    }
  }else if(x>7){
          solve(grid, 0, y+1);
  }else{
    solve(grid, x+1, y);
  }
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
      cout << '\n';
      cout << myText;
      cout << '\n';
      // Traverse the string
      for (int i = 0; i < myText.length(); i++) {
          int dig = myText[i] - '0';
          cout<< dig<< ", ";
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



