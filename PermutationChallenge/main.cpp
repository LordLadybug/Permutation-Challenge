#include <iostream>
#include <string>
/*Given a string, list all permutations of this string in console*/

using namespace std;

void swapCharacters(std::string *PermutableString);

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Proper Usage: " << argv[0] << " <string>"<<endl;
        return 1;
    }
    else
    {
        std::string stringToPermute = argv[1];
        if(stringToPermute.empty())
        {
            cout<< "Cannot enter empty string"<< endl;
            return 1;
        }
        cout << "String: " << argv[1] << endl;
        unsigned int stringLength = stringToPermute.length();
        std::string *StringManipulator; //Pointer that will be used to swap around characters in stringToPermute
        StringManipulator = &stringToPermute;
        for (unsigned int i=0; i<stringLength*2; i++)
        {
            //  char& leading_char = stringToPermute.front();
            //  char* leading_char_location -> stringToPermute.data();
            //const char *leading_char;
            //leading_char = &stringToPermute.data();

            swapCharacters(StringManipulator);
            //stringToPermute.push_back(*leading_char);
            //stringToPermute.erase(leading_char); //c++ does not like this; causes out-of-bounds error
            cout<< stringToPermute << endl;
        }
        delete StringManipulator; //deleting for good measure
        StringManipulator = nullptr;  //reassign pointer as a null pointer just after deleting

        return 0;
    }
}

void swapCharacters (std::string *PermutableString)
{
    const char *leading_char;
    leading_char = PermutableString.data();
    PermutableString.push_back(*leading_char);
    PermutableString.erase(leading_char);
}
