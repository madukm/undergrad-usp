#Maria Eduarda Kawakami Moreira - 11218751
#SSC0251 - Image Processing
#01/2020
#Short Assignment 2: Image Restoration

import numpy as np
import imageio
from scipy.fftpack import fftn, ifftn, fftshift

def gaussian_filter(k, sigma):
    arx = np.arange((-k // 2) + 1., (k // 2) + 1.)
    x, y = np.meshgrid(arx, arx)
    filt = np.exp( -(1/2)*(np.square(x) + np.square(y))/np.square(sigma) )
    return filt/np.sum(filt)

def padding(f, g):
    pad1 = (f.shape[0]//2)-g.shape[0]//2
    wp = np.pad(g, (pad1, pad1-1), "constant", constant_values=0)
    return wp

def fft_filter(g, w):
    wp = padding(g, w)

    W = fftn(wp)
    G = fftn(g)
    R = np.multiply(W, G)

    return np.real(fftshift(ifftn(R)))


def normalization(f, maxpixel):
    smallest_pixel = np.amin(f, axis=(0,1))   # smallest pixel in the image
    largest_pixel = np.amax(f, axis=(0, 1))     # largest pixel in the image
    return np.divide(
            np.multiply(
                np.subtract(f.astype(np.float), smallest_pixel), maxpixel), np.subtract(largest_pixel, smallest_pixel))


def CLS(G, H, P, gamma):
    return H.conjugate() / (np.abs(H)**2 + gamma*np.abs(P)**2) * G


def standard_deviation(f):
    return np.round(np.std(f[:]),1)

def main():
    filename = str(input()).rstrip()
    image = imageio.imread(filename)
    k = int(input()) #filter size
    sigma = float(input()) #standard deviation (0 < sigma <= 1)
    gamma = float(input()) #regularization factor (0 < gamma <= 1)

    #Gaussian filter
    g_filter = gaussian_filter(k, sigma)
    filtered = fft_filter(image, g_filter)
    normalized = normalization(filtered, np.amax(image, axis=(0,1)))

    #Laplacian filter
    laplacian_filter = np.array([[0,-1,0], [-1,4,-1], [0,-1,0]])
    laplacian_padded = padding(normalized, laplacian_filter)

    #Constrained Least Squares filter
    P = fftn(laplacian_padded)
    H = fftn(normalized)
    g_padded = padding(normalized, g_filter)
    G = fftn(g_padded)

    F_chapeu = ifftn(CLS(H, G, P, gamma)).real

    final = normalization(F_chapeu, np.amax(normalized, axis=(0,1)))
    print(standard_deviation(final))

if __name__ == '__main__':
    main()
