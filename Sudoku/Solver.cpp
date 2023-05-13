#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>

using namespace std;





int addition (int a, int b)
{
  int r;
  r=a+b;
  return r;
}

int print_board(vector<int> d, int x, int y)
{
  int count = 0;
  for(int i = 0; i < y; i++){
    cout << "\n"  << endl;
    for(int j = 0; j < x; j++){
      cout << " " << d[count];
      count++;
    }
  }

  return 0;
}

int print_board(vector<int> d, int x, int y, int counter)
{
  int count = 0;
  for(int i = 0; i < y; i++){
    cout << "\n"  << endl;
    for(int j = 0; j < x; j++){
      if(count==counter){
        cout << "|" << d[count];
      }else{
        cout << " " << d[count];
      }
      
      count++;
    }
  }

  return 0;
}

int complete(vector<int> d, int x, int y)
{
  int n = 0;
  while(n < d.size()){
    if(d[n] == 0){
      return -1;
    }
    n++;
  }
  return 1;
}


int check(vector<int> d, int x, int y, int counter, int num)
{
  cout << "\n counter:" << counter << endl;
  cout << "\n num:" << num << endl;
  print_board(d, x, y, counter);
  int row = counter / x;
  int column = counter % x;
  // print_board(d, x, y);
  // check column
  int m = column;
  while(m < d.size()){
    if(d[m]==num){
      // print_board(d, x, y);
      cout << "\n Return_#1 \n";
      return -1;
    }
    m = m+x;
  }
  // check row
  int n = row;
  int begin = row;
  while(n < begin+x){
    if(d[n]==num){
      // print_board(d, x, y);
      cout << "\n Return_#2 \n";
      cout << "\n n:" << n << endl;
      cout << "\n d[n]:" << d[n] << endl;
      cout << "\n num:" << num << endl;
      return -1;
    }
    n++;
  }
  // check box
  int r1 = row/3;
  int c1 = column/3;
  int pos = r1*x + c1;
  cout << "\n r1: " << r1  << endl;
  cout << "\n c1 : " <<  c1 << endl;
  cout << "\n pos : " <<  pos << endl;
  if(d[pos]==num){
    // print_board(d, x, y);
    cout << "\n Return_#3 \n";
    return -1;
  }
  if(d[pos+1]==num){
    // print_board(d, x, y);
    cout << "\n Return_#4 \n";
    return -1;
  }
  if(d[pos+2]==num){
    // print_board(d, x, y);
    cout << "\n Return_#4 \n";
    return -1;
  }
  if(d[pos+x]==num){
    // print_board(d, x, y);
    cout << "\n Return_#5 \n";
    return -1;
  }
  if(d[pos+x+1]==num){
    // print_board(d, x, y);
    cout << "\n Return_#6 \n";
    return -1;
  }
  if(d[pos+x+2]==num){
    // print_board(d, x, y);
    cout << "\n Return_#7 \n";
    return -1;
  }
  if(d[pos+x+x]==num){
    // print_board(d, x, y);
    cout << "\n Return_#8 \n";
    return -1;
  }
  if(d[pos+x+x+1]==num){
    // print_board(d, x, y);
    cout << "\n Return_#9 \n";
    return -1;
  }
  if(d[pos+x+x+2]==num){
    // print_board(d, x, y);
    cout << "\n Return_#10 \n";
    return -1;
  }
  return 1;
}

int solve (vector<int> d, int x, int y, int counter)
{
  if(counter >= d.size()){
    return 1;
  }
  // print_board(d, x, y);
  int finished = complete(d, x, y);
  if(finished == 1){
    return 1;
  }
  if(d[counter]==0)
  {
    for(int i = 1; i < 10; i++){
      int result = check(d, x, y, counter, i);
      if(result == 1){
        d[counter] = i;
        cout << "\n \n d[counter] = i \n";
        cout << "\n \n i : " <<  i << endl;
        solve(d, x, y, counter+1);
        //  print_board(d, x, y);
      }else{
          cout << "\n Number already found: " << i << endl;
      }
    }
  }else if(counter < d.size()){
    solve(d, x, y, counter+1);
  }
  return 1;
}


int main () {
    list<int> mylist;
    int myint;
    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file
    ifstream MyReadFile("Easy.txt");
    int x = 0;
    int y = 0;
    while (getline (MyReadFile, myText)) {
      x = myText.length();
      y++;
    }
    MyReadFile.close();

    ifstream MyReadFile2("Easy.txt");
    int arr[x][y];
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
          arr[i][j] =  dig;
      }
  }
  // Close the file
  MyReadFile2.close();

  solve(d, x, y, 0);
  print_board(d, x, y);


}



