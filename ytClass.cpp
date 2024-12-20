#include <iostream>
using namespace std;
#include <list>
class youTubeChannel
{
public:
    string Name;
    string ownerName;
    int subCount;
    int vidVeiws;
    list<string> publishVideoTitle;
    youTubeChannel(string name, string OwnerName, int subscriber, int viewer)
    {
        Name = name;
        ownerName = OwnerName;
        subCount = subscriber;
        vidVeiws = viewer;
    }
    void GetInfo()
    {
        cout << "__________________________________________________" << endl;
        cout << "Name: " << Name << endl;
        cout << "Channel Owner: " << ownerName << endl;
        cout << "Views: " << vidVeiws << "M" << endl;
        cout << "Subscriber: " << subCount << "M" << endl;
        for (string videoTitle : publishVideoTitle)
        {
            cout << "Title: " << videoTitle << endl;
        }
    }
};
int main()
{

    youTubeChannel ytChannel("MS Professor", "Salman", 56, 230);
    ytChannel.publishVideoTitle.push_back("Web Development Full Course HTML, CSS");
    ytChannel.publishVideoTitle.push_back("Complete Python Course For Beginners.");
    ytChannel.publishVideoTitle.push_back("JavaScript Complete Crash Course for Beginners.");
    ytChannel.GetInfo();
    cout << "__________________________________________________" << endl;
    youTubeChannel YTChannel("MS Tech", "Professor", 26, 67);
    YTChannel.publishVideoTitle.push_back("Advance Adobe After Effects Full Course");
    YTChannel.publishVideoTitle.push_back("Adobe Illustrator Full Course For Beginners");
    YTChannel.publishVideoTitle.push_back("Complete Adobe Photoshop Course for Beginners");
    YTChannel.GetInfo();
    cout << "__________________________________________________" << endl;
    system("pause");
    return 0;
}