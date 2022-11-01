import cv2
import os
import numpy as np
PATH = "training-data/s"

test_label = [1,2,3,41]

imagelist = []
labellist = []
filename = ''
fullname = ''

print("Loading data...")
for val in test_label:
    filename = PATH + "{0}/".format(val)
    for x in range(1,11):
        fullname = filename + "{0}".format(x) + ".pgm"
        imagelist.append(cv2.imread(fullname))
        labellist.append((val))
print(fullname)
print("Total faces: {im}, Total labels: {lb}".format(im=len(imagelist),lb=len(labellist)))
model = cv2.face.EigenFaceRecognizer_create()
model.train(imagelist,np.array(labellist))


