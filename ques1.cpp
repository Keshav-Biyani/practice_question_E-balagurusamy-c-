#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class book
{
  char **title, **author;
  float *price;
  int no_copie, *stock, total_price;

public:
  int size;
  void input_data(const char *aut, const char *tit, float p, int s, int i);
  book();
  void search();
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
  price=new float[size];
  stock=new int[size];
}

void book ::input_data(const char *aut, const char *tit, float p, int s, int i)
{

  {
    int length = strlen(aut);
    // author = new char *[length + 1];//
    author[i] = new char[length + 1];
    strcpy(author[i], aut);
  }
  {
    int length = strlen(tit);
    // title = new char *[length + 1];//
    title[i] = new char[length + 1];
    strcpy(title[i], tit);
  }

  price[i] = p;
  stock[i]= s;
  // cout<<author[i]<<endl;//
  // cout<<title[i]<<endl;//
}
void book ::display()
{
  cout << "Author" << setw(30) << "Title" << setw(30) << "Price" << setw(10) << "Stock" << endl;
  for (int i = 0; i < size; i++)
  {
    cout << author[i] << setw(20) << title[i] << setw(30) << price[i] << setw(10) << stock[i] << endl;
  }
}

void book ::search()
{
    char name[80];
char t[80];


  cout << "\nEnter name of author" << endl;
  cin.ignore();
  cin.getline(name, sizeof(name));
  cout << "Enter title of book" << endl;
  cin.getline(t, sizeof(t));
  int a, b;
  for (int i = 0; i < size; i++)
  {
    a = strcmp(name, author[i]);
    b = strcmp(t, title[i]);
    if (a == 0 && b == 0)
    {
      cout << "Book is available" << endl;
      cout<< "How much do you want to order"<<endl;
      cin>>no_copie;

      if ( stock[i]-no_copie<0)
      {
        cout<<"copies are not available"<<endl;


      }else{
        stock[i]=stock[i]-no_copie;
        total_price=price[i]*no_copie;
        cout<<"Total price will be = "<<total_price<<endl;
      }

    }
  }
}
int main()
{
  book b;
  char name[80];
char t[80];


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
  while (choice != 3)
  {

    cout << "1.for displaying all stoke" << endl;
    cout << "2. for coustomers" << endl;
    cout << "3.Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      b.display();
      break;

    case 2:
    {
      b.search();
    }
    }
  }
}
