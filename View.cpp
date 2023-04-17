#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "View.h"
#include "Presenter.h"
#include "Tienda/Prenda.h" 
#include <algorithm>
#include <vector>

const std::string ANY_KEY_MESSAGE = "Escribe cualquier tecla para continuar.";
const std::string INVALID_OPTION_MESSAGE = "La opci�n ingresada es inv�lida, por favor reintente.";

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
}

void View::showText(const char* text)
{
	std::cout << text << std::endl;
}


void View::showText(const std::string& text)
{
	std::cout << text << std::endl;
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

		// mostramos las opciones del men� que permiten seleccionar prenda a cotizar.
		
		// PANTALON O CAMISA
		// EN funcion de respuesta mandar a la siguiente -> showTipoCamisa o showTipoPantalon
		showText("X- Volver atr�s...");
		std::cin >> optionString;
		selectPrenda(optionString.c_str(), isValidOption); //validar la opci�n escogida
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
			showText("Volveremos al men� principal.");
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
		//Aca nombre de tienda y direcci�n
		showText("�Qu� desea hacer?");
		showText("");
		showText("1- Historial de cotizaciones");
		showText("2- Realizar cotizaci�n");
		showText("X- Salir");
		std::cin >> option;
		std::system("cls");
		//runOption(option.c_str(), exitCondition);
		showText("");
		showText(ANY_KEY_MESSAGE);
		std::cin.get();
	} while (!exitCondition);
}
/*
void View::runOption(const char* option, bool& exitCondition)
{
	auto str_option = std::string(option);

	if (str_option == "1")
	{
		showMenuToTakeAWeapon();
		exitCondition = false;
	}
	else if (str_option == "2")
	{
		m_presenter->dropCurrentWeapon();
		std::cin.get();
		exitCondition = false;
	}
	else if (str_option == "3")
	{
		m_presenter->shoot();
		std::cin.get();
		exitCondition = false;
	}
	else if (str_option == "4")
	{
		m_presenter->seeCurrentWeapon();
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
*/