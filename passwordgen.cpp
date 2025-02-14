#include "passwordgen.h"

QString PasswordGen::GetGeneratePassword()
{
    if (m_generatedPassword.length() != 0)
        m_generatedPassword = 0;
    std::mt19937 gen(rd());												// Mersenne Twister pseudo-random generator
    // Define the range of random numbers


    if (m_allowSpecialCharacters)
    {



        std::uniform_int_distribution<> dis(0, m_defaultCharactersAllowed.length() - 1);                    //length calculated after removal

        for (int i = 0; i < m_characterLength; i++)
        {

            m_generatedPassword.push_back(m_defaultCharactersAllowed.at(dis(gen)));

        }
    }

    return QString(m_generatedPassword);
}

QString PasswordGen::GetRetrievePassword()
{
    return QString(m_generatedPassword);
}

void PasswordGen::SetPasswordLength(QString qstring)
{
    m_characterLength = qstring.toInt();
}

void PasswordGen::AllowUppercase(bool allowUppercase)
{
    if (!allowUppercase)
    {
        QString charsToRemove = "ZXCVBNMASDFGHJKLQWERTYUIOP";

        for (QChar c : charsToRemove)
        {
            m_defaultCharactersAllowed.remove(c);
        }
    }
}

void PasswordGen::AllowLowercase(bool allowLowercase)
{
    if (!allowLowercase)
    {
        QString charsToRemove = "zxcvbnmasdfghjklqwertyuiop";

        for (QChar c : charsToRemove)
        {
            m_defaultCharactersAllowed.remove(c);
        }
    }
}

void PasswordGen::AllowNumbers(bool allowNumbers)
{
    if (!allowNumbers)
    {
        QString charsToRemove = "1234567890";

        for (QChar c : charsToRemove)
        {
            m_defaultCharactersAllowed.remove(c);
        }
    }
}

void PasswordGen::DissallowedCharacters(QString dissallowedCharacters)
{
    if (!m_dissallowedCharacters.isEmpty())
    {
        QString tempString;

        for (int i = 0; i < m_defaultCharactersAllowed.length(); ++i)
        {
            if (!m_dissallowedCharacters.contains(m_defaultCharactersAllowed.at(i)))
            {
                tempString.append(m_defaultCharactersAllowed.at(i));
            }
        }

        m_defaultCharactersAllowed = tempString; // Update the original string
    }
}

void PasswordGen::AllowSymbols(bool allowSymbols)
{
    if (!allowSymbols)
    {
        QString charsToRemove = "!@#$&";

        for (QChar c : charsToRemove)
        {
            m_defaultCharactersAllowed.remove(c);
        }
    }
}


