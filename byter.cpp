#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <filesystem>

int main()
{
    using namespace std;
    string _filename = "Balance";
    Initiation:
        _filename = "Balance";
        cout << "Name the name for the file. passing *prev makes it remember previous file\n";
        cin >> _filename;

        if(_filename == "*prev")
        {
            ifstream _oldfile;
            _oldfile.open("byter.ini");

            if(_oldfile.bad())
                _filename = "byter_default";
            else
                _oldfile >>_filename;

            _oldfile.close();
        }
    
    ifstream _oldfileconfigread;
    _oldfileconfigread.open("byter.ini");
    if(_oldfileconfigread.good())
    {
    	string _oldfilename;
		_oldfileconfigread >> _oldfilename;
		if(_filename != _oldfilename && !std::filesystem::path("/" + _oldfilename).empty())
		{
            string _ynanswer;
            cout << "Warning, the file name you input is already existing and dnor is the previous file. Do you shall continue?\n[y][n]";
            while (_ynanswer != "y" || _ynanswer != "n")
            {
                cin >> _ynanswer;
            }
            if (_ynanswer == "n")
            {
                goto Initiation;
            }
		}
	}

    ofstream _oldfileconfig;
    _oldfileconfig.open("byter.ini", ios_base::out | ios_base::trunc);

    _oldfileconfig << _filename;

    int _byte;

    cout << "How much byte you want to set on it?\n";
    cin >> _byte;
    while(!cin) // or if(cin.fail())
    {
        // user didn't input a number
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
        // next, request user reinput
        cout << "Input numeric values.\n";
        cin >> _byte;
    }

    ifstream _readtargetfile;
    ofstream _writetargetfile;
    string _targetfilecontent;

    _readtargetfile.open(_filename);
    _readtargetfile >> _targetfilecontent;
    _readtargetfile.close();

    _writetargetfile.open(_filename, ios_base::out | ios_base::trunc);
    for(int i = 0; i < _byte; i++)
    {
        _writetargetfile << "a";
    }
    return 0;

}
