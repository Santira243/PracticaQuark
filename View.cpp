#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "View.h"
#include "Presenter.h"
#include "Tienda/Prenda.h" 
#include "Tienda/Vendedor.h"
#include "Tienda/Prenda_factory.h"
#include <algorithm>
#include <vector>


const std::string ANY_KEY_MESSAGE = "Escribe cualquier tecla para continuar.";
const std::string INVALID_OPTION_MESSAGE = "La opción ingresada es inválida, por favor reintente.";

View::View()
{
	SetConsoleTitleW(L"La Tienda");
	setlocale(LC_ALL, "es_Es");
	m_presenter = new Presenter(this);
	showMainMenu();
}

View::~View()
{
	delete m_presenter;
	std::for_each(m_PrendaMenuItems.begin(), m_PrendaMenuItems.end(), [](const auto& itr) { delete (itr.second); });
	m_PrendaMenuItems.clear();
}

void View::showText(const char* text)
{
	std::cout << text << std::endl;
}


void View::showText(const std::string& text)
{
	std::cout << text << std::endl;
}

void View::showText(const char* text1,const char* text2)
{
	std::cout << text1 << " || " <<  text2 << std::endl;
}

void View::showText(const char* text1, const char* text2, int text3)
{
	std::cout << text1 << "  " << text2 << " || " << text3 << std::endl;
}


void View::showSeparador()
{
	std::cout << "---------------------------------------" << std::endl;
}

void View::showMenuCotizar()
{
	std::string optionString = "";
	bool isValidOption = true;
	do
	{
		std::system("cls");
		showText("Por favor, escoja prenda a cotizar:");
		showText("");

		// mostramos las opciones del menú que permiten seleccionar prenda a cotizar.
		
		// PANTALON O CAMISA
		// EN funcion de respuesta mandar a la siguiente -> showTipoCamisa o showTipoPantalon
		showText("X- Volver atrás...");
		std::cin >> optionString;
		selectPrenda(optionString.c_str(), isValidOption); //validar la opción escogida
		std::cin.get();
	} while (!isValidOption);

	showMainMenu();
}
void View::showHistorialCotizaciones()
{
	std::string optionString = "";
	bool isValidOption = true;
	do
	{
		std::system("cls");
		showText(m_presenter->datos_tienda()->nombre_tienda(), m_presenter->datos_tienda()->direccion_tienda());
		showText("Listando Historial");
		showSeparador();
		showText("");

		// mostramos las opciones del menú que permiten seleccionar prenda a cotizar.

		// PANTALON O CAMISA
		// EN funcion de respuesta mandar a la siguiente -> showTipoCamisa o showTipoPantalon
		showText("X- Volver atrás...");
		std::cin >> optionString;
		selectPrenda(optionString.c_str(), isValidOption); //validar la opción escogida
		std::cin.get();
	} while (!isValidOption);

	showMainMenu();
}

void View::selectPrenda(const char* option, bool& isValidOption)
{
	try
	{
		int optionInt = std::stoi(option);
		
		if (optionInt == 1)
		{
			//Camisa
			isValidOption = true;
			std::cin.get();
		} 
		else if (optionInt == 2)
		{
			//Pantalon
			isValidOption = true;
			std::cin.get();
		}
		else
		{
			isValidOption = false;
		}
		if (!isValidOption)
		{
			std::system("cls");
			showText(INVALID_OPTION_MESSAGE);
			std::cin.get();
		}
	}
	catch (std::invalid_argument)
	{
		auto str_option = std::string(option);
		if (str_option == "x" || str_option == "X")
		{
			isValidOption = true;
			std::system("cls");
			showText("Volveremos al menú principal.");
			std::cin.get();
		}
		else
		{
			std::system("cls");
			showText(INVALID_OPTION_MESSAGE);
			isValidOption = false;
		}
	}

	showText("");
	showText(ANY_KEY_MESSAGE);
}

void View::showMainMenu() 
{
	std::string option;
	bool exitCondition = false;
	

	do
	{
		std::system("cls");
		showText("-== Bienvenido al Cotizador Express ==-");
		showSeparador();
		
		showText(m_presenter->datos_tienda()->nombre_tienda(), m_presenter->datos_tienda()->direccion_tienda());
		showText(m_presenter->datos_tienda()->listar_vendedores(0).devolver_nombre(), m_presenter->datos_tienda()->listar_vendedores(0).listar_datos_vendedor()->apellido, (m_presenter->datos_tienda()->listar_vendedores(0).listar_datos_vendedor()->id_vendedor)); // por alguna razon falla

	    showSeparador();
		
		//showText(std::to_string(datos->listar_prendas().size()));
		//showText(std::to_string(datos->listar_prendas()[0].devolver_stock()));

		showText("¿Qué desea hacer?");
		showText("");
		showText("1- Historial de cotizaciones");
		showText("2- Realizar cotización");
		showText("X- Salir");
		std::cin >> option;
		std::system("cls");
		runOption(option.c_str(), exitCondition);
		showText("");
		showText(ANY_KEY_MESSAGE);
		std::cin.get();
	} while (!exitCondition);
}

void View::runOption(const char* option, bool& exitCondition)
{
	auto str_option = std::string(option);

	if (str_option == "1")
	{
		showHistorialCotizaciones();
		exitCondition = false;
	}
	else if (str_option == "2")
	{
		showMenuCotizar();
		std::cin.get();
		exitCondition = false;
	}
	
	else if (str_option == "x" || str_option == "X")
	{
		std::cout.flush();
		exit(EXIT_SUCCESS);
	}
	else
	{
		showText(INVALID_OPTION_MESSAGE);
		std::cin.get();
		exitCondition = false;
	}
}

void View::Seleccionar_prenda()
{
	std::string optionString = "";
	bool isValidOption = true;
	do
	{
		std::system("cls");
		showText("Por favor, escoja la prenda a cotizar:");
		showText("");
		m_presenter->getListaPrendas();

		for (const auto& item : m_PrendaMenuItems)
		{
			const auto* prenda_a = m_PrendaMenuItems[item.first];
			std::string nombre_prenda = prenda_a->getName();
			auto numberOfItem = 1;
			std::string  str_numberOfItem = std::to_string(numberOfItem);
			std::string menuItem = str_numberOfItem + "- " + nombre_prenda; // construímos el ítem/opción de menú 
			showText(menuItem.c_str());
		}

		showText("X- Volver atrás...");
		std::cin >> optionString;
		selectPrenda(optionString.c_str(), isValidOption);
		std::cin.get();
	}
	 while (!isValidOption);
}

void View::setPrendasMenuItems(const std::map<PrendaType, Prenda*>&items)
{
	if (items.empty())
	{
		showText("Sin prendas por aqui...");
	}
	else
	{
		m_PrendaMenuItems = items;
	}
}