#!/usr/bin/python

# Call example:
#	python generate_emoticon_data.py -d data > ..\lib\src\QrwEmoticons_data.cpp

import argparse
import os
import subprocess
import sys
from shutil import copy2
import errno
import shutil

#
# PARSE ARGUMENTS
#
parser = argparse.ArgumentParser(description='Copy files')

parser.add_argument('-d', '--dir', action='store', dest='DIR', type=str, required=True,
                    help='Absolute path to directory containing the emoticon data files')

args = parser.parse_args()

DIR=args.DIR.replace("\\", "/")

#
# METHODS
#
def writeData(data):
	print ("\t{" + ",".join(data) + "},")

def parseFile(file):
	with open(file, encoding="utf8") as f:
		for line in f:
			if( line.startswith("#") ):
				continue
			tokens = line.split(';')
			
			codeData = tokens[0].strip()
			
			if( codeData != "" ):
				if( ".." in codeData ): # shortened notation for sequential codes
					r = codeData.split("..")
					for x in range(int('0x'+r[0],16), int('0x'+r[1],16)):
						writeData( [hex(x)] )
				elif( " " in codeData ): # multi sequence emotjis
					s = codeData.split(" ")
					d = []
					for x in s:
						d.append( "0x"+x )
					writeData( d )
				else: # single value emoji
					writeData( ['0x'+codeData] )

#
# TRAVERSE DIR
#
if os.path.isdir(DIR) == False:
	print("'" + DIR + "' is not a directory")
	sys.exit(1)

print( "#include \"QrwEmoticons_p.h\"" )
print( "const EmoticonsData QrwEmoticonsPrivate::EMOTICONS{" )

for file in os.listdir(DIR):
	path = DIR + "/" + file
	if os.path.isfile(path) == False:
		continue
	filename, file_extension = os.path.splitext(path)
	if( file_extension == ".txt" ):
		parseFile(path)

print( "};" );
