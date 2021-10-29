#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class book
{
  char **title, **author;
  float price;
  int no_copie, stock, total_price;

public:
int size;
  void input_data(const char *aut, const char *tit, float p, int s, int i);
  book();
  void search(const char *aut, const char *tit);
  void copies(void);
  void tot(void);
  void display(void);
};
book::book()
{
  cout << "Enter how much book you want to add" << endl;
  cin >> size;
  int length = 0;
  author = new char *[size];
  title = new char *[size];
  
}

void book ::input_data(const char *aut, const char *tit, float p, int s, int i)
{

  {
    int length = strlen(aut);
    // author = new char *[length + 1];
    author[i] = new char[length + 1];
    strcpy(author[i], aut);
  }
  {
    int length = strlen(tit);
    // title = new char *[length + 1];
    title[i] = new char[length + 1];
    strcpy(title[i], tit);
  }

  price = p;
  stock = s;
  // cout<<author[i]<<endl;
  // cout<<title[i]<<endl;
}
void book ::display()
{
  cout << "Author" << setw(30) << "Title" << setw(30) << "Price" << setw(10) << "Stock" << endl;
  for (int i = 0; i < size; i++)
  {
    cout << author[i] << setw(20) << title[i] << setw(30) << "Price" << setw(10) << "Stock" << endl;
  }
}

// void book ::search(const char *aut, const char *tit)
// {
// }
int main()
{
  book b;
  char *name;
  name = new char[80];
  char *t;
  t = new char[80];
  int s;
  float p;
  for (int i = 0; i < b.size; i++)
  {
    cout << "\nEnter name of author" << endl;
    cin.ignore();
    cin.getline(name, sizeof(name));
    cout << "Enter title of book" << endl;
    cin.getline(t, sizeof(t));
    cout << "Enter price" << endl;
    cin >> p;
    cout << "Enter stock" << endl;
    cin >> s;
    b.input_data(name, t, p, s, i);
  }
  int choice;
    while ( choice != 4)
    {
      

        
    cout << "1.for displaying all stoke" << endl;
    cout << "2. for adding new books in stook" << endl;
    cout << "3.Display account details" << endl;
    cout << "4.Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;


        switch (choice)
        {
        case 1:
         b.display();
         break;
         case 2:
}

    }}