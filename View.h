#ifndef VIEW_H
#define VIEW_H

#include "IView.h"
//#include "WeaponFactory.h"
#include <string>

class Presenter;


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
};
#endif //VIEW_H
