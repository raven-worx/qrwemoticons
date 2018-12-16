#!/usr/bin/python

import argparse
import os
import sys
import errno
import shutil

# python ../scripts/generate_emoticon_qrc.py --provider twitter --dir twemoji --filename emoticons_twitter
# python ../scripts/generate_emoticon_qrc.py --provider google --dir noto-emoji --filename emoticons_google
# python ../scripts/generate_emoticon_qrc.py --provider emojione --dir EmojiOne_4.0_64x64_png --filename emoticons_emojione
# python ../scripts/generate_emoticon_qrc.py --provider openmoji --dir openmoji --filename emoticons_openmoji

SUPPORTED_PROVIDERS = ['twitter','google','emojione','openmoji']

#
# PARSE ARGUMENTS
#
parser = argparse.ArgumentParser(description='Generate .qrc files for emoticon files')

parser.add_argument('-d', '--dir', action='store', dest='DIR', type=str, required=True,
                    help='Absolute path to base directory containing the emoticon icon files')
parser.add_argument('-p', '--provider', action='store', dest='PROVIDER', type=str, required=True,
                    help='[' + '|'.join(SUPPORTED_PROVIDERS) + ']')
parser.add_argument('-b', '--batch', action='store', dest='BATCH', type=int, required=False, default=1000,
                    help='Batch size of emoticon files to prevent too big .qrc files')
parser.add_argument('-f', '--filename', action='store', dest='FILENAME', type=str, required=True,
                    help='Base name of the output .qrc file')

args = parser.parse_args()

DIR=args.DIR.replace("\\", "/")
PROVIDER=args.PROVIDER
BATCH=args.BATCH
FILENAME=args.FILENAME

#
# CHECKS
#

if not PROVIDER in SUPPORTED_PROVIDERS:
	sys.stderr.write("Unknown provider '" + PROVIDER + "' specified. Supported providers are [" + ', '.join(SUPPORTED_PROVIDERS) + "]")
	sys.exit(1)

if os.path.isdir(DIR) == False:
	sys.stderr.write("'" + DIR + "' is not a directory")
	sys.exit(1)

#
# METHODS
#

TOTAL_LINES=0
file=None

def openFile():
	global file
	file = open(FILENAME+'_'+str(int(TOTAL_LINES/BATCH))+'.qrc', 'w')
	file.write('<!DOCTYPE RCC><RCC version="1.0">\n')
	file.write('<qresource prefix="/QrwEmoticons/' + PROVIDER + '">\n')

def closeFile():
	global file
	if not file is None:
		file.write('</qresource>\n')
		file.write('</RCC>\n')
		file.close()
		file=None

def writeToFile(line):
	global file
	global TOTAL_LINES
	global BATCH
	if file is None:
		openFile()
	TOTAL_LINES += 1
	file.write(line + '\n')
	if TOTAL_LINES % BATCH == 0:
		closeFile()

def fileNameTransform(fileName):
	name, ext = os.path.splitext(fileName)
	tokens = name.split("-")
	for i in range(len(tokens)):
		tokens[i] = tokens[i].rjust(5, '0') # pad the string to 5 characters for convenience searching
	return "-".join(tokens).lower() + ext.lower()

def googleFileNameTransform(fileName):
	if( fileName.startswith('emoji_u') ):
		fileName = fileName[7:]
	fileName = fileName.replace('_', '-')
	return fileNameTransform(fileName)

def traverseFiles(path, fileNameTransform=None):
	for file in os.listdir(path):
		filePath = path + '/' + file
		if os.path.isfile(filePath) == False:
			continue
		filename, file_extension = os.path.splitext(filePath)
		if( file_extension in ['.png','.svg'] ):
			fileName = os.path.basename(filePath)
			if fileNameTransform:
				fileName = fileNameTransform(fileName)
			relFilePath = os.path.relpath(filePath)
			writeToFile('\t<file alias="' + fileName + '">' + relFilePath + '</file>')

#
# CREATE QRC FILE
#

if PROVIDER == 'twitter':
	twitterPaths = [
		DIR + '/2/svg',
		DIR + '/2/72x72'
	]
	for p in twitterPaths:
		if os.path.isdir(p):
			traverseFiles(p, fileNameTransform)
		else:
			sys.stderr.write("'" + p + "' is not a directory")
	
elif PROVIDER == 'google':
	googlePaths = [
		#DIR + '/svg',
		DIR + '/png/128'
	]
	for p in googlePaths:
		if os.path.isdir(p):
			traverseFiles(p, fileNameTransform)
		else:
			sys.stderr.write("'" + p + "' is not a directory")
	
elif PROVIDER == 'emojione':
	emojionePath = DIR
	if os.path.isdir(emojionePath):
		traverseFiles(emojionePath, fileNameTransform)
	else:
		sys.stderr.write("'" + emojionePath + "' is not a directory")
	
elif PROVIDER == 'openmoji':
	openmojiPaths = [
		#DIR + '/color/svg',
		DIR + '/color/72x72'
	]
	for p in openmojiPaths:
		if os.path.isdir(p):
			traverseFiles(p, fileNameTransform)
		else:
			sys.stderr.write("'" + p + "' is not a directory")

closeFile()