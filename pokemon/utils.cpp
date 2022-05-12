#include "utils.h"
#include "QFile"
#include "QTextStream"
#include <QDir>

#include "player.h"

void delay(int msec)
{
    QTime dieTime= QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents , 100);
}

vector<string> parseLine(string aString)
{
    stringstream lineStream(aString);
    string cell;

    vector<string> keys;

    // parse line
    while(getline(lineStream, cell, ',')) {
        keys.push_back(cell);
    }

    return keys;
}

const vector<map<string, string>> extract_fileData(string fileName)
{
    vector<map<string, string>> data;

    // open file
    string path = ":/data/" + fileName;
    cout << "Opening file (" << path << ")" << endl;

    QFile file( QString::fromStdString(path) );

    if(!file.open(QIODevice::ReadOnly)) {
        cout << "Unable to open the file named: " << fileName << endl;
    }
    else {
        QTextStream in(&file);
        QString line = in.readLine();

        // prepare keys for map
        vector<string> keys = parseLine(line.toStdString());
        // end prepare keys for map

        while(!in.atEnd()) {

            // parse every line of the file remaning
            line = in.readLine();
            vector<string> values = parseLine(line.toStdString());

            map<string, string> map_tmp;
            for (unsigned long long i = 0; i < keys.size(); i++) {
                map_tmp.insert({keys[i], values[i]});
            }

            // put the map in the vector data
            data.push_back(map_tmp);
        }
    }

    // close file to avoid trouble
    file.close();

    return data;
}


void print_data(vector<map<string, string> > aData)
{
    cout << "Printing data :" << endl;

    for (unsigned long long i = 0; i < aData.size(); i++) {
        map<string, string> line = aData[i];
        string toCout = "";

        for (map<string, string>::iterator it = line.begin(); it != line.end(); it++) {
            toCout += it->first + ": " + it->second + ",";
        }

        cout << "\t" << i << "(" << toCout << ")" << std::endl;
    }
}

void save_data(Player *aPlayer)
{
    string playerName = aPlayer->getItsName();

    cout << "Saving data for " << playerName << endl;

    QDir curDir(QDir::currentPath());

    string folderName = curDir.canonicalPath().toStdString() + "/";
    string fileName = "save.txt";

    QDir folder(QString::fromStdString(folderName));

    if (!folder.exists()) {
        QDir().mkdir(QString::fromStdString(folderName));
    }
    else {
        //cout << "Folder already exists" << endl;
    }

    QFile outputFile(QString::fromStdString(folderName + fileName));

    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
        cout << "Unable to open the file named: " << folderName + fileName << endl;
    }
    else {
        QTextStream outstream(&outputFile);

        outstream << QString::fromStdString(playerName) << Qt::endl;

    }

    outputFile.close();
}
