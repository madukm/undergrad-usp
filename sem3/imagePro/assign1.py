#Maria Eduarda Kawakami Moreira - 11218751
#SSC0215 - Image Processing
#First semester - 2020
#Assignment 1: Intensity Transformation

import numpy as np
import imageio

#adjusting all the images values to float to avoid memory overflow

def inversion(input_img): #transformation 1
    return 255 - input_img.astype(np.float)

def contrastModulation(input_img, lowRange, highRange): #transformation 2
    return (input_img.astype(np.float) - 0)*(highRange-lowRange)/(255-0) + lowRange #255 being the highest image intensity value, and 0 the lowest 

def logarithmic(input_img): #transformation 3
    return 255*(np.log2(1+input_img.astype(np.float))/np.log2(1+255)) #255 being the highest image intensity value

def gammaAdjust(input_img, w, lambd): #transformation 4
    return np.power(input_img.astype(np.float), lambd)*w

def rse(input_img, output_img): #root squared error
    error = np.subtract(input_img.astype(np.float), output_img.astype(np.float)) 
    error = np.sum(np.square(error))
    return np.round(np.sqrt(error), 4)

def main():
    filename = str(input()).rstrip()
    input_img = imageio.imread(filename)
    method = int(input())
    save = int(input())

    if method == 1:
        output_img = inversion(input_img)

    if method == 2:
        c = int(input())
        d = int(input())
        output_img = contrastModulation(input_img, c, d)

    if method == 3:
        output_img = logarithmic(input_img)

    if method == 4:
        W = int(input())
        lambd = float(input())
        output_img = gammaAdjust(input_img, W, lambd)

    if save == 1:
        imageio.imwrite('output_img.png', output_img)

    print(rse(input_img, output_img))

if __name__ == '__main__':
    main()
