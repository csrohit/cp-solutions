def get_feb(year):
    if year < 1918:
        return 28 if year % 4 else 29
    elif year > 1918:
        return 29 if (year % 400 == 0) or ((year % 4 == 0) and (year % 100 != 0)) else 28
    else:
        return 15

if __name__ == '__main__':
    year = int(input())
    day_feb = get_feb(year)
    day_8_mo = 215
    day_sep = 256 - (day_feb + day_8_mo)
    print(str(day_sep) + ".09." + str(year))





        # leap year if
        # devided by 400 or devided 4 and not dvided by 100