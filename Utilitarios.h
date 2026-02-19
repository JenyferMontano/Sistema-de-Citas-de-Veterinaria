#include <windows.h>
#include <iostream>
#include <ctime>
#include <iostream>
using namespace std;
 
class Utilitarios
{
public:
  Utilitarios(){};
  void gotoxy(int x, int y)
  {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
  }
  void limpiarLinea(int colu, int fila, int espacios)
  {
    for (int i = fila; i <= espacios; i++)
    {
      gotoxy(i, fila);
      cout << " ";
    }
    colu++;
  }
  void dibujarRaya(int x, int y, int tam)
  {
    gotoxy(x, y);
    for (int i = 1; i <= tam; i++)
    {
      gotoxy(x + i, y);
      cout << "-";
    }
  }
  string fecha()
  {
    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);

    string cad = std::to_string(now->tm_mday) + '/' +
                 std::to_string(now->tm_mon + 1) + '/' +
                 std::to_string(now->tm_year + 1900);
    return cad;
  }
};

 