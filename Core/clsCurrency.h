#pragma once
using namespace std;
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include "clsString.h"
class clsCurrency
{
private:
	static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector<string> vCurrencyData;
		vCurrencyData = clsString::Split(Line, Seperator);
		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));
	}
	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{
		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.Country() + Seperator;
		stCurrencyRecord += Currency.CurrencyCode() + Seperator;
		stCurrencyRecord += Currency.CurrencyName() + Seperator;
		stCurrencyRecord += to_string(Currency.Rate());
		return stCurrencyRecord;

	}
	static void _SaveCurrenciesDataToFile(vector <clsCurrency> vCurrencys) {
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);
		string Line;
		while (MyFile.is_open()) {
			for (clsCurrency C : vCurrencys) {
				
					Line = _ConvertCurrencyObjectToLine(C);
					MyFile << Line << endl;
				

			}
			MyFile.close();
		}

	}
	static  vector <clsCurrency> _LoadCurrenciesDataFromFile()
	{

		vector <clsCurrency> vCurrencies;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

				vCurrencies.push_back(Currency);
			}

			MyFile.close();

		}

		return vCurrencies;

	}
	enum enMode { EmptyMode = 0, UpdateMode = 1};
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	void _Update() {
		vector<clsCurrency>vCurrencies = _LoadCurrenciesDataFromFile();
		for (clsCurrency& Currency : vCurrencies) {
			if (Currency.CurrencyCode() == CurrencyCode()) {
				Currency = *this;
				break;
			}
		}
		_SaveCurrenciesDataToFile(vCurrencies);
	}
	static clsCurrency _GetEmptyObject() {
		return clsCurrency(enMode::EmptyMode,"", "", "", 0);
	}
public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}
	string Country() {
		return _Country;
	}
	string CurrencyCode() {
		return _CurrencyCode;
	}
	string CurrencyName() {
		return _CurrencyName;
	}
	void UpdateRate(float NewRate) {
		_Rate = NewRate;
		_Update();
	}
	float Rate() {
		return _Rate;
	}
	static clsCurrency FindByCode(string CurrencyCode) {
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode
		string Line;
		if (MyFile.is_open()) {
			while (getline(MyFile, Line)) {
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode) {
					MyFile.close();
					return Currency;
				}
				
			}
		
		}
		MyFile.close();
		return _GetEmptyObject();
	}
	static clsCurrency FindByCountry(string Country) {
		Country = clsString::UpperAllString(Country);
		fstream MyFile;
		MyFile.open("Currencies.txt",ios::in);
		string Line;
		if (MyFile.is_open()) {
			while (getline(MyFile, Line)) {
				clsCurrency Currency= _ConvertLinetoCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country) {
					MyFile.close();
					return Currency;
				}
			}
		}
		MyFile.close();
		return _GetEmptyObject();
	}
	static bool IsCurrencyExist(string CurrencyCode) {
		clsCurrency C1 = FindByCode(CurrencyCode);
		return !(C1.IsEmpty());
	}
	static vector<clsCurrency> GetListCurrencies(){
		return _LoadCurrenciesDataFromFile();
	}
	float ConvertToUSD(float Amount) {
		return (float)(Amount / Rate());
		
	}
	float ConvertToOtherCurrency(float Amount,clsCurrency Currency2) {
		float AmountInUSD = ConvertToUSD(Amount);
		if (Currency2.CurrencyCode() == "USD") {
			return AmountInUSD;
		}
		return (float)(AmountInUSD * Rate());

	}
};

