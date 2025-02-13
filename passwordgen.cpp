#include "passwordgen.h"

QString PasswordGen::GetGeneratePassword()
{
    if (m_generatedPassword.length() != 0)
        m_generatedPassword = 0;
    std::mt19937 gen(rd());												// Mersenne Twister pseudo-random generator
    // Define the range of random numbers


    if (m_allowSpecialCharacters)
    {


        //Remove disallowed characters from string
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

        std::uniform_int_distribution<> dis(0, m_defaultCharactersAllowed.length() - 1);                    //length calculated after removal




        for (int i = 0; i < m_characterLength; i++)
        {

            m_generatedPassword.push_back(m_defaultCharactersAllowed.at(dis(gen)));

        }
    }
    else
    {

        //Remove disallowed characters from string
        if (!m_dissallowedCharacters.isEmpty())
        {
            QString tempString;

            for (int i = 0; i < m_defaultCharsAllowedNoSpecial.length(); ++i)
            {
                if (!m_dissallowedCharacters.contains(m_defaultCharsAllowedNoSpecial.at(i)))
                {
                    tempString.append(m_defaultCharsAllowedNoSpecial.at(i));
                }
            }

            m_defaultCharsAllowedNoSpecial = tempString; // Update the original string
        }


        std::uniform_int_distribution<> dis(0, m_defaultCharsAllowedNoSpecial.length() - 1);



        for (int i = 0; i < m_characterLength; i++)
        {

            m_generatedPassword.push_back(m_defaultCharsAllowedNoSpecial.at(dis(gen)));

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

void PasswordGen::SetDissallowedCharacters(QString qstring)
{
    m_dissallowedCharacters = qstring;
}

void PasswordGen::SetDefaultCharactersAllowed(QString qstring)
{
    m_defaultCharactersAllowed = qstring;
}

void PasswordGen::AllowSpecialCharacters(bool allowspecial)
{
    m_allowSpecialCharacters = allowspecial;
}
