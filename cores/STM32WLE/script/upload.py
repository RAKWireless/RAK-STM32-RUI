#!/usr/bin/python3

import sys
from getopt import getopt
from getopt import GetoptError
import serial
from time import sleep
import threading
import subprocess

def usage():
    print("Usage: %s -p <COM PORT>" % sys.argv[0])
    print("       %s -f <ZIP FILE>" % sys.argv[0])
    print("       %s -t <TOOL NAME>" % sys.argv[0])
    print("OPTIONS:")
    print("    --help, print information")

def parse_arg(argv):
    global com_port
    global zip_file
    global tool_name
    try:
        opts, args = getopt(argv, "p:f:t:", ["help"])
        for opt, arg in opts:
            if opt == '-h':
                usage()
                sys.exit()
            elif opt == "-p":
                com_port = arg
            elif opt == "-f":
                zip_file = arg
            elif opt == "-t":
                tool_name = arg
            else:
                Usage()
                sys.exit(1)
    except getopt.GetoptError:
        print("Error: GetoptError!")
        usage()
        sys.exit(1)

def enter_dfu_mode():
    ser = serial.Serial(com_port, 115200, timeout=5)
    ser.write(b"atdfu\r\n")
    ser.close()
    sleep(1)

parse_arg(sys.argv[1:])
enter_dfu_mode()
result = subprocess.run([tool_name, 'dfu', 'usb-serial', '--package', zip_file, '-p', com_port])
print(result)
