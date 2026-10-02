typedef enum { English, Italian, Spanish } language;
const char *month(int number, language lang);
const char *lang2str(language lang);

const char *month(int number, language lang) 
{
    if (number < 1 || number > 12 || lang < English || lang > Spanish) 
    {
        return "Error";

    }
    static const char *months[3][12] = {
        // English = 0
        {
            "January", "February", "March", "April", 
            "May", "June", "July", "August", 
            "September", "October", "November", "December"
        },
        // Italian = 1
        {
            "Gennaio", "Febbraio", "Marzo", "Aprile", 
            "Maggio", "Giugno", "Luglio", "Agosto", 
            "Settembre", "Ottobre", "Novembre", "Dicembre"
        },
        // Spanish = 2
        {
            "Enero", "Febrero", "Marzo", "Abril", 
            "Mayo", "Junio", "Julio", "Agosto", 
            "Septiembre", "Octubre", "Noviembre", "Diciembre"
        }
    };
    return months[lang][number - 1];
}

const char *lang2str(language lang) 
{
    if (lang < English || lang > Spanish)
    {
        return "Error";
    }

    static const char *lang_names[] = {
        "English",
        "Italian",
        "Spanish"
    };

    return lang_names[lang];

}