#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <tuple>

using namespace std;


const int width = 9;
const int height = 9;




int print_board(int grid[width][height])
{
  cout << "\n\n\n\n"  << endl;
  int count = 0;
  for(int i = 0; i < height; i++){
    cout << "\n"  << endl;
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
        cout << "\n Sudoku is not complete \n"  << endl;
        return -1;
      }
    }
  }
  cout << "\n Sudoku is complete  \n"  << endl;
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
  int x0 = (int)(x / 3);
  int y0 = (int)(y / 3);
  for(int l = 0; l <= 3; l++){
    for(int m = 0; m <= 3; m++){
        if(grid[x0+l][y0+m]==num){
            cout << "\n Return_#3 \n";
            return -1;
        }
    }
  }


  return 1;
}

std::tuple<int, int> find_empty_spot(int grid[width][height])
{
    for(int i = 1; i < width; i++){
      for(int j = 1; j < height; j++){
        if(grid[i][j]==0){
          return  {i, j};
        }
      }
    }
    return  {-1, -1};
}

int solve(int grid[width][height])
{
  int finished = complete(grid);
  if(finished == 1){
    print_board(grid);
    cout << "\n\n ------------COMPLETED------------ \n\n";
    exit(0);
  }
  auto [x, y] = find_empty_spot(grid);
  if(x == -1 || y == -1){
    print_board(grid);
    cout << "\n\n ------------COMPLETED------------ \n\n";
    exit(0);
  }
  cout << "\n x : " <<  x << endl;
  cout << "\n y : " <<  y << endl;

  for(int i = 1; i <= 9; i++){
    int result = check(grid, x, y, i);
    if(result == 1){
      grid[x][y] = i;
      cout << "\n grid[x][y] = i; \n";
      cout << "\n i : " <<  i << endl;

      if(solve(grid)){
        return 1;
      }
      grid[x][y] = 0;
    }
  }

  return -1;
}


int main () {
    list<int> mylist;
    int myint;
    // Create a text string, which is used to output the text file
    string myText;
    ifstream MyReadFile2("Grid17.txt");
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

  solve(grid);
  print_board(grid);
  
}



