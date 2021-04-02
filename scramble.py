#!/bin/python3

import sys
import random
ckey = "abcdefghijklmnopqrstuvwxyz1234567890!£$%^&*()-_=+[{]};:'@#~|,<.>/? ABCDEFGHIJKLMNOPQRSTUVWXYZ\""


def keygen(key):
    
    cba = ""
    #print(len(abc))
    length = len(key)
    for i in range(94):		
        rannum = random.randint(0,length-1)
        rancha = key[rannum]
        cba += rancha
        key = key.replace(rancha, "")
        length = len(key)
    return cba
    choose()

def encode(key):
    out = ""
    choose3 = input("[f]ile to encode | [i]nput to encode: ")
    if choose3 == "i":
        inp = input("ENCODE: ")
    elif choose3 == "f":
        filename = input("path to file: ")
        with open(filename, 'r') as file:
                inp = file.read()
                file.close() 
    for i in range(len(inp)):
        for j in range(len(ckey)):
            if inp[i] == ckey[j]:
                tmp = key[j]
                out += tmp
    
    choose4 = input("[w]rite result to file | [p]rint result | [b]oth: ")
    if choose4 == "p":
        print("[+]",out,"[+]")
    elif choose4 == "w":
        file1 = open("encoded.txt", 'w')     
        n = file1.write(out)
        file1.close()
    elif choose4 == "b":
        print(out)
        file1 = open("encoded.txt", 'w')
        n = file1.write(out)
        file1.close()
    choose()
				
	
def decode(key):
    dkey = ""
    for i in range(len(key)):
        loc1 = ckey[i]
        loc2 = key.find(loc1)
        loc3 = ckey[loc2]
        dkey += loc3
    out = ""
    choose3 = input("[f]ile to decode | [i]nput to decode: ")
    if choose3 == "i":
        inp = input("DECODE: ")
    elif choose3 == "f":
        filename = input("path to file: ")
        with open(filename, 'r') as file:
                inp = file.read()
                file.close() 
  
    for i in range(len(inp)):
        for j in range(len(ckey)):
            if inp[i] == ckey[j]:
                tmp = dkey[j]
                out += tmp 
    
    choose4 = input("[w]rite result to file | [p]rint result | [b]oth: ")
    if choose4 == "p":
        print("[+]",out,"[+]")
    elif choose4 == "w":
        file1 = open("decoded.txt", 'w')     
        n = file1.write(out)
        file1.close()
    elif choose4 == "b":
        print(out)
        file1 = open("encoded.txt", 'w')
        n = file1.write(out)
        file1.close()
    choose()


def choose():
    choice = input("[E]ncode | [D]ecode | [G]enerate key | [Q]uit: ")
    if choice == "e":
        choice1 = input("[f]ile as key | [g]enerate key | [i]nput key: ")
        if choice1 == "g":
            key = keygen(ckey)
            print("[KEY] ",key," [KEY]")
            encode(key)
        elif choice1 == "i":
            key = input("Input Key: ")
            encode(key)
        elif choice1 == "f":
            filename = input("path to key: ")
            with open(filename, 'r') as file:
                data = file.read().replace('\n', '')
                file.close()
                encode(data)
		
    elif choice == "d":
        choice1 = input("[f]ile as key | [g]enerate key | [i]nput key: " )
        if choice1 == "g":
            key = keygen(ckey)
            print("[KEY] ",key," [KEY]")
            decode(key)
        elif choice1 == "i":
            key = input("Input Key: ")
            decode(key)
        elif choice1 == "f":
            filename = input("Path to key: ")
            with open(filename, 'r') as file:
                data = file.read().replace('\n', '')
                decode(data)
                 
    elif choice == "g":
        choice2 = input("[p]rint key | [w]rite key to file: ")
        if choice2 == "p":
            print("[KEY] ",keygen(ckey)," [KEY]")
        elif choice2 == "w":
            key = keygen(ckey)
            file1 = open("KEY", 'w')
            n = file1.write(key)
            file1.close()

    elif choice == "q":
        sys.exit()
choose()
