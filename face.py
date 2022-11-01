import cv2
import os
import numpy as np
PATH = "training-data/s"

def train_model():
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
            myimage = cv2.imread(fullname)
            gray = cv2.cvtColor(myimage, cv2.COLOR_BGR2GRAY)
            imagelist.append(gray)
            labellist.append((val))
    print("Total faces: {im}, Total labels: {lb}".format(im=len(imagelist),lb=len(labellist)))
    model = cv2.face.EigenFaceRecognizer_create()
    model.train(imagelist,np.array(labellist))
    return model
#need function that a) resizes and converts to .pgm gray input pictures

mymodel = train_model()
myimage = cv2.imread("test1.pgm")
gray = cv2.cvtColor(myimage, cv2.COLOR_BGR2GRAY)
predicted = mymodel.predict(gray)

print(predicted)