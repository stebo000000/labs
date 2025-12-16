import ctypes
import sys

lib = ctypes.CDLL("/mnt/pth/labs/cpp-labs/mlib.so")


C_CHAR_P = ctypes.POINTER(ctypes.c_char)


lib.run.restype = None
lib.run.argtypes = [C_CHAR_P]

lib.run(sys.argv[1].encode("utf-8"))
