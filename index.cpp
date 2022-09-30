
#include<iostream>
using namespace std;
// This function describes the program and how it works.
void instructions();
//  This function will return a choice to the main ; 1) draw triangle, 2) draw diamond, and 3) quit
int menu();
// This function calls on appropriate function depending on the choice to draw a shape
void draw_shape(int choice);
// This function draws a triangle of size size using character c
int get_size();
// This function will ask users to select a character that will be used to draw the shape.
char get_char();
// This function draws a triangle of size size using character c.
void draw_triangle(int size, char c);
// This function first calls draw_triangle, then draw_bottom to draw the diamond.
void draw_diamond(int size, char c);
// This function actually draws an upside down triangle of size size-1 as the bottom of the diamond.
void draw_bottom(int size, char c);
// This function draws a right triangle
void draw_righttriangle(int size, char c);
// This function draws a sideways triangle
void draw_sidewaystriangle(int size, char c);

int main()
{
    int choice;

    instructions();
    choice = menu();
    if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
    {
        cout << "You requested to quit, bye.\n";
        return 0;
    }

    draw_shape(choice);

    return 0;
}

void instructions()
{
    // Print out instructions.
    cout << "Choose whether to draw a triangle (1), diamond (2), right triangle (3), or sideways triangle (4)." << endl;
}

int menu()
{
    int choice;
    cout << "Enter shape number: " << endl;
    cin >> choice;
    return choice;
}

void draw_shape(int choice)
{
    int size;
    char c;
    cout << "Enter character: " << endl;
    cin >> c;
    cout << "Enter size: " << endl;
    cin >> size;

    switch (choice)
    {
    case 1:
        draw_triangle(size, c);
        break;
    case 2:
        draw_diamond(size, c);
        break;
    case 3:
        draw_righttriangle(size, c);
        break;
    case 4:
        draw_sidewaystriangle(size, c);
        break;
    default:
        cout << "shape error";
        break;
    }    
}

void draw_triangle(int size, char c)
{
  for (int line=1; line<=size; line++)
    {
      for(int spaces=0; spaces < (size - line); spaces++)
        cout << " ";
      for(int character = 0; character < 2 * line - 1; character++)
        cout << c;
      cout << endl;
    }
  return;
}

void draw_bottom(int size, char c)
{
  for (int line=1; line<=(size-1); line++)
    {
      for(int spaces=0; spaces < line; spaces++)
        cout << " ";
      for(int character = 0; character< (size - line) * 2 - 1; character++)
        cout << c;
      cout << endl;
    }
  return;
}

void draw_diamond(int size, char c)
{
  draw_triangle(size, c);
  draw_bottom(size, c);

  return;
}

void draw_righttriangle(int size, char c)
{
  for(int line = 1; line <= size; line++)
    {
      for(int character = 0; character < line; character++)
        cout << c;
      cout << endl;
    }
  return;
}

void draw_sidewaystriangle(int size, char c)
{
  for(int line = 1; line <= size; line++)
    {
      for(int character = 0; character < line; character++)
        cout << c;
      cout << endl;
    }
  for(int line = 1; line <= (size - 1); line++)
    {
      for(int character = 0; character < (size - line); character++)
        cout << c;
      cout << endl;
    }
  return;
}
