#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;
class clsBankClient : public clsPerson
{
    
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddMode = 3, DeleteMode = 4 ,ListMode = 5};
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkDelete = false;
    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }
    
    static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);
        
        return stClientRecord;

    }

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C._MarkDelete == false) {
                    DataLine = _ConvertClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
                

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;

                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));

    }
    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
    string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient, string User,string seperator = "#//#") {
        string TransferLogRecord;
        TransferLogRecord += (clsDate::GetSystemDateTimeString()) + seperator;
        TransferLogRecord += AccountNumber()+seperator;
        TransferLogRecord += DestinationClient.AccountNumber() + seperator;
        TransferLogRecord += to_string(AccountBalance) + seperator;
        TransferLogRecord += to_string(DestinationClient.AccountBalance) + seperator;
        TransferLogRecord += to_string(Amount) + seperator;
        TransferLogRecord += User;
        return TransferLogRecord;
    }
    void _RegisterTransferLogin(float Amount, clsBankClient DestinationClient,string User) {
        fstream MyFile;

        MyFile.open("TransferLog.txt", ios::out | ios::app);
        string stDataLine;
        stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient,User);
        if (MyFile.is_open()) {

            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }
    struct stTransferLogRecord;
    static stTransferLogRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
    {
        stTransferLogRecord TransferLogRecord;
        vector <string> TransferLogRecordDataLine = clsString::Split(Line, Seperator);
        TransferLogRecord.DateTime = TransferLogRecordDataLine[0];
        TransferLogRecord.SourceAccountNumber = TransferLogRecordDataLine[1];
        TransferLogRecord.DestinationAccountNumber = TransferLogRecordDataLine[2];
        TransferLogRecord.SourceAccountBalance = stod(TransferLogRecordDataLine[3]);
        TransferLogRecord.DestinationAccountBalance = stod(TransferLogRecordDataLine[4]);
        TransferLogRecord.Amount = stod(TransferLogRecordDataLine[5]);
        TransferLogRecord.UserName = TransferLogRecordDataLine[6];
        return TransferLogRecord;

    }
public:
    struct stTransferLogRecord
    {
        string DateTime;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        int SourceAccountBalance;
        int DestinationAccountBalance;
        int Amount;
        string UserName;

    };
    
    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }
   
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }


    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    void SetAccountNumber(string AccountNumber)
    {
        _AccountNumber = AccountNumber;
    }
    
    
    

    static clsBankClient Find(string AccountNumber)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {



        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }
    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddMode, "", "", "", "", AccountNumber, "", 0);
    }


    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2
    };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {

            return enSaveResults::svFaildEmptyObject;
        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

        
        }

        case enMode::AddMode:
        {


            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();

                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;

        }
        case enMode::ListMode:
        {


            
                GetClientsList();
                _Mode = enMode::ListMode;
                return enSaveResults::svSucceeded;
                break;

        }
     }



    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

    vector <clsBankClient> SaveClientToFile(string FileName, vector<clsBankClient> vClient) {
        fstream MyFile;
        MyFile.open(FileName, ios::out);
        string DataLine;
        if (MyFile.is_open()) {
            for (clsBankClient c : vClient) {
                if (c._MarkDelete == false) {
                    DataLine =_ConvertClientObjectToLine(*this);
                    MyFile << DataLine << endl;
                }
            }
            MyFile.close();
        }
        return vClient;
    }
    
    bool Delete() {
        vector<clsBankClient> vClient = _LoadClientsDataFromFile();
        for (clsBankClient& C : vClient) {
            if (C._AccountNumber == _AccountNumber) {
                C._MarkDelete = true;
                break;
            }
        }

        _SaveCleintsDataToFile(vClient);
        *this = _GetEmptyClientObject();
        return true;
    }
    static vector <clsBankClient> GetClientsList() {
        return  _LoadClientsDataFromFile();
        
    }
 
    static double GetTotalBalances() {
        vector <clsBankClient>vClient = clsBankClient::GetClientsList();
        double TotalBalances = 0;
        for (clsBankClient Client : vClient) {
            TotalBalances += Client.AccountBalance;
        }
        return TotalBalances;

    }
    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    
    bool Withdraw(double Amount) {
        if (Amount > _AccountBalance) {
            return false;
        }
        else {
            _AccountBalance -= Amount;
            Save();
            return true;
        }
    }
    /*bool IsEquals(clsBankClient Client) {
		return (this->AccountNumber() == Client._AccountNumber);
    }*/
    bool Transfer(float Amount,clsBankClient& DestinationClient,string User) {
        if (Amount > AccountBalance) {
			return false;
		}

        Withdraw(Amount);
		DestinationClient.Deposit(Amount);
        _RegisterTransferLogin(Amount, DestinationClient,User);
        return true;
    }
    static vector<stTransferLogRecord>GetTransferLogList() {
        vector<stTransferLogRecord>vTransferLog;
        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in);
        if (MyFile.is_open()) {
            string Line;
            stTransferLogRecord TransferLog;
            while (getline(MyFile, Line)) {
                TransferLog = _ConvertLoginRegisterLineToRecord(Line);
                vTransferLog.push_back(TransferLog);
            }
            MyFile.close();
        }
        return vTransferLog;
    }
    
};

