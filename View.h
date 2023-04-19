#ifndef VIEW_H
#define VIEW_H

#include "IView.h"
#include "Tienda/Tienda.h"
#include "Tienda/Vendedor.h"
#include <string>

class Presenter;
class Tienda;
class Vendedor;

class View : public IView
{
private:

	Presenter* m_presenter;
	std::map<PrendaType, Prenda*> m_PrendaMenuItems;
	void showMainMenu();
	void runOption(const char* option, bool& exitCondition);
public:
	View();
	~View() override;
	void showMenuCotizar();
	void selectPrenda(const char* option, bool& isValidOption);
	void showHistorialCotizaciones();
	void showText(const char* text) override;
	void showText(const std::string& text) override;
	void showText(const char* text1, const char* text2) override;
	void showText(const char* text1, const char* text2, int text3);
	void showSeparador();
	void setPrendasMenuItems(const std::map<PrendaType, Prenda*>& items) override;
	void Seleccionar_prenda();

};
#endif //VIEW_H
