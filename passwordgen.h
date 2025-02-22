#ifndef PASSWORDGEN_H
#define PASSWORDGEN_H
#include <random>
#include <QString>

class PasswordGen
{
public:
    PasswordGen() {};
    QString GetGeneratePassword();                                      // Generates and stores password
    QString GetRetrievePassword();                                      // Retrieves already stored password
    void SetPasswordLength(QString qstring);                            // Changes  password length
    void AllowUppercase(bool allowUppercase);
    void AllowLowercase(bool allowLowercase);
    void AllowNumbers(bool allowNumbers);
    void DissallowedCharacters(QString dissallowedCharacters);
    void AllowSymbols(bool allowSymbols);


private:
    // Create a random number generator
    std::random_device rd;												// Random hardware device to seed;

    int m_characterLength = 12;

    QString m_generatedPassword = "";
    QString m_dissallowedCharacters = "";                               //characters dissallowed by the users
    QString m_defaultCharactersAllowed = "ZXCVBNMASDFGHJKLQWERTYUIOPzxcvbnmasdfghjklqwertyuiop1234567890!@#$&";
    QString m_defaultCharsAllowedNoSpecial = "ZXCVBNMASDFGHJKLQWERTYUIOPzxcvbnmasdfghjklqwertyuiop1234567890";

    bool m_allowSpecialCharacters = true;



};

#endif // PASSWORDGEN_H
