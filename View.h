#ifndef VIEW_H
#define VIEW_H

#include "IView.h"
#include  "Tienda/Tienda.h"
#include <string>

class Presenter;
class Tienda;

class View : public IView
{
private:
	
	Presenter* m_presenter;
	void showMainMenu();
	//void runOption(const char* option, bool& exitCondition);
public:
	View();
	~View() override;
	void showMenuCotizar();
	void selectPrenda(const char* option, bool& isValidOption);
	//void showHistorialCotizaciones();
	void showText(const char* text) override;
	void showText(const std::string& text) override;
	void showText(const char* text1, const char* text2);
	void showSeparador();
};
#endif //VIEW_H
