#Maria Eduarda Kawakami Moreira - 11218751
#SSC0251 - Image Processing
#01/2020
#Short Assignment 3: Mathematical Morphology for Color Image Processing

import numpy as np
import imageio
from skimage import morphology
import matplotlib.colors

def normalization(f):
    smallest_pixel = np.amin(f, axis=(0,1))   # smallest pixel in the image
    largest_pixel = np.amax(f, axis=(0, 1))     # largest pixel in the image
    return np.divide(
            np.multiply(
                np.subtract(f.astype(np.float), smallest_pixel), 255), np.subtract(largest_pixel, smallest_pixel))


def RGBopening(rgb_img, k):
    disk = morphology.disk(k)

    #Applying opening
    r_channel = morphology.dilation(morphology.erosion(rgb_img[:,:,0], disk).astype(np.uint8), disk).astype(np.uint8)
    g_channel = morphology.dilation(morphology.erosion(rgb_img[:,:,1], disk).astype(np.uint8), disk).astype(np.uint8)
    b_channel = morphology.dilation(morphology.erosion(rgb_img[:,:,2], disk).astype(np.uint8), disk).astype(np.uint8)

    img_open = np.zeros(rgb_img.shape)
    img_open[:,:,0] = r_channel
    img_open[:,:,1] = g_channel
    img_open[:,:,2] = b_channel

    return img_open

def composition(rgb_img, k):

    #RGB to HSV
    hsv_image = matplotlib.colors.rgb_to_hsv(rgb_img)
    h_channel = normalization(hsv_image[:,:,0])

    #Erosion and dilation
    h_erosion = morphology.erosion(h_channel, morphology.disk(k)).astype(np.uint8)
    h_dilation = morphology.dilation(h_channel, morphology.disk(k)).astype(np.uint8)

    #Gradient = dilation-erosion
    gradient = normalization(np.subtract(h_dilation, h_erosion))

    #Opening and closing
    h_opening = morphology.dilation(h_erosion, morphology.disk(k)).astype(np.uint8)
    h_closing = morphology.erosion(h_dilation, morphology.disk(k)).astype(np.uint8)

    new_rgb = np.zeros(rgb_img.shape)
    new_rgb[:,:,0] = gradient
    new_rgb[:,:,1] = h_opening
    new_rgb[:,:,2] = h_closing

    return new_rgb


def RMSE(f, g):
    n, m = f.shape[0:2]
    error = np.subtract(f.astype("float"), g.astype("float"))
    error = np.divide(np.sum(np.square(error)), n*m)
    return np.round(np.sqrt(error), 4)


def main():
    filename = str(input()).rstrip()
    image = imageio.imread(filename)
    k = int(input()) #size of the structuring element
    option = int(input())

    if option == 1:
        rgb_img = RGBopening(image, k)
        print(RMSE(image, rgb_img))

    if option == 2:
        new_rgb = composition(image, k)
        print(RMSE(image, new_rgb))

    if option == 3:
        rgb_open = RGBopening(image, 2*k)
        composition_img = composition(rgb_open, k)
        print(RMSE(image, composition_img))

if __name__ == '__main__':
    main()
