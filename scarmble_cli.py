#!/bin/python3

import argparse
import sys
import secrets

ckey = 'abcdefghijklmnopqrstuvwxyz1234567890!£$%^&*()-_=+[{]};:"@#~|,<.>/? ABCDEFGHIJKLMNOPQRSTUVWXYZ\''

def keygen(key):
    cba = ''   
    while(len(cba) < 94):
        tmp = ''.join(secrets.choice(key))
        if(tmp not in cba):
            cba += tmp

    return cba
  
def encode(key,message,output):
    out = ''
     
    for i in range(len(message)):
        for j in range(len(ckey)):
            if message[i] == ckey[j]:
                tmp = key[j]
                out += tmp
   
    if output == True:
        print('[+]',out,'[+]')
    elif output == False:
        file1 = open('encoded.txt', 'w')     
        n = file1.write(out)
        file1.close()
    else:
        print('[+]',out,'[+]')
        file1 = open('encoded.txt', 'w')
        n = file1.write(out)
        file1.close()
				
def decode(key,message,output):
    dkey = ''
    for i in range(len(key)): 
        loc1 = ckey[i]
        loc2 = key.find(loc1)
        loc3 = ckey[loc2]
        dkey += loc3
    out = ''

    for i in range(len(message)):
        for j in range(len(ckey)):
            if message[i] == ckey[j]:
                tmp = dkey[j]
                out += tmp 

    if output == True:
        print('[+]',out,'[+]')
    elif output == False:
        file1 = open('decoded.txt', 'w')     
        n = file1.write(out)
        file1.close()
    else:
        print('[+]',out,'[+]')
        file1 = open('decoded.txt', 'w')
        n = file1.write(out)
        file1.close()

parser = argparse.ArgumentParser(description='Encode and Decode messages with a unique key')    
parser.add_argument('-k', '--Key', metavar='', help='Path to unique key')
parser.add_argument('-e', '--Encode', metavar='', help='path to file to encode')
parser.add_argument('-d', '--Decode', metavar='', help='path to file to decode')
parser.add_argument('-p', '--Print', action='store_true', help='print encoded/decoded message')
parser.add_argument('-s', '--Store', action='store_true', help='store encoded/decoded message to file')
parser.add_argument('-b', '--Both', action='store_true', help='print and store encoded/decoded message')
parser.add_argument('-K', '--Keygen', action='store_true',  help='generate unique key')
args = parser.parse_args()

if __name__ == '__main__':
    if len(sys.argv)==1:
        parser.print_help(sys.stderr)
        sys.exit(1)
   
    elif args.Encode and args.Print and args.Key:
        output = True
        filename = args.Encode
        with open(filename, 'r') as file:
            filecontents = file.read()
            file.close()
        keyname = args.Key 
        with open(keyname, 'r') as file:
            keycontents = file.read()
            file.close()
        encode(keycontents,filecontents,output)

    elif args.Encode and args.Store and args.Key:
        output = False
        filename =args.Encode
        with open(filename, 'r') as file:
            filecontents = file.read()
            file.close()
        keyname = args.Key
        with open(keyname, 'r') as file:
            keycontents = file.read()
            file.close()
        encode(keycontents,filecontents,output)
     
    elif args.Encode and args.Both and args.Key:
        output = 2
        filename = args.Encode 
        with open(filename, 'r') as file:
            filecontents = file.read()
            file.close()
        keyname = args.Key 
        with open(keyname, 'r') as file:
            keycontents = file.read()
            file.close()
        encode(keycontents,filecontents,output)
     
    elif args.Encode and args.Print and args.Keygen:
        keycontents = keygen(ckey)
        print('[KEY]',keycontents,'[KEY]')
        output = True
        filename = args.Encode
        with open(filename, 'r') as file:
            filecontents = file.read()
            file.close()
        encode(keycontents,filecontents,output)
    
    elif args.Encode and args.Store and args.Keygen:
        keycontents = keygen(ckey)
        print('[KEY]',keycontents,'[KEY]')
        output = False
        filename = args.Encode
        with open(filename, 'r') as file:
            filecontents = file.read()
            file.close()
        encode(keycontents,filecontents,output)
     
    elif args.Encode and args.Both and args.Keygen:
        keycontents = keygen(ckey)
        print('[KEY]',keycontents,'[KEY]')
        output = 2
        filename = args.Encode
        with open(filename, 'r') as file:
            filecontents = file.read()
            file.close()
        encode(keycontents,filecontents,output)
    
    elif args.Decode and args.Print and args.Key:
        output = True
        filename = args.Decode
        with open(filename, 'r') as file:
            filecontents = file.read()
            file.close()
        keyname = args.Key
        with open(keyname, 'r') as file:
            keycontents = file.read()
            file.close()
        decode(keycontents,filecontents,output)

    elif args.Decode and args.Store and args.Key:
        output = False
        filename = args.Decode
        with open(filename, 'r') as file:
            filecontents = file.read()
            file.close()
        keyname = args.Key
        with open(keyname, 'r') as file:
            keycontents = file.read()
            file.close()
        decode(keycontents,filecontents,output)
     
    elif args.Decode and args.Both and args.Key:
        output = 2
        filename = args.Decode
        with open(filename, 'r') as file:
            filecontents = file.read()
            file.close()
        keyname = args.Key 
        with open(keyname, 'r') as file:
            keycontents = file.read()
            file.close()
        decode(keycontents,filecontents,output)
     
    elif args.Decode and args.Print and args.Keygen:
        keycontents = keygen(ckey)
        print('[KEY]',keycontents,'[KEY]')
        output = True
        filename = args.Decode
        with open(filename, 'r') as file:
            filecontents = file.read()
            file.close()
        decode(keycontents,filecontents,output)
    
    elif args.Decode and args.Store and args.Keygen:
        keycontents = keygen(ckey)
        print('[KEY]',keycontents,'[KEY]')
        output = False
        filename = args.Decode
        with open(filename, 'r') as file:
            filecontents = file.read()
            file.close()
        decode(keycontents,filecontents,output)

    elif args.Decode and args.Both and args.Keygen:
        keycontents = keygen(ckey)
        print('[KEY]',keycontents,'[KEY]')
        output = 2
        filename = args.Decode
        with open(filename, 'r') as file:
            filecontents = file.read()
            file.close()
        Decode(keycontents,filecontents,output)
    
    elif args.Keygen and args.Print:
        print(keygen(ckey))
    elif args.Keygen and args.Store:
        key = keygen(ckey)
        file1 = open('KEY', 'w')
        file1.write(key)
        file1.close()
    elif args.Keygen and args.Both:
        key = keygen(ckey)
        print(key)
        file1 = open('KEY', 'w')
        file1.write(key)
        file1.close()
