#include "move_rect.h"

move_rect::move_rect() : rect()
{}
move_rect::move_rect(COORD LeBo, COORD RiTo, color Color) : rect(LeBo, RiTo, Color)
{}
void move_rect::increase(color Color)
{
	HWND hWnd = GetForegroundWindow();
	RECT cr;
	GetClientRect(hWnd, &cr);						// получение размеров рабочей области окна стандартного вывода
	COORD clirect = { static_cast<short>(cr.right), static_cast<short>(cr.bottom) }; // размеры окна в COORD
	COORD lebo, rito;
	get_rect(&lebo, &rito); // Если аргументы передаются по указателю, то зачем нужна функция set_rect(), если можно менять значения через указатель?
	set_rect( lebo.X - cr.right / 20, lebo.Y + cr.bottom / 20, // задаем левую нижнюю координату
			  rito.X + cr.right / 20, rito.Y - cr.bottom / 20, // задаем правую верхнюю координату
			  Color.red, Color.green, Color.blue );					 // задаем цвет
	draw_rect();
}
void move_rect::decrease(color Color)
{
	HWND hWnd = GetForegroundWindow();
	RECT cr;
	GetClientRect(hWnd, &cr); //poluchenie razmerov rabochey oblasti okna standartnogo vyvoda
	COORD clirect = { static_cast<short>(cr.right), static_cast<short>(cr.bottom) };
	COORD lebo, rito;
	get_rect(&lebo, &rito);
	set_rect(lebo.X + cr.right / 20, lebo.Y - cr.bottom / 20, // задаем левую нижнюю координату
			 rito.X - cr.right / 20, rito.Y + cr.bottom / 20, // задаем правую верхнюю координату
		     Color.red, Color.green, Color.blue);					// задаем цвет
	draw_rect();
}