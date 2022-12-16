# importing os module
import os
# Function to rename multiple files
def main():
	folder = "bonus"
	for count, filename in enumerate(os.listdir(folder)):
		filen = filename.split(".")
		if filen[1] == "c":
			src =f"{folder}/{filename} \\"
			print(src)
if __name__ == '__main__':
	main()
# # importing os module
# import os
# # Function to rename multiple files
# def main():
# 	folder = "bb"
# 	for count, filename in enumerate(os.listdir(folder)):
# 		filen = filename.split(".")
# 		if filen[1] == "c":
# 			dst = f"{filen[0]}_bonus.c"
# 			src =f"{folder}/{filename}"
# 			dst =f"{folder}/{dst}"
# 		if filen[1] == "h":
# 			dst = f"{filen[0]}_bonus.h"
# 			src =f"{folder}/{filename}"
# 			dst =f"{folder}/{dst}"
# 		os.rename(src, dst)
# if __name__ == '__main__':
# 	main()