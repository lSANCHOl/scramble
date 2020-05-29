#!/bin/python3

import sys
import random
ckey = "abcdefghijklmnopqrstuvwxyz1234567890!£$%^&*()-_=+[{]};:'@#~|,<.>/? ABCDEFGHIJKLMNOPQRSTUVWXYZ\""





def keygen():
	abc = "abcdefghijklmnopqrstuvwxyz1234567890!£$%^&*()-_=+[{]};:'@#~|,<.>/? ABCDEFGHIJKLMNOPQRSTUVWXYZ\""
	cba = ""
	print(len(abc))
	length = len(abc)
	for i in range(94):		
		rannum = random.randint(0,length-1)
		rancha = abc[rannum]
		cba += rancha
		abc = abc.replace(rancha, "")
		length = len(abc)
	print(cba)
	choose()

def encode():
	key = input("KEY: ")
	dkey = ""
	for i in range(len(key)):
		loc1 = ckey[i]
		loc2 = key.find(loc1)
		loc3 = ckey[loc2]
		dkey += loc3
	out = ""
	inp = input("ENCODE: ")
	for i in range(len(inp)):
		for j in range(len(ckey)):
			if inp[i] == ckey[j]:
				tmp = key[j]
				out += tmp
	print(out)
	choose()
	
				
def decode():
	key = input("KEY: ")
	dkey = ""
	for i in range(len(key)):
		loc1 = ckey[i]
		loc2 = key.find(loc1)
		loc3 = ckey[loc2]
		dkey += loc3
	out = ""
	inp = input("DECODE: ")
	for i in range(len(inp)):
		for j in range(len(ckey)):
			if inp[i] == ckey[j]:
				tmp = dkey[j]
				out += tmp
	print(out)
	choose()

def choose():
	choice = input("Encode, decode, generate key or quit? [e/d/k/q]:")
	if choice == "e":
		encode()
	if choice == "d":
		decode()
	if choice == "k":
		keygen()
	if choice == "q":
		sys.exit()

choose()
