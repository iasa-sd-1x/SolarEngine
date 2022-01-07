#ifndef SOLSTD_H
#define SOLSTD_H

#define F_STR   0x1        // string
#define F_INT32 0x2        // int
#define F_INT64 0x3        // long (не реализовано)
#define F_DOUB  0x4        // double

/**
 * @brief Функция, которая возвращает отформатированную строку согласно командам форматирования функций printf, scanf, etc
 * 
 * @param fmt Строка, которая будет форматироваться
 * @param ... переменное количество аргументов (%s, %d, %f)
 * @return (std::string) Отредактированная строка, в которой команды форматирования
 * заменены на определённые переменные
 */
std::string fstring(const char *fmt, ...);

/**
 * @brief ---
 * 
 */
class sol_exception : virtual std::exception
{

private:
    std::string _error_string;

public:
    sol_exception(const char *error_str);
    virtual ~sol_exception() = default;
    virtual const char *what() const throw();
};

#endif // SOLSTD_H