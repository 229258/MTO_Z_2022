#!/usr/bin/env python3

import sys

def convert_hex(my_string):
    convert = ''
    for char in my_string:
        if 'a' <= char <= 'f':
            char = chr(ord(char+6))
        convert += char
    return convert


def my_printf(format_string,param):
    #print(format_string)
    shouldDo=True
    for idx in range(0,len(format_string)):
        if shouldDo:
            if format_string[idx] == '#' and format_string[idx+1] == '.'  and format_string[idx+2] == 'Z'  and format_string[idx+3] == 'j' and param.isnumeric():
                hex_value = f"{int(param):x}"
                print(convert_hex(hex_value),end="")
                shouldDo=False
            else:
                print(format_string[idx],end="")
        else:
            shouldDo=True
    print("")

data=sys.stdin.readlines()

for i in range(0,len(data),2):
    my_printf(data[i].rstrip(),data[i+1].rstrip())
