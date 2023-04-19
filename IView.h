#ifndef IVIEW_H
#define IVIEW_H
#include <map>
#include <string>
#include "Tienda/Prenda_factory.h"

class IView 
{
public:
	virtual ~IView() = default;
	virtual void showText(const char* text) = 0;
	virtual void showText(const std::string& text) = 0;
	virtual void showText(const char* text1, const char* text2) =0;
	virtual void setPrendasMenuItems(const std::map<PrendaType, Prenda*>& items) = 0;

};
#endif // IVIEW_H
