import ctypes
import sys

filename = sys.argv

my_dll = ctypes.CDLL("./mlib.so")


C_CHAR_PP = ctypes.POINTER(ctypes.POINTER(ctypes.c_char))
C_INT_P = ctypes.POINTER(ctypes.c_int)
C_INT_P_P = ctypes.POINTER(ctypes.POINTER(ctypes.c_int))
C_FILE_P = ctypes.POINTER(ctypes.FILE)  # Use appropriate type for FILE pointer


lib.readWords.argtypes = [C_FILE_P, C_CHAR_PP, C_INT_P_P, C_INT_P]
lib.readWords.restype = None


lib.sort.argtypes = [C_INT_P, ctypes.c_int, C_CHAR_PP, ctypes.c_int, ctypes.c_int]
lib.sort.restype = None


lib.printRes.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.c_int, C_INT_P, C_CHAR_PP]
lib.printRes.restype = None

strs = ctypes.cast(ctypes.malloc(ctypes.sizeof(ctypes.c_char_p)), C_CHAR_PP)
wordsLens = ctypes.cast(ctypes.malloc(ctypes.sizeof(ctypes.c_int)), C_INT_P)
wordsCount = ctypes.c_int(0)

print(f"Opening file: {filename}")
lib.readWords(fptr, strs, wordsLens, ctypes.byref(wordsCount))
